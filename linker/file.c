#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../utils/utils.h"
#include "file.h"

// Function to read the entire content of a file into a dynamically allocated buffer
static char* ReadFile(const char* filename, uint64_t *len)
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
    buffer = (char*)malloc(file_size);
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
    //buffer[file_size] = '\0'; // FIXME, do we need this? we have len already
    *len = file_size;

    // Close the file
    fclose(file);
    return buffer;
}

struct File *MustNewFile(const char* filename)
{
    struct File* file = (struct File*)malloc(sizeof(struct File));
    printf("file is %p\n", file);
    Assert(file);
    
    file->contents = ReadFile(filename, &file->contents_len);
    if (file->contents == NULL) {
        perror("ReadFile failed!");
        free(file);
	    return NULL;
    }
    file->name = strdup(filename);

    return file;
}
