// Lab_2_20.03.2020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"Lab_2_20.03.2020.h"
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include "input.h"
#include "cmp.h"
#include "Storage.h"
#include <iostream>


int (*cmp_array[])(Storage, Storage) = {
 not_full_company_cmp,

 obj_type_cmp,

 vehicle_model_cmp,
 vehicle_cost_cmp,
 vehicle_max_speed_cmp,
 vehicle_quantity_cmp,

 vegetable_type_cmp,
 vegetable_quantity_cmp,
 vegetable_cost_cmp,

 fruit_type_cmp,
 fruit_quantity_cmp,
 fruit_cost_cmp,

 ammo_type_cmp,
 ammo_quantity_cmp,
 ammo_cost_cmp,
};

void (*input_func_array[])(Storage*) = {

 input_company,

 input_type,

 input_Vehicle_model,
    input_vehicle_cost,input_vehicle_max_speed,input_vehicle_quantity,
input_Vegetable_type,
    input_vegetable_quantity,input_vegetable_cost,
 input_Fruit_type,
    input_fruit_quantity,input_fruit_cost,
input_Ammo_type,
 input_ammo_quantity, input_ammo_cost,
};

int main() {
    int size = 0;
    Storage* array=static_cast<Storage*>(malloc(0));
    while (true) {
        switch (menu()) {
        case 1: array = input_array(&size); break;
        case 2: output_array(array, size); break;
        case 3: edit_inf(array, size); break;
        case 4: find_inf(array, size); break;
        case 5: sort_array(array, size); break;
        case 6: delete_array(array, &size); break;
        case 7 : not_full_search(array, size); break;
        case -1: return 0; break;
        default: printf("Wrong choice\n"); break;
        }
    }
    free(array);
    return 0;
}

int menu() {
    int choice;

    do {
        system("CLS");
        printf("1 - input storage array\n");
        printf("2 - output storage array\n");
        printf("3 - edit storage\n");
        printf("4 - find storage\n");
        printf("5 - sort storage\n");
        printf("6 - delete storage\n");
        printf("7 - partial search\n");
        printf("-1 - quit\n");
        printf("choose  - ");
        rewind(stdin);
    } while(!scanf_s("%d", &choice) || ((choice < 1 || choice > 7) && choice != -1));

    return choice;
}



int is_empty(int size) {
    if (size == 0) {
        printf("Array is empty\n");
        rewind(stdin);
        return 1;
    }
    return 0;
}

int fl_type_storage(int choice) {
    int type_storage=0;
    switch (choice) {
        case 1 : case 2 :
            type_storage = FL_NO_MATTER;
            break;
        case 3: case 4:case 5 : case 6 :
            type_storage = Vehicle;//hdd ssd disk ammo
            break;
        case 7:case 8 : case 9 :
            type_storage = Vegetable;
            break;
        case 10 : case 11 : case 12 :
            type_storage = Fruit;
            break;
        case 13: case 14 : case 15 :
            type_storage = Ammo;
            break;
        case -1 :
            type_storage = 0;
            break;
    }
    return type_storage;
}

//-----------INPUT------------------------------------------------------------------------------------

Storage* input_array(int* size) {
    Storage* array = new_array();
    int choice;
    while (1) {
        do {
            system("CLS");
            printf("0 - stop\n");
            printf("1 - continue\n");
            rewind(stdin);
        } while (!scanf_s("%d", &choice) || choice < 0 || choice > 1);
        if (choice == 0)
            break;
        array = new_inf(array, size);
    }
    return array;
}

Storage* new_array() {
    Storage* storage;
    if (!(storage = (Storage*)malloc(1 * sizeof(Storage)))) {
        printf("memory allocation error");
        exit(0);
    }
    return storage;
}

Storage* new_inf(Storage* array, int* size) {
    if (!(array = static_cast<Storage*>(realloc(array, (*size + 1) * sizeof(Storage))))) {
        printf("memory reallocation error");
        exit(0);
    }

    for (int i = 0; i <= 1; ++i)
        input_func_array[i](&array[*size]);
    switch (array[*size].type) {
        case Vehicle :
            for (int i = 2; i <= 5; ++i)
                input_func_array[i](&array[*size]);
            break;
        case Vegetable :
            for (int i = 7; i <= 8; ++i) 
                input_func_array[i](&array[*size]);
            break;
        case Fruit :
            for (int i = 9; i <= 12; ++i)
                input_func_array[i](&array[*size]);   
            break;
        case Ammo :
            for (int i = 13; i <= 14; ++i)
                input_func_array[i](&array[*size]);
            break;
    }
    (*size)++;
    return array;
}

//----------------OUTPUT------------------------------------------

void output_array(Storage* array, int size) {
    int i;
    if (is_empty(size)) 
        return;
    do {
        system("cls");
        printf("write index of array to output\n");
        printf("-1 - ouput all array\n");
        printf("choice - ");
        rewind(stdin);
    }while (!scanf_s("%d", &i) || i >= size || i < -1);
    table();
    if (i == -1) {
        
        for (int j = 0; j < size; ++j) {
            output_inf(array, j);
        }
    }
    else {
        output_inf(array, i);
    }
    rewind(stdin);
    _getch();
} 

void table() {//table of output data
    printf("4 - vehicle model\n");
    printf("5 - vehicle cost\n");
    printf("6 - vehicle max speed\n");
    printf("7 - vehicle quantity\n");
    printf("8 - vegetable type\n");
    printf("9 - vegetable quantity\n");
    printf("9 - vegetable cost\n");
    printf("11 - fruit type\n");
    printf("12 - fruit quantity\n");
    printf("13 - fruit cost\n");           
    printf("14 - ammo type\n");
    printf("15 - ammo quantity\n");
    printf("16 - ammo cost\n");
    printf("\n");
    printf("ind ");
    printf("company    ");
    printf("type\t");
    printf("4\t");
    printf("5\t");
    printf("6\t");
    printf("7\t");
    printf("8\t");
    printf("9\t");
    printf("10\t");
    printf("11\t");
    printf("12\t");
    printf("13\t");
    printf("14\t");
    printf("15\t");
    printf("16\t");
    printf("\n");
}

void output_inf(Storage* inf, int i) {
    
    printf("%d. ", i);
    printf("%-8s ", inf[i].company);
    
    switch (inf[i].type) {
        case Vehicle : printf("Vehicle \t"); break;
        case Vegetable : printf("Vegetable \t"); break;
        case Fruit : printf("Fruit \t"); break;
        case Ammo : printf("Ammo \t"); break;
    }

    switch (inf[i].type) {
        case Fruit :
            switch (inf[i].fruit.type) {
            case banana: printf("banana\t"); break;
            case apple: printf("apple\t"); break;
            case orange: printf("orange\t"); break;
            case peach: printf("peach\t"); break;
            }
           
            printf("%d\t", inf[i].fruit.cost);
            printf("%d\t", inf[i].fruit.quantity);
            printf("--\t--\t--\t--\t--\t--\t--\t--\t");           
            break;
        case Vehicle :
            printf("--\t--\t--\t--\t");
            switch (inf[i].vehicle.model) {
            case ferrari: printf("ferrari\t"); break;
            case mercedes: printf("mercedes\t"); break;
            case tesla: printf("tesla\t"); break;
            case audi: printf("audi\t"); break;
            }
            printf("%d\t", inf[i].vehicle.quantity);
            printf("%d\t", inf[i].vehicle.cost);
            printf("%d\t", inf[i].vehicle.max_speed);
            printf("--\t--\t--\t--\t--\t");
            break;
        case Vegetable :
            printf("--\t--\t--\t--\t--\t--\t--\t");
            switch (inf[i].vegetable.type) {
            case potato: printf("potato\t"); break;
            case tomato: printf("tomato\t"); break;
            case carrot: printf("carrot\t"); break;
            case corn: printf("corn\t"); break;
            }
            printf("%d\t", inf[i].vegetable.cost);
            printf("%d\t", inf[i].vegetable.quantity);
            printf("--\t--\t--\t");
            break;
        case Ammo :
    	switch (inf[i].ammo.type)
    	{
        case bullet: printf("bullet\t"); break;
        case grenade: printf("grenade\t"); break;
        case mine: printf("mine\t"); break;
        case bomb: printf("bomb\t"); break;
    	}
            printf("--\t--\t--\t--\t--\t--\t--\t--\t--\t");
            printf("%d\t", inf[i].ammo.cost);
            printf("%d\t", inf[i].ammo.quantity);
            break;
    }   
    printf("\n");
}

//-----------------EDIT--------------

void edit_inf(Storage* array, int size) {
   // int choice;
    int i;
    if (is_empty(size))
        return;
    
    printf("Choose index of array to edit\n");
    rewind(stdin);
    while (!scanf_s("%d", &i) || i < 0 || i >= size) {
        printf("Wrong choice\n");
        printf("Try again - ");
        rewind(stdin);
    }
    while (1) {
        int choice = choose_field_to_edit(&array[i]);
        system("cls");
        switch (choice) {
            case 1 : case 2 : case 3 : case 4 :
                input_func_array[choice - 1](&array[i]); 
                break;
            case 5 : case 6 : case 7 : case 8 :
                storage_type_edit(&array[i], choice);
                break;
            case -1 :
                return;
            default :
                printf("Wrong choice\n");
                break;
        }
    } 
}

int choose_field_to_edit(Storage* inf) {
    int choice;
    while (1) {
        system("cls");
        printf("1 - obj type\n");
        printf("2 - company name\n");
        switch (inf->type) {
            case Vehicle :
                printf("3 - vehicle model\n");
                printf("4 - vehicle cost\n");
                printf("5 - vehicle max speed\n");
                printf("6 - vehicle quantity");
                break;
            case Vegetable :
                printf("3 - vegetable type\n");
                printf("4 - vegetable quantity\n");
                printf("5 - vegetable cost\n");
                break;
            case Fruit :
                printf("3 - fruit type\n");
                printf("4 - fruit quantity\n");
                printf("5 - fruit cost\n");      
                break;
            case Ammo :
                printf("3 - ammo type\n");
                printf("4 - ammo quantity\n");
                printf("5 - ammo cost\n");
                break;
        }
        printf("-1 - quit\n");
        printf("choice - ");
        rewind(stdin);
        if (scanf_s("%d", &choice) && ((choice >= 1 && choice <= 6) 
        || (inf->type == Vehicle && choice == 7)
        || (inf->type == Fruit && (choice == 7 || choice == 8))
        || (inf->type == Ammo && choice == 7)
        || choice == -1))
            break;
    }
   return choice;
}

void storage_type_edit(Storage* inf, int choice) {
    switch (inf->type) {
        case Vehicle :
            input_func_array[choice - 1](inf);
            break;
        case Vegetable :
            input_func_array[choice + 2](inf);
            break;
        case Fruit :
            input_func_array[choice + 4](inf);
            break;
        case Ammo :
            input_func_array[choice + 8](inf);
            break;
    }
}

//-----------SEARCH-----------------------------------

void find_inf(Storage* array, int size) {
    int fl = 0;
    Storage find{};
    if (is_empty(size))
        return;
    
    int choice = choose_find_inf(array);
    int type_storage = fl_type_storage(choice);
    if (!type_storage)
        return;

    input_func_array[choice - 1](&find);

    if (choice == 1 || choice == 2) {
        choice += 16;
    }
    for (int i = 0; i < size; ++i) {
        if ((type_storage == FL_NO_MATTER || array[i].type == type_storage)
        && cmp_array[choice - 1](array[i], find) == 0) {
            output_inf(array, i);
            fl = 1;
        }
    }
    if (!fl)
        printf("No found\n");
    rewind(stdin);
}

int choose_find_inf(Storage* array) {
    int choice;
    while (1) {
        system("cls");
        printf("1 - company\n");
        printf("2 - storage type\n");
        printf("3 - vehicle model\n");
        printf("4 - vehicle cost\n");
        printf("5 - vehicle max speed\n");
        printf("6 - vehicle quantity\n");
        printf("7 - vegetable type\n");
        printf("8 - vegetable quantity\n");
        printf("9 - vegetable cost\n");
        printf("10 - fruit type\n");
        printf("11 - fruit quantity\n");
        printf("13 - fruit cost\n");           
        printf("14 - ammo type\n");
        printf("15 - ammo quantity\n");
        printf("16 - ammo cost\n");
        printf("-1 - quit\n");
        printf("choice - ");
        rewind(stdin);
        if (scanf_s("%d", &choice) && (choice >= 1 && choice <= 16 || choice == -1))
            break;
    }
   return choice;
}    

//------------------SORT---------------------

void sort_array(Storage* array, int size) {
	int swap_index;
    int swap_fl = 0;
    if (is_empty(size))
        return;
    
    int choice = choose_find_inf(array);
    int type_storage = fl_type_storage(choice);
    if (!type_storage)
        return;

    for (int i = 0; i < size - 1; ++i) {
        int fl = 0;
        for (int j = 0; j < size - i; ++j) {
            if ((type_storage == FL_NO_MATTER || array[j].type == type_storage)) {
                if (!fl) {
                    fl = 1;
                    swap_index = j;
                    continue;
                }
                if (cmp_array[choice - 1](array[swap_index], array[j]) > 0) {
                    swap(array, swap_index, j);
                    swap_fl = 1;
                }
                    
                swap_index = j;
            }
        }
    }
    if (!swap_fl)
        printf("Array is already sorted\n");
    else 
        printf("Sort is completed\n");
    rewind(stdin);
}

void swap(Storage* array, int a, int b) {
    Storage tmpr = array[a];
    array[a] = array[b];
    array[b] = tmpr;
}

//------------DELETION------------------

void delete_array(Storage* array, int* size) {
	int fl = 0;
    Storage find{};
    if (is_empty(*size))
        return;
    
    int choice = choose_find_inf(array);
    int type_media = fl_type_storage(choice);
    if (!type_media)
        return;

    input_func_array[choice - 1](&find);
    for (int i = 0; i < *size; ++i) {
        if ((type_media == FL_NO_MATTER || array[i].type == type_media)
        && cmp_array[choice - 1](array[i], find) == 0) {
            delete_inf(array, i, size);
            i--;
            fl = 1;
        }
    }
    if (fl)
        printf("Deleteion succesfully done\n");
    else 
        printf("No found\n");
    rewind(stdin);
}

void delete_inf(Storage* array, int i, int* size) {
    for (i; i < *size - 1; ++i) 
        array[i] = array[i + 1];
    (*size)--;
    if (*size == 0)
        return;
    if (!(array = static_cast<Storage*>(realloc(array, *size * sizeof(Storage))))) {
        printf("memory reallocation error");
        exit(0);
    }
}
//----------------------------------------------------------------------------- notfull search--------------------------------------------
 int (*not_full_cmp_array[])(Storage a, Storage b) = {
     not_full_company_cmp
 };

 void not_full_search(Storage* array, int size) {
     int choice;
     Storage find;
     system("CLS");
         printf("1 - company\n");
         printf("-1 - exit\n");
         printf("choice - ");
         rewind(stdin);
         while (!scanf_s("%d", &choice) || ((choice < 0 || choice > 1) && choice != -1)) {
             printf("Wrong choice \n");
             rewind(stdin);
         }
     if (choice == -1)
         return;
     input_func_array[choice - 1](&find);
     for (int i = 0; i < size; ++i) {
         if (not_full_cmp_array[choice - 1](array[i], find) != NULL) {
             printf("%d. ", i);
             output_inf(&array[i],choice);
         }
     }
     rewind(stdin);
     _getch();
 }