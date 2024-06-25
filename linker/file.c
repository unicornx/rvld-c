#include <stdlib.h>
#include <string.h>

#include "../utils/utils.h"
#include "file.h"

struct File *MustNewFile(const char* filename)
{
    struct File* file = (struct File*)malloc(sizeof(struct File));
    Assert(file);
    
    char* contents = ReadFile(filename, &file->contents_len);
    if (contents == NULL) {
        free(file);
	    return NULL;
    }

    file->name = strdup(filename);
    file->contents = contents;

    return file;
}
