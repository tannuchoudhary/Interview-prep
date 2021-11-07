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
When you are creating a class, you need to create different class for different kinds of data types, for e.g if I have created a class which is creating array and assigning values in the array and displaying them, if I want to create this for int and float then I have to write it two times, but if i will declare the class as template and replace the datatypes with place holder then it will work for all data types.

Basically class template is to make the class generic, so it can accept any datatype and we don't need to create different classes of different datatypes for the same work.

![Screenshot from 2021-09-08 02-32-13](https://user-images.githubusercontent.com/42698268/132455710-3b0377f4-e075-4534-932a-e0323a5c824a.png)

## For integer
```cpp
#include<bits/stdc++.h>
using namespace std;

class arrayList{
    private:
        struct controlBlock{
          int capacity;
          int *arr_ptr;
        };
        
        controlBlock *s;
        
    public:
        arrayList(int capacity){
            s = new controlBlock;
            s->capacity = capacity;
            s->arr_ptr = new int[s->capacity];
        }
        
        void addElement(int index, int data){
            if(index>=0 && index<=s->capacity-1){
                s->arr_ptr[index] = data;
            }
            else cout<<endl<<"Array index is not valid";
        }
        
        //passing the reference to store the data in reference variable data
        void viewElement(int index, int &data){
            if(index>=0 && index<=s->capacity-1){
               data = s->arr_ptr[index];
            }
            else cout<<endl<<"Array index is not valid";
        }
        
        void viewList(){
            int i;
            for(i=0; i<s->capacity; i++){
                cout<<" "<<s->arr_ptr[i];
            }
        }
    
};

int main(){
    int data;
    arrayList list1(4);
    list1.addElement(0, 25.6);
    list1.viewElement(0, data);
    cout<<"Value in the array is "<<data;
    return 0;
}


```
## For general using template

```cpp
#include<bits/stdc++.h>
using namespace std;
//syntax
template<class X> class arrayList{
    private:
        struct controlBlock{
          int capacity;
          X *arr_ptr;
        };
        
        controlBlock *s;
        
    public:
        arrayList(int capacity){
            s = new controlBlock;
            s->capacity = capacity;
            s->arr_ptr = new X[s->capacity];
        }
        
        void addElement(int index, X data){
            if(index>=0 && index<=s->capacity-1){
                s->arr_ptr[index] = data;
            }
            else cout<<endl<<"Array index is not valid";
        }
        
        //passing the reference to store the data in reference variable data
        void viewElement(int index, X &data){
            if(index>=0 && index<=s->capacity-1){
               data = s->arr_ptr[index];
            }
            else cout<<endl<<"Array index is not valid";
        }
        
        void viewList(){
            int i;
            for(i=0; i<s->capacity; i++){
                cout<<" "<<s->arr_ptr[i];
            }
        }
    
};

int main(){
    float data;
    //pass value as parameter as constructor is taking parameter
    arrayList <float> list1(4);
    //and here also you have to tell the template that what kind of data you are going to pass
    list1.addElement(0, 25.6);
    list1.viewElement(0, data);
    cout<<"Value in the array is "<<data;
    return 0;
}

```


``` accessing elements through the name of the structure is done by dot operator and accessing it through the pointer which is pointing to the structure is done by arrow operator```

# 6. Virtual function
```pounter k through object ko call kro to arrow operator lgta h, and object k through kro to dot operator``` 

------------------------------------------------------------------------------------------------------

## Static Keyword

```cpp
#include<bits/stdc++.h>
using namespace std;

class Account{
    private:
        int balance;
        static float roi;
    public:
        void setBalance(int b){
            balance = b;
        }
        
        static void setROI(float r){
            roi = r;
        }
};

float Account:: roi;
int main(){
    Account a1, a2;
    //Account::roi = 4.5;
    
    a1.setROI(4.5);
    Account::setROI(4.5);
}


```

## Constructor
* Is a member function of class
* name is same as class
* No return type, so can't use return keyword
* Will never be static
* Is an instance member function, as create when instance(object) is created(so never static)
* Called just after an object is created, so used for initialisation

### Default constructor, parameterized constructor, Constructor overloading
```cpp
#include<bits/stdc++.h>
using namespace std;

class Complex{
    private:
        int a, b;
    public:
        //parameterized constructor
        Complex(int x, int y){
            a = x;
            b = y;
        }
        
        //parameterized constructor
        Complex(int x){
            a = x;
        }
        //default constructor
        Complex(){
            
        }
    
};

int main(){
    Complex c1(2, 3), c2(4), c3;
    return 0;
}

```
* If you havent created any constructor compiler will create default const. and copy const.
* If you have created default or parameterized const. then compiler would only create copy const.
* If you have created only copy const. then compiler will not create any const.

### Copy constructor

```cpp
#include<bits/stdc++.h>
using namespace std;

class Complex{
    private:
        int a, b;
    public:
        //parameterized constructor
        Complex(int x, int y){
            a = x;
            b = y;
        }
        
        //parameterized constructor
        Complex(int x){
            a = x;
        }
        //default constructor
        Complex(){
            
        }
        
        //copy constructor
        //using reference variable to prevent recursion and then infinite loop
        //as c will again call same constructor as c is passing as parameter, and it will always tak evalue
        //so we'll pass it as reference variable
        //bcz ye object ban rha h islie constructor call ho rha h
        //agar object na bana k reference bana do to constructor call hi ni hoga dobaara
        //so copy constructor me reference variable banana compulsory h, ni to error ayegi
        Complex(Complex &c){
            a = c.a;
            b = c.b;
        }
    
};

int main(){
    Complex c1(2, 3), c2(4), c3;
    //it will need copy constructor
    Complex c4(c1);
    return 0;
}

```

## Destructor

* Is a member function of class
* name is same as class
* tild sign(~) used before name
* No return type, so can't use return keyword
* Takes no argument(no overloading is possible)
* Will never be static
* Is an instance member function, as create when instance(object) is created(so never static)
* called just before object is going to get destroyed
* so used for deallocation of memory, example - for deallocation of dynamically allocated memory


```cpp
#include<bits/stdc++.h>
using namespace std;

class Complex{
   private:
    int a, b;
    
    public:
    ~Complex(){
        cout<<"Destructor executed"<<endl;
    }
};

void fun(){
    Complex c1;
}

int main(){
    fun();
    return 0;
}

```

# Operator Overloading

## Overloading of binary operator(addition)

### without operator overloading

```cpp
#include<bits/stdc++.h>
using namespace std;

class Complex{
   private:
    int a, b;
    
    public:
    void setData(int x, int y){
        a = x;
        b = y;
    }
    Complex add(Complex c){
        Complex temp;
        temp.a = a + c.a;
        temp.b = b + c.b;
        
        return temp;
    }
    void showData(){
        cout<<"a-"<<a<<" b-"<<b<<endl;
    }
    
};



int main(){
    Complex c1, c2, c3;
    
    c1.setData(2, 3);
    c2.setData(1, 5);
    
    c3 = c1.add(c2);
    c3.showData();
    
    return 0;
}

```

``` output : a-3 b-8 ```

### changing the function name from add to +, this is more readable 

```cpp


#include<bits/stdc++.h>
using namespace std;

class Complex{
   private:
    int a, b;
    
    public:
    void setData(int x, int y){
        a = x;
        b = y;
    }
    //use operator keyword
    Complex operator +(Complex c){
        Complex temp;
        temp.a = a + c.a;
        temp.b = b + c.b;
        
        return temp;
    }
    void showData(){
        cout<<"a="<<a<<" b="<<b<<endl;
    }
    
};



int main(){
    Complex c1, c2, c3;
    
    c1.setData(2, 3);
    c2.setData(1, 5);
    
    //Both of them are same
    //c3 = c1.operator+(c2);
    c3 = c1 + c2;
    
    
    c3.showData();
    
    return 0;
}



```

``` output : a-3 b-8 ```

* We can see that, by just using operator keyword, we changed the name to +
* Now in main, we don't need to use dot operator and as we are not using dot, therefore no need of operator word


![Screenshot from 2021-11-07 23-50-36](https://user-images.githubusercontent.com/42698268/140657262-6b68c3e3-ccde-4c66-8e18-c5d9a9368bc0.png)


 ![Screenshot from 2021-11-07 23-51-08](https://user-images.githubusercontent.com/42698268/140657273-f64bcdfe-8149-44f1-b679-54c31de5314c.png)


## Overloading of unary operator(negation)

```cpp

#include<bits/stdc++.h>
using namespace std;

class Complex{
   private:
    int a, b;
    
    public:
    void setData(int x, int y){
        a = x;
        b = y;
    }
    //use operator keyword
    Complex operator -(){
        Complex temp;
        temp.a = -a;
        temp.b = -b;
        
        return temp;
    }
    void showData(){
        cout<<"a="<<a<<" b="<<b<<endl;
    }
    
};


int main(){
    Complex c1, c2;
    
    c1.setData(2, 3);
   
    //both are same
    //c2 = c1.operator-();
    c2 = -c1;
    
    c2.showData();
    
    return 0;
}

```
