#include <stdlib.h>
#include <string.h>

#include "Compare.h"
#include "FileHandler.h"

static void compareLines(char *smallestLine, char *biggestLIne, size_t *diffCount, size_t *diffIndexes)
{
    size_t index = 0;

    while (smallestLine[index] != '\0')
    {
        if (biggestLIne[index] != smallestLine[index])
        {
            diffIndexes[(*diffCount)++] = index;
        }
        index++;
    }

    while (biggestLIne[index] != '\0')
    {
        diffIndexes[(*diffCount)++] = index;
        index++;
    }
}

static size_t* findDifferences(char *leftLine, char *rightLine, size_t *diffCount)
{
    size_t leftLen = strlen(leftLine);
    size_t rightLen = strlen(rightLine);
    size_t diffCapacity = (leftLen > rightLen) ? leftLen : rightLen;
    size_t *diffIndexes = malloc(sizeof(size_t) * diffCapacity);

    if (leftLen > rightLen)
    {
        compareLines(rightLine, leftLine, diffCount, diffIndexes);
    }
    else
    {
        compareLines(leftLine, rightLine, diffCount, diffIndexes);
    }
    
    return diffIndexes;
}

static comparison setComparisonResult(fileContent *leftFile, fileContent *rightFile, size_t index, size_t *diffIndexes, size_t diffCounter)
{
    comparison newResult = {0};

    newResult.leftLine = strdup(leftFile->lines[index]);
    newResult.rightLine = strdup(rightFile->lines[index]);
    newResult.diffIndexes = diffIndexes;
    newResult.diffIndexesCount = diffCounter;
    newResult.row = index + 1;

    return newResult;
}

static comparison oneSideComparisonResult(fileContent *file, size_t index, char fileSide)
{
    comparison newResult = {0};

    if (fileSide == 'L')
    {
        newResult.leftLine = strdup(file->lines[index]);
        newResult.rightLine = NULL;
    }
    else if (fileSide == 'R')
    {
        newResult.leftLine = NULL;
        newResult.rightLine = strdup(file->lines[index]);
    }
    
    newResult.diffIndexes = NULL;
    newResult.diffIndexesCount = 0;
    newResult.row = index + 1;

    return newResult;
}

static void checkComparisonResultSize(comparison **compareResult, size_t *resultArrayCapacity, size_t resultSize)
{
    if ((*resultArrayCapacity) == resultSize)
    {
        (*resultArrayCapacity) *= 2;
        *compareResult = realloc(*compareResult, sizeof(comparison) * (*resultArrayCapacity));
    }
}

comparison* compareContents(fileContent *leftFile, fileContent *rightFile, size_t *resultSize)
{
    size_t *diffIndexes = NULL;
    size_t diffIndexesCount = 0;
    size_t resultArrayCapacity = 5;
    char fileSide = 0;
    size_t rowIndex = 0;
    comparison *compareResult = malloc(sizeof(comparison) * resultArrayCapacity);

    while (leftFile->numberOfRows > rowIndex && rightFile->numberOfRows > rowIndex)    
    { 
        checkComparisonResultSize(&compareResult, &resultArrayCapacity, *resultSize);

        diffIndexes = findDifferences(leftFile->lines[rowIndex], rightFile->lines[rowIndex], &diffIndexesCount);

        if (diffIndexesCount > 0)
        {
            compareResult[(*resultSize)++] = setComparisonResult(leftFile, rightFile, rowIndex, diffIndexes, diffIndexesCount);
        }
        else
        {
            free(diffIndexes);
        }

        rowIndex++;
        diffIndexesCount = 0;
        diffIndexes = NULL;
    }

    fileSide = 'L';
    while (leftFile->numberOfRows > rowIndex)
    {
        checkComparisonResultSize(&compareResult, &resultArrayCapacity, *resultSize);

        compareResult[(*resultSize)++] = oneSideComparisonResult(leftFile, rowIndex, fileSide);
        rowIndex++;
    }
 
    fileSide = 'R';
    while (rightFile->numberOfRows > rowIndex)
    {
        checkComparisonResultSize(&compareResult, &resultArrayCapacity, *resultSize);

        compareResult[(*resultSize)++] = oneSideComparisonResult(rightFile, rowIndex, fileSide);
        rowIndex++;
    }
    
    return compareResult;
}

void deinitComparisonResult(comparison *comparesonResult, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        free(comparesonResult[i].leftLine);
        free(comparesonResult[i].rightLine);
        free(comparesonResult[i].diffIndexes);
    }

    free(comparesonResult);
}