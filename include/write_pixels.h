#include <stdint.h>

typedef struct{
    uint32_t length;
    uint8_t *array;
} array_of_pixels;

uint8_t calculate_from_8boolean_values_to_one_bite(uint8_t array[]);
uint8_t write_pixels(array_of_pixels array, char* name_of_file, uint32_t width);