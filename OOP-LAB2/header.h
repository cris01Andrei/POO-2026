#pragma once
#include <stdio.h>
#include <string.h>

#define MAX 1000

enum VALORI {
    INMULTIRE = 0, 
    SUMA = 1,      
    DIFERENTA = 3, 
    IMPARTIRE = 5  
};

typedef int (*func)(int, int);

struct Content {
    int p1;
    int p2;
};

int Sum(int a, int b);
int Dif(int a, int b);
int Mul(int a, int b);
int Div(int a, int b);