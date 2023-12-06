#include "header.h"
// 桶排序
template <typename T>
void bucketSort(vector<T> &arr) {
    int n = arr.size();
    vector<float> b[n];

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; // Index in bucket
        b[bi].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(b[i].begin(), b[i].end());
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float v : b[i]) {
            arr[index++] = v;
        }
    }
}

int main() {
    vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    bucketSort(arr);
    print_vec(arr);
    return 0;
}