# *Sorting algorithms*:

## 1. Selection sort

*The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.
1) The subarray which is already sorted. 
2) Remaining subarray which is unsorted.
In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.*

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

*Use:* The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation. 

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
* ```In place sorting algo``` as no extra space is used
* ```Stable sorting algo``` as two objects with equal or same keys appear in the same order in sorted output

*Uses*: Due to its simplicity, bubble sort is often used to introduce the concept of a sorting algorithm. 
In computer graphics it is popular for its capability to detect a very small error (like swap of just two elements) in almost-sorted arrays and fix it with just linear complexity (2n). For example, it is used in a polygon filling algorithm, where bounding lines are sorted by their x coordinate at a specific scan line (a line parallel to x axis) and with incrementing y their order changes (two elements are swapped) only at intersections of two lines
## 4. 
