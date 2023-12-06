#include "header.h"
// 归并排序
template <typename T>
void mergeTwoIntervals(vector<T>& arr, int l1, int r1, int l2, int r2) {
    int i = l1, j = l2, k = 0;
    vector<T> temp(r2 - l1 + 1);
    while (i <= r1 || j <= r2)
        temp[k++] = (j > r2 || (i <= r1 && arr[i] < arr[j])) ? arr[i++] : arr[j++];
    memcpy((char *)(arr.data() + l1), (char *)temp.data(), temp.size()*sizeof(int));
}
template <typename T>
void mergeSort(vector<T>& arr, int start, int end) {
    if (start >= end) return ;
    int mid = (start + end) >> 1;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    mergeTwoIntervals(arr, start, mid, mid + 1, end);
}


int main(){
    vector<int> arr = {1, 3, 2, 5, 4};
    mergeSort(arr, 0, arr.size() - 1);
    print_vec(arr);
    return 0;
}