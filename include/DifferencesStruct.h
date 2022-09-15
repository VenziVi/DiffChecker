#ifndef DIFFERENCES_STRUCT_H_
#define DIFFERENCES_STRUCT_H_

#include "Defines.h"
#include <stdbool.h>

typedef struct
{
    char* row;
    num_v size;
    num_v capacity;
    bool isDifferent;
} DiffRow;

void initDiffRow(DiffRow* diffRow);
void addSymbolToDiffRol(DiffRow* diffRow, char symbol);
void resetDiffRow(DiffRow* diffRow);
void resizeDiffRow(DiffRow* diffRow);
void deinitDiffRow(DiffRow* diffRow);

#endif // DIFFERENCES_STRUCT_H_