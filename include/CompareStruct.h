#ifndef COMPARE_STRUCT_H_
#define COMPARE_STRUCT_H_

#include <stddef.h>

typedef struct 
{
    char* line;
    size_t size;
} Comparison;

typedef struct
{
    Comparison* rows;
    size_t size;
    size_t differencesCount;
} FilesComparison;

FilesComparison* initFilesComparison(size_t size);
void initDiffIndexes(Comparison* comparison, size_t size);
void deinitFilesComaprison(FilesComparison* comparisons);

#endif // COMPARE_STRUCT_H_