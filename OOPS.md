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
  

# 6. Virtual function
```pounter k through object ko call kro to arrow operator lgta h, and object k through kro to dot operator``` 

------------------------------------------------------------------------------------------------------

# 7.Static Keyword

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
## Increment operator overloading

# this pointer

![Screenshot from 2021-11-08 20-33-07](https://user-images.githubusercontent.com/42698268/140766953-b72f4a7a-b237-4887-9344-08540e5a82f4.png)


![Screenshot from 2021-11-08 20-44-50](https://user-images.githubusercontent.com/42698268/140767658-ac6191e8-3fa2-44be-b0ae-560e0f33)

# Method overriding
![Screenshot from 2021-11-08 21-05-54](https://user-images.githubusercontent.com/42698268/140771390-4fcc6726-47e2-421d-bc86-618c9f031a80.png)
9438.png)

# Virtual Function

## Points to keep in mind
* Pointer of a parent class can point to the object of child class, or to the object of any descendent(vanshaj) of the parent class

![Screenshot from 2021-11-05 23-51-40](https://user-images.githubusercontent.com/42698268/140559966-7fc03785-81e8-4bee-8a46-0ed31ae5fd86.png)

* Program to understand this concept

```cpp
#include<bits/stdc++.h>
using namespace std;

class A{
    public:
        void f1(){
            
        }
};

class B : public A{
    public:
        //this is function overriding
        void f1(){
            
        }
    
};

int main(){
    A *ptr1, *ptr2, obj1;
    B obj2;
    
    ptr1 = &obj1; // ptr1 pointer of type base class can store the address of type A(this is normally what we do)
    ptr2 = &obj2; //parent class pointer can point to object of child class
    
    //calling function using object
    //here early binding is happening, i.e while compiling compiler will find out that obj2 is of child class type 
    obj2.f1(); //therefore it will call the f1 function of child class as obj2 is of type child class
    
    //calling function using pointer
    ptr2->f1() //as ptr2 is containing the address of type of child class
    //so it should have called the f1() of child class
    
    /* but at the time of compilation, compiler will not able to find out the type of 
    address contained in ptr2 at the time of early binding */
    
    /* as at compile time only the type of pointer can be found out and not the type of object
    whose address is contained by the pointer, and the type of pointer was decided at the time
    of declaration, in line 21, which is of type A*/
    
    /*so compiler will assume that, we are trying to call f1() of parent class i.e A, and it 
    will call the f1() of class A, which is very wrong */
    
    /*but the bigger problem is that it will not even show the error, you will never be able to 
    figure out what is the problem*/
    
    /* So to avoid this problem, the solution is that we'll prevent early binding, we'll tell 
    compiler to do late binding, so that pointer k type ko nahi balki pointer k content ko
    adhaar maana jaye */
    
    /* so to do this, we'll declare the function in parent class i.e class A as virtual*/
    
    /* Now no need to define these functions as virtual in child classes, as compiler will
    automatically consider them as virtual function*/
    
    /* Now as we have defined the function as virtual, now due to virtual keyword, late 
    binding will be done*/
    
}

```
## Result:
```cpp
#include<bits/stdc++.h>
using namespace std;

class A{
    public:
       virtual void f1(){
            
        }
};

class B : public A{
    public:
        void f1(){
            
        }
    
};

int main(){
    A *ptr1, *ptr2, obj1;
    B obj2;
    
    ptr1 = &obj1; 
    ptr2 = &obj2; 
    
    obj2.f1(); 
    ptr2->f1() 
}
```

A virtual function is a member function which is declared within a base class and is re-defined(Overridden) by a derived class. When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class’s version of the function. 

* Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer) used for function call.
* They are mainly used to achieve Runtime polymorphism
* Functions are declared with a virtual keyword in base class.
* The resolving of function call is done at Run-time.


### Rules for virtual function:

* Virtual functions cannot be static.
* A virtual function can be a friend function of another class.
* Virtual functions should be accessed using pointer or reference of base class type to achieve run time polymorphism.
* The prototype of virtual functions should be the same in the base as well as derived class.
* They are always defined in the base class and overridden in a derived class. It is not mandatory for the derived  class to override (or re-define the virtual function), in that case, the base class version of the function is used.
* A class may have virtual destructor but it cannot have a virtual constructor.

# Abstract Class

![Screenshot from 2021-11-08 21-48-26](https://user-images.githubusercontent.com/42698268/140778653-d682e4c1-5276-49f6-a8e7-4f477660fae9.png)

* An object can't be created of that class which have do nothing function inside it
* But you can do inheritance, i.e you can create a child class using that class which have do nothing function
* But the rule is, if you inherit then you have to override that function in the child class which was do nothing in the parent class
* Now what if the parent class contains other functions also, and if we can't create an object of parent class how we'll call that function
* Answer is, you can call that function using child class
*  But also we know that, still do nothing function i.e f1() in this case can be called if we'll use pointer, so to avoid that we'll declare that function as virtual, to avoid early binding
*  and this function is called ```pure virtual function```, i.e do nothing function

![Screenshot from 2021-11-08 21-58-35](https://user-images.githubusercontent.com/42698268/140782311-9b9d2297-fc73-4cc3-a9a9-a6a238a693fd.png)


## Abstract class
* That class which contains atleast one pure virtual function is called abstract class
* and we can never create an object of the abstract class(reason we know from above explanation)
* In java, we write abstract keyword before the class to make it abstract class, but in c++ there isn't any abstarct keyword, so in c++, that class which contains a pure virtual function is called abstract class.


* Now if you don't want to do the overriding of the parent class to call other functions, you can again declare them as the virtual class in child class also
* so you have to do one thing atleast, i.e either override it in child class, or declare it as pure virtual function in child class also
* but if the function is pure virtual function in child class also, then we can't create an object of child class too, as it is an abstract class now, so again you have to create a child class to create object


If we have two classes to create, i.e student and faculty, so there must be few of the properties similar in both of them, so we'll create a generalised class let's say person, which will store all the common things,
and whenever we'll want to create a new class, we'll use person class 
## Advantage
* efforts reduced
* architecture maintainable
* do not need need to create same thing again and again
* as replica is getting used
* less cost

### example
* Now we can see that, there would never need to create an object of person class, we'll need student class to keep the data of student , faculty class to keep the data of faculty , but we'd never need person class, because let us say the common things between student and faculty is name and phone number, and no what would we do by creating an object having name and phone number, if we dont know that who is that person, this is just useless, so we want that the object of the person class can never be created

* so we created person class just to provide common properties of student and faculty
* so we'll make person class as abstract class
* there is one more advantage of creating pure virtual functio, we are pressurizing child class to override the function 

#  Templates

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


# namespace

* header file contains declaration of identifiers, functions etc
* library file contains definition of identifiers and functions
* if two header file is written and both contains declaration of same function, so to avoid ambuigity, namespace was used
* inside header files, all declarations are inside namespace
* namespace is a block of code containing declarations
* now there would be no conflicts, as both declaration(which is of same identifier) belongs to different namespaces


 ![Screenshot from 2021-11-08 22-35-49](https://user-images.githubusercontent.com/42698268/140786851-01392d28-f998-43ba-9085-237ad32e253e.png)
 
 
 ![Screenshot from 2021-11-08 22-35-57](https://user-images.githubusercontent.com/42698268/140787062-2518cd2f-0baf-4670-af2d-fa4342b3fe5f.png)
 
 ![Screenshot from 2021-11-08 22-42-51](https://user-images.githubusercontent.com/42698268/140787825-59a001f4-161e-45f2-9532-e3d8b8ae8df6.png)

* this is how it is written

![Screenshot from 2021-11-08 22-43-43](https://user-images.githubusercontent.com/42698268/140787883-a41cbeb5-e00c-40a1-aac0-e51274eafa0c.png)

* You can use alias for namespace for convenience

![Screenshot from 2021-11-08 22-44-09](https://user-images.githubusercontent.com/42698268/140787922-b218eb61-6dc4-42fe-84ad-6c2314aa2c87.png)



![Screenshot from 2021-11-08 22-44-22](https://user-images.githubusercontent.com/42698268/140787934-dd50048a-fc86-4c83-bacc-e554097a914d.png)



![Screenshot from 2021-11-08 22-44-45](https://user-images.githubusercontent.com/42698268/140787949-e4f493af-e06b-4a1c-adaf-fb417f55ef8b.png)



![Screenshot from 2021-11-08 22-44-52](https://user-images.githubusercontent.com/42698268/140787958-db7b1385-1bdf-41d7-8157-acd89d4faeef.png)




# Interface


* An interface in Java is a blueprint of a class. It has static constants and abstract methods.

* The interface in Java is a mechanism to achieve abstraction
 There can be only abstract methods in the Java interface, not method body. It is used to achieve abstraction and multiple inheritance in Java


* In other words, you can say that interfaces can have abstract methods and variables. It cannot have a method body.

* Java Interface also represents the IS-A relationship.
* It cannot be instantiated just like the abstract class.


* An abstract class allows you to create functionality that subclasses can implement or override. An interface only allows you to define functionality, not implement it. And whereas a class can extend only one abstract class, it can take advantage of multiple interfaces.


## Why use Java interface?
There are mainly three reasons to use interface. They are given below.

It is used to achieve abstraction.
By interface, we can support the functionality of multiple inheritance.
It can be used to achieve loose coupling.


## How to declare an interface?
An interface is declared by using the interface keyword. It provides total abstraction; means all the methods in an interface are declared with the empty body, and all the fields are public, static and final by default. A class that implements an interface must implement all the methods declared in the interface.





 
 
