#ifndef structure
#define structure

#include<stdio.h>
#include<stdlib.h>

enum Colors{
	Red,
	White,
	Black,
	Green
};


typedef struct {
	char* name;
	int speed;
	int year;
	enum Colors colors;
} cars;

void get_int(int* x);
cars* init_arr(int size);
void show_struct(cars arr[], int size);
int get_car(cars arr[]);
void quick_sort_year(cars arr[], int low, int high);
void quick_sort_speed(cars arr[], int low, int high);
void quick_sort_year_name(cars arr[], int low, int high);
void get_st(int* st);
cars create_cars(int year, int speed, char* name);
int menu(cars arr[], int size_car);


#endif
