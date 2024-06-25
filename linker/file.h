#ifndef _RVLD_FILE_H
#define _RVLD_FILE_H

#include <stdint.h>

struct File {
    char* name;
    char* contents;
    uint64_t contents_len;   //由于有'\0'，添加这个
};

#endif // _RVLD_FILE_H
