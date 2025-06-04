#include <iostream>
using namespace std;

int count = 0;

void selectionSort(int arr[], int n, bool ascending)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int extremumIndex = i; 
        for (int j = i + 1; j < n; ++j)
        {
            if ((ascending && arr[j] < arr[extremumIndex]) || (!ascending && arr[j] > arr[extremumIndex]))
                extremumIndex = j;
            count++;
        }
        if (extremumIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[extremumIndex];
            arr[extremumIndex] = temp;
        }
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
        selectionSort(data, n, true);
        cout << "Array setelah diurutkan (Ascending):\n";
    } else if (choice == 2) {
        selectionSort(data, n, false);
        cout << "Array setelah diurutkan (Descending):\n";
    } else {
        cout << "Pilihan tidak valid.\n";
    }
    
    printArray(data, n);
    cout << "Total perbandingan utama: " << count << endl;
    return 0;
}
