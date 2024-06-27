#ifndef _RVLD_ELF_H
#define _RVLD_ELF_H

#include <stdint.h>

// Elf32_Ehdr Executable header type. One per ELF file.
struct Ehdr {
    uint8_t Ident[16];      //表示ELF文件的标识信息
    uint16_t  Type;         //表示 ELF 文件的类型，比如可执行文件、共享库等
    uint16_t  Machine;
    uint32_t  Version;
    uint64_t  Entry ;       //表示程序的入口地址
    uint64_t  PhOff ;       //表示程序头表（Program Header Table）的偏移量
    uint64_t  ShOff ;       //表示节表（Section Header Table）的偏移量
    uint32_t  Flags ;       //表示 ELF 文件的标志信息
    uint16_t  EhSize;       //表示 ELF 文件头部的大小  sizeof(Elf32_Ehdr);
    uint16_t  PhEntSize ;   //表示program header table中每个表项的大小，每一个表项描述一个Segment信息
    uint16_t  PhNum ;       //表示program header table中表项的数量
    uint16_t  ShEntSize;    //Section header table中每个表项的大小sizeof(Elf32_Shdr)
    uint16_t  ShNum ;       //num sections
    uint16_t  ShStrndx ;    //表示节表中字符串表的索引，第多少个表项描述的是字符串表......
};

struct Shdr {
    uint32_t Name;          //section名称，是在字符串表节区的索引
    uint32_t Type;
    uint64_t Flags;         //描述杂项属性
    uint64_t Addr;          //如果该section将出现在进程的内存映像中，则该成员给出该section的第一个字节应该驻留的地址。否则，该成员的值为0
    uint64_t Offset;        //该节在elf文件中偏移量
    uint64_t Size;          //该节的大小
    uint32_t Link;          //holds a section header table index link,表示当前节依赖于对应的节
    uint32_t Info;          //该节的附加信息， 如符号表节中存储的第一个global的信息
    uint64_t AddrAlign;     //该节的对齐方式
    uint64_t EntSize;       //某些节区中包含固定大小的项目，如符号表节中每个符号的大小,没有则是0
};

#endif // _RVLD_ELF_H