#include<stdio.h>
#include<string.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#include"structure.h"

void main()
{
	setlocale(LC_ALL, "Rus");
	int st = 0;
	printf("Чтобы использовать готовые структуры, введите 1\nЧтобы ввести структуры самому введите 2\n");
	get_st(&st);
	cars* car = NULL;
	int size_car = 0;
	if (st == 1)
	{
		car = init_arr(10);
		car[0] = create_cars(2020, 100, "Audi", Red);
		car[1] = create_cars(2020, 110, "Mercedes", White);
		car[2] = create_cars(2001, 90, "Lada", White);
		car[3] = create_cars(2010, 80, "BMW", Green);
		car[4] = create_cars(2020, 300, "Bugatti", Black);
		car[5] = create_cars(2010, 275, "Kia", Black);
		car[6] = create_cars(2020, 290, "Tesla", Green);
		car[7] = create_cars(2020, 350, "Opel", Red);
		car[8] = create_cars(2018, 130, "Acura", Red);
		car[9] = create_cars(2018, 110, "Ford", Green);
		car[10] = create_cars(2018, 400, "Lambargini", Black);
		size_car = 11;
	}
	if(st == 2)
	{
		car = init_arr(256);
		size_car = get_car(car);
	}
	int flag = 0;
	menu(car, size_car);
	
}
