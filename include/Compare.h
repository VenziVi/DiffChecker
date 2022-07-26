#ifndef CODE_ACADEMY_DIFF_TOOL_COMPARE_H
#define CODE_ACADEMY_DIFF_TOOL_COMPARE_H

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

#endif // CODE_ACADEMY_DIFF_TOOL_COMPARE_H
