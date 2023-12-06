
#include "header.h"
// 插入排序
template <typename T>
void insertionSort(vector<T>& arr, int left, int right) {
    for (int i = left + 1, j = i; i <= right; i++, j = i)
        while (j > left && arr[j] < arr[j - 1]) swap(arr[j], arr[j--]);
}
int main(){
    vector<int> arr = {1, 3, 2, 5, 4};
    insertionSort(arr, 0, arr.size() - 1);
    print_vec(arr);
    return 0;
}