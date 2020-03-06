#include "Storage.h"
#include <string.h>

int notfull_name_cmp(Storage a, Storage b) {
    return (strstr(a.name, b.name) == NULL) ? -1 : 0;
}

int notfull_author_cmp(Storage a, Storage b) {
    return (strstr(a.author, b.author) == NULL) ? -1 : 0;
}

int name_cmp(Storage a, Storage b) {
    return strcmp(a.name, b.name);
}

int author_cmp(Storage a, Storage b) {
    return strcmp(a.author, b.author);
}

int type_cmp(Storage a, Storage b) {
    return (int)(a.type - b.type);
}

int capacity_cmp(Storage a, Storage b) {
    return a.capacity - b.capacity;
}

int fruit_interface_cmp(Storage a, Storage b) {
    return (int)(a.fruit.interface_fruit - b.fruit.interface_fruit);
}

int fruit_average_seek_time_cmp(Storage a, Storage b) {
    float c = a.fruit.average_seek_time - b.fruit.average_seek_time;
    return (c == 0) ? 0 : (c > 0) ? 1 : -1;
}

int fruit_spindle_speed_cmp(Storage a, Storage b) {
    return a.fruit.spindle_speed - b.fruit.spindle_speed;
}

int vegetable_interface_cmp(Storage a, Storage b) {
    return (int)(a.vegetable.interface_vegetable - b.vegetable.interface_vegetable);
}

int vegetable_input_output_cmp(Storage a, Storage b) {
    return a.vegetable.input_output - b.vegetable.input_output;
}

int vehicle_type_cmp(Storage a, Storage b) {
    return (int)(a.vehicle.type - b.vehicle.type);
}

int vehicle_ammo_type_cmp(Storage a, Storage b) {
    return (int)(a.vehicle.ammo_type - b.vehicle.ammo_type);
}

int vehicle_access_time_cmp(Storage a, Storage b) {
    return a.vehicle.access_time - b.vehicle.access_time;
}

int vehicle_data_rate_cmp(Storage a, Storage b) {
    return a.vehicle.data_rate - b.vehicle.data_rate;
}

int usb_standart_cmp(Storage a, Storage b) {
    float c = a.ammo.usb_standart - b.ammo.usb_standart;
    return (c == 0) ? 0 : (c > 0) ? 1 : -1;
}

int usb_read_speed_cmp(Storage a, Storage b) {
    return a.ammo.read_speed - b.ammo.read_speed;
}

int usb_write_speed_cmp(Storage a, Storage b) {
    return a.ammo.write_speed - b.ammo.write_speed;
}
