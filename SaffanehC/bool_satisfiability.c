#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* bSat(int **clauses, int n, int m);
int satisfy(int *vars, int **clauses, int n, int m);

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int **clauses = (int **) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);

        clauses[i] = (int *) malloc(k * sizeof(int));
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &clauses[i][j]);
        }
    }
    
    int *ans = bSat(clauses, n, m);
}

int* bSat(int **clauses, int n, int m)
{
    int *vars = (int *) malloc(sizeof(int));
    memset(vars, -1, sizeof(vars));

    int result = satisfy(vars, clauses, n, m, 0);


}

int satisfy(int *vars, int **clauses, int n, int m, int v)
{
    if (v == m) return 0;

    int r = 0;
    r |= satisfy(vars, clauses, n, m, v+1);
    if (r) return 1;

    r = 1;
    for(int i = 0; i < n; i++)
    {
        int k = sizeof(clauses[i]) / sizeof(int);
        int a = 0;
        
        for(int j = 0; j < k; j++)
        {
            int var = clauses[i][j];
            int sgn = (var > 0 ? +1 : -1);
            var *= sgn;

            if (vars[var-1] == sgn)
            {
                a = 1;
                break;
            }
        }

        if (!a)
        {
            r = 0;
            break;
        }
    }

    if (r) return 1;
    vars[v] = 1;
    r |= satisfy(vars, clauses, n, m, v+1);
}