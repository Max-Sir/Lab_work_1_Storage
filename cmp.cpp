#include"cmp.h"
#include "Storage.h"
int not_full_company_cmp(Storage a, Storage b)
{
	return (strstr(a.company, b.company) == NULL) ? -1 : 0;
}

int obj_type_cmp(Storage a, Storage b)
{
    return (int)(a.type - b.type);
}


int vehicle_model_cmp(Storage a, Storage b) {
    return (int)(a.vehicle.model - b.vehicle.model);
}

int vehicle_cost_cmp(Storage a, Storage b) {
    return (int)(a.vehicle.cost - b.vehicle.cost);
}

int vehicle_quantity_cmp(Storage a, Storage b) {
    return (int)(a.vehicle.quantity - b.vehicle.quantity);
}

int vehicle_max_speed_cmp(Storage a, Storage b) {
    return (int)(a.vehicle.max_speed - b.vehicle.max_speed);
}

int vegetable_type_cmp(Storage a, Storage b) {
    return (int)(a.vegetable.type - b.vegetable.type);
}

int vegetable_cost_cmp(Storage a, Storage b) {
    return (int)(a.vegetable.cost - b.vegetable.cost);
}

int vegetable_quantity_cmp(Storage a, Storage b) {
    return (int)(a.vegetable.quantity - b.vegetable.quantity);
}

int fruit_type_cmp(Storage a, Storage b) {
    return (int)(a.fruit.type - b.fruit.type);
}

int fruit_cost_cmp(Storage a, Storage b) {
    return (int)(a.fruit.cost - b.fruit.cost);
}

int fruit_quantity_cmp(Storage a, Storage b) {
    return (int)(a.fruit.quantity - b.fruit.quantity);
}

int ammo_type_cmp(Storage a, Storage b) {
    return (int)(a.ammo.type - b.ammo.type);
}

int ammo_cost_cmp(Storage a, Storage b) {
    return (int)(a.ammo.cost - b.ammo.cost);
}

int ammo_quantity_cmp(Storage a, Storage b) {
    return (int)(a.ammo.quantity - b.ammo.quantity);
}

