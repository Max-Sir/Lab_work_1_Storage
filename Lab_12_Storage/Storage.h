#pragma once
#define MAX_STR_SIZE 256
#define FL_NO_MATTER 10
typedef enum
{
	vehicle = 1, fruit, vegetable,ammo
}object;

typedef enum {
	banana = 1, apple, orange, lemon
}fruit_type;
typedef enum {
	Potato = 1, Tomato
}Vegetable_TYPE;
typedef enum {
	bullet = 1, grenade, mine
}ammo_type;
typedef enum {
	bugatti = 1, Ferrari, Porshche
}vehicle_type;

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
	char author[MAX_STR_SIZE];
	char name[MAX_STR_SIZE];
	int capacity;
	object type;
	union //objects
	{
		Vehicle vehicle;
		Vegetable vegetable;
		Fruit fruit;
		Ammo ammo;
	};
};
