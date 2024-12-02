#include <stdio.h>
#define MAX_REPORTS 1000
#define MAX_LEVELS 8

int getData(char filename[], int reports[][MAX_LEVELS]);
void checkConditions(int reports[][MAX_REPORTS], int items);

int main()
{
    int report[MAX_REPORTS][MAX_LEVELS];
    int i, j;
    int items;

    /*Since none of the levels equals 0, i will initialize all of the values to prevent random numbers*/
    for (i = 0; i < MAX_REPORTS; i++)
        for (j = 0; j < MAX_LEVELS; j++)
            report[i][j] = 0;

    items = getData("data.txt", report);

    for (i = 0; i < 1000; i++) {
        for (j = 0; j < MAX_LEVELS; j++) {
            printf("%d ", report[i][j]);
        }
        printf("\n");
    }

    return 0;
}


int getData(char filename[], int reports[][MAX_LEVELS])
{
    FILE *file = fopen(filename, "rt");
    int i, j = 0;
    

  

    fclose(file);
    return i;
}

void checkConditions(int reports[][MAX_REPORTS], int items)
{
    int i, j = 0;

    for (i = 0; i < items; i++)
    {
        for (j = 0; j < MAX_LEVELS; j++)
        {
            

        }

    }
}