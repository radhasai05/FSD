#include <iostream>
#include <chrono>
#include <random>
#include <fstream>

using namespace std;
using namespace std::chrono;

// Merge two subarrays of arr[]: arr[l..m] and arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = l; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Function to generate random numbers and write them to a file
void generateRandomNumbersToFile(int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000);

    ofstream file("numbers.txt");
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            file << dis(gen) << " ";
        }
        file.close();
    } else {
        cout << "Unable to open the file." << endl;
    }
}

// Function to read numbers from a file into an array
void readNumbersFromFile(int arr[], int n) {
    ifstream file("numbers.txt");
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            file >> arr[i];
        }
        file.close();
    } else {
        cout << "Unable to open the file." << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements to sort: ";
    cin >> n;

    // Generate random numbers and write them to a file
    generateRandomNumbersToFile(n);

    // Read the numbers from the file into an array
    int arr[n];
    readNumbersFromFile(arr, n);

    // Perform merge sort and measure the time taken
    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto end = high_resolution_clock::now();

    // Calculate the time taken for sorting
    auto duration = duration_cast<milliseconds>(end - start);

    // Display the sorted array and the time taken
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;

    return 0;
}
