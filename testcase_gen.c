#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    /* iimage */
    FILE *fp = fopen("iimage.bin", "wb");
    int i, j, x;
    /* Set the number of PC */
    x = 0;
    for (i = 3; i >= 0; i--) {
        char temp = ((x >> i * 8) & 0x000000FF);
        fwrite(&temp, 1, 1, fp);
    }
    /* Set the number of word */
    x = 256;
    for (i = 3; i >= 0; i--) {
        char temp = ((x >> i * 8) & 0x000000FF);
        fwrite(&temp, 1, 1, fp);
    }
    /* LW randomly */
    srand(time(NULL));
    for (i = 0; i < 255; i++) {
        x = 0x00000023 << 26;
        int y = rand() % 128 * 4;
        x |= y;
        for (j = 3; j >= 0; j--) {
            char temp = ((x >> j * 8) & 0x000000FF);
            fwrite(&temp, 1, 1, fp);
        }
    }
    /* HALT */
    x = 0xFFFFFFFF;
    for (i = 3; i >= 0; i--) {
        char temp = ((x >> i * 8) & 0x000000FF);
        fwrite(&temp, 1, 1, fp);
    }
    fclose(fp);
    /* dimage */
    fp = fopen("dimage.bin", "wb");
    x = 0;
    for (i = 3; i >= 0; i--) {
        char temp = ((x >> i * 8) & 0x000000FF);
        fwrite(&temp, 1, 1, fp);
    }
    for (i = 3; i >= 0; i--) {
        char temp = ((x >> i * 8) & 0x000000FF);
        fwrite(&temp, 1, 1, fp);
    }
    return 0;
}