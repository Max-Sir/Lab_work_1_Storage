#pragma once
#define MAX_STR_SIZE 256
#define FL_NO_MATTER 10
typedef enum
{
	vehicle = 1, fruit, vegetable,ammo
}object;

typedef enum {
	banana = 1, apple, orange, lemon
}Fruit_type;
typedef enum {
	Potato = 1, Tomato
}Vegetable_TYPE;
typedef enum {
	bullet = 1, grenade, mine
}Ammo_type;
typedef enum {
	bugatti = 1, Ferrari, Porshche
}Vehicle_type;

//typedef struct
//{
//	char* model;
//	int cost;
//
//}Vehicle;
//
//typedef struct
//{
//	char* sort;
//	int cost;
//}Fruit;
//
//typedef struct
//{
//	char* type;
//	int cost;
//
//}Vegetable;
//
//typedef struct
//{
//	char* type;
//	int cost;
//
//}Ammo;
typedef struct {
	Fruit_type fruit_type;
	float average_seek_time; // ms
	int spindle_speed; //rpm
} Vehicle;

typedef struct {
	float usb_standart; // 1.0, 1.1, 2.0, 3.0, 3.1, 3.2
	int read_speed; // Mb/s
	int write_speed; // Mb/s
} Fruit;

typedef struct {
	Vegetable_TYPE type;
	Ammo_type record_type;
	int data_rate; // Mb/s
	int access_time; // ms 
}Vegetable;

typedef struct {
	Vehicle_type interface_ssd;
	int input_output; // Mb/s
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
