#pragma once
class sort
{
public:
    static int** create_ivector(int n, int m);
    static void remove_ivector(int** iv_array, int m);
    static int** create_sorted_ivector(int n, int m);
    static int** create_reverse_sorted_ivector(int n, int m);
    static int** create_random_ivector(int n, int m, bool small);

    static void insertion_sort(int** A, int n, int l, int r);

    static bool check_sorted(int** A, int n, int l, int r);
    static int ivector_length(int* pVector, int iCount);
    static void insertion_sort_im(int** A, int n, int l, int r);
    static void merge_sort(int** pAA, int D1Length, int D2Length);
};
