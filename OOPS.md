# 1. [40 OOPS Interview Questions](https://www.interviewbit.com/oops-interview-questions/) .


# 2. Multithreading
* Multithreading is a process of executing multiple threads simultaneously. A thread is a lightweight sub-process, the smallest unit of processing
* Multithreading is a specialized form of multitasking and a multitasking is the feature that allows your computer to run two or more programs concurrently

## Advantages of Java Multithreading
1) It doesn't block the user because threads are independent and you can perform multiple operations at the same time.

2) You can perform many operations together, so it saves time.

3) Threads are independent, so it doesn't affect other threads if an exception occurs in a single thread., as it uses a shared memory area.



# 3. Multitasking
Multitasking is a process of executing multiple tasks simultaneously. We use multitasking to utilize the CPU. Multitasking can be achieved in two ways:
  * Process-based Multitasking (Multiprocessing)
  * Thread-based Multitasking (Multithreading)

# 4. Multiprocessing vs Multithreading

## 1) Process-based Multitasking (Multiprocessing)
Each process has an address in memory. In other words, each process allocates a separate memory area.
  * A process is heavyweight.
  * Cost of communication between the process is high.
  * Switching from one process to another requires some time for saving and loading registers, memory maps, updating lists, etc.
## 2) Thread-based Multitasking (Multithreading)
  * Threads share the same address space.
  * A thread is lightweight.
  * Cost of communication between the thread is low.
  
# 5. Templates

## definition: Function aur class ko generalize krne ka tareeka h template.
![Screenshot from 2021-09-08 02-01-58](https://user-images.githubusercontent.com/42698268/132408890-46540e26-4229-4c50-9c03-d111ba035c60.png)

![Screenshot from 2021-09-08 02-02-33](https://user-images.githubusercontent.com/42698268/132408906-aa6e976e-f6c6-4cf0-898d-b8956fb3195b.png)


## Function Template

![Screenshot from 2021-09-08 02-25-27](https://user-images.githubusercontent.com/42698268/132410251-874ce7e2-cc02-49e9-bc3b-3f3685efcd1e.png)


If we want to caluclate the maxm of two integers as well as maximum of two double values, then we have to overload a function i.e create two function definitions having same name but different data types, but we have other method also which will reduce our work.

Whenever the whole code is same, number of parameters are same, the only difference is the type of parameter then we don't overload the function, instead we'll create a template which would be generalized for all data types, this is called ***Function template***, function template is also known as generalized function
```cpp
#include<bits/stdc++.h>
using namespace std;

// this is how we create function template
// X is place holder, i.e can be replaced with any data type
//compiler will convert X with required data type
template <class X> X maxm(X a, X b){
    if(a>b) return a;
    else return b;
}
int main(){
    
    cout<<maxm(2, 3)<<",";
    cout<<maxm(5.7, 5.4);
    
    return 0;
}
```
```output: 3, 5.7 ```

Now what if I want one parameter to be of int type and other to be of double type, then we have to define two different kind of placeholders like this

```cpp
#include<bits/stdc++.h>
using namespace std;

// this is how we create function template
// X is place holder,  i.e can be replaced with any data type
//compiler will convert X with required data type
template <class X, class Y> Y maxm(X a, Y b){
    if(a>b) return a;
    else return b;
}
int main(){
    
    
    cout<<maxm(5, 5.4);
    
    return 0;
}
```
```output: 5.4```

## Class Template

