#include <stdbool.h>
#include <stdint.h>
#include <string.h>

bool CheckMagic(const char* contents, int64_t len)
{
    const unsigned char magic[] = {0x7F, 'E', 'L', 'F'};
    size_t magicSize = sizeof(magic) / sizeof(magic[0]);

    if (len < magicSize)
	    return false;

    return memcmp(contents, magic, magicSize) == 0;
}