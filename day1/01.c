#include <stdio.h>
#define MAX_ITEMS 1000

int getData(char filename[], int firstList[], int secondList[]);
void sort(int in[], int out[], int entries);
void calcDistance(int a[], int b[], int distance[], int entries);
int sumItems(int a[], int entries);
void calcSimilarity(int a[], int b[], int similarity[], int entries);

int main()
{
    int a[MAX_ITEMS], aSorted[MAX_ITEMS];
    int b[MAX_ITEMS], bSorted[MAX_ITEMS];
    int distance[MAX_ITEMS], similarity[MAX_ITEMS];
    int totalDistance, similarityScore;
    
    int items = getData("data.txt", a, b);

    sort(a, aSorted, items);
    sort(b, bSorted, items);

    calcDistance(aSorted, bSorted, distance, items);

    totalDistance = sumItems(distance, items);

    printf("distance: %d\n", totalDistance);

    /*Part two: */

    calcSimilarity(a, b, similarity, items);

    similarityScore = sumItems(similarity, items);

    printf("score: %d\n", similarityScore);


    return 0;
}

int getData(char filename[], int firstList[], int secondList[])
{
    FILE *file = fopen(filename, "rt");
    int i = 0;

    while(fscanf(file, "%d \t%d\n", &firstList[i], &secondList[i]) == 2 && i <= MAX_ITEMS)
    {
        i++;
    }

    fclose(file);
    return i;
}

/*Inspired from geeksforgeeks.com bubble sort explanation*/
void sort(int in[], int out[], int entries)
{
    int i, j, temp;

    for (i = 0; i < entries; i++)
        out[i] = in[i];

    for (i = 0; i < entries; i++)
    {
        for (j = 0; j < (entries - i - 1); j++)
        {
            if (out[j] > out[j + 1])
            {
                temp = out[j];
                out[j] = out[j + 1];
                out[j + 1] = temp;
            }
        }
    }
}

void calcDistance(int a[], int b[], int distance[], int entries)
{
    int i;

    for (i = 0; i < entries; i++)
    {
        if (a[i] > b[i])
            distance[i] = a[i] - b[i];
        if (a[i] < b[i])
            distance[i] = b[i] - a[i];
        if (a[i] == b[i])
            distance[i] = 0;
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

void calcSimilarity(int a[], int b[], int similarity[], int entries)
{
    int i, j, count;

    for (i = 0; i < entries; i++)
    {
        count = 0;
        for(j = 0; j < entries; j++)
        {
            if (a[i] == b[j])
                count++;
        }
        similarity[i] = a[i] * count;
    }
}