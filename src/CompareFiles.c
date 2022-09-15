#include "DifferencesStruct.h"
#include "CompareStruct.h"
#include "CompareFiles.h"
#include <stdbool.h>

static void completeLine(Line* line, DiffRow* diffRow, num_v index)
{
    while (line->line[index] != END_OF_STRING)
    {
        addSymbolToDiffRol(diffRow, DIFFERENCE_SYMBOL);
        index++;
    }
}

static void compareLines(Line* leftLine, Line* rightLine, DiffRow* diffRow)
{
    num_v index = INIT_ZERO;

    while (leftLine->line[index] != END_OF_STRING && rightLine->line[index] != END_OF_STRING)
    {
        if (leftLine->line[index] != rightLine->line[index])
        {
            addSymbolToDiffRol(diffRow, DIFFERENCE_SYMBOL);
        }
        else
        {
            addSymbolToDiffRol(diffRow, WHITESPACE_SYMBOL);
        }

        index++;
    }

    completeLine(leftLine, diffRow, index);
    completeLine(rightLine, diffRow, index);
    addSymbolToDiffRol(diffRow, END_OF_STRING);
}

static void oneSideComparison(FileContent* file, num_v rowIndex, FilesComparison* comparison)
{
    while (file->size > rowIndex)
    {
        addRowIndexToIndexes(comparison, rowIndex);
        rowIndex++;
    }
}

void compareFiles(FileContent* leftFile, FileContent* rightFile, FilesComparison* comparisons)
{
    initFilesComparison(comparisons);
    DiffRow diffRow;
    initDiffRow(&diffRow);
    num_v rowIndex = INIT_ZERO;

    while (leftFile->size > rowIndex && rightFile->size > rowIndex)
    {
        compareLines(&leftFile->rows[rowIndex], &rightFile->rows[rowIndex], &diffRow);
        
        if (diffRow.isDifferent)
        {
            addDiffRowTOComparisons(comparisons, diffRow.row, rowIndex);
        }
        
        resetDiffRow(&diffRow);
        rowIndex++;
    }

    oneSideComparison(leftFile, rowIndex, comparisons);
    oneSideComparison(rightFile, rowIndex, comparisons);

    deinitDiffRow(&diffRow);
}
