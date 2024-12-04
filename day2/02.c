#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_REPORTS 1000
#define MAX_LENGHT 24
#define MAX_LEVELS 8

int getReports(char filename[], char rawReports[][MAX_LENGHT]);
void stringToInt(char rawReport[][MAX_LENGHT], int items, int report[][MAX_LEVELS], int levels[]);
void checkConditions(int report[][MAX_LEVELS], int items, int safe[], int levels[]);
int sumItems(int a[], int entries);

int main()
{
    char rawReport[MAX_REPORTS][MAX_LENGHT];
    /*Since none of the levels equals 0, i will initialize all of the values to prevent random numbers*/
    int report[MAX_REPORTS][MAX_LEVELS] = {{0}};
    int levels[MAX_REPORTS];
    int safe[MAX_REPORTS] = {0};
    int items;
    int total;

    /*New approach: get all reports as a whole, then separate the levels*/
    items = getReports("data.txt", rawReport);
    stringToInt(rawReport, items, report, levels);
    
    checkConditions(report, items, safe, levels);    

    total = sumItems(safe, items);

    printf("Safe Reports: %d", total);

    return 0;
}

int getReports(char filename[], char rawReports[][MAX_LENGHT])
{
    FILE *file = fopen(filename, "rt");
    int i = 0;

    while(fscanf(file, "%[^\n]\n", rawReports[i]) == 1 && i < MAX_REPORTS)
    {
        i++;
    }  
    
    fclose(file);
    return i;
}

void stringToInt(char rawReport[][MAX_LENGHT], int items, int report[][MAX_LEVELS], int levels[])
{
    int i;

    for (i = 0; i < items; i++)
    {
        char *token = strtok(rawReport[i], " ");
        int j = 0;

        while (token != NULL && j < MAX_LEVELS)
        {
            report[i][j] = atoi(token);
            token = strtok(NULL, " ");
            j++;
        }     
        
        levels[i] = j;
    }
}

void checkConditions(int report[][MAX_LEVELS], int items, int safe[], int levels[])
{
    int i, j, a, b, ascendant, descendant = 0;

    for (i = 0; i < items; i++)
    {
        a = b = ascendant = descendant = 0;

        for (j = 1; j < levels[i]; j++)
        {
                a = report[i][j] - report[i][j - 1];
                if ( 1 <= a && a <= 3)
                    ascendant++;  
        
                b = report[i][j - 1] - report[i][j];
                if ( 1 <= b && b <= 3)
                    descendant++;    
        }

        if (ascendant == levels[i] - 1 || descendant == levels[i] - 1)
            safe[i] = 1;
        
        /*check removing each value. 
        couldn't figure this out on my own*/
        for (j = 0; j < levels[i]; j++) 
        {
            int tempAscendant = 0, tempDescendant = 0;
            int lastIndex = -1;

            for (int k = 0; k < levels[i]; k++)
            {
                if (k == j) 
                    continue;

                if (lastIndex != -1)
                {
                    a = report[i][k] - report[i][lastIndex];
                    if (1 <= a && a <= 3)
                        tempAscendant++;

                    b = report[i][lastIndex] - report[i][k];
                    if (1 <= b && b <= 3)
                        tempDescendant++;
                }

                lastIndex = k;
            }

            if (tempAscendant == levels[i] - 2 || tempDescendant == levels[i] - 2)          
                safe[i] = 1;
        }
    }
}

int sumItems(int a[], int entries)
{
    int i;
    int sum = 0;

    for (i = 0; i < entries; i++)
        sum += a[i];

    return sum;
}