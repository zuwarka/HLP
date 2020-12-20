#define _CRT_NO_WARNINGS
#include <stdio.h>
#define N 10

/*19. Дан целочисленный массив A размера N. Вывести номер первого из тех его элементов A[i], 
которые удовлетворяют двойному неравенству: 
A[1] < A[i] < A[N]. 
Если таких элементов нет, то вывести 0.*/

int main()
{
	int A[N], i = 0;
	int* ptr = A;
	printf("Input your string: ");
	for (i = 0; i < N; i++)
		scanf_s("%d", &A[i]);

	i = 0; //Обнуляем счетчик

	for (int* pa = A; pa <= &A[N - 1]; pa++) //Проходим по массиву с помощью указателя, пока 
	{										 //он не дойдет до адреса последнего элемента массива
		if ((*(ptr + i) > (*ptr)) && (*(ptr + i) < *(ptr + N-1))) //Проверка заданного условия
		{
			printf("The answer is: %d\n", i);
			break;
		}
		else
			i++;
	}

	if(i == N)
		printf("The answer is: 0\n");

	return 0;
}
