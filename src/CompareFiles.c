#include "DifferencesStruct.h"
#include "CompareStruct.h"
#include "CompareFiles.h"
#include <stdbool.h>

static void completeLine(Line* line, DiffRow* diffRow, num_v index, bool* isDifferent)
{
    while (line->line[index] != END_OF_STRING)
    {
        addSymbolToDiffRol(diffRow, DIFFERENCE_SYMBOL);
        *isDifferent = true;
        index++;
    }
}

static bool compareLines(Line* leftLine, Line* rightLine, DiffRow* diffRow)
{
    bool isDifferent = false;
    num_v index = INIT_ZERO;

    while (leftLine->line[index] != END_OF_STRING && rightLine->line[index] != END_OF_STRING)
    {
        if (leftLine->line[index] != rightLine->line[index])
        {
            addSymbolToDiffRol(diffRow, DIFFERENCE_SYMBOL);
            isDifferent = true;
        }
        else
        {
            addSymbolToDiffRol(diffRow, WHITESPACE_SYMBOL);
        }

        index++;
    }

    completeLine(leftLine, diffRow, index, &isDifferent);
    completeLine(rightLine, diffRow, index, &isDifferent);

    addSymbolToDiffRol(diffRow, END_OF_STRING);
    return isDifferent;
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
        if (compareLines(&leftFile->rows[rowIndex], &rightFile->rows[rowIndex], &diffRow))
        {
            addDiffRowTOComparisons(comparisons, diffRow.row, rowIndex);
        }

        diffRow.size = INIT_ZERO;
        rowIndex++;
    }

    oneSideComparison(leftFile, rowIndex, comparisons);
    oneSideComparison(rightFile, rowIndex, comparisons);

    deinitDiffRow(&diffRow);
}
