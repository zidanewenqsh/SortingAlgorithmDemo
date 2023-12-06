#include "header.h"

// 混合排序
// 插入排序
template <typename T>
void insertionSort(vector<T>& arr, int left, int right) {
    for (int i = left + 1, j = i; i <= right; i++, j = i)
        while (j > left && arr[j] < arr[j - 1]) swap(arr[j], arr[j--]);
}

// 堆排序
/*heapify 函数：此函数是堆排序的核心。它确保以索引 i 为根的子树符合最大堆的性质。如果子节点的值大于其父节点的值，该函数会递归地调整堆。
 *heapSort 函数：这个函数首先通过调用 heapify 函数从无序数组创建最大堆。一旦堆构建完成，它将堆的根（即最大元素）与堆的最后一个元素交换，并减少堆的大小，然后再次调用 heapify 来恢复最大堆的性质。这个过程重复进行，直到堆的大小为 1。
 *构建最大堆：开始时，heapSort 从最后一个非叶子节点开始向上构建最大堆。
 *排序：每次循环都将当前最大元素（堆顶元素）移动到数组末尾（即堆的外部），然后在减小的堆上重新运行 heapify，以确保最大元素总是位于堆顶。
*/

// 堆排序的辅助函数
template <typename T>
void heapify(std::vector<T>& arr, int n, int i) {
    int largest = i; // 初始化最大元素为当前节点
    int left = 2 * i + 1; // 计算左子节点的索引
    int right = 2 * i + 2; // 计算右子节点的索引

    // 检查左子节点是否存在并且是否大于当前最大元素
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 检查右子节点是否存在并且是否大于当前最大元素
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大元素不是当前节点，交换它们，并递归地调整被交换的子树
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// 堆排序
template <typename T>
void heapSort(std::vector<T>& arr, int start, int end) {
    int n = end - start + 1; // 计算堆的大小

    // 构建最大堆
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    // 一个个从堆顶取出元素，然后重新调整堆
    for (int i = n - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]); // 将当前最大元素移到数组末尾
        heapify(arr, i, 0); // 调整剩余数组，使其成为最大堆
    }
}


// 快速排序
// 分区函数
template <typename T>
int partition(std::vector<T>& arr, int start, int end) {
    T pivot = arr[(start + end) / 2]; // 选择中间的元素作为枢轴
    int l = start, r = end;

    while (l <= r) {
        while (arr[l] < pivot) l++;  // 从左侧找到第一个不小于枢轴的元素
        while (arr[r] > pivot) r--;  // 从右侧找到第一个不大于枢轴的元素

        if (l <= r) {
            std::swap(arr[l], arr[r]);  // 交换这两个元素
            l++;
            r--;
        }
    }

    return l; // 返回分区后的分界点
}

// 快速排序
template <typename T>
void quickSort(std::vector<T>& arr, int start, int end, int depthLimit) {
    if (start < end) {
        if (end - start < 16) { // 小数组使用插入排序
            insertionSort(arr, start, end);
        } else if (depthLimit == 0) { // 深度限制达到时使用堆排序
            heapSort(arr, start, end);
        } else {
            int l = partition(arr, start, end); // 快速排序的分区操作
            quickSort(arr, start, l - 1, depthLimit - 1);
            quickSort(arr, l, end, depthLimit - 1);
        }
    }
}


// 组合排序
template <typename T>
void hybridSort(std::vector<T>& arr) {
    int maxDepth = log(arr.size()) * 2;
    quickSort(arr, 0, arr.size() - 1, maxDepth);
}


int main() {
    // 生成随机数
    srand(static_cast<unsigned int>(time(0))); // 初始化随机数生成器
    std::vector<int> testArray;
    for (int i = 0; i < 30; ++i) {
        testArray.push_back(rand() % 100); // 生成0到99之间的随机数
    }

    // 打印未排序的数组
    std::cout << "Original array:\n";
    for (int i : testArray) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    // 使用混合排序
    hybridSort(testArray);

    // 打印排序后的数组
    std::cout << "Sorted array:\n";
    for (int i : testArray) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}
