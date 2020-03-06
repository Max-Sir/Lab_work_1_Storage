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

int hdd_interface_cmp(Storage a, Storage b) {
    return (int)(a.hdd.fruit_t - b.hdd.fruit_t);
}

int hdd_average_seek_time_cmp(Storage a, Storage b) {
    float c = a.hdd.average_seek_time - b.hdd.average_seek_time;
    return (c == 0) ? 0 : (c > 0) ? 1 : -1;
}

int hdd_spindle_speed_cmp(Storage a, Storage b) {
    return a.hdd.spindle_speed - b.hdd.spindle_speed;
}

int ssd_interface_cmp(Storage a, Storage b) {
    return (int)(a.ssd.interface_ssd - b.ssd.interface_ssd);
}

int ssd_input_output_cmp(Storage a, Storage b) {
    return a.ssd.input_output - b.ssd.input_output;
}

int disk_type_cmp(Storage a, Storage b) {
    return (int)(a.disk.type - b.disk.type);
}

int disk_access_time_cmp(Storage a, Storage b) {
    return a.disk.access_time - b.disk.access_time;
}

int disk_data_rate_cmp(Storage a, Storage b) {
    return a.disk.data_rate - b.disk.data_rate;
}