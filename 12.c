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
    char s1[300] = "it was the best of times it was the worst of times it was the age of wisdom it was the age of foolishness it was the epoch of belief";  // ũ�Ⱑ 30�� char�� �迭�� �����ϰ� ���ڿ� �Ҵ�
    puts(s1);
    char* context = NULL;
    char* ptr = strtok_s(s1, " ", &context);      // " " ���� ���ڸ� �������� ���ڿ��� �ڸ�, ������ ��ȯ
    char* index[SIZE] = { NULL, };
    char inputstring[20];
    struct resultstruct resultStruct[SIZE] = { NULL, };
    int i = 0, num = 0, locationNum = 0;
    int cursor;
    while (ptr != NULL)               // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
    {
        index[i] = ptr;                                            // �ڸ� ���ڿ� ���
        strcpy(resultStruct[num].result, ptr);          // �ڸ� ���ڿ� ����
        num++;
        i++;
        ptr = strtok_s(NULL, " ", &context);      // ���� ���ڿ��� �߶� �����͸� ��ȯ
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
                        strcpy(resultStruct[k].result, resultStruct[k + 1].result);       //�ڸ� ���ڿ� �ߺ� ����
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
