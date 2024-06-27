#include <stdlib.h>

#include "../utils/utils.h"
#include "elf.h"
#include "file.h"

#include "inputfile.h"

extern bool CheckMagic(const char* contents, int64_t len);

struct InputFile* NewInputFile(struct File* file)
{
    if (file->contents_len < sizeof(struct Ehdr))
    	Fatal("file too small");

    if (!CheckMagic(file->contents, file->contents_len))
	    Fatal("not an ELF file\n");

    struct InputFile *inputFile = (struct InputFile*) malloc(sizeof(struct InputFile));
    inputFile->file = file;

    struct Ehdr *ehdr = (struct Ehdr *)file->contents;
    
    struct Shdr *first_shdr = (struct Shdr*)(file->contents + ehdr->ShOff);

    uint64_t numSections = (uint64_t)ehdr->ShNum;
    if (numSections == 0)
        numSections = first_shdr->Size;

    inputFile->ElfSections = first_shdr;
    inputFile->sectionNum = numSections;

    return inputFile;
}