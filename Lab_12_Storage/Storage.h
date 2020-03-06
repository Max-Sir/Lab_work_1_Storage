#pragma once
#define MAX_STR_SIZE 256
#define FL_NO_MATTER 10

typedef enum {
    vehicle = 1, fruit, vegetable, ammo
}Type;
typedef enum {
    banana = 1, apple, orange, lemon
}Fruit_t;
typedef enum {
    potato = 1, tomato
}Vegetable_t;
typedef enum {
    bugatti = 1, ferrari, audi
}Vehicle_t;

typedef struct {
    Fruit_t fruit_t;
    float average_seek_time; // ms
    int spindle_speed; //rpm
} Fruit;

typedef struct {
    Vegetable_t type;
    int data_rate; // Mb/s
    int access_time; // ms 
} Vegetable;

typedef struct {
    Vehicle_t interface_ssd;
    int input_output; // Mb/s
} Vehicle;

typedef struct {
    Type type;
    float capacity;
    char author[MAX_STR_SIZE];
    char name[MAX_STR_SIZE];
    union {
        Fruit hdd;
        Vegetable disk;
        Vehicle ssd;
    };
}Storage;