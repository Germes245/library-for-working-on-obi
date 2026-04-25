#include <stdint.h>
#include <stdio.h>

typedef struct{
    uint32_t length;
    uint8_t *array;
} array_of_pixels;

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