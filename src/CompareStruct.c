#include "CompareStruct.h"
#include "Messages.h"
#include "Defines.h"
#include <stdlib.h>
#include <string.h>

void initFilesComparison(FilesComparison* comparison)
{
    comparison->rows = malloc(sizeof(char*) * COMPARISON_INIT_CAPACITY);
    comparison->indexesSize = SIZE_INIT_VALUE;
    comparison->rowsSize = SIZE_INIT_VALUE;
    comparison->indexes = malloc(sizeof(size_t) * COMPARISON_INIT_CAPACITY);
    comparison->rowsCapacity = COMPARISON_INIT_CAPACITY;
    comparison->indexesCapacity = COMPARISON_INIT_CAPACITY;
}

void initDiffRow(DiffRow* diffRow)
{
    diffRow->row = malloc(DIFF_ROW_CAPACITY);
    diffRow->capacity = DIFF_ROW_CAPACITY;
    diffRow->size = SIZE_INIT_VALUE;
}

void addSymbolToDiffRol(DiffRow* diffRow, char symbol)
{
    if ((diffRow->capacity - CAPACITY_COMPARE_VALUE) == diffRow->size)
    {
        resizeDiffRow(diffRow);
    }
    
    diffRow->row[diffRow->size++] = symbol;
}

void addDiffRowTOComparisons(FilesComparison* comparisons, char* diffRow, size_t rowIndex)
{
    if((comparisons->rowsCapacity - CAPACITY_COMPARE_VALUE) == comparisons->rowsSize)
    {
        resizeComparisonsRows(comparisons);
    }

    comparisons->rows[comparisons->rowsSize++] = strdup(diffRow);
    comparisons->indexes[comparisons->indexesSize++] = rowIndex;
}

void addRowIndexToIndexes(FilesComparison* comparisons, size_t rowIndex)
{
    if((comparisons->indexesCapacity - CAPACITY_COMPARE_VALUE) == comparisons->indexesSize)
    {
        resizeComparisonsIndexes(comparisons);
    }

    comparisons->indexes[comparisons->indexesSize++] = rowIndex;
}

void resizeComparisonsIndexes(FilesComparison* comparisons)
{
    comparisons->indexesCapacity *= INCREASE_VALUE;

    size_t* resizedIndexes = realloc(comparisons->indexes, sizeof(size_t) * comparisons->indexesCapacity);

    if (resizedIndexes == NULL)
    {
        printResizingError("Resize comparison indexes");
        return;
    }
    
    comparisons->indexes = resizedIndexes;
}

void resizeComparisonsRows(FilesComparison* comparisons)
{
    comparisons->rowsCapacity *= INCREASE_VALUE;

    char** resizedRows = realloc(comparisons->rows, sizeof(char*) * comparisons->rowsCapacity);

    if (resizedRows == NULL)
    {
        printResizingError("Resize comparison rows");
        return;
    }

    comparisons->rows = resizedRows;
}

void resizeDiffRow(DiffRow* diffRow)
{
    diffRow->capacity *= INCREASE_VALUE;

    char* resizedDiffRow = realloc(diffRow->row, diffRow->capacity);

    if (resizedDiffRow == NULL)
    {
        printResizingError("Resize diffRow");
        return;
    }
    
    diffRow->row = resizedDiffRow;
}

void deinitDiffRow(DiffRow* diffRow)
{
    free(diffRow->row);
}

void deinitFileComparison(FilesComparison* comparison)
{
    for (size_t i = 0; i < comparison->rowsSize; i++)
    {
        free(comparison->rows[i]);
    }
    
    free(comparison->rows);
    free(comparison->indexes);
}