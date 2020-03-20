#pragma once
#include "Storage.h"

int menu();
int is_empty(int size);
int fl_type_media(int choice);
Storage* input_array(int* size);
Storage* new_array();
Storage* new_inf(Storage* array, int* size);
void output_array(Storage* array, int size);
void output_inf(Storage* inf, int index);
void table();
void edit_inf(Storage* array, int size);
int choose_field_to_edit(Storage* inf);
void media_specification_edit(Storage* inf, int choice);
void find_inf(Storage* array, int size);
int choose_find_inf(Storage* array);
void sort_array(Storage* array, int size);
void swap(Storage* array, int a, int b);
void delete_array(Storage* array, int* size);
void delete_inf(Storage* array, int i, int* size);
void notfull_search(Storage* array, int size);