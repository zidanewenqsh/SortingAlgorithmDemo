import os

def create_sorting_algorithm_files(src_directory):
    # List of sorting algorithm names
    sorting_algorithms = [
        "Bubble Sort",
        "Selection Sort",
        "Insertion Sort",
        "Quick Sort",
        "Merge Sort",
        "Heap Sort",
        "Shell Sort",
        "Counting Sort",
        "Radix Sort",
        "Bucket Sort"
    ]

    # Check if src directory exists, create if not
    if not os.path.exists(src_directory):
        os.makedirs(src_directory)

    # Create empty .cpp files for each sorting algorithm
    for algo in sorting_algorithms:
        file_name = algo.replace(" ", "_") + ".cpp"
        file_path = os.path.join(src_directory, file_name)
        print(file_path)
        with open(file_path, 'w') as file:
            # File is created empty, ready for your content
            pass

    print(f"Files created in {src_directory}")

# Example usage
src_directory = "src"  # Replace with your desired path
create_sorting_algorithm_files(src_directory)
