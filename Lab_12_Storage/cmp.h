#pragma once
#include "Storage.h"

int notfull_name_cmp(Storage a, Storage b);
int notfull_author_cmp(Storage a, Storage b);
int name_cmp(Storage a, Storage b);
int author_cmp(Storage a, Storage b);
int type_cmp(Storage a, Storage b);
int capacity_cmp(Storage a, Storage b);
int fruit_interface_cmp(Storage a, Storage b);
int fruit_average_seek_time_cmp(Storage a, Storage b);
int fruit_spindle_speed_cmp(Storage a, Storage b);
int vegetable_interface_cmp(Storage a, Storage b);
int vegetable_input_output_cmp(Storage a, Storage b);
int vehicle_type_cmp(Storage a, Storage b);
int vehicle_ammo_type_cmp(Storage a, Storage b);
int vehicle_access_time_cmp(Storage a, Storage b);
int vehicle_data_rate_cmp(Storage a, Storage b);
int usb_standart_cmp(Storage a, Storage b);
int usb_read_speed_cmp(Storage a, Storage b);
int usb_write_speed_cmp(Storage a, Storage b);

int (*cmp_array[])(Storage, Storage) = {
    name_cmp, author_cmp, type_cmp,
    capacity_cmp, fruit_interface_cmp, fruit_average_seek_time_cmp,
    fruit_spindle_speed_cmp, vegetable_interface_cmp, vegetable_input_output_cmp,
    vehicle_type_cmp, vehicle_ammo_type_cmp, vehicle_data_rate_cmp,
    vehicle_access_time_cmp, usb_standart_cmp, usb_read_speed_cmp,
    usb_write_speed_cmp, notfull_name_cmp, notfull_author_cmp
};
