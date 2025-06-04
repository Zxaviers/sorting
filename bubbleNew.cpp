#include <iostream>
using namespace std;

int count = 0;

void bubbleSort(int arr[], int n, bool ascending)
{
    bool swapped;
    for (int i = 0; i < n - 1; ++i)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j)
        {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1]))
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
            count++;
        }
        if (!swapped)
            break;
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
        bubbleSort(data, n, true);
        cout << "Array setelah diurutkan (Ascending):\n";
    } else if (choice == 2) {
        bubbleSort(data, n, false);
        cout << "Array setelah diurutkan (Descending):\n";
    } else {
        cout << "Pilihan tidak valid.\n";
    }
    
    printArray(data, n);
    cout << "Total perbandingan utama: " << count << endl;
    return 0;
}
