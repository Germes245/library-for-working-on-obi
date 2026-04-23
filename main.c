#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
//#include <stdint.h>

typedef struct{
    uint32_t length;
    uint8_t *array;
} array_of_pixels;

void print_binary(uint8_t n) {
    if (n > 1)
        print_binary(n >> 1); // рекурсивный вызов для старших битов
    putchar((n & 1) ? '1' : '0');
}

uint8_t write_pixels(array_of_pixels array, char* name_of_file){
    //FILE* file = fopen(name_of_file, "wb");
    //if(file == NULL) return 1;
    //fwrite(&array.length, sizeof(uint32_t), 1, file);
    for (size_t i = 0; i < array.length; i++) {
        uint8_t number_to_load = 0;
        for (size_t j = 0; j < 8; j++) {
            //printf("%d ", array.array[i*8 + j]);
            printf("%d\n", array.array[i*8 + j] ? 1 : 0);
            //printf("number to load %b\n", number_to_load);
            print_binary(number_to_load);
            putchar('\n');
            number_to_load <<= 1;
            number_to_load += array.array[i*8 + j] ? 1 : 0;
        }
        //printf("shya\n");
        putchar('\n');
        printf("number to load ");
        print_binary(number_to_load);
        putchar('\n');
    }
    //fclose(file);
    return 0;
}

int main(){
    array_of_pixels array;
    //size_t number = 1;
    //number <<= 2;
    //printf("%d\n", number);
    uint8_t array2[] = {0, 255, 255, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255};
    array.array = array2;
    array.length = sizeof(array2)/8;
    write_pixels(array, "test.obi");
    return 0;
}