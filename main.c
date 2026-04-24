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
    uint8_t number_to_load = 0;
    for (size_t j = 0; j < 8; j++) {
        //printf("%d ", array.array[i*8 + j]);
        printf("%d", array.array[j] ? 1 : 0);
        
    }
    printf("\n\n");
    print_binary(number_to_load);
    return 0;
}

uint8_t calculate_from_8boolean_values_to_one_bite(uint8_t array[]){
    uint8_t one_bite_value = 0;
    uint8_t power_of_two = 1;
    for(uint8_t i = 7; i >= 0; i--){
        one_bite_value += power_of_two * (array[i] ? 1 : 0);
        power_of_two *= 2;
    }
    return one_bite_value;
}

int main(){
    array_of_pixels array;
    uint8_t array2[] = {0, 255, 255, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255};
    array.array = array2;
    array.length = sizeof(array2)/8;
    write_pixels(array, "test.obi");
    return 0;
}