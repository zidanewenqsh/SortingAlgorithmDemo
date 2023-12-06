
#include "header.h"

// 基数排序
// Function to get the maximum value in arr[]
int getMax(vector<int> &arr) {
    return *max_element(arr.begin(), arr.end());
}

// Function to do counting sort of arr[] according to the digit represented by exp.
void countSort(vector<int> &arr, int exp) {
    vector<int> output(arr.size());
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < arr.size(); i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

// The main function that sorts arr[] of size n using Radix Sort
void radixSort(vector<int> &arr) {
    // Find the maximum number to know number of digits
    int m = getMax(arr); // 获取数组中的最大数以确定数字的最大位数

    // Do counting sort for every digit. Note that instead of passing digit number, exp is passed.
    // exp is 10^i where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10) {
        // 对每个位（个位、十位、百位...）执行一次计数排序
        countSort(arr, exp);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);
    print_vec(arr);
    return 0;
}