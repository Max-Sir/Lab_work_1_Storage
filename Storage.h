#pragma once
#include<conio.h>
#include<stdio.h>
#define MAX_STR_SIZE 32
#define FL_NO_MATTER 10
enum Object
{
	Vehicle=1, Vegetable, Fruit, Ammo
};

enum Vegetable_e
{
	potato = 1, tomato, carrot, corn
};

enum Fruit_e
{
	banana = 1, apple, orange, peach
};

enum Ammo_e
{
	bullet = 1, grenade, mine, bomb
};

enum Vehicle_e
{
	ferrari = 1, mercedes, tesla, audi
};

struct Storage
{
	char* company;
	Object type;
	union
	{
		struct Vehicle
		{
			Vehicle_e model;
			int cost;
			int max_speed;
			int quantity;
		}vehicle;

		struct Vegetable
		{
			Vegetable_e type;
			int quantity;
			int cost;
		}vegetable;

		struct Fruit
		{
			Fruit_e type;
			int quantity;
			int cost;
		}fruit;

		struct Ammo
		{
			Ammo_e type;
			int quantity;
			int cost;
		}ammo;
	};
};