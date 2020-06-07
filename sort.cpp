#include "sort.h"
#include <math.h>
#include <malloc.h>
#include <cstring>
#include "random_generator.h"
#include "iostream"

//  Arguments use LENGTH rather than index. For an [2][3] array, 2 and 3 should be used.
void sort::merge_sort(int** pAA, int D1Length, int D2Length)
{
    //  Divide the 2D Array into two sub 2D arrays and copy values
    int Sub0Len = D1Length / 2;
    int Sub1Len = D1Length - D1Length / 2;

    int** pSub0 = new int* [Sub0Len];
    int ** pSub1 = new int* [Sub1Len];

    for (int i = 0; i < Sub0Len; i++)
    {
        pSub0[i] = (int *) malloc(sizeof(int) * D2Length);
        memcpy(pSub0[i], pAA[i], sizeof(int) * D2Length);
    }

    for (int i = 0; i < Sub1Len; i++)
    {
        pSub1[i] = (int *) malloc(sizeof(int) * D2Length);
        memcpy(pSub1[i], pAA[Sub0Len + i], sizeof(int) * D2Length);
    }

    sort::insertion_sort_im(pSub0, D2Length, 0, Sub0Len - 1);
    sort::insertion_sort_im(pSub1, D2Length, 0, Sub1Len - 1);

    int MainIndex = 0;
    int Sub0Index = 0;
    int Sub1Index = 0;

    while (true)
    {
        if (sort::ivector_length(pSub0[Sub0Index], D2Length) < sort::ivector_length(pSub1[Sub1Index], D2Length))
        {
            memcpy(pAA[MainIndex], pSub0[Sub0Index], sizeof(int) * D2Length);
            Sub0Index++;
            MainIndex++;
        }
        else
        {
            memcpy(pAA[MainIndex], pSub1[Sub1Index], sizeof(int) * D2Length);
            Sub1Index++;
            MainIndex++;
        }

        if (Sub0Index == Sub0Len)
        {
            for (int i = Sub1Index; i < Sub1Len; ++i)
            {
                memcpy(pAA[MainIndex], pSub1[i], sizeof(int) * D2Length);
                MainIndex++;
            }
            break;
        }

        if (Sub1Index == Sub1Len)
        {
            for (int i = Sub0Index; i < Sub0Len; ++i)
            {
                memcpy(pAA[MainIndex], pSub0[i], sizeof(int) * D2Length);
                MainIndex++;
            }
            break;
        }
    }
    sort::remove_ivector(pSub0, Sub0Len);
    sort::remove_ivector(pSub1, Sub1Len);
}

int** sort::create_ivector(int n, int m)
{
    int** iv_array;

    iv_array = new int* [m];
    for (int i = 0; i < m; i++)
        iv_array[i] = new int[n];

    return iv_array;
}

void sort::remove_ivector(int** iv_array, int m)
{
    for (int i = 0; i < m; i++)
        delete[] iv_array[i];
    delete[] iv_array;
}

int** sort::create_sorted_ivector(int n, int m)
{
    int** iv_array;

    iv_array = create_ivector(n, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            iv_array[i][j] = (i + j) / n;

    return iv_array;
}

int** sort::create_reverse_sorted_ivector(int n, int m)
{
    int** iv_array;

    iv_array = create_ivector(n, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            iv_array[i][j] = ((m - i) + j) / n;

    return iv_array;
}

int** sort::create_random_ivector(int n, int m, bool small)
{
    random_generator rg;
    int** iv_array;

    iv_array = create_ivector(n, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            rg >> iv_array[i][j];
            if (small)
                iv_array[i][j] %= 100;
            else
                iv_array[i][j] %= 65536;
        }

    return iv_array;
}

bool sort::check_sorted(int** A, int n, int l, int r)
{
    for (int i = l+1; i <= r; i++)
        if (ivector_length(A[i-1], n) > ivector_length(A[i], n))
            return false;
    return true;
}

void sort::insertion_sort(int** A, int n, int l, int r)
{
    int i;
    int* key;

    for (int j = l+1; j <= r; j++)
    {
        key = A[j];
        i = j - 1;

        while ((i >= l) && (ivector_length(A[i], n) > ivector_length(key, n)))
        {
            A[i+1] = A[i];
            i = i - 1;
        }

        A[i+1] = key;
    }
}

void sort::insertion_sort_im(int** A, int n, int l, int r)
{
    int* pLength = (int*)malloc(sizeof(int) * (r + 1));

    for (int i = 0; i < (r + 1); i++)
    {
        *(pLength + i) = ivector_length(A[i], n);
    }

    int i;
    int* key;

    for (int j = l+1; j <= r; j++)
    {
        key = A[j];
        int LK = pLength[j];
        i = j - 1;

        while ((i >= l) && (pLength[i] > LK))
        {
            A[i+1] = A[i];
            pLength[i + 1] = pLength[i];
            i = i - 1;
        }

        A[i+1] = key;
        pLength[i + 1] = LK;
    }

    free(pLength);
}

int sort::ivector_length(int* v, int n)
{
    int length = 0;

    for (int i = 0; i < n; i++)
        length += abs(v[i]);

    return length;
}
