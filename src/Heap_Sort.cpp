
#include "header.h"
template <typename T>
void heapSort(vector<T>& arr, int start, int end) {
    // 构建最大堆（make_heap）
    // 在这一阶段，从数组的中间位置开始向前遍历，处理每个非叶子节点。对于每个节点，如果它大于其父节点，则将其与父节点交换，直至满足最大堆的性质
    int mid = start + ((end - start + 1) >> 1);
    for (int i = end; i >= mid; i--) {
        int ind = i, parent = start + ((ind - start - 1) >> 1);
        while (ind > start && parent >= start) {
            if (arr[parent] < arr[ind]) swap(arr[parent], arr[ind]);
            ind = parent, parent = start + ((ind - start - 1) >> 1);
        }
    }
    // 执行排序（pop_heap）
    // 在排序阶段，不断将堆顶元素（即当前最大元素）与堆的最后一个元素交换，并减少堆的大小。每次交换后，它重新调整剩余的堆，以确保堆顶元素是最大的。
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