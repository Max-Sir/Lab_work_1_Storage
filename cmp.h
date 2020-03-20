#pragma once
#include "Storage.h"
#include <string.h>

//int notfull_name_cmp(Storage* a, Storage b) {
//    return (strstr(a, b.name) == NULL) ? -1 : 0;
//}
//int notfull_author_cmp(Storage a, Storage b) {
//    return (strstr(a.author, b.author) == NULL) ? -1 : 0;
//}
//int hdd_average_seek_time_cmp(Storage a, Storage b) {
//    float c = a.hdd.average_seek_time - b.hdd.average_seek_time;
//    return (c == 0) ? 0 : (c > 0) ? 1 : -1;
//}
//

int obj_type_cmp(Storage a, Storage b);

int vehicle_model_cmp(Storage a, Storage b);

int vehicle_cost_cmp(Storage a, Storage b);

int vehicle_quantity_cmp(Storage a, Storage b);

int vehicle_max_speed_cmp(Storage a, Storage b);

int vegetable_type_cmp(Storage a, Storage b);

int vegetable_cost_cmp(Storage a, Storage b);

int vegetable_quantity_cmp(Storage a, Storage b);

int fruit_type_cmp(Storage a, Storage b);

int fruit_cost_cmp(Storage a, Storage b);

int fruit_quantity_cmp(Storage a, Storage b);

int ammo_type_cmp(Storage a, Storage b);

int ammo_cost_cmp(Storage a, Storage b);

int ammo_quantity_cmp(Storage a, Storage b);

int (*cmp_array[])(Storage, Storage) = {
    obj_type_cmp,vehicle_model_cmp,vehicle_cost_cmp,vehicle_quantity_cmp,vehicle_max_speed_cmp,vegetable_type_cmp,
    vegetable_cost_cmp,vegetable_quantity_cmp,fruit_type_cmp,fruit_cost_cmp,fruit_quantity_cmp,ammo_type_cmp,
    ammo_cost_cmp,ammo_quantity_cmp
};