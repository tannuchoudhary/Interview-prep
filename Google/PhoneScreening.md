# *Sorting algorithms*:

## 1. Selection sort
## 3. Bubble Sort

### a.) Brute Bubble sort

![Screenshot from 2021-09-26 13-03-16](https://user-images.githubusercontent.com/42698268/134798359-fa4507ff-7f34-47fb-bd8d-60829dcc323e.png)

This will run for ```O(n^2)``` even if the array is sorted, it can be optimized by implmenting a condition that, if swap doesn't work for one whole inner iteration then break

* Worst case TC is ```O(n^2)```
* Best case TC is ```O(n^2)```
* Space comp is ```O(1)```


![bubble-sort1](https://user-images.githubusercontent.com/42698268/134798365-d1d8880f-8b60-48c4-ad11-c92ed6d752c6.png)

### b.) Optimized bubble sort

it can be optimized by implmenting a condition that, if swap doesn't work for one whole inner iteration then break


![Screenshot from 2021-09-26 13-19-42](https://user-images.githubusercontent.com/42698268/134798795-d4b0421d-e4b6-4cac-a43f-65f4bff958f4.png)

* Worst case TC is ```O(n^2)```
* Best case TC is ```O(n)```
* Space comp is ```O(1)```
* ```In place sorting algo``` as no extra space is used
* ```Stable sorting algo``` as the elements with same value will be in same order in resultant array

*Uses*: Due to its simplicity, bubble sort is often used to introduce the concept of a sorting algorithm. 
In computer graphics it is popular for its capability to detect a very small error (like swap of just two elements) in almost-sorted arrays and fix it with just linear complexity (2n). For example, it is used in a polygon filling algorithm, where bounding lines are sorted by their x coordinate at a specific scan line (a line parallel to x axis) and with incrementing y their order changes (two elements are swapped) only at intersections of two lines
## 4. 
