#ifndef _RVLD_INPUTFILE_H
#define _RVLD_INPUTFILE_H

#include <stdint.h>
#include "elf.h"

// InputFile 包含obj file或so file, 作为一个基类
// 用于解析elf文件后存储信息用
struct InputFile {
    struct File *file;

    // ElfSyms 是一个 Sym 结构体的数组
    struct Shdr *ElfSections;
    int64_t sectionNum;
};

struct InputFile* NewInputFile(struct File* file);

#endif // _RVLD_INPUTFILE_H