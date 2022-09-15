#ifndef COMPARE_STRUCT_H_
#define COMPARE_STRUCT_H_

#include "Defines.h"

typedef struct
{
    char** rows;
    num_v* indexes;
    num_v rowsSize;
    num_v indexesSize;
    num_v rowsCapacity;
    num_v indexesCapacity;
} FilesComparison;

void initFilesComparison(FilesComparison* comparison);
void addDiffRowTOComparisons(FilesComparison* comparisons, char* diffRow, num_v rowIndex);
void resizeComparisonsRows(FilesComparison* comparisons);
void addRowIndexToIndexes(FilesComparison* comparisons, num_v rowIndex);
void resizeComparisonsIndexes(FilesComparison* comparisons);
void deinitFileComparison(FilesComparison* comparison);

#endif // COMPARE_STRUCT_H_