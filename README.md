# SortingAlgorithmDemo
My Sorting Algorithm Demo Project

# 排序算法集合

## 项目介绍
此项目包含了多种常见排序算法的C++实现。目的是为了提供一个清晰、高效的代码库，用于教学、学习和实践排序算法。

## 包含的排序算法
项目中实现了以下排序算法：
- 冒泡排序 - Bubble Sort
- 选择排序 - Selection Sort
- 插入排序 - Insertion Sort
- 快速排序 - Quick Sort
- 归并排序 - Merge Sort
- 堆排序 - Heap Sort
- 希尔排序 - Shell Sort
- 计数排序 - Counting Sort
- 基数排序 - Radix Sort
- 桶排序 - Bucket Sort
- 混合排序 - Hybrid Sort

## 文件结构
- `src/`: 存放每种排序算法的源代码。
- `include/`: 存放所有的头文件。
- `obj/`: 存放编译过程中生成的对象文件。
- `bin/`: 存放编译后的可执行文件。

## 编译和运行
1. 克隆项目：
   ```bash
   git clone [项目仓库URL]
   cd [项目文件夹]

1. 编译项目：

```bash
make
```
这将在bin/目录下生成可执行文件。

2. 运行示例：
```bash
./bin/[排序算法对应的执行文件]
```
3. 全部运行
```
bash run.sh
```
# 清理项目
要清理项目（删除对象文件和可执行文件），运行：

```bash
make clean
```
# 贡献
欢迎对项目进行贡献。您可以通过提交问题或Pull Requests来提出改进建议或添加新功能。

# 许可
该项目根据MIT许可证发布。有关详细信息，请参阅LICENSE文件。


在这个`README.md`文件中，我简要介绍了项目的目的、包含的排序算法、文件结构以及如何编译和运行项目。同时，也提供了有关如何贡献和许可证信息的说明。请根据您的项目具体情况调整文件内容，如项目的具体URL、不同排序算法的执行文件名等。
---

# 备注
# Makefile编写规则
这个Makefile的工作流程如下：

编译器和标志：指定了使用的编译器（g++）以及编译时使用的标志（-Wall用于显示所有警告，-g用于添加调试信息）。

目录：定义了源文件（src）、对象文件（obj）和二进制文件（bin）的目录。

文件查找：使用wildcard函数查找src目录中的所有.cpp文件，并将它们映射到obj和bin目录中的.o文件和可执行文件。

默认目标：默认目标all依赖于所有的可执行文件。

规则：定义了如何从.cpp文件创建.o对象文件，以及如何从.o文件创建可执行文件。

目录创建：自动创建obj和bin目录。

清理：clean目标用于删除obj和bin目录及其内容，以便进行干净的重建。

Phony Targets：声明了all和clean为伪目标，以防止与同名文件发生冲突。

包含路径：通过CPPFLAGS := -I$(INC_DIR)添加了一个新的变量CPPFLAGS，用于指定包含路径。这里，-I$(INC_DIR)告诉编译器在include目录中查找头文件。

编译规则中的CPPFLAGS：在编译对象文件的规则中，$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@添加了$(CPPFLAGS)，以确保编译器在编译过程中使用正确的包含路径。

将此Makefile保存在与src、obj、bin目录同级的位置。然后，在命令行中运行make命令来构建项目，或运行make clean来清理构建文件。每个源文件将单独编译成其对应的对象文件和可执行文件。