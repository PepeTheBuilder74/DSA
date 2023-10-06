
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &A, int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
            swap(A[i], A[j]);
    } while (i < j);
    swap(A[l], A[j]);
    return j;
}

void QuickSort(vector<int> &A, int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}

int main()
{
    vector<int> A = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = 10, i;
    QuickSort(A, 0, n);
    for (i = 0; i < 10; i++)
        cout << A[i] << " ";
    cout << "\n";
    return 0;
}

#include <iostream>

using namespace std;

template <class T>
void Print(T &vec, int n, string s)
{
    cout << s << ": [" << flush;
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << flush;
        if (i < n - 1)
        {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

void Merge(int A[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[high + 1];
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    while (i <= mid)
    {
        B[k++] = A[i++];
    }
    while (j <= high)
    {
        B[k++] = A[j++];
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void RecursiveMergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        // Calculate mid point
        int mid = low + (high - low) / 2;

        // Sort sub-lists
        RecursiveMergeSort(A, low, mid);
        RecursiveMergeSort(A, mid + 1, high);

        // Merge sorted sub-lists
        Merge(A, low, mid, high);
    }
}

int main()
{

    int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(A) / sizeof(A[0]);

    Print(A, n, "\t\tA");
    RecursiveMergeSort(A, 0, n - 1);
    Print(A, n, " Sorted A");

    return 0;
}