#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<list>
typedef enum
{
	vehicle = 1, fruit, vegetable
}object;

typedef struct
{
	char* model;
	int cost;

}Vehicle;

typedef struct
{
	char* sort;
	int cost;
}Fruit;

typedef struct
{
	char* type;
	int cost;

}Vegetable;

typedef struct
{
	char* type;
	int cost;

}Ammo;

struct Storage
{
	int capacity;
	object type;
	union objects
	{
		Vehicle vehicle;
		Vegetable vegetable;
		Fruit fruit;
		Ammo ammo;
	};
};


int main(void)
{
	Storage* st;
	
}