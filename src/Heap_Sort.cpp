
#include "header.h"
template <typename T>
void heapSort(vector<T>& arr, int start, int end) {
    // make_heap
    int mid = start + ((end - start + 1) >> 1);
    for (int i = end; i >= mid; i--) {
        int ind = i, parent = start + ((ind - start - 1) >> 1);
        while (ind > start && parent >= start) {
            if (arr[parent] < arr[ind]) swap(arr[parent], arr[ind]);
            ind = parent, parent = start + ((ind - start - 1) >> 1);
        }
    }
    // pop_heap
    // end = (end - start);
    while (end > start) {
        swap(arr[start], arr[end--]); // pop
        int ind = start, child = start + ((ind - start) << 1) + 1;
        while (child <= end) {
            if (child < end && arr[child] < arr[child + 1]) child++;
            if (arr[ind] < arr[child]) swap(arr[ind], arr[child]);
            else break;
            ind = child, child = start + ((ind - start) << 1) + 1;
        }
    }
}

int main(){
    vector<int> arr = {1, 3, 2, 5, 4};
    heapSort(arr, 0, arr.size() - 1);
    print_vec(arr);
    return 0;
}