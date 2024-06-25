#include <stdio.h>
#include "utils/utils.h"
#include "linker/inputfile.h"

int main (int argc, char* argv[])
{
    if (argc < 2)
        Fatal("wrong args\n");
//    for(int i = 0;i<argc;i++){
//        printf("%s\n",argv[i]);
//    }

    struct File *file = MustNewFile(argv[1]);
    Assert(file);

    struct InputFile *inputfile = NewInputFile(file);
    Assert(inputfile);

    Assert(inputfile->sectionNum == 11);

    return 0;
}