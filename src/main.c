#include "FileHandler.h"
#include "OutputResult.h"
#include "ContentStruct.h"
#include "CompareStruct.h"
#include "CompareFiles.h"
#include "Defines.h"
#include "Messages.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != ARGS_COUNT)
    {
        printArgumentError();
        return EXIT_FAILURE;
    }

    FileContent leftFile;
    if (!readFile(&leftFile, argv[1]))
    {
        printFileError(argv[1]);
        deinitFileContent(&leftFile);
        return EXIT_FAILURE;
    }

    FileContent rightFile;
    if (!readFile(&rightFile, argv[2]))
    {
        printFileError(argv[2]);
        deinitFileContent(&leftFile);
        deinitFileContent(&rightFile);
        return EXIT_FAILURE;
    }

    FilesComparison comparisons;
    compareFiles(&leftFile, &rightFile, &comparisons);
    printResult(&leftFile, &rightFile, &comparisons);

    deinitFileContent(&leftFile);
    deinitFileContent(&rightFile);
    deinitFileComparison(&comparisons);

    return EXIT_SUCCESS;
}
