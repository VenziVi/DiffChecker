#include "OutputResult.h"
#include <stdio.h>

void printResult(FileContent* leftFile, FileContent* rightFile, FilesComparison* comparisons)
{
    if (comparisons->indexesSize == 0)
    {
        printf("Files are identical.\n");
    }
    else
    {
        for (size_t i = 0; i < comparisons->indexesSize; i++)
        {
            size_t index = comparisons->indexes[i];

            if (leftFile->size > index)
            {
                printf("Left  %.2zu: %s\n", index + 1, leftFile->rows[index].line);
            }
            
            if (rightFile->size > index)
            {
                printf("Right %.2zu: %s\n", index + 1, rightFile->rows[index].line);
            }

            if (comparisons->rowsSize > i)
            {
                printf("Diff  %.2zu: %s\n", index + 1, comparisons->rows[i]);
            }
        }
    }
}