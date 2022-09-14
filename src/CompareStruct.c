#include "CompareStruct.h"
#include "Defines.h"
#include <stdlib.h>

FilesComparison* initFilesComparison(size_t size)
{
    FilesComparison* comparison = malloc(sizeof(FilesComparison));
    comparison->rows = malloc(sizeof(Comparison) * size);
    comparison->size = size;
    comparison->differencesCount = SIZE_INIT_VALUE;

    return comparison;
}

void initDiffIndexes(Comparison* comparison, size_t size)
{
    comparison->line = malloc(sizeof(size_t) * size);
    comparison->size = SIZE_INIT_VALUE;
}


void deinitFilesComaprison(FilesComparison* comparisons)
{
    for (size_t i = 0; i < comparisons->size; i++)
    {
        free(comparisons->rows[i].line);
    }

    free(comparisons->rows);
    free(comparisons);
}