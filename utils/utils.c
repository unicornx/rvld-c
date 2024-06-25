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

// Function to read the entire content of a file into a dynamically allocated buffer
char* ReadFile(const char* filename,uint64_t *len)
{
    FILE* file;
    char* buffer;
    size_t file_size;

    // Open the file
    file = fopen(filename, "rb");
    if (file == NULL) {
        //perror("Error opening file");
        return NULL;
    }

    // Find the size of the file
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    // Allocate memory for the entire content
    buffer = (char*)malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    // Read the file into the buffer
    if (fread(buffer, 1, file_size, file) != file_size) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return NULL;
    }

    // Null-terminate the buffer
    buffer[file_size] = '\0'; // FIXME, do we need this? we have len already
    *len = file_size;

    // Close the file
    fclose(file);
    return buffer;
}
