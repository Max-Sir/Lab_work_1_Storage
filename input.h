#pragma once
#include <cstdio>

#include "Storage.h"

void input_type(Storage* a);

void input_Vehicle_model(Storage* a);

void input_Ammo_type(Storage* a);

void input_Vegetable_type(Storage* a);

void input_Fruit_type(Storage* a);

void input_vehicle_cost(Storage* a);

void input_vehicle_max_speed(Storage* a);

void input_vehicle_quantity(Storage* a);

void input_vegetable_cost(Storage* a);

void input_vegetable_quantity(Storage* a);

void input_fruit_cost(Storage* a);

void input_fruit_quantity(Storage* a);

void input_ammo_cost(Storage* a);

void input_ammo_quantity(Storage* a);

void (*input_func_array[])(Storage*) = {
    input_ammo_cost,input_ammo_quantity,input_Ammo_type,input_fruit_cost,input_fruit_quantity,
    input_Fruit_type, input_type,input_vegetable_cost,input_vegetable_quantity,
    input_Vegetable_type,input_vehicle_cost,input_vehicle_max_speed,input_Vehicle_model,input_vehicle_quantity
};