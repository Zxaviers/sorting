#include <iostream>
using namespace std;


int count = 0; 

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            cout << ++count << "\t"; 
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
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
    cout << "Array sebelum diurutkan:\n";
    printArray(data, n);
    selectionSort(data, n);
    cout << endl;
    cout << "Array setelah diurutkan:\n";
    printArray(data, n);
    cout << "Total perbandingan utama: " << count << endl;
    return 0;
}