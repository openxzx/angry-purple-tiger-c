#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "md5.h"
#include "words.h"

#define MD5_HASH_SIZE               16
#define COMPRESS_SEGMENT_SIZE       5

uint8_t compress(uint8_t *buf, uint8_t size)
{
    int i = 0;

    uint8_t ret = buf[0];
    for (i = 1; i < size; i++)
        ret ^= buf[i];

    return ret;
}

void print_animals_name(uint8_t *p)
{
    uint8_t adjectives_buf[COMPRESS_SEGMENT_SIZE] = {0};
    uint8_t colors_buf[COMPRESS_SEGMENT_SIZE] = {0};
    uint8_t animals_buf[COMPRESS_SEGMENT_SIZE + 1] = {0};
    uint8_t adjectives_idx = 0;
    uint8_t colors_idx = 0;
    uint8_t animals_idx = 0;

    memcpy(adjectives_buf, p, sizeof(adjectives_buf));
    memcpy(colors_buf, p + sizeof(adjectives_buf), sizeof(colors_buf));
    memcpy(animals_buf, p + sizeof(adjectives_buf) + sizeof(colors_buf), sizeof(animals_buf));

    adjectives_idx = compress(adjectives_buf, sizeof(adjectives_buf));
    colors_idx = compress(colors_buf, sizeof(colors_buf));
    animals_idx = compress(animals_buf, sizeof(animals_buf));

    printf("Animal Name: ");
    printf("%s-%s-%s\n", adjectives[adjectives_idx], colors[colors_idx], animals[animals_idx]);
}

int main(int argc, char *argv[])
{
    int i = 0;
    uint8_t ret[MD5_HASH_SIZE];

    if (argc > 1) {
        for (i = 1; i < argc; i++) {
            md5String(argv[i], ret);
            print_animals_name(ret);
        }
    } else {
        printf("Please input address string.\n");
    }

    return 0;
}
