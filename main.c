#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FindTop3(float[], int[]);
int GetFailures(float[], int[]);
void PrintResults(char *[], int[], int[], int);

int main()
{
    char *athletes[9] = {"Juku", "Meelis", "Peeter", "Ats", "Teet", "Paul", "Anti", "Peep", "Mart"};

    float results[9] = {4.98, 5.10, 4.75, 4.77, 0.00, 4.92, 5.05, 4.95, 0.00};

    int failures[9];
    int numberOfFailures;
    int top3[3];

    numberOfFailures = GetFailures(results, failures);

    FindTop3(results, top3);

    PrintResults(athletes, top3, failures, numberOfFailures);
}

void FindTop3(float results[], int top3[])
{
    float best = 0;
    for (int i = 1; i < 9; i++)
    {
        if (results[i] > best)
        {
            best = results[i];
            top3[0] = i;
        }
        float secondBest = 0;
        for (int i = 1; i < 9; i++)
        {
            if (results[i] > secondBest && i != top3[0])
            {
                secondBest = results[i];
                top3[1] = i;
            }
            float thirdBest = 0;

            for (int i = 1; i < 9; i++)
            {
                if (results[i] > thirdBest && i != top3[0] && i != top3[1])
                {
                    thirdBest = results[i];
                    top3[2] = i;
                }
            }
        }
    }
}

int GetFailures(float results[9], int failures[9])
{
    int i;
    int failNumber = 0;
    for (i = 0; i < 9; i++)
    {

        if (results[i] == 0)
        {
            failures[failNumber] = i;
            failNumber++;
        }
    }
    return failNumber;
}

void PrintResults(char *athletes[9], int top3[3], int failures[9], int numberOfFailures)
{
    printf("Participants in competiotion: \n");
    for (int i = 0; i < 9; i++)
    {
        printf("%s ", athletes[i]);
    }
    printf("\n");

    printf("\nTop three: \n");
    for (int i = 1; i < 4; i++)
    {
        printf("%d. place: %s \n", i, athletes[top3[i]]);
    }

    printf("\nUnsuccessful during the race (DNF): %d", numberOfFailures);
    for (int i = 0; i < numberOfFailures; i++)
    {
        printf("%s ", athletes[failures[i]]);
    }
}
