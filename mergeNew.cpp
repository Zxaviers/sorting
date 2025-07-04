#include <iostream>
using namespace std;

int count = 0;

void merge(int arr[], int left, int mid, int right, bool ascending)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if ((ascending && L[i] <= R[j]) || (!ascending && L[i] >= R[j]))
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
        count++;
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right, bool ascending)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, ascending);
        mergeSort(arr, mid + 1, right, ascending);
        merge(arr, left, mid, right, ascending);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n = 50;
    int data[n] = {
        42, 23, 17, 89, 55, 23, 78, 34, 11, 90,
        5,  66, 3,  17, 54, 88, 12, 44, 29, 37,
        1,  99, 6,  67, 33, 70, 80, 13, 47, 10,
        20, 22, 91, 35, 60, 62, 28, 15, 49, 98,
        2,  40, 25, 76, 18, 38, 71, 85, 36, 7
    };

    int choice;
    cout << "Array sebelum diurutkan:\n";
    printArray(data, n);

    cout << "Pilih urutan (1: Ascending, 2: Descending): ";
    cin >> choice;

    count = 0; 

    if (choice == 1) {
        mergeSort(data, 0, n - 1, true);
        cout << "Array setelah diurutkan (Ascending):\n";
    } else if (choice == 2) {
        mergeSort(data, 0, n - 1, false);
        cout << "Array setelah diurutkan (Descending):\n";
    } else {
        cout << "Pilihan tidak valid.\n";
    }
    
    printArray(data, n);
    cout << "Total perbandingan utama: " << count << endl;
    return 0;
}
