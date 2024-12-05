#include <stdio.h>
#include <string.h>
#define MAX_INSTRUCTIONS 2000
#define MAX_LENGHT 30

int getData (char filename[], char rawData[][MAX_LENGHT]);
void verifyInstructions (char rawData[][MAX_LENGHT], int items, char instructions[][MAX_LENGHT]);


int main ()
{
    char fractionedData[MAX_INSTRUCTIONS][MAX_LENGHT];
    int items, i;
    char instructions[MAX_INSTRUCTIONS][MAX_LENGHT];

    items = getData("data.txt", fractionedData);

    for (i = 0; i < items; i++)
        printf("%s\n", fractionedData[i]);

    printf("%d\n", items);

    return 0;
}

int getData (char filename[], char rawData[][MAX_LENGHT])
{
    FILE *file = fopen(filename, "rt");
    int i = 0;

    while (i < MAX_INSTRUCTIONS && !feof(file))
    {
        if (fscanf(file, "%[^)])", rawData[i]) == 1)
            i++;
        else fscanf(file, "%*s");
    }

    fclose(file);
    return i;
}

void verifyInstructions (char rawData[][MAX_LENGHT], int items, char instructions[][MAX_LENGHT])
{
    int i, j;

    for (i = 0; i < items; i++)
    {
        


    }

}