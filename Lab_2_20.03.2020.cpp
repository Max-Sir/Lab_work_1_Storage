
// Lab_2_20.03.2020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"Lab_2_20.03.2020.h"
#include <iostream>

int main() {
    int size = 0;
    Storage* array;
    while (1) {
        switch (menu()) {
        case 1: array = input_array(&size); break;
        case 2: output_array(array, size); break;
        case 3: edit_inf(array, size); break;
        case 4: find_inf(array, size); break;
        case 5: sort_array(array, size); break;
        case 6: delete_array(array, &size); break;
            // case 7 : notfull_search(array, size); break;
        case -1: return 0; break;
        default: printf("Wrong choice\n"); break;
        }
    }
    free(array);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

int menu() {
    int choice;

    do {
        system("CLS");
        printf("1 - input inf array\n");
        printf("2 - output inf array\n");
        printf("3 - edit inf\n");
        printf("4 - find inf\n");
        printf("5 - sort inf\n");
        printf("6 - delete inf\n");
        //printf("7 - partial search\n");
        printf("-1 - quit\n");
        printf("choose  - ");
        rewind(stdin);
    } while(!scanf("%d", &choice) || ((choice < 1 || choice > 6) && choice != -1));

    return choice;
}



int is_empty(int size) {
    if (size == 0) {
        printf("Array is empty\n");
        rewind(stdin);
        getchar();
        return 1;
    }
    return 0;
}

int fl_type_media(int choice) {
    int type_media;
    switch (choice) {
        case 1 : case 2 : case 3 : case 4 :
            type_media = FL_NO_MATTER;
            break;
        case 5 : case 6 : case 7 :
            type_media = HDD;
            break;
        case 8 : case 9 :
            type_media = SSD;
            break;
        case 10 : case 11 : case 12 : case 13 :
            type_media = DISK;
            break;
         case 14 : case 15 : case 16 :
            type_media = USB_FLASH;
            break;
        case -1 :
            type_media = 0;
            break;
    }
    return type_media;
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
        } while (!scanf("%d", &choice) || choice < 0 || choice > 1);
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
    if (!(array = (Storage*)realloc(array, (*size + 1) * sizeof(Storage)))) {
        printf("memory reallocation error");
        exit(0);
    }

    for (int i = 0; i <= 3; ++i)
        input_func_array[i](&array[*size]);
    switch (array[*size].type) {
        case HDD :
            for (int i = 4; i <= 6; ++i)
                input_func_array[i](&array[*size]);
            break;
        case SSD :
            for (int i = 7; i <= 8; ++i) 
                input_func_array[i](&array[*size]);
            break;
        case DISK :
            for (int i = 9; i <= 12; ++i)
                input_func_array[i](&array[*size]);   
            break;
        case USB_FLASH :
            for (int i = 13; i <= 15; ++i)
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
    }while (!scanf("%d", &i) || i >= size || i < -1);
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
    getchar();
} 

void table() {
    printf("5 - hdd interface\n");
    printf("6 - hdd average seek time(ms)\n");
    printf("7 - hdd spindle speed(rpm)\n");
    printf("8 - ssd interface\n");
    printf("9 - input output speed(Mb/s)\n");
    printf("10 - disk type\n");
    printf("11 - disk record type\n");
    printf("12 - disk data rate(Mb/s)\n");
    printf("13 - disk access time(ms)\n");           
    printf("14 - usb standart\n");
    printf("15 - usb read speed(Mb/s)\n");
    printf("16 - usb write speed(Mb/s)\n");
    printf("\n");
    printf("ind ");
    printf("Name    ");
    printf("Author    ");
    printf("type ");
    printf("cap\t");
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
    printf("%-8s ", inf[i].name);
    printf("%-8s ", inf[i].author);
    
    switch (inf[i].type) {
        case HDD : printf("HDD "); break;
        case SSD : printf("SSD "); break;
        case DISK : printf("disk "); break;
        case USB_FLASH : printf("usb "); break;
    }
    printf("%.2f\t", inf[i].capacity);

    switch (inf[i].type) {
        case DISK :
            switch (inf[i].disk.type) {
                case CD: printf("CD\t"); break;
                case DVD: printf("DVD\t"); break;
            }
            switch (inf[i].disk.record_type) {
                case R: printf("R\t"); break;
                case RW: printf("RW\t"); break;        
                case ROM: printf("ROM\t"); break;
            }
            printf("%d\t", inf[i].disk.data_rate);
            printf("%d\t", inf[i].disk.access_time);
            printf("--\t--\t--\t--\t--\t--\t--\t--\t");           
            break;
        case HDD :
            printf("--\t--\t--\t--\t");
            switch (inf[i].hdd.interface_hdd) {
                case IDE: printf("IDE\t"); break;
                case SAS:  printf("SAS\t"); break;
                case SATA_HDD: printf("SATA\t"); break;
                case SCSI: printf("SCSI\t"); break;
            }
            printf("%.2f\t", inf[i].hdd.average_seek_time);
            printf("%d\t", inf[i].hdd.spindle_speed);
            printf("--\t--\t--\t--\t--\t");
            break;
        case SSD :
            printf("--\t--\t--\t--\t--\t--\t--\t");
            switch (inf[i].ssd.interface_ssd) {
                case M_2: printf("M_2\t"); break;
                case PCIE:  printf("PCIE\t"); break;
                case SATA_SSD : printf("SATA\t"); break;
            }
            printf("%d\t", inf[i].ssd.input_output);
            printf("--\t--\t--\t");
            break;
        case USB_FLASH :
            printf("--\t--\t--\t--\t--\t--\t--\t--\t--\t");
            printf("%.1f\t", inf[i].usb_flash.usb_standart);
            printf("%d\t", inf[i].usb_flash.read_speed);
            printf("%d\t", inf[i].usb_flash.write_speed);
            break;
    }   
    printf("\n");
}

//-----------------EDIT--------------

void edit_inf(Storage* array, int size) {
    int choice;
    int i;
    if (is_empty(size))
        return;
    
    printf("Choose index of array to edit\n");
    rewind(stdin);
    while (!scanf("%d", &i) || i < 0 || i >= size) {
        printf("Wrong choice\n");
        printf("Try again - ");
        rewind(stdin);
    }
    while (1) {
        choice = choose_field_to_edit(&array[i]);
        system("cls");
        switch (choice) {
            case 1 : case 2 : case 3 : case 4 :
                input_func_array[choice - 1](&array[i]); 
                break;
            case 5 : case 6 : case 7 : case 8 :
                media_specification_edit(&array[i], choice);
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
        printf("1 - name\n");
        printf("2 - author\n");
        printf("3 - media type\n");
        printf("4 - capacity\n");
        switch (inf->type) {
            case HDD :
                printf("5 - hdd interface\n");
                printf("6 - hdd average seek time(ms)\n");
                printf("7 - hdd spindle speed(rpm)\n");
                break;
            case SSD :
                printf("5 - ssd interface\n");
                printf("6 - input output speed(Mb/s)\n");
                break;
            case DISK :
                printf("5 - disk type\n");
                printf("6 - disk record type\n");
                printf("7 - disk data rate(Mb/s)\n");
                printf("8 - disk access time(ms)\n");           
                break;
            case USB_FLASH :
                printf("5 - usb standart\n");
                printf("6 - usb read speed(Mb/s)\n");
                printf("7 - usb write speed(Mb/s)\n");
                break;
        }
        printf("-1 - quit\n");
        printf("choice - ");
        rewind(stdin);
        if (scanf("%d", &choice) && ((choice >= 1 && choice <= 6) 
        || (inf->type == HDD && choice == 7)
        || (inf->type == DISK && (choice == 7 || choice == 8))
        || (inf->type == USB_FLASH && choice == 7)
        || choice == -1))
            break;
    }
   return choice;
}

void media_specification_edit(Storage* inf, int choice) {
    switch (inf->type) {
        case HDD :
            input_func_array[choice - 1](inf);
            break;
        case SSD :
            input_func_array[choice + 2](inf);
            break;
        case DISK :
            input_func_array[choice + 4](inf);
            break;
        case USB_FLASH :
            input_func_array[choice + 8](inf);
            break;
    }
}

//-----------SEARCH-----------------------------------

void find_inf(Storage* array, int size) {
    int fl = 0;
    int choice;
    int type_media;
    Storage find;
    if (is_empty(size))
        return;
    
    choice = choose_find_inf(array);
    type_media = fl_type_media(choice);
    if (!type_media)
        return;

    input_func_array[choice - 1](&find);

    if (choice == 1 || choice == 2) {
        choice += 16;
    }
    for (int i = 0; i < size; ++i) {
        if ((type_media == FL_NO_MATTER || array[i].type == type_media)
        && cmp_array[choice - 1](array[i], find) == 0) {
            output_inf(array, i);
            fl = 1;
        }
    }
    if (!fl)
        printf("No found\n");
    rewind(stdin);
    getchar();
}

int choose_find_inf(Storage* array) {
    int choice;
    while (1) {
        system("cls");
        printf("1 - name\n");
        printf("2 - author\n");
        printf("3 - media type\n");
        printf("4 - capacity\n");
        printf("5 - hdd interface\n");
        printf("6 - hdd average seek time(ms)\n");
        printf("7 - hdd spindle speed(rpm)\n");
        printf("8 - ssd interface\n");
        printf("9 - input output speed(Mb/s)\n");
        printf("10 - disk type\n");
        printf("11 - disk record type\n");
        printf("12 - disk data rate(Mb/s)\n");
        printf("13 - disk access time(ms)\n");           
        printf("14 - usb standart\n");
        printf("15 - usb read speed(Mb/s)\n");
        printf("16 - usb write speed(Mb/s)\n");
        printf("-1 - quit\n");
        printf("choice - ");
        rewind(stdin);
        if (scanf("%d", &choice) && (choice >= 1 && choice <= 16 || choice == -1))
            break;
    }
   return choice;
}    

//------------------SORT---------------------

void sort_array(Storage* array, int size) {
    int choice;
    int type_media;
    int fl;
    int swap_index;
    int swap_fl = 0;
    if (is_empty(size))
        return;
    
    choice = choose_find_inf(array);
    type_media = fl_type_media(choice);
    if (!type_media)
        return;

    for (int i = 0; i < size - 1; ++i) {
        fl = 0;
        for (int j = 0; j < size - i; ++j) {
            if ((type_media == FL_NO_MATTER || array[j].type == type_media)) {
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
    getchar();
}

void swap(Storage* array, int a, int b) {
    Storage tmpr = array[a];
    array[a] = array[b];
    array[b] = tmpr;
}

//------------DELETION------------------

void delete_array(Storage* array, int* size) {
    int choice;
    int fl = 0;
    int type_media;
    Storage find;
    if (is_empty(*size))
        return;
    
    choice = choose_find_inf(array);
    type_media = fl_type_media(choice);
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
    getchar();
}

void delete_inf(Storage* array, int i, int* size) {
    for (i; i < *size - 1; ++i) 
        array[i] = array[i + 1];
    (*size)--;
    if (*size == 0)
        return;
    if (!(array = (Storage*)realloc(array, *size * sizeof(Storage)))) {
        printf("memory reallocation error");
        exit(0);
    }
}