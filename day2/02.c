#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_REPORTS 1000
#define MAX_LENGHT 24
#define MAX_LEVELS 8

int getReports(char filename[], char rawReports[][MAX_LENGHT]);
void stringToInt(char rawReport[][MAX_LENGHT], int items, int report[][MAX_LEVELS]);
void checkConditions(int reports[][MAX_LEVELS], int items);

int main()
{
    char rawReport[MAX_REPORTS][MAX_LENGHT];
    /*Since none of the levels equals 0, i will initialize all of the values to prevent random numbers*/
    int report[MAX_REPORTS][MAX_LEVELS] = {{0}};
    int i, j;
    int items;

    /*New approach: get all reports as a whole, then separate the levels*/
    items = getReports("data.txt", rawReport);
    stringToInt(rawReport, items, report);

    for (i = 0; i < 1000; i++) {
        for (j = 0; j < MAX_LEVELS; j++) {
            printf("%d ", report[i][j]);
        }
        printf("\n");
    }

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

void stringToInt(char rawReport[][MAX_LENGHT], int items, int report[][MAX_LEVELS])
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
    }
}


void checkConditions(int reports[][MAX_LEVELS], int items)
{
    int i, j = 0;

    for (i = 0; i < items; i++)
    {
        for (j = 0; j < MAX_LEVELS; j++)
        {
            

        }

    }
}