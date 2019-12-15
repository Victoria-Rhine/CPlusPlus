#ifndef MCMDYNAMIC_H
#define MCMDYNAMIC_H
#include <stdio.h>
#include <limits.h>
#include <limits>
#include <iostream>

// function for mcm using dynamic programming
void matrixChainOrder(int p[], int n);

// function for finding optimal parenthese
void printParenthesis(int i, int j, int n, int *bracket, char &name);

// function for mcm using memoization
int matrixChainOrderMem(int *p);

// helper function for mcm using memoization
int lookupChain(int m[7][7], int p[7], int i, int j);

#endif // MCMDYNAMIC_H
