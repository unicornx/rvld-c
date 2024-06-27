#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

void Fatal(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    printf("fatal: ");
    vprintf(format, args);
    printf("\n");

    va_end(args);

    exit(1);
}

void Assert(bool condition)
{
    if (!condition)
        Fatal("assert failed");
}

void Read(void* out, const void* data, size_t size)
{
    // Assuming little-endian format
    memcpy(out, data, size);
}
