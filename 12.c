#include <stdio.h>
#include <string.h>
#define SIZE 50

#pragma warning(disable : 4996)

struct resultstruct
{
    char result[SIZE];
    int count;
    int location[10];
};
void main()
{
    char s1[300] = "it was the best of times it was the worst of times it was the age of wisdom it was the age of foolishness it was the epoch of belief";  // 크기가 30인 char형 배열을 선언하고 문자열 할당
    puts(s1);
    char* context = NULL;
    char* ptr = strtok_s(s1, " ", &context);      // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환
    char* index[SIZE] = { NULL, };
    char inputstring[20];
    struct resultstruct resultStruct[SIZE] = { NULL, };
    int i = 0, num = 0, locationNum = 0;
    int cursor;
    while (ptr != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
    {
        index[i] = ptr;                                            // 자른 문자열 출력
        strcpy(resultStruct[num].result, ptr);          // 자른 문자열 저장
        num++;
        i++;
        ptr = strtok_s(NULL, " ", &context);      // 다음 문자열을 잘라서 포인터를 반환
    }
   
    printf("\n\n\n");


        for (int i = 0; i < SIZE; i++)
        {
            for (int j = i + 1; j < 30; j++)
            {
                if (strcmp(resultStruct[i].result, resultStruct[j].result) == 0)
                {
                    for (int k = j; k < sizeof(resultStruct[i].result) - 1; k++)
                    {
                        strcpy(resultStruct[k].result, resultStruct[k + 1].result);       //자른 문자열 중복 제거
                    }
                }
            }
        }
/*
        for (int r = 0; r < SIZE; r++)
        {
            printf("%s\t ", resultStruct[r].result);
        }
        */
        for (int i = 0; i < SIZE; i++)
        {
            locationNum = 0;
            for (int j = 0; j < 30; j++)
            {
                if (strcmp(resultStruct[i].result, index[j]) == 0)
                {
                    resultStruct[i].count++;
                    resultStruct[i].location[locationNum] = j + 1;
                    locationNum++;
                }
            }
        }

            printf("\n\n\n");
        /*for (int r = 0; resultStruct[r].count != NULL; r++)
        {
            printf("%d ", resultStruct[r].count);
        }*/
        printf("\n\n\n");

        for (int k = 0; resultStruct[k].count != NULL; k++)
        {
            printf("%s\t ", resultStruct[k].result);
            printf("%d    (", resultStruct[k].count);
            for (int r = 0; resultStruct[k].location[r] != NULL; r++)
            {
                printf("%d  ", resultStruct[k].location[r] - 1);
            }
            printf(")\n");
        }

        printf("Input string: ");
        gets(inputstring);

        for (int i = 0; resultStruct[i].count != NULL; i++)
        {
            if (strcmp(inputstring, resultStruct[i].result) == 0)
            {
                printf("\"%s\" (answer: %d, ", resultStruct[i].result, resultStruct[i].count );
                for (int j = 0; resultStruct[i].location[j] != NULL; j++)
                {
                    cursor = resultStruct[i].location[j];
                    if (index[cursor] != NULL)
                    {
                        printf("\"%s %s\", ", index[cursor], index[cursor + 1]);
                    }
                }
                printf(")\n");
            }
        }
   }
