# Simple Sorting Algorithm

## Description
This repository is an implementation of three simple sorting algorithms: Bubble Sort, Selection Sort, and Insertion Sort in C. This program will generate 1 million random integer numbers. The numbers are sorted by bubble sort, selection sort and insertion sort and the unsorted and sorted numbers will be saved into a .txt file.

## How to run the program code

1. Make sure you have the C compiler installed on your system.
2. Clone this repository or download the file 
3. Compile the code using the following command:
   
   ```bash
   gcc 2208107010044_Simple_Sorting.c -o sorting
   ```
   
4. Run the compiled result:
   
   ```bash
   ./sorting
   ```
   
5. The program will produce an output file in the `output` folder containing the numbers sorted by algorithm type and number.

## Functions in the Program Code

### 1. `saveToFile`
   - Function to save the array into a text file.
   - Parameters:
     - `arr`: An array of integer numbers to be saved.
     - `n`: The number of elements in the array.
     - `filename`: The name of the destination file.

### 2. `bubbleSort`
   - Function to perform Bubble Sort on the array.
   - Parameters:
     - `arr`: An array of integer numbers to be sorted.
     - `n`: The number of elements in the array.
     - `filename`: The name of the file to store the sort result.

### 3. `selectionSort`
   - Function to perform Selection Sort on the array.
   - Parameters:
     - `arr`: An array of integer numbers to be sorted.
     - `n`: The number of elements in the array.
     - `filename`: The name of the file to store the sort result.

### 4. `insertionSort`
   - Function to perform Insertion Sort on the array.
   - Parameters:
     - `arr`: An array of integer numbers to be sorted.
     - `n`: The number of elements in the array.
     - `filename`: The name of the file to save the sort result.

### 5. `printTableBorder`
   - The function to print the table border on the output.

### 6. `main`
   - The main function that initializes variables, generates random numbers, saves to the input file, performs sorting, and prints the execution time result on the table.

## Demonstration video
(https://youtu.be/zBETZBZkH7o).

