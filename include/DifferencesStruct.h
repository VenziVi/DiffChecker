#ifndef DIFFERENCES_STRUCT_H_
#define DIFFERENCES_STRUCT_H_

#include <stddef.h>

typedef struct
{
    char* row;
    size_t size;
    size_t capacity;
} DiffRow;

void initDiffRow(DiffRow* diffRow);
void addSymbolToDiffRol(DiffRow* diffRow, char symbol);
void resizeDiffRow(DiffRow* diffRow);
void deinitDiffRow(DiffRow* diffRow);

#endif // DIFFERENCES_STRUCT_H_