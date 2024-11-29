//Знайти шість найменших елементів масиву, користуючись функцією
//сортування елементів
//Переробити з масивами, сортування


#include <iostream>

using namespace std;

int* bubbleSort(const int* original, const int n)
{
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = original[i];
    }

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    return arr;
}

/// Bubble sort that prevents using new and delete to prevent memory leaks 

unique_ptr<int[]> betterBubble(const int original[], int n) {
    unique_ptr<int[]> arr = make_unique<int[]>(n);

    for (int i = 0; i < n; i++) {
        arr[i] = original[i];
    }

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }

    return arr;
}



int main()
{
    int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    int n = sizeof(arr) / sizeof(arr[0]);

    int* sorted = bubbleSort(arr, n);

    for (int i = 1; i < 7; i++) {
        cout << sorted[n - i] << "\n";
    }

    delete[] sorted;

    unique_ptr<int[]> safeSorted = betterBubble(arr, n);

    for (int i = 1; i < 7; i++) {
        cout << "\n" << safeSorted[n - i];
    }

    return 0;
}

