# [#0 STL short notes](https://www.hackerearth.com/practice/notes/standard-template-library/)

``` For each question, time complexity has to be told. ```

# [#1](https://www.geeksforgeeks.org/amazon-wow-interview-experience/)

# Ques 0 . [Infix to Postfix](https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/)

```
Precedence of operators
()
^     (right to left)
* /   (left to right)
+ -   (left to right)
```
```cpp

#include<bits/stdc++.h>
using namespace std;

//this will return the order of precedence of operator
int prec(char c){
    if(c=='^')
        return 3;
    else if(c == '/' || c == '*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else return -1;
}

void infixToPostfix(string s){
    //stack to store operators
    stack<char> st;
    //store answer
    string result;
    
    //iterate for all characters
    for(int i=0; i<s.length(); i++){
        char c = s[i];
        
        //if the current character is operand then add it in result
        if((c>='a' && c<= 'z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            //note down how we are concatinating characters using + operator in string
            result += c;
        }
        
        //if current char is opening bracket, push it in stack
        else if(c=='(')
            st.push('(');
        
        //if closing bracket, pop elements from stack and add it in result until opening bracket is not encountered
        else if(c == ')'){
            while(st.top() != '('){
                result += st.top();
                st.pop();
            }
            //pop the ;ast opening bracket present in stack
            st.pop();
        }
        
        //if the current char is operator
        else{
            //check if the precedence of operator is less than the precedence of operator already 
            //present in the stack and then pop it and add it in result
            
            //while popping if closing bracket will be encounered then prec function will return -1
            //for it i.e it has the least precedence, so we'll stop there
            while(!st.empty() && prec(s[i])<=prec(st.top())){
                result += st.top();
                st.pop();
            }
            //push the current character in stack
            st.push(c);
        }
    }
    
    //after coming out of while loop, add the remaining operators from stack to the result
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
        
    
    //print the result string
    cout<<result<<endl;
}

int main(){
    
    string expr = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(expr);
    return 0;
}

```
# Ques 1. [Program for Mean, median and mode of an unsorted array](geeksforgeeks.org/program-for-mean-and-median-of-an-unsorted-array/)

* Mean of an array = (sum of all elements) / (number of elements)
    * Mean can be found easily in O(n) by iterating through the loop and adding all elements and divide them by the size of the array

* Mode is the element having the most no of occurence or frequency
     * Mode can also be found easily using unordered_map


```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int ar[] = {1, 15, 6, 17, 8, 10, 19, 30, 15, 1, 1};
    
    
    //find mode
    
    unordered_map<int, int> freq;
    for(auto it : ar){
        freq[it]++;
    }
    
    int maxm = INT_MIN;
     int i=0;
     int num;
    for(auto it : freq){
        if(it.second>maxm){
            maxm = it.second;
            num = it.first;
        }
    }
    cout<<"Mode: "<<num;
    return 0;
}
```


* Median of a sorted array of size n is defined as the middle element when n is odd and average of middle two elements when n is even
    * To find median, we have 3 approaches
        * approach 1: sort the array and find the middle element or avg of middle two elements if no of elements are even
        * approach 2: If all the elements are unique then we can find it using set(by using the same approach as we use to  find the kth smallest element in an unsorted array, if the elements are unique)
        * approach 3: Use Min heap or Max heap i.e priority queue in c++ if elements are repeating.( build a min heap or max heap and insert all the elements and extract elements n/2 times, but it would also take O(n + nlogn), where n is for inserting and nlogn is for fetching n/2 elements.
 



## approach 02:
```cpp
/*approach 2: If all the elements are unique then we can find it using set(by using the same approach as we use to  find the kth smallest element in an unsorted array, if the elements are unique)*/
int main(){
    int ar[] = {1, 15, 6, 17, 8, 10, 19, 30, 15, 1, 1};
    
    //find median
    
    int n = sizeof(ar) / sizeof(ar[0]);
    int k = n/2;
    
    //if no of elements are odd then middle element in sorted array is mean
   
        
        //insert the array in set
        set<int> s(ar, ar+n);
        
        //set the iterator to the beginning
        set<int> :: iterator itr = s.begin();
        
        //advance the iterator to the k-1th position
        advance(itr, k-1);
        
        cout<<"Mean: "<<*itr<<endl;
    
}

```

``` Time Complexity:  O( log N) in Average Case and O(N) in Worst Case, as we know the Set in C++ STL is implemented using Binary Search Tree and we also know that the time complexity of all cases(searching , inserting, deleting ) in BST is log (n) in average case and O(n) in worst case.```




# Ques 2. [Alternate reversal of linked list in a group of size k. Like the first group should be reversed, the second group should be the same, the third should be reversed, the fourth should be the same, etc.](https://www.youtube.com/watch?v=Of0HPkk3JgI)

```
Example : 

Input : 1->2->3->4->5->6->7->8

k=2

Output : 2->1->3->4->6->5->7->8

```
apply the reversing of nodes of linked list in group of size k along with skipping k nodes each times after reversing the group:

![IMG20210911013012](https://user-images.githubusercontent.com/42698268/132911145-ff9f721a-5f4b-4fd8-b41c-325c79d24f8d.jpg)

## Code

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //if k is 1 or LL is empty then return original LL
        if(k==1 || head==NULL) return head;
        
        //delcare dummy node and point it to head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        //declare 3 dummy nodes
        ListNode *pre = dummy, *cur = dummy, *nex = dummy;
        int count = 0;
        
        //count the number of nodes
        while(cur->next!=NULL){
            cur = cur->next;
            count++;
        }
        
        //alt will help to skip the skipping very first time
        int alt = 1;
        
        while(count>=(k*2)){
            //set current = next of pre
            //set nex = next of current
            cur = pre->next;
            nex = cur->next;
            
            //skip every alternate group after the first iteration
             if(alt>1){
                 int skip = k;
                while(skip--){
                    pre = pre->next;
                    cur = cur->next;
                    nex = nex->next;
                }
                 //after skipping the group, decrease the size
                 count -= k;
            }
            
            //reverse the next group after skipping
            //the idea is to implement the reverse process k-1 times, it will help to reverse the group of k elements
            for(int i=1; i<k; i++){
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
                
            }
            //set the pre at the cur, for next iteration
            pre = cur;  
            //again decrease the size
            count -= k;
            alt++;
        }
        return dummy->next;
    }
};

```

# Ques 3. There are two strings given to find the matching and non-matching characters.

```
Example :

Input : s1 = abc s2 = abd 
Output : matching = 2 non-matching = 1
```
## Bruteforce
```
We have to traverse the first string and for each characters, find that character in the second string using find() operation of stl in strings.
This operation will take total of O(n1 * n2) where n1 is the size of the first string and n2 is the size of the second string
```

## better

```
sort both strings
take two pointers, keep ptr1 at start of first string and keep ptr2 at start of second string,
if characters match increase count by by 1 and increment both pointers
if they don't match then increment that pointer only which is pointing to the smaller character.
at last, no of matching characters = count, and non matching characters = length sf string - count

time complexity would be O(2n logn ) for sorting both strings and O(2n) for traversing both the strings in worst case, overall O(n logn) 

```


## Optimal

```
store the frequency of all characters of string 1 in hashmap and traverse the second string, if the character is in hashmap then increment the count by 1.
time complexity  = O(n) for putting everything in the hashmap and O(n) for traversing the second string
i.e O(2n) => O(n)
space comp: O(n) for hashmap

```

---------------------------------------------------------------------------------------------------------------------
# Ques 4. Reach from one start string to the destination string in a minimum number of steps provided some set of intermediate strings cannot be reached. The string consists of numbers starting from 0 to 9 and it works like a suitcase lock where from 0 there can be two options 1 or 9, similarly, from 1 we can go to 2 or 0. 

Hint: Use BFS constructing graphs of strings.

```
Input : 
Source = 123
Destination = 456
steps = 9
```
## My approach without using BFS
``` i don't know how to implement it using bfs ```
```
iterate through the first string and for each character find out whether going clockwise or anticlockwise would take minimum steps and add the min in the answer
if first string is ar[], and target array is t[] then

```
```cpp
int steps=0;
for(int i=0; i<n; i++){
    int minStep = min(t[i] - ar[i] , (a[i]+(10-t[i])));
    steps += minStep;
}
    
```

---------------------------------------------------------------------------------------------------------------------
# Ques 5: Find a maximum of the difference between maximum and minimum of all subarrays of size k.

## Soltuion:
## *There are four questions you should know before solving this question*
## Ques(i): Find all subarrays of an array

![Screenshot from 2021-09-14 00-06-21](https://user-images.githubusercontent.com/42698268/133139713-b0aba731-8146-4bbc-b150-33dd921f1136.png)

![Screenshot from 2021-09-14 00-19-48](https://user-images.githubusercontent.com/42698268/133140148-9756b5dc-309f-4539-8f01-3a888ffe7b51.png)


```O(n^3) solution ```
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int ar[] = {10, 20, 30, 40};
    int sz = sizeof(ar)/sizeof(ar[0]);
    
    for(int sp=0; sp<sz; sp++){
        for(int ep=sp; ep<sz; ep++){
            for(int cur=sp; cur<=ep; cur++){
                cout<<ar[cur]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
```

``` O(n^2) solution ```

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int ar[] = {10, 20, 30, 40};
    int sz = sizeof(ar)/sizeof(ar[0]);
    
    for(int sp=0; sp<sz; sp++){
        string st = "";
        for(int ep=sp; ep<sz; ep++){
            //convert integer to string
            st += to_string(ar[ep]);
            st += " ";
            cout<<st;
            cout<<endl;
        }
    }
    return 0;
}
```
## Ques(ii): Find all subarrays of an array of size k

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int ar[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int sz = sizeof(ar)/sizeof(ar[0]);
    int k=5;
    
    for(int sp=0; sp<sz-k+1; sp++){
        
        for(int ep=sp; ep<(sp+k); ep++){
                cout<<ar[ep]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
```
## Ques(iii): using Sliding window concept find the maximums from the subarray of size k from an array(striver question sliding window maximum)

![Screenshot from 2021-09-16 15-38-55](https://user-images.githubusercontent.com/42698268/133594029-85f55db1-55c2-4b8f-a6d6-d6e562a1ae05.png)


### Brute solution
![Screenshot from 2021-09-16 15-41-09](https://user-images.githubusercontent.com/42698268/133598775-9d18a339-1ea4-4677-9b5d-e7ac1b58e913.png)

### Optimal Solution

![Screenshot from 2021-09-16 16-11-09](https://user-images.githubusercontent.com/42698268/133598880-c1f7e65c-d2ab-4505-ac1b-2abbc424b389.png)

![Screenshot from 2021-09-16 16-15-40](https://user-images.githubusercontent.com/42698268/133599246-8ac3fb3d-73fd-46ed-91be-3ac8c7014893.png)

### steps:
* create a dequeue and an answer array
* Iterate through the array
* check if the front of dequeue is out of bound i.e beyond the size k, i.e, dq.front() == i-k, then pop the front element
* now iterate in the dequeue and find out if any of the element is smaller then the current element then pop it out, because if any of the element is smmaller then the current element then there is no need to keep them as someone is there who has the largest value and as we are finding the maximum then only this element will be considered.
* Now push the current element into dequeue
* Now if i>=k-1 then push the maximum element i.e the front element into the answer 

![Screenshot from 2021-09-16 16-48-00](https://user-images.githubusercontent.com/42698268/133609064-2c3510d9-e454-4a41-853e-b4f577519cad.png)


![Screenshot from 2021-09-16 16-49-51](https://user-images.githubusercontent.com/42698268/133609038-c551d18e-d446-42c4-a40d-53ea5bf5d46e.png)

### Code
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++){
            if(!dq.empty() && dq.front() == i-k) //check out of bound elements at front and push them out
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<nums[i]) // check if any of the element in the deque is lesser than the current element then pop it out
                dq.pop_back();
            
            dq.push_back(i);//push the current element index in deque
            if(i>=k-1) ans.push_back(nums[dq.front()]);//psuh the answer in ans vector, i.e the front of deque because front of deque is maximum
        }
        
        return ans;
    }
};

```



* Time complexity is ``` O(N) + O(N) ``` , as first O(N) is for traversing all the elements and the second O(N) is for removing those elements which are out of bound ech time, so throughout the iteration, total of n elements would be removed in worst case, so the time complexity is O(2N) which is eventually O(N)
* Space complexity is ``` O(K) ``` which is taking by dequeue, for storing the k elements at a time in decreasing order to fetch the maximum element.

# [#2](https://www.geeksforgeeks.org/amazon-interview-experience-amazewow-2020/)

# Ques 4.
# Ques 5. type of traversals in trees
# Ques 6. is there anyway to reconstruct the tree using these traversals.
# Ques 7. He then asked is there any exception to reconstruct tree using only one type of traversal. The answer was BST which was my coding question as- [Construct the binary search tree using given preorder traversal](https://www.geeksforgeeks.org/construct-a-special-tree-from-given-preorder-traversal/).


# Ques 8: some basic paradigms of OOPCs , following with the difference between run time polymorphism and compile time polymorphism

# Ques 9: [Find k closest elements to a given value](https://www.geeksforgeeks.org/find-k-closest-elements-given-value/) with first O(n) then the optimised one with O(logn+k).


# [#3](https://www.geeksforgeeks.org/amazon-interview-experience-for-fte-sde-internship-amazewow/?ref=rp)

# Ques 10: [Queue based approach for first non-repeating character in a stream.](https://www.geeksforgeeks.org/queue-based-approach-for-first-non-repeating-character-in-a-stream/)

# Ques 11: Output the leaves of a tree in the first line, then output the nodes which will become leaves after removing the current leaves in the next line. We had to repeat this process until the tree was empty. This can be done by storing the height of each node. Output the nodes in ascending order of heights.

```He asked me the time and space complexities at each and every step. He also asked me to check my codes for edge cases.```

```Know the time and space complexities of every piece of code you write.```


# Ques 12: There is a stream of numbers scattered in memory, and we need to find out the frequency of corrupted data. Corrupted data resembles a given pattern. (Not sure if this was the exact question. It was a bit confusing.)

# Ques 13: This problem was a variation of one of the most famous Graphs problems, the Number of Islands. We’re given a 2D matrix of 0’s and 1’s, where 1 represents land, and 0 represents water. All the 1’s together represent an island. So, we need to find out:

* The number of islands
* The size of the largest island
* Number of islands nearest to a given coordinate

```Understand the problem completely: If you don’t get the question, ask the interviewer twice or thrice until you get the question correctly.```

```Keep talking: During the whole interview, you should be talking to the interviewer because if you stay silent, the interviewer won’t understand your thought process.```
```Comment your code: For every line of code, write short comments for your and interviewer’s ease.```
``` Always review your code: When you’re done with your coding, try to explain the algorithm with a sample test case and perform the complete dry run.```
# [#4](https://medium.com/@saismitapanda09/amazewow-interview-experience-and-preparation-guidelines-1dfb49795185)

# [#5](https://www.codingninjas.com/codestudio/interview-experiences/amazon-interview-experience-by-khushboo-jaisinghani-off-campus-may-2020-190)

# ques 14: Students are standing in the row. given an input of weights of children find the position of a child, such that all students lighter to him are in his left and the ones heavier than him are in his right.

# ques 15: Transform BST to greater sum tree

# ques 16: You have been given a binary tree of 'N' unique nodes and a Start node from where the tree will start to burn. Given that the Start node will always exist in the tree, your task is to print the time (in minutes) that it will take to burn the whole tree.

# ques 17: Distance between nodes of a binary tree

# [#6](https://www.geeksforgeeks.org/amazon-interview-experience-for-sde-internship-amazewow-2020/?ref=rp)
# ques 18: [Find the longest substring containing distinct characters.](https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/) 
```
Input: abbabcdd
Output: 4
```

# Ques 19: Given preorder and pre_LN that contains whether the node is leaf nodes or not,  construct a binary tree. 

# ques 20: A bag contains magic balls.  Each ball has a specific weight.  Every time, balls with two highest weight are removed (let the balls be X and Y) and collision which may or may not result in a new ball following the given constraints 

# ques 21: There are n workers, each having some capacity. The workers are given rotis based on their capacity,  i.e workers with a higher rating will get a more number of rotis. A worker can only know the rotis and capacity of two of his neighbors, one on the left and other on the right. Given an array specifying the capacity of workers, find the minimum rotis that should be given for each worker,  so that no worker feels unfair

# [#7](https://www.geeksforgeeks.org/amazon-interview-experience-for-sde-1-fte-6-months-internship-amazewow/?ref=rp)

# ques 22: [Rearrange characters in a string such that no two adjacent are same](https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/)

# ques 23: Given 2 strings of numbers, I was asked to add them

# ques 24: [Path in a Rectangle with Circles I was required to print the path](https://www.geeksforgeeks.org/path-rectangle-containing-circles/).

# ques 25: [Box Stacking Problem](https://www.geeksforgeeks.org/box-stacking-problem-dp-22/) (But there was an assumption that we have the only box of each dimension.)

# ques 26: A person is standing at floor ‘A’ and wants to go floor ‘B’ using a lift. A lift can either go x floors up and y floors down. I was supposed to tell the minimum number of steps.


# [#8](https://www.geeksforgeeks.org/amazon-interview-experience-for-fte-6-months-sde-1-internship-amazewow/?ref=rp)

# [#9](https://www.geeksforgeeks.org/amazon-sde-1-fte-6-months-internship-experience-amazewow-2021/?ref=rp)

# [#10](https://www.geeksforgeeks.org/amazon-interview-experience-off-campus-amazewow/?ref=rp)

# [#11](https://www.geeksforgeeks.org/amazon-interview-experience-6-months-internship-off-campus/?ref=rp)

# [#12](https://www.geeksforgeeks.org/amazon-interview-experience-2-months-internship/?ref=rp)

# [#13](https://www.geeksforgeeks.org/amazon-interview-experience-2-months-internship/?ref=rp)

# [#14](https://www.geeksforgeeks.org/amazon-interview-experience-off-campus-amazewow/?ref=rp)

# [#15](https://www.geeksforgeeks.org/amazon-sde-1-fte-6-months-internship-experience-amazewow-2021/?ref=rp)

# [#16](https://www.geeksforgeeks.org/amazon-interview-experience-off-campus-amazewow/)


# [#17](https://www.geeksforgeeks.org/amazon-interview-experience-for-sde-internship-amazewow-2020/)

# [#18](https://www.geeksforgeeks.org/amazon-sde-1-fte-6-months-internship-experience-amazewow-2021/?ref=rp)

# [#19](https://www.geeksforgeeks.org/amazon-interview-experience-sde-1-offcampus/?ref=rp)

# [#12]()














# CS  fundamentals
# ques 1: In the first question of CS fundamentals, I was to perform Database Normalisation. In the second question, I was given a program in which I had to state whether the program would encounter a deadlock situation. If yes, how can you prevent the same with modifications in the code?

# ques 2: 2 Behavioral questions were also asked, behavioural questions at amazon interviews are primarily focused on their [leadership principles](https://www.amazon.jobs/en-gb/principles)

# ques 3: prepare these topics: [link](https://www.amazon.jobs/en-gb/landing_pages/software-development-topics)




# Coding Round Problems:
* [Counting Inversions](https://www.geeksforgeeks.org/counting-inversions)
* [No of ways to get a given sum with n no of m faced dices](https://www.geeksforgeeks.org/number-of-ways-to-get-a-given-sum-with-n-number-of-m-faced-dices/ )
* Longest Palindromic Substring: Standard DP question.
* Find the most frequently occurring word in a sentence that is not in a given list of banned words: Divide the sentence into a stream of words, then use a hashmap to keep the count of the number of occurrences of each word that is not in the list of banned words and print the words from the hashmap with the maximum count.
* most common Dynamic Programming problems: Longest decreasing sub-sequence.
* find out the mean, median, and mode in an array.
* Longest decreasing subsequence: You are given an array/list ARR consisting of N integers. Your task is to find the length of the longest decreasing subsequence.
* Next greater element: You are given an array: You are given an array arr of length N. You have to return a list of integers containing the NGE(next greater element) of each element of the given array.
* 

# SIEVE OF ERATOSTHENES
```cpp
#include<bits/stdc++.h>
using namespace std;
int n=1000;
//if ar[i] contains 0, then i is prime
//if ar[i] contains 1, then i is not prime

//array a is filled with numbers 0 and 1, each posiiton will tll whether i is prime or not
//basically this array will give you all the prime no.s if you will print that element of "a"
//which contains 0
void seive(int a[]){
    //all even numbers are non prime
   for(int i=0; i<=n; i+=2){
       a[i] = 1;
   }
   
   //1 is neither prime nor composite
   a[1] = 1;
   //2 is prime
   a[2] = 0;
   
   for(int i=3; i<=n; i+=2){
       //if the no is already marked as non prime then no neeed to check that
       //mark all the multiples of i as non prime if they are marked as prime
       if(a[i] == 0){
           for(int j=i*i; j<=n; j+=i){
               //marked multiple as non prime
               a[j] = 1;
           }
       }
   }
}
int main(){
    int a[n] = {0};
    seive(a);
    for(int i = 0; i<n; i++){
        if(a[i] == 0)
        cout<<i<<" ";
    }
    return 0;
}
```
