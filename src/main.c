#include <stdio.h>
#include "Compare.h"
#include "FileHandler.h"
#include "UI.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Wrong arguments count!");
        return 1;
    }

    fileContent leftFile = readFile(argv[1]);    
    fileContent rightFile = readFile(argv[2]);

    size_t compariosnResultSize = 0;
    comparison *comparesonResult = compareContents(&leftFile, &rightFile, &compariosnResultSize);
    
    displayResult(comparesonResult, compariosnResultSize);

    deinitFileContent(&leftFile);
    deinitFileContent(&rightFile);
    deinitComparisonResult(comparesonResult, compariosnResultSize);

    return 0;
}
 
