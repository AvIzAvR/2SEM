#include<stdio.h>
#include<string.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#include"structure.h"


void get_int(int* x)
{
	while (!scanf_s("%d", x) || getchar() != '\n' || *x <= 0)
	{
		rewind(stdin);
		printf("Неверный тип данных!\n");
	}
}

char* get_string()
{
	int num = 256;
	char* string = (char*)calloc(num, sizeof(char));
	char ch;
	int pos = 0;
	while (1)
	{
		ch = getchar();
		if (ch == '\n')
		{
			string[pos] = '\0';
			string = (char*)realloc(string, (pos + 1) * sizeof(char));
			return string;
		}

		string[pos] = ch;
		pos++;
		if (pos == 256)
			string = (char*)realloc(string, (pos + 1) * sizeof(char));
	}
}

void get_st(int* st)
{
	while (!scanf_s("%d", st) || getchar() != '\n' || *st < 1 || *st > 2)
	{
		rewind(stdin);
		printf("Неверный тип данных!\n");
	}
}

cars* init_arr(int size)
{
	return (cars*)malloc(size * sizeof(cars));
}

void show_struct(cars arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("Название авто: %s        Скорость: %d        Год выпуска: %d        ", arr[i].name, arr[i].speed, arr[i].year);
		switch (arr[i].colors) {
		case Red:
			printf("Color: Red\n");
			break;
		case Green:
			printf("Color: Green\n");
			break;
		case Black:
			printf("Color: Black\n");
			break;
		case White:
			printf("Color: White\n");
			break;
		default:
			printf("Unknown color\n");
			break;
		}
	}
}

cars create_cars(int year, int speed, char* name, enum Colors color)
{
	cars a;
	a.speed = speed;
	a.year = year;
	a.name = name;
	a.colors = color;
	return a;
}



int get_car(cars arr[])
{
	int size_car = 0;
	int size_z = 256;
	printf("Введите название авто, чтобы выйти введите \'s\':");
	char* z = (char*)calloc(size_z, sizeof(char));
	int i = 0;
	int check = 0;
	while (1)
	{
		char letter;
		letter = getchar();
		if (letter != '\n')
		{
			if (i < size_z)
			{
				z[i] = letter;
				printf("%c", letter);
				i++;
			}
			else
			{
				size_z++;
				z = (char*)realloc(z, size_z * sizeof(char));
				z[i] = letter;
				i++;
			}
		}
		else
		{
			z[i] = '\0';
			if (z[0] == 's' && z[1] == '\0')
			{
				break;
			}
			else
			{
				arr[size_car].name = (char*)malloc((sizeof(z) + 1) * sizeof(char));
				strcpy_s(arr[size_car].name, 256, z);
				printf("\nВведите максимальную скорость автомобиля:");
				get_int(&arr[size_car].speed);
				printf("Введите год выпуска автомобиля:");
				get_int(&arr[size_car].year);
				printf("Введите цвет авто из предложенных:\n1 - Red\n2 - White\n3 - Черный\n4 - Зелёный");
				int color;
				get_int(&color);
				switch (color) {
				case 1:
					arr[size_car].colors = Red;
					break;
				case 2:
					arr[size_car].colors = White;
					break;
				case 3:
					arr[size_car].colors = Black;
					break;
				case 4:
					arr[size_car].colors = Green;
					break;
				default:
					arr[size_car].colors = Red;
					break;
				}
				size_car++;
				printf("\nВведите название авто, чтобы выйти введите \'s\':");
				i = 0;
				check++;
			}
		}
	}
	free(z);
	return size_car;
}

int quick_year(cars arr[], int low, int high)
{
	int pivot = arr[high].year;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (arr[j].year <= pivot) {
			i++;
			cars temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	cars temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

void quick_sort_year(cars arr[], int low, int high)
{
	if (low < high) {
		int pi = quick_year(arr, low, high);

		quick_sort_year(arr, low, pi - 1);
		quick_sort_year(arr, pi + 1, high);
	}
}



void quick_sort_speed(cars arr[], int low, int high)
{
	if (low < high) {
		int pi = quick_speed(arr, low, high);

		quick_sort_speed(arr, low, pi - 1);
		quick_sort_speed(arr, pi + 1, high);
	}
}

int quick_speed(cars arr[], int low, int high)
{
	int pivot = arr[high].speed;
	int i = (low - 1);

	for (int j = low; j < high; j++) {
		if (arr[j].speed < pivot) {
			i++;
			cars temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	cars temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

void quick_sort_name(cars arr[], int low, int high)
{
	if (low < high) {
		int pi = quick_name(arr, low, high);

		quick_sort_name(arr, low, pi - 1);
		quick_sort_name(arr, pi + 1, high);
	}
}

int quick_name(cars arr[], int low, int high)
{
	char pivot = arr[high].name[0];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (arr[j].name[0] >= pivot) {
			i++;
			cars temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	cars temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}



void quick_sort_year_name(cars arr[], int low, int high)
{
	quick_sort_year(arr, 0, high);
	for (int i = high; i != 0; i--)
	{
		for (int j = i-1; j != 0; j--)
		{
			if (arr[i].year == arr[j].year)
			{
				quick_sort_name(arr, j, i);
			}
		}
	}
}



void remove_struct(cars arr[], int* size_car)
{
	int delete;
	printf("Выберите номер структуры, который хотите удалить:\n");

	for (int i = 0; i < *size_car; ++i) {
		printf("[%d]: Название авто: %s        Скорость: %d        Год выпуска: %d\n", (i + 1), arr[i].name, arr[i].speed, arr[i].year);
	}
	printf("\n");
	rewind(stdin);
	while (!scanf_s("%d", &delete) || getchar() != '\n' || delete < 1 || delete > *size_car)
	{
		rewind(stdin);
		printf("Неверный тип данных!\n");
	}
	for (int j = delete - 1; j < *size_car - 1; j++)
	{
		arr[j] = arr[j + 1];
	}
	(*size_car)--;
}



int compare_cars_by_year_speed(const void* a, const void* b) {
	cars* car1 = (cars*)a;
	cars* car2 = (cars*)b;

	if (car1->year < car2->year) {
		return -1;
	}
	else if (car1->year > car2->year) {
		return 1;
	}
	else {
		if (car1->speed < car2->speed) {
			return -1;
		}
		else if (car1->speed > car2->speed) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

sort_cars(cars arr[], int size_car)
{
	int key;
	printf("Выберите каким методом вы желаете отсортировать структуры\n1-По алфавиту(названия)\n2-По году\n3-По скорости\n4-По алфавиту(названия) и году\n");
	while (!scanf_s("%d", &key) || key > 4 || key <= 0) {
		printf("Неверно введённые данные\n");
		rewind(stdin);
	}
	switch (key) {
	case 1: {
		quick_sort_name(arr, 0, size_car - 1);
		break;
	}
	case 2: {
		quick_sort_year(arr, 0, size_car - 1);
		break;
	}
	case 3: {
		quick_sort_speed(arr, 0, size_car - 1);
		break;
	}
	case 4: {
		quick_sort_year_name(arr, 0, size_car - 1);
	}
	}
}

void menu(cars arr[], int size_car)
{
	int key;
	while (1) {
		printf("Что вы хотите сделать?\n1) Показать структуры\n2) Отсортировать структуры\n3) Удалить структуру\n");
		while (!scanf_s("%d", &key) || key > 3 || key <= 0) {
			printf("Неверно введённый тип данных\n");
			rewind(stdin);
		}
		switch (key) {
		case 1: {
			show_struct(arr, size_car);
			break;
		}
		case 2: {
			sort_cars(arr, size_car);
			show_struct(arr, size_car);
			break;
		}
		case 3: {
			remove_struct(arr, &size_car);
			show_struct(arr, size_car);
			break;
		}
		default: {
			printf("Неверно введённый тип данных\n");
			break;
		}
		}
	}
}

