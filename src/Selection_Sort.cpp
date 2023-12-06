
#include "header.h"
// 选择排序
template <typename T>
void selectionSort(vector<T>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}
int main(){
    vector<int> arr = {1, 3, 2, 5, 4};
    selectionSort(arr);
    print_vec(arr);
    return 0;
}