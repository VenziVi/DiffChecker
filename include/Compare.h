#ifndef _COMPARE_H
#define _COMPARE_H

#include "FileHandler.h"

typedef struct 
{
    size_t row;
    char *leftLine;
    char *rightLine;
    size_t *diffIndexes;
    size_t diffIndexesCount;

} comparison;

comparison* compareContents(fileContent *leftFile, fileContent *rightFile, size_t *resultSize);
void deinitComparisonResult(comparison *comparesonResult, size_t size);

#endif // _COMPARE_H
