﻿#include "pch.h"

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, LPTSTR argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 3)
	{
		printf("Использование: cpCF file1 file2\n");
		return 1;
	}
	if (!СopyFile(argv[1], argv[2], FALSE))
	{
		printf("Ошибка CopyFile : %x\n", GetLastError());
		return 2;
	}
	return 0;
}
