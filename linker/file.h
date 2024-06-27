#ifndef _RVLD_FILE_H
#define _RVLD_FILE_H

#include <stdint.h>

struct File {
    char* name;
    char* contents;
    uint64_t contents_len;
};

struct File *MustNewFile(const char* filename);

#endif // _RVLD_FILE_H
