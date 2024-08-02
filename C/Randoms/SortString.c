#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void swap(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int compare_strings_desc(const void *a, const void *b)
{
    const char **strA = (const char **)a;
    const char **strB = (const char **)b;
    return strcmp(*strB, *strA);
}


void sort_words(char *words[], int count)
{
    qsort(words, count, sizeof(char *), compare_strings_desc);
}

// void sort_words(char *words[], int count)
// {
//     int InnerCounter = 0, OutterCounter = 0, SortedFlag = 0; 

//     for(OutterCounter = 0; OutterCounter < count-1; ++OutterCounter)
//     {
//         for(InnerCounter = 0; InnerCounter < (count-1-OutterCounter); ++InnerCounter)
//         {
//             if(strcmp(words[InnerCounter], words[InnerCounter+1]) < 0)
//             {
//                 swap(&words[InnerCounter], &words[InnerCounter+1]);
//             }
//         }
//         if (SortedFlag)
//         {
//             break;
//         }
        
//     }
// }

#ifndef RunTests
int main()
{
    char *words[] = { "cherry", "orange", "apple" };

    sort_words(words, 3);

    for (int i = 0; i < 3; i++)
    {
        printf("%s ", words[i]);
    }
}
#endif