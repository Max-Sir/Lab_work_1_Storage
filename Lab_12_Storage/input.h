#pragma once
#include "Storage.h"
void input_variable(char variable_type, ...);
void input_type(Storage* a);
void input_capacity(Storage* a);
void input_author(Storage* a);
void input_name(Storage* a);
void input_hdd_interface(Storage* a);
void input_hdd_average_seek_time(Storage* a);
void input_hdd_spindle_speed(Storage* a);
void input_ssd_interface(Storage* a);
void input_ssd_input_output(Storage* a);
void input_disk_type(Storage* a);
void input_disk_record_type(Storage* a);
void input_disk_access_time(Storage* a);
void input_disk_data_rate(Storage* a);
void input_usb_standart(Storage* a);
void input_usb_read_speed(Storage* a);
void input_usb_write_speed(Storage* a);

void (*input_func_array[])(Storage*) = {
    input_name, input_author, input_type,
    input_capacity, input_hdd_interface, input_hdd_average_seek_time,
    input_hdd_spindle_speed, input_ssd_interface, input_ssd_input_output,
    input_disk_type, input_disk_record_type, input_disk_data_rate,
    input_disk_access_time, input_usb_standart, input_usb_read_speed,
    input_usb_write_speed
};