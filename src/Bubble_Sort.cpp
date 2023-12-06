#include "header.h"
// 冒泡排序
template <typename T>
void bubbleSort(vector<T>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
//        cout << arr.size() - 1 - i << endl;
        for (int j = 0; j < arr.size() - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
int main () {
    vector<int> arr = {1, 3, 2, 5, 4};
    bubbleSort(arr);
    print_vec(arr);
    return 0;
}