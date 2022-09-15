#include "CompareStruct.h"
#include "Messages.h"
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

void addDiffRowTOComparisons(FilesComparison* comparisons, char* diffRow, num_v rowIndex)
{
    if((comparisons->rowsCapacity - CAPACITY_COMPARE_VALUE) == comparisons->rowsSize)
    {
        resizeComparisonsRows(comparisons);
    }

    comparisons->rows[comparisons->rowsSize++] = strdup(diffRow);
    addRowIndexToIndexes(comparisons, rowIndex);
}

void addRowIndexToIndexes(FilesComparison* comparisons, num_v rowIndex)
{
    if((comparisons->indexesCapacity - CAPACITY_COMPARE_VALUE) == comparisons->indexesSize)
    {
        resizeComparisonsIndexes(comparisons);
    }

    comparisons->indexes[comparisons->indexesSize++] = rowIndex;
}

void resizeComparisonsIndexes(FilesComparison* comparisons)
{
    comparisons->indexesCapacity *= CAPACITY_MULTIPLIER;

    num_v* resizedIndexes = realloc(comparisons->indexes, sizeof(num_v) * comparisons->indexesCapacity);

    if (resizedIndexes == NULL)
    {
        printResizingError("Resize comparison indexes");
        return;
    }
    
    comparisons->indexes = resizedIndexes;
}

void resizeComparisonsRows(FilesComparison* comparisons)
{
    comparisons->rowsCapacity *= CAPACITY_MULTIPLIER;

    char** resizedRows = realloc(comparisons->rows, sizeof(char*) * comparisons->rowsCapacity);

    if (resizedRows == NULL)
    {
        printResizingError("Resize comparison rows");
        return;
    }

    comparisons->rows = resizedRows;
}

void deinitFileComparison(FilesComparison* comparison)
{
    for (num_v i = 0; i < comparison->rowsSize; i++)
    {
        free(comparison->rows[i]);
    }
    
    free(comparison->rows);
    free(comparison->indexes);
}