# *Sorting algorithms*:

## 1. Selection sort

*The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning.*
The algorithm maintains two subarrays in a given array.
1. The subarray which is already sorted.
2. Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

```cpp
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
```

Time Complexity: ```O(n^2)``` as there are two nested loops.
Auxiliary Space: ```O(1)```
In Place: ```Yes```
Stable: ```No```(The  default implementation is not stable, but it can be made stable)

*Use:* The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation. 

## 2. Insertion sort

*Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.*

Algorithm
To sort an array of size n in ascending order: 
1. Iterate from arr[1] to arr[n] over the array. 
2. Compare the current element (key) to its predecessor. 
3. If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.
![insertionsort](https://user-images.githubusercontent.com/42698268/134842931-05899664-f5cf-4864-914e-2392256bdfd0.png)


```cpp
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
```

* Time Complexity: ```O(n^2)```
* Auxiliary Space: ```1O(1)```
* In Place: ```Yes```
* Stable: ```Yes```

Uses: *Insertion sort is used when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.*

## 3. Bubble Sort

*Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.*

### a.) Brute Bubble sort

```cpp
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
     
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}
```
This will run for ```O(n^2)``` even if the array is sorted, it can be optimized by implmenting a condition that, if swap doesn't work for one whole inner iteration then break

* Worst case TC is ```O(n^2)```
* Best case TC is ```O(n^2)```
* Space comp is ```O(1)```


![bubble-sort1](https://user-images.githubusercontent.com/42698268/134798365-d1d8880f-8b60-48c4-ad11-c92ed6d752c6.png)

### b.) Optimized bubble sort

it can be optimized by implmenting a condition that, if swap doesn't work for one whole inner iteration then break


```cpp
// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }
 
     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
}
```

* Worst case TC is ```O(n^2)```
* Best case TC is ```O(n)```
* Space comp is ```O(1)```
* In place : ```Yes``` (as no extra space is used)
* Stable : ```yes``` (as two objects with equal or same keys appear in the same order in sorted output)

*Uses*: Due to its simplicity, bubble sort is often used to introduce the concept of a sorting algorithm. 
In computer graphics it is popular for its capability to detect a very small error (like swap of just two elements) in almost-sorted arrays and fix it with just linear complexity (2n). For example, it is used in a polygon filling algorithm, where bounding lines are sorted by their x coordinate at a specific scan line (a line parallel to x axis) and with incrementing y their order changes (two elements are swapped) only at intersections of two lines

## 4. Shell sort

## 5. Merge Sort

## 6. Quick Sort

## 7. Heap Sort

# Chart

![1_wv3W3jYq7EHCDiwYVaCXrA](https://user-images.githubusercontent.com/42698268/136614156-be962f99-b26c-4a2c-9e26-b3929e166d4b.png)

# [Website](https://algs4.cs.princeton.edu/cheatsheet/): This has helped me so much






