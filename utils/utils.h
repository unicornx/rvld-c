#ifndef _RVLD_UTIL_H
#define _RVLD_UTIL_H

#include <stdint.h>
#include <stdbool.h>

void Fatal(const char* format, ...);
void Assert(bool condition);
void Read(void* out, const void* data, size_t size);
char* ReadFile(const char* filename, uint64_t *len);

#endif // _UTIL_H
