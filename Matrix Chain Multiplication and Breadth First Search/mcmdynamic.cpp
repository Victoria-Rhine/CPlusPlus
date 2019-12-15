#include "mcmdynamic.h"

/* function for printing the optimal
   parenthesization of a matrix chain product */
void printParenthesis(int i, int j, int n, int *bracket, char &name)
{
    // if only one matrix left in current segment
    if (i == j)
    {
        std::cout << name++;
        return;
    }

    std::cout << "(";

    // recursively put brackets around subexpression
    // from i to bracket[i][j].
    // Note that "*((bracket + i * n ) + j)" is similar to bracket[i][j]
    printParenthesis(i, *((bracket + i *n) +j), n, bracket, name);

    // recursively put brackets around subexpression from bracket[i][j] + 1 to j.
    printParenthesis(*((bracket + i * n) +j) + 1, j,
                     n, bracket, name);
    std::cout << ")";
}

// MCM using dynamic programming
void matrixChainOrder(int p[], int n)
{
    /* for simplicity of the program, one extra
    row and one extra column are allocated in
    m[][]. 0th row and 0th column of m[][] are not used */
    int m[n][n];

    // bracket[i][j] stores optimal break point in subexpression from i to j.
    int bracket[n][n];

    /* m[i,j] = minimum number of scalar multiplications
    needed to compute the matrix A[i]A[i+1]...A[j] =
    A[i..j] where dimension of A[i] is p[i-1] x p[i] */

    // cost is zero when multiplying one matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // l is chain length.
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;

                    // each entry bracket[i,j] = k shows
                    // where to split the product arr
                    // i, i+1....j for the minimum cost.
                    bracket[i][j] = k;
                }
            }
        }
    }
    // the first matrix is printed as 'A', next as 'B', and so on
    char name = 'A';

    std::cout << "Optimal Parenthesization is : ";
    printParenthesis(1, n - 1, n, reinterpret_cast<int*>(bracket), name);
    std::cout << "\nOptimal Cost is : " << m[1][n - 1] << std::endl;
}

// function for memoized MCM
int matrixChainOrderMem(int *p)
{
    int n = 6; // equal to  p length - 1
    int m[7][7];

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            m[i][j] = INT_MAX; //  add large ("infinity") values to indicate it's not filled in
        }
    }
    return lookupChain(m, p, 1, n);
}

int lookupChain(int m[7][7], int p[7], int i, int j)
{
    if (m[i][j] < INT_MAX) // if less than large value then return previously computer cost
        return  m[i][j];

    if (i == j)
        m[i][j] = 0;
    else
        for (int  k = i; k <= j - 1; k++)
        {
            // recursively call
            int q = lookupChain(m, p, i, k) + lookupChain(m, p, k + 1, j) + p[i - 1] * p[k] * p[j];
            if (q < m[i][j])
            {
                m[i][j] = q;
            }
        }
    return m[i][j];
}

