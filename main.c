#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(int a, int b)
{
    if (a > b) return 1;
    else return -1;
}

int absoluteCompare(int a, int b)
{
    if (abs(a) > abs(b)) return 1;
    else return -1;
}

void bubbleSort(int *a, int n, int (*compare)(int, int))
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if ((*compare)(*(a + j), *(a + j + 1)) > 0)
            {
                temp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = temp;
            }
        }
    }
}

int main()
{
    int a[] = {-31, 22, -1, 50, -6, 4};

    void (*p)(int*, int, int (*)(int, int)) = &bubbleSort; 
    (*p)(a, 6, &absoluteCompare);

    for (int i = 0; i < 6; i++) printf("%d ", a[i]);
}
