# 1. What is meant by the term OOPs?
OOPs refers to Object-Oriented Programming. It is the programming paradigm that is defined using objects. Objects can be considered as real-world instances of entities like class, that have some characteristics and behaviors.

# 2. What is the need for OOPs?
There are many reasons why OOPs is mostly preferred, but the most important among them are: 

OOPs helps users to understand the software easily, although they don’t know the actual implementation.
With OOPs, the readability, understandability, and maintainability of the code increase multifold.
Even very big software can be easily written and managed easily using OOPs.

# 3. What are the main features of OOPs?
OOPs or Object Oriented Programming mainly comprises of the below four features, and make sure you don't miss any of these:

Inheritance
Encapsulation
Polymorphism
Data Abstraction

# 4. Inheritence

The capability of a class to derive properties and characteristics from another class is called Inheritance. Inheritance is one of the most important feature of Object Oriented Programming. 
* Sub Class: The class that inherits properties from another class is called Sub class or Derived Class. 
* Super Class:The class whose properties are inherited by sub class is called Base Class or Super class. 

## Types of Inheritance in C++

1. Single Inheritance: In single inheritance, a class is allowed to inherit from only one class. i.e. one sub class is inherited by one base class only.


![Screenshot from 2021-10-11 06-16-57](https://user-images.githubusercontent.com/42698268/136719173-2a9d48dd-6df0-46af-abba-c25fc79f9836.png)




2. Multiple Inheritance: Multiple Inheritance is a feature of C++ where a class can inherit from more than one classes. i.e one sub class is inherited from more than one base classes.

![Screenshot from 2021-10-11 06-17-10](https://user-images.githubusercontent.com/42698268/136719186-8c14eada-0725-4e14-a3ad-131c26e817bd.png)

3. Multilevel Inheritance: In this type of inheritance, a derived class is created from another derived class.

![Screenshot from 2021-10-11 06-17-20](https://user-images.githubusercontent.com/42698268/136719196-aac26758-f60f-4b0a-896b-263154d5ab93.png)

4. Hierarchical Inheritance: In this type of inheritance, more than one sub class is inherited from a single base class. i.e. more than one derived class is created from a single base class.

![Screenshot from 2021-10-11 06-17-27](https://user-images.githubusercontent.com/42698268/136719223-4034e387-05f1-4126-9587-5ecdda43c28e.png)


# 5. Difference between abstract and interface

Abstract class and interface both are used to achieve abstraction where we can declare the abstract methods. Abstract class and interface both can't be instantiated.

![Screenshot from 2021-10-11 06-22-06](https://user-images.githubusercontent.com/42698268/136719335-08a1056e-013f-4513-900f-e8628eb4a42b.png)

# 6. Dangling pointers
A pointer pointing to a memory location that has been deleted (or freed) is called dangling pointer

# 7. Void pointers
Void pointer is a specific pointer type – void * – a pointer that points to some data location in storage, which doesn’t have any specific type. Void refers to the type. Basically the type of data that it points to is can be any. If we assign address of char data type to void pointer it will become char Pointer, if int data type then int pointer and so on. Any pointer type is convertible to a void pointer hence it can point to any value.

# 8. NULL pointers
NULL Pointer is a pointer which is pointing to nothing. In case, if we don’t have address to be assigned to a pointer, then we can simply use NULL.

# 9. Wild Pointers
A pointer which has not been initialized to anything (not even NULL) is known as wild pointer. The pointer may be initialized to a non-NULL garbage value that may not be a valid address.

# 10. Normal forms

1. 1NF: If a table is created from ER diagram, it is in 1NF, i.e, composite attributes are broken down into simple attributes
2. 2NF: There should not be any partial dependency( if AB -> C and A -> D, then this is partial dependency, as part of AB i.e A is deriving something)
3. 3NF: There should not be a transitive dependency( if A -> B a nd B->C then A->C, this is a transtive dependency)
4. BCNF: Left hand side should be a super key

# 11 Difference between 4NF and BCNF

* Boyce-Codd Normal Form (BCNF) :
Any relation is said to be in the BCNF if and only if it satisfies the following condition :
For every Functional Dependency (FD) X->Y, X is SuperKey in given relation.

* 4th Normal Form (4NF) :
Any relation is said to be in the fourth normal form when it satisfies the following conditions :
It must be in Boyce Codd Normal Form (BCNF).
It should have no multi-valued dependency.

# 12. Dirty read
Dirty Reads –
When a transaction is allowed to read a row that has been modified by an another transaction which is not committed yet that time Dirty Reads occurred. It is mainly occurred because of multiple transaction at a time which is not committed.

# 13. Difference between SQL and noSQL

![Screenshot from 2021-10-11 06-44-43](https://user-images.githubusercontent.com/42698268/136720367-14f389a3-5f68-4a6b-8081-4c09f148290d.png)

