#include "inputfile.h"
#include "../utils/utils.h"

extern bool CheckMagic(const char* contents, int64_t len);

struct InputFile* NewInputFile(struct File* file)
{
    if (file->contents_len < sizeof(struct Ehdr))
	Fatal("file too small");

    if (!CheckMagic(file->Contents, file->contents_len))
	Fatal("not an ELF file\n");

    struct InputFile *inputFile = (struct InputFile*) malloc(sizeof(struct InputFile));
    inputFile->file = file;

    struct Ehdr *ehdr = (Ehdr*)file->contents;
    
    struct Shdr *first_shdr = (struct Shdr*)(file->Contents + ehdr->ShOff);

    uint64_t numSections = (uint64_t)ehdr->ShNum;
    if (numSections == 0)
        numSections = shdr->Size;

    inputFile->ElfSections = first_shdr;
    inputFile->sectionNum = numSections;

    return inputFile;
}