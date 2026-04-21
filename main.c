#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

int main(){
    FILE *file = fopen("test.bin", "rb");
    uint8_t buffer_for_read[4];
    buffer_for_read[3] = '\n';
    size_t length;
    while((length = fread(buffer_for_read, sizeof(buffer_for_read)-1, 1, file))!=0){
        write(1, buffer_for_read, sizeof(buffer_for_read));
        //putchar('\n');
    }
    fclose(file);
    return 0;
}