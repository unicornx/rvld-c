#ifndef _RVLD_UTIL_H
#define _RVLD_UTIL_H

#include <stdbool.h>
#include <stdio.h>

void Fatal(const char* format, ...);
void Assert(bool condition);
void Read(void* out, const void* data, size_t size);

#endif // _UTIL_H
