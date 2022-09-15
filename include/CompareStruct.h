#ifndef COMPARE_STRUCT_H_
#define COMPARE_STRUCT_H_

#include <stddef.h>

typedef struct
{
    char* row;
    size_t size;
    size_t capacity;
} DiffRow;

typedef struct
{
    char** rows;
    size_t* indexes;
    size_t rowsSize;
    size_t indexesSize;
    size_t rowsCapacity;
    size_t indexesCapacity;
} FilesComparison;

void initFilesComparison(FilesComparison* comparison);
void initDiffRow(DiffRow* diffRow);
void addSymbolToDiffRol(DiffRow* diffRow, char symbol);
void resizeDiffRow(DiffRow* diffRow);
void addDiffRowTOComparisons(FilesComparison* comparisons, char* diffRow, size_t rowIndex);
void resizeComparisonsRows(FilesComparison* comparisons);
void addRowIndexToIndexes(FilesComparison* comparisons, size_t rowIndex);
void resizeComparisonsIndexes(FilesComparison* comparisons);
void deinitDiffRow(DiffRow* diffRow);
void deinitFileComparison(FilesComparison* comparison);

#endif // COMPARE_STRUCT_H_