
#include "header.h"
#include <vector>
#include <map>
#include <algorithm>
// 计数排序
void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    vector<int> count(maxVal + 1, 0), output(arr.size());

    // Count each element
    for (int num : arr) {
        count[num]++;
    }

    // Cumulative count
    for (int i = 1; i <= maxVal; ++i) {
        count[i] += count[i - 1];
    }

    // Place the elements in sorted order
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements into original array
    // for (int i = 0; i < arr.size(); i++) {
    //     arr[i] = output[i];
    // }
    memcpy(arr.data(), output.data(), arr.size() * sizeof(int));
}

void countingSortWithMap(vector<int>& arr) {
    std::map<int, int> count;
    vector<int> output(arr.size());

    // Count each element
    for (int num : arr) {
        count[num]++;
    }

    // Cumulative count
    int total = 0;
    for (auto& pair : count) {
        total += pair.second;
        pair.second = total;
    }

    // Place the elements in sorted order
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements into original array
    memcpy(arr.data(), output.data(), arr.size() * sizeof(int));
}

int main() {
    vector<int> arr = {1, 4, 1, 2, 7, 5, 2};
    countingSort(arr);
    print_vec(arr);
    
    vector<int> arr2 = {1, 4, 1, 2, 7, 5, 2};
    countingSortWithMap(arr2);
    print_vec(arr2);

    return 0;
}