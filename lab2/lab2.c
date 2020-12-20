#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 2048

/*19. В новом файле каждая строка должна иметь свой номер,
текст строки располагаться с 15-й позиции*/

void nullcheck(FILE* f) //проверка на нуль 
{
	if (!f)
	{
		printf("Error opening file!!!\n");
		exit(1);
	}
}

int main()
{
	char initfile[500] = "C:\\Users\\Oldenburg\\Desktop\\ГУАП\\2 курс\\Программирование 3 семестр\\Лаб 2 пяву\\Readme.txt";
	char resfile[500] = "C:\\Users\\Oldenburg\\Desktop\\ГУАП\\2 курс\\Программирование 3 семестр\\Лаб 2 пяву\\Wrttome.txt";
	char str[N], res[N]; //входная и с отступами строка
	char* inptr = str, * outptr = res; //указатели для входной и результирующей строк
	int i = 1; //счетчик строк
	FILE* F1, * F2;

	printf("The program has started...\n");
	F1 = fopen(initfile, "rt");
	nullcheck(F1);
	F2 = fopen(resfile, "wt");
	nullcheck(F2);

	while (!feof(F1))
	{
		do {
			inptr = fgets(str, N, F1); //читаем строку из файла F1 с помощью указателя inptr
			if (inptr == NULL) //если строки кончились, выходим из цикла
				break;
			fprintf(F2, "%d. ", i); //ставим в результирующий файл номер данной строки
			i++; //прибавляем счетчик строк
			for (int j = 0; j <= 14; j++) //берем отступ в 14 позиции, так как один отступ уже есть для номера строки
				fprintf(F2, "%c", ' ');
			fprintf(F2, "%s", str); //пишем строку в новый файл
		} while (*inptr != '\0'); //читаем строку, пока не встретим нуль-терминатор
	}

	fclose(F1);
	fclose(F2);
	printf("The program has finished succesfully!\n");

	return 0;
}
