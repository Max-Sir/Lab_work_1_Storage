#pragma once
#include "Storage.h"

int notfull_name_cmp(Storage a, Storage b);
int notfull_author_cmp(Storage a, Storage b);
int name_cmp(Storage a, Storage b);
int author_cmp(Storage a, Storage b);
int type_cmp(Storage a, Storage b);
int capacity_cmp(Storage a, Storage b);
int hdd_interface_cmp(Storage a, Storage b);
int hdd_average_seek_time_cmp(Storage a, Storage b);
int hdd_spindle_speed_cmp(Storage a, Storage b);
int ssd_interface_cmp(Storage a, Storage b);
int ssd_input_output_cmp(Storage a, Storage b);
int disk_type_cmp(Storage a, Storage b);
int disk_record_type_cmp(Storage a, Storage b);
int disk_access_time_cmp(Storage a, Storage b);
int disk_data_rate_cmp(Storage a, Storage b);
int usb_standart_cmp(Storage a, Storage b);
int usb_read_speed_cmp(Storage a, Storage b);
int usb_write_speed_cmp(Storage a, Storage b);

int (*cmp_array[])(Storage, Storage) = {
    name_cmp, author_cmp, type_cmp,
    capacity_cmp, hdd_interface_cmp, hdd_average_seek_time_cmp,
    hdd_spindle_speed_cmp, ssd_interface_cmp, ssd_input_output_cmp,
    disk_type_cmp, disk_record_type_cmp, disk_data_rate_cmp,
    disk_access_time_cmp, usb_standart_cmp, usb_read_speed_cmp,
    usb_write_speed_cmp, notfull_name_cmp, notfull_author_cmp
};
