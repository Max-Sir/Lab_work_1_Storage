#pragma once
#include "Storage.h"

void input_variable(char variable_type, ...);
void input_type(Storage* a);
void input_capacity(Storage* a);
void input_author(Storage* a);
void input_name(Storage* a);
void input_fruit_interface(Storage* a);
void input_fruit_average_seek_time(Storage* a);
void input_fruit_spindle_speed(Storage* a);
void input_vegetable_interface(Storage* a);
void input_vegetable_input_output(Storage* a);
void input_vehicle_type(Storage* a);
void input_vehicle_ammo_type(Storage* a);
void input_vehicle_access_time(Storage* a);
void input_vehicle_data_rate(Storage* a);
void input_usb_standart(Storage* a);
void input_usb_read_speed(Storage* a);
void input_usb_write_speed(Storage* a);

void (*input_func_array[])(Storage*) = {
    input_name, input_author, input_type,
    input_capacity, input_fruit_interface, input_fruit_average_seek_time,
    input_fruit_spindle_speed, input_vegetable_interface, input_vegetable_input_output,
    input_vehicle_type, input_vehicle_ammo_type, input_vehicle_data_rate,
    input_vehicle_access_time, input_usb_standart, input_usb_read_speed,
    input_usb_write_speed
};