#include "FileHandler.h"
#include "ContentStruct.h"
#include "CompareStruct.h"
#include "CompareFiles.h"
#include "Messages.h"
#include <stdio.h>
#include <stdlib.h>

void printResult(FileContent* leftFile, FileContent* rightFile, FilesComparison* comparisons);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printArgumentError();
        return EXIT_FAILURE;
    }
    
    FileContent* leftFile = initFileContent();

    if (!readFile(leftFile, argv[1]))
    {
        printFileError(argv[1]);
        return EXIT_FAILURE;
    }

    FileContent* rightFile = initFileContent();;

    if (!readFile(rightFile, argv[2]))
    {
        printFileError(argv[2]);
        return EXIT_FAILURE;
    }

    FilesComparison* comparisons = compareFiles(leftFile, rightFile);

    printResult(leftFile, rightFile, comparisons);

    deinitFileContent(leftFile);
    deinitFileContent(rightFile);
    deinitFilesComaprison(comparisons);

    return EXIT_SUCCESS;
}

void printResult(FileContent* leftFile, FileContent* rightFile, FilesComparison* comparisons)
{
    if (comparisons->differencesCount == 0)
    {
        printf("Files are identicle.\n");
    }
    else
    {
        for (size_t i = 0; i < comparisons->size; i++)
        {
            if (comparisons->rows[i].size > 0)
            {
                if (leftFile->size > i)
                {
                    printf("Left  %.2zu: %s\n", i + 1, leftFile->rows[i].line);
                }
                if (rightFile->size > i)
                {
                    printf("Right %.2zu: %s\n", i + 1, rightFile->rows[i].line);
                }

                printf("Diff  %.2zu: %s\n", i + 1, comparisons->rows[i].line);
            }
        }
    }
}