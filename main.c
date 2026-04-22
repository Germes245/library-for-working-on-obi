#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

int main(){
    FILE *file = fopen("test.bin", "rb");
    uint32_t size;
    fread(&size, sizeof(uint32_t), 1, file);
    //size /= 8;
    uint8_t buffer[size];
    //printf("%d\n", size);
    size_t size_for_reading;
    while ((size_for_reading = fread(buffer, size, 1, file))!=0) {
        for(size_t i = 0; i < size; i++){
            //printf("%d ", buffer[i]);
        }
        putchar('\n');
    }
    fclose(file);
    return 0;
}