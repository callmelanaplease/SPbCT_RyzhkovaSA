﻿#include "pch.h"
#include <stdio.h>
#include <errno.h>
#include <locale.h>
#define BUF_SIZE 256
int main(int argc, char *argv[])
{
	setlocale (LC_ALL, "Russian");
	errno_t err;
	FILE *in_file, *out_file; char rec
		[BUF_SIZE]; size_t bytes_in,
		bytes_out;
	if (argc != 3)
	{
		printf("Использование: Cрc file1 File2\n");
		return 1;
	}
	err = fopen_s(&in_file, argv[1], "rb");
	if (in_file == NULL)
	{
		perror(argv[1]);
		return 2;
	}
	err = fopen_s(&out_file, argv[2], "wb");
	if (out_file == NULL)
	{
		perror(argv[2]);
		return 3;
	}
	/* Обрабатываем входной файл по одной записи. */
	while ((bytes_in = fread(rec, 1, BUF_SIZE, in_file)) > 0)
	{
		bytes_out = fwrite(rec, 1, bytes_in, out_file);
		if (bytes_out != bytes_in)
		{
			perror("Неисправимая ошибка записи.");
			return 4;
		}
	}
	fclose(in_file);
	fclose(out_file);
}
