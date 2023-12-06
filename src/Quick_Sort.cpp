#include "header.h"
#include <vector>
// 快速排序
// 递归快速排序
template <typename T>
void quickSort(vector<T>& arr, int start, int end) {
    if (start >= end) return ;
    int l = start, r = end;
    T pivot = arr[(start + end) / 2];
    while (l <= r) {
        while (l <= r && arr[l] < pivot) l++;
        while (l <= r && arr[r] > pivot) r--;
        if (l <= r) swap(arr[l++], arr[r--]);
    }
    quickSort(arr, start, r);
    quickSort(arr, l, end);
}

// 单边递归快速排序
template <typename T>
void quickSortSingleRecursion(vector<T>& arr, int start, int end) {
    while (start < end) {
        int l = start, r = end, pivot = arr[(start + end) / 2];
        while (l <= r) {
            while (l <= r && arr[l] < pivot) l++;
            while (l <=r && arr[r] > pivot) r--;
            if (l <= r) {
                swap(arr[l], arr[r]);
                l++; r--;
            }
        }
        quickSortSingleRecursion(arr, l, end);
        end = r;
    }
}

// 无监督快速排序
template <typename T>
void quickSortUnwatched(vector<T>& arr, int start, int end) {
    while (start < end) {
        int l = start, r = end, pivot = arr[(start + end) / 2];
        do {
            while (arr[l] < pivot) l++;
            while (arr[r] > pivot) r--;
            if (l <= r) {
                swap(arr[l], arr[r]);
                l++; r--;
            }
        }while (l <= r);
        quickSortUnwatched(arr, l, end);
        end = r;
    }
}

int main(){
    vector<int> arr = {1, 3, 2, 5, 4};
    quickSort(arr, 0, arr.size() - 1);
    print_vec(arr);
    vector<float> arr2 = {1, 3, 2, 5, 4};
    quickSortSingleRecursion(arr2, 0, arr2.size() - 1);
    print_vec(arr2);
    vector<float> arr3 = {1, 3, 2, 5, 4};
    quickSortUnwatched(arr3, 0, arr3.size() - 1);
    print_vec(arr3);
    return 0;
}