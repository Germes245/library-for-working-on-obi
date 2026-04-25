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

uint8_t calculate_from_8boolean_values_to_one_bite(uint8_t array[]){
    uint8_t one_bite_value = 0;
    uint8_t power_of_two = 1;
    for(uint8_t i = 7; i > 0; i--){
        one_bite_value += power_of_two * (array[i] ? 1 : 0);
        power_of_two *= 2;
    }
    one_bite_value += power_of_two * (array[0] ? 1 : 0);
    return one_bite_value;
}

uint8_t write_pixels(array_of_pixels array, char* name_of_file, uint32_t width){//, char* name_of_file
    FILE *file = fopen(name_of_file, "wb");
    width /= 8;
    fwrite(&width, sizeof(uint32_t), 1, file);
    array.length -= array.length % 8;
    for(size_t i = 0; i < array.length; i+=8){
        uint8_t bite_from_8boolean_values = calculate_from_8boolean_values_to_one_bite(array.array + i);
        fwrite(&bite_from_8boolean_values, 1, 1, file);
    }
    fclose(file);
    return 0;
}

int main(){
    array_of_pixels array;
    uint8_t array2[] = {1, 255, 255, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0};
    array.array = array2;
    array.length = sizeof(array2);
    printf("%b\n", write_pixels(array, "test.obi", 8));
    return 0;
}