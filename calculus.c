#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

#define BASK_RESET 0, 0, 0, 0, 0, 0, 0
#define MESSAGE_LIM 256
typedef struct BaskStructure
{
    float a;
    float b;
    float c;
    float delta;
    float deltaRoot;
    float root1;
    float root2;
    char message[MESSAGE_LIM];
} BasckStruct;

#pragma region BASK_INTERFACE
struct BaskStructure calculateBask(float a, float b, float c);
void drawData(struct BaskStructure data);
#pragma endregion BASK_INTERFACE

#pragma region MATH_BASES

#pragma region BASK_IMPLEMENTATION
struct BaskStructure calculateBask(float a, float b, float c)
{
    BasckStruct data;
    data.a = 0;
    data.b = 0;
    data.c = 0;

    if (!a)
    {
        puts("ax^2 is invalid.");
        exit(EXIT_FAILURE);
    }

    if (!b)
    {
        puts("bx is invalid.");
        exit(EXIT_FAILURE);
    }

    if (!c)
    {
        puts("c is invalid.");
        exit(EXIT_FAILURE);
    }
    data.a = a;
    data.b = b;
    data.c = c;
    data.delta = pow(b, 2) - 4 * data.a * data.c;
    data.deltaRoot = sqrt(data.delta);
    if (data.delta < 0)
    {
        snprintf(data.message, MESSAGE_LIM, "[CALCULUS]:There's no real roots!");
    }

    else if (data.delta == 0)
    {
        snprintf(data.message, MESSAGE_LIM, "[CALCULUS]: There's one real root!");
        data.root1 = -b / 2 * a;
    }

    else
    {
        snprintf(data.message, MESSAGE_LIM, "[CALCULUS]: There's two roots!");
        data.root1 = (-b + data.deltaRoot) / (2 * a);
        data.root2 = (-b - data.deltaRoot) / (2 * a);
    }

    return data;
}
void drawData(struct BaskStructure data)
{
    printf("\n******RESULTS******\n");
    printf("\nA:%f", data.a);
    printf("\nB:%f", data.b);
    printf("\nC:%f", data.c);
    printf("\nDelta Root:%f", data.deltaRoot);
    printf("\nRoot 1:%f", data.root1);
    printf("\nRoot 2:%f", data.root2);
}
#pragma endregion BASK_IMPLENTATION
