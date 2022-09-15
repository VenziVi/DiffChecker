#include "DifferencesStruct.h"
#include "Messages.h"
#include "Defines.h"
#include <stdlib.h>

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

void resizeDiffRow(DiffRow* diffRow)
{
    diffRow->capacity *= CAPACITY_MULTIPLIER;

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