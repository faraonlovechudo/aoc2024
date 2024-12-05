#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_UPDATES 200
#define MAX_LENGHT 70
#define MAX_PAGES 23
#define MAX_RULES 1200

void getData(char filename[],int rules[][2], char updates[][MAX_LENGHT], int items[]);
void stringToInt(char rawUpdates[][MAX_LENGHT], int nUpdates, int updates[][MAX_PAGES], int pages[]);
void verifyUpdates(int updates[][MAX_PAGES], int nUpdates, int pages[], int rules[][2], int nRules, int correctUpdates[]);


int main ()
{
    int rules[MAX_RULES][2]; /*[X]|[Y]*/
    char updatesString[MAX_UPDATES][MAX_LENGHT];
    int updates[MAX_UPDATES][MAX_PAGES] = {{0}};
    int pages[MAX_UPDATES];
    int items[2]; /*[0]: rules, [1]: updates*/
    int nRules, nUpdates, i;
    int correctUpdates[MAX_UPDATES] = {0};

    getData("data.txt", rules, updatesString, items);

    nRules = items[0];
    nUpdates = items[1];

    printf("Rules read:\t%d\n", nRules);
    printf("Updates read:\t%d\n", nUpdates);

    stringToInt(updatesString, nUpdates, updates, pages); 

    /*now we come up with an algorithm :P*/
    /*1st: check which updates comply with the rules*/
    verifyUpdates(updates, nUpdates, pages, rules, nRules, correctUpdates);

    for (i = 0; i < nUpdates; i++)
    {
        printf("%d", correctUpdates[i]);
    }
    
    /*2nd: find middle number of each correct updates*/

    return 0;
}

void getData(char filename[],int rules[][2], char updates[][MAX_LENGHT], int items[])
{
    FILE *file = fopen(filename, "r");
    int i = 0;
    int control = 0;
    char buffer[MAX_LENGHT];

    /*messy ahh reading, whatever*/
    while (control != 1)
    {
        fscanf(file,"%[^\n]\n", buffer);
    
        if (!strchr(buffer, '|'))
        {
            strcpy(updates[0], buffer);
            control = 1;
        }
        else
        {
            sscanf(buffer,"%d|%d\n", &rules[i][0], &rules[i][1]);
            printf("%d|%d\n", rules[i][0], rules[i][1]);
            i++;
        }
    }
    
    items[0] = i;
    printf("%s\n", updates[0]);
    i = 1;

    while (fscanf(file, "%[^\n]\n", updates[i]) == 1)
    {
        printf("%s\n", updates[i]);
        i++;
    }

    items[1] = i;
}

void stringToInt(char rawUpdates[][MAX_LENGHT], int nUpdates, int updates[][MAX_PAGES], int pages[])
{
    int i;

    for (i = 0; i < nUpdates; i++)
    {
        char *token = strtok(rawUpdates[i], ",");
        int j = 0;

        while (token != NULL && j < MAX_PAGES)
        {
            updates[i][j] = atoi(token);
            token = strtok(NULL, " ");
            j++;
        }     
        
        pages[i] = j;
    }
}

int getRules(int x, int rules[][2], int nRules, int specificRules[])
{
    int i;
    int count = 0;

    for (i = 0; i < nRules; i++)
    {
        if (x == rules[i][0])
        {
            specificRules[count] = rules[i][1];
            printf("%d\n", specificRules[count]);
            count++;
        }
    }
    
    printf("values to check: %d\n", count);
    return count;
}

int checkRules(int updates[], int specificRules[], int valuesToCheck, int pos)
{
    int i, j;
    int errors = 0;

    for (i = 0; i < pos; i++)
    {
        for (j = 0; j < valuesToCheck; j++)
        {
            if (updates[i] == specificRules[j])
                errors++;
        }
    }

    return errors;
}

void verifyUpdates(int updates[][MAX_PAGES], int nUpdates, int pages[], int rules[][2], int nRules, int correctUpdates[])
{
    int i, j;

    for (i = 0; i < nUpdates; i++)
    {
        int errors = 0;
        for (j = (pages[i] - 1); j >= 0; i--)
        {
            int specificRules[MAX_RULES];   

            int valuesToCheck = getRules(updates[i][j], rules, nRules, specificRules);
            errors += checkRules(updates[i], specificRules, valuesToCheck, j);
        }

        if (errors == 0)
            correctUpdates[i] = 1;
    }
}
