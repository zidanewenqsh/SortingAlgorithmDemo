#include "header.h"
// 希尔排序
template <typename T>
void shellSort(vector<T>& arr, int start, int end) {
    // Increment 表示排序过程中的间隔，初始为数组长度的一半
    for (int increment = (end - start + 1) >> 1; increment > 0; increment >>= 1) {
        // 从第 increment 个元素开始，向后遍历数组
        for (int i = increment, j = i; i <= end; i++, j = i) {
            // 内层循环：对于每个 i，将 arr[i] 向前移动到正确的位置
            while (j >= start + increment && arr[j] < arr[j - increment]) {
                // 当前元素小于间隔 increment 处的元素时，交换它们
                swap(arr[j -= increment], arr[j]);
            }
        }
    }
}

int main() {
    vector<float> arr = {1, 3, 2, 5, 4};
    shellSort(arr, 0, arr.size() - 1);
    print_vec(arr);
    return 0;
}