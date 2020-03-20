#include "input.h"
#include <cstdio>
#include <conio.h>
#include <cstdlib>

//#include "Storage.h"

void input_type(Storage* a)
{
	int type;
	do
	{
		system("cls");
		printf("1 - Vehicle\n");
		printf("2 - Fruit\n");
		printf("3 - Vegetable\n");
		printf("4 - Ammo\n");
		printf("Write media type - ");
		rewind(stdin);
	}
	while (!scanf_s("%d", &type) || type < Vehicle || type > Ammo);
	a->type = (Object)type;
}

void input_Vehicle_model(Storage* a)
{
	int type;
	do
	{
		system("cls");
		printf("1 - ferrari\n");
		printf("2 - mercedes\n");
		printf("3 - tesla\n");
		printf("4 - audi\n");
		printf("Write vehicle model: ");
		rewind(stdin);
	}
	while (!scanf_s("%d", &type) || type < ferrari || type > audi);
	a->vehicle.model = (Vehicle_e)type;
}

void input_Ammo_type(Storage* a)
{
	int type;
	do
	{
		system("cls"); // = 1, , , 
		printf("1 - bullet \n");
		printf("2 - grenade\n");
		printf("3 - mine\n");
		printf("4 - bomb\n");
		printf("Write ammo type: ");
		rewind(stdin);
	}
	while (!scanf_s("%d", &type) || type < bullet || type > bomb);
	a->ammo.type = (Ammo_e)type;
}

void input_Vegetable_type(Storage* a)
{
	int type;
	do
	{
		system("cls"); // = 1, , , 
		printf("1 - potato \n");
		printf("2 - tomato\n");
		printf("3 - carrot\n");
		printf("4 - corn\n");
		printf("Write Vegetable type: ");
		rewind(stdin);
	}
	while (!scanf_s("%d", &type) || type < potato || type > corn);
	a->vegetable.type = (Vegetable_e)type;
}

void input_Fruit_type(Storage* a)
{
	int type;
	do
	{
		system("cls"); // banana = 1, apple, orange, peach 
		printf("1 - banana \n");
		printf("2 - apple\n");
		printf("3 - orange\n");
		printf("4 - peach\n");
		printf("Write fruit type: ");
		rewind(stdin);
	}
	while (!scanf_s("%d", &type) || type < banana || type > peach);
	a->fruit.type = (Fruit_e)type;
}

void input_vehicle_cost(Storage* a)
{
	printf("Write vehicle cost - ");
	scanf_s("%d", &a->vehicle.cost);
}

void input_vehicle_max_speed(Storage* a)
{
	printf("Write vehicle max_speed- ");
	scanf_s("%d", &a->vehicle.max_speed);
}

void input_vehicle_quantity(Storage* a)
{
	printf("Write vehicle quantity- ");
	scanf_s("%d", &a->vehicle.quantity);
}

void input_vegetable_cost(Storage* a)
{
	printf("Write vegetable cost- ");
	scanf_s("%d", &a->vegetable.cost);
}

void input_vegetable_quantity(Storage* a)
{
	printf("Write vegetable quantity- ");
	scanf_s("%d", &a->vegetable.quantity);
}

void input_fruit_cost(Storage* a)
{
	printf("Write fruit cost- ");
	scanf_s("%d", &a->fruit.cost);
}

void input_fruit_quantity(Storage* a)
{
	printf("Write fruit quantity- ");
	scanf_s("%d", &a->fruit.quantity);
}

void input_ammo_cost(Storage* a)
{
	printf("Write ammo cost- ");
	scanf_s("%d", &a->ammo.cost);
}

void input_ammo_quantity(Storage* a)
{
	printf("Write ammo quantity- ");
	scanf_s("%d", &a->ammo.quantity);
}
