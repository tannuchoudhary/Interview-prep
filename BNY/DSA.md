# 1. [Decimal Equivalent of Binary Linked List](https://www.geeksforgeeks.org/decimal-equivalent-of-binary-linked-list/)

## My approach(01): 
Take two pointers, traverse both of them until all the initial zero passed and then move first pointer upto the end to calculate the size of the LL and then start moving the second pointer and along with that, keep caluclating the value by ```ans += pow(2, size) * head->value```

## Aprroach 02
traverse and just do this ``` ans = ans*2 + head->data ```, it will add 0 until all the initial zeroes will pass and when it will start adding numbers, then it will multiply it by 2 each time, giving the correct result

## code
```cpp
long long unsigned int decimalValue(Node *head)
{
   long long unsigned int ans = 0;
   while(head!=NULL){
       ans = ((ans * 2)%1000000007 + (head->data));
       
       head = head->next;
   }
   return ans;
}
```

# 2. [Bubble Sort](https://www.geeksforgeeks.org/bubble-sort/)


```cpp
void bubbleSort(int arr[], int n)
{
    // Your code here    
    int flag = 0;
    for(int i=0; i<n-1; i++){
        flag = 0;
        for(int j=0; j<(n-i-1); j++){
            if(arr[j] > arr[j+1]){
                flag = 1;
                swap(&arr[j], &arr[j+1]);
            }
        }
        if(flag == 0) break;
    }
}
```
# 3. Which data structure is used to implement auto-complete feature

Ans : Autocomplete is a feature of suggesting possible extensions to a partially written text and is widely used in search engine, code IDEs and much more. Trie data structure is a perfect fit to implement this feature efficient in terms of memory and time [O(length of string)].

# 4. [Trie Implementation (from techdose)](https://www.youtube.com/playlist?list=PLEJXowNB4kPyi859E6qGUs7jlpQehJndl)

## 1. Basics of Trie
-------------------------
###  Intro
      * Trie is exactly like binary tree, but instead of two child for each node, it can have n nodes
      * Trie is an n-ary tree
      
Structure of trie node:

![Screenshot from 2021-10-17 13-50-26](https://user-images.githubusercontent.com/42698268/137624712-1955d9cd-2c41-4c28-9342-031910b5d3c0.png)

Making dictionary using trie:

![Screenshot from 2021-10-17 13-54-17](https://user-images.githubusercontent.com/42698268/137624720-e085cbcb-3409-4604-88e7-e4ee4e0083ec.png)



      
###  Uses of trie data structure:

#### 1. Used in Dictionary to
      * Store words
      * Search words
      * Remove words
   
#### 2. Search a word in O(length of word) time

#### 3. used in finding prefixes
#### 4. Very Ordered and clean data structure




























