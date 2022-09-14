#include "CompareFiles.h"
#include "CompareStruct.h"
#include <stdbool.h>

static void oneSideComparison(Line* line, Comparison* comparison)
{
    size_t index = 0;
    initDiffIndexes(comparison, line->size);

    while (line->line[index] != '\0')
    {
        comparison->line[index++] = '^';
        comparison->size++;
    }

    comparison->line[index] = '\0';
}

static bool compareLines(Line* leftLine, Line* rightLine, Comparison* comparison)
{
    Line* longerLine = (leftLine->size > rightLine->size) ? leftLine : rightLine;
    Line* shorterLine = (leftLine->size <= rightLine->size) ? leftLine : rightLine;
    size_t size = longerLine->size;
    bool isdifferent = false;
    initDiffIndexes(comparison, size);
    size_t index = 0;

    while (shorterLine->line[index] != '\0')
    {
        if (shorterLine->line[index] != longerLine->line[index])
        {
            comparison->line[index++] = '^';
            comparison->size++;
            isdifferent = true;
        }
        else
        {
            comparison->line[index++] = ' ';
        }
    }

    while (longerLine->line[index] != '\0')
    {
        comparison->line[index++] = '^';
        comparison->size++;
        isdifferent = true;
    }

    comparison->line[index] = '\0';
    return isdifferent;
}

FilesComparison* compareFiles(FileContent* leftFile, FileContent* rightFile)
{
    FileContent* longerFile = (leftFile->size > rightFile->size) ? leftFile : rightFile;
    size_t size = longerFile->size;
    FilesComparison* comparison = initFilesComparison(size);
    size_t rowIndex = 0;

    while (leftFile->size > rowIndex && rightFile->size > rowIndex)
    {
        if (compareLines(&leftFile->rows[rowIndex], &rightFile->rows[rowIndex], &comparison->rows[rowIndex]))
        {
            comparison->differencesCount++;
        }
        rowIndex++;
    }
    
    while (longerFile->size > rowIndex)
    {
        oneSideComparison(&longerFile->rows[rowIndex], &comparison->rows[rowIndex]);
        rowIndex++;
        comparison->differencesCount++;
    }
    
    return comparison;

}
