#include <stdio.h>
#include <stdlib.h>

void invert_sequence(int *v1, int n, int *v2);
void copy(int *v1, int n, int *v2);
void reverse_array(int *arr, int i, int j);
void swap(int *a, int *b);

int main()
{
    int n, *v1, *v2;
    scanf("%d", &n);

    v1 = (int*) malloc(n * sizeof(int));
    v2 = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &v1[i]);
    
    invert_sequence(v1, n, v2);
        
    for (int i = 0; i < n; i++)
        printf("%d ", v2[i]);
}

void invert_sequence(int *v1, int n, int *v2)
{
    copy(v1, n, v2);

    for (int i = 0; i < n; i++) {
        int j;
        for (j = i+1; j < n; j++) {
            if (v2[j-1] >= v2[j]) break;
        }

        // printf("rev(%d,%d)\n", i, j);
        reverse_array(v2, i, j);
        i = j-1;
    }
}

void copy(int *v1, int n, int *v2)
{
    for (int i = 0; i < n; i++)
    {
        v2[i] = v1[i];
    }
}

void reverse_array(int *arr, int i, int j)
{
    j--;
    while (i < j) {
        swap(&arr[i++], &arr[j--]);
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}