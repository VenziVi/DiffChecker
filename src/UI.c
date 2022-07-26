#include <stdio.h>
#include "UI.h"

void displayResult(comparison *comparisonResult, size_t size)
{
    comparison printResult = {0};
    char symbol = '^';
    size_t symbolIndex = 0;
    size_t lineIndex = 0;
    size_t diffCount = 0;

    if (size > 0)
    {
        for (size_t i = 0; i < size; i++)
        {
            printResult = comparisonResult[i];
            
            if (printResult.leftLine != NULL)
            {
                printf("Left %3lu: %s\n", (unsigned long)printResult.row, printResult.leftLine);
            }

            if (printResult.leftLine != NULL && printResult.rightLine != NULL)
            {
                diffCount = printResult.diffIndexesCount;
                printf("Diff    : ");

                while (lineIndex <= printResult.diffIndexes[diffCount - 1])
                {
                    if (lineIndex == (printResult.diffIndexes[symbolIndex]))
                    {
                        printf("%c", symbol);
                        symbolIndex++;
                    }
                    else
                    {
                        printf(" ");
                    }
                    lineIndex++;
                }
                printf("\n");
            }
            
            if (printResult.rightLine != NULL)
            {
                printf("Right %2lu: %s\n", (unsigned long)printResult.row, printResult.rightLine);
            }

            symbolIndex = 0;
            lineIndex = 0;
        }
    }
    else
    {
        printf("Files are identical.\n");
    }

}
