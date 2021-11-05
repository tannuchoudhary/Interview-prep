# 0. Introduce yourself.
# 1. Brief discussion about my final year project.
# 2. [Decimal Equivalent of Binary Linked List](https://www.geeksforgeeks.org/decimal-equivalent-of-binary-linked-list/)

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

# 3. [Bubble Sort](https://www.geeksforgeeks.org/bubble-sort/)


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
# 4. Touched upon each of the technologies that I’ve used in my projects and asked me questions based on it.
# 5. few questions from CS fundamentals
# 6. What tech stack are you most comfortable with?
# 7. Which data structure is used to implement auto-complete feature

Ans : Autocomplete is a feature of suggesting possible extensions to a partially written text and is widely used in search engine, code IDEs and much more. Trie data structure is a perfect fit to implement this feature efficient in terms of memory and time [O(length of string)].

# 8. [Trie Implementation (from techdose)](https://www.youtube.com/playlist?list=PLEJXowNB4kPyi859E6qGUs7jlpQehJndl)

## L 01. Basics of Trie

###  Intro
      * Trie is exactly like binary tree, but instead of two child for each node, it can have n nodes
      * Trie is an n-ary tree
      * Each node have value and bool which tells whether this is the end of word or not
      * Each node have pointer for 26 childs (if creating for dictioanry)
      
Structure of trie node:

![Screenshot from 2021-10-17 13-50-26](https://user-images.githubusercontent.com/42698268/137624712-1955d9cd-2c41-4c28-9342-031910b5d3c0.png)

Making dictionary using trie:

![Screenshot from 2021-10-17 13-54-17](https://user-images.githubusercontent.com/42698268/137624720-e085cbcb-3409-4604-88e7-e4ee4e0083ec.png)



      
###  Uses of trie data structure:

#### 1. Used in Dictionary to
      * Store words
      * Search words
      * Remove words
   
#### 2. Used in searching a word in O(length of word) time

#### 3. used in finding prefixes
#### 4. Very Ordered, structured and clean data structure


## L 02. Trie Insertion and Search
## Insertion in Trie


* First of all create a root node which will contain no data, word end will be zero and will have 26 pointers

* How to get a characters value for inserting, subtract it with base value

![Screenshot from 2021-10-17 20-17-10](https://user-images.githubusercontent.com/42698268/137632663-8582ee54-6340-4545-915a-cfae196be152.png)

* First of all we will have root node, word end will be zero for that, then in this case we'll insert aba, for the last character, word end will be 1
* Insert aba

![Screenshot from 2021-10-17 20-25-08](https://user-images.githubusercontent.com/42698268/137634044-6facb285-c102-4797-a947-e40e811a4873.png)

* Insert abc

![Screenshot from 2021-10-17 20-26-22](https://user-images.githubusercontent.com/42698268/137634060-9d9f340a-65aa-4016-af5c-7da856674dd1.png)


* Insert ab(just change the word count of 'b' after 'a' to be 1, which will represent that one of the string has ended here.


![Screenshot from 2021-10-17 20-28-08](https://user-images.githubusercontent.com/42698268/137634088-56bd05fa-844c-4530-b791-96797739a7e4.png)


## Searching in a Trie
For each word, start traversing from the root, if the required character's pointer is not null then continue else break, and if the end character of the word has word end == 1 in node, then word is present else not.


## Trie deletion and search
Whole code:

```cpp
//CODE TO Count_Number_Of_Strings_With_Given_Prefix
//Assumption: All characters are in lowercase
#include<iostream>
using namespace std;
//#define NULL 0

struct Trienode
{
    char data;
    int wc;  //wc:word_count
    Trienode *child[26];
};
Trienode nodepool[100000];  //Pool of 100K Trienodes
Trienode *root;    //Root of Trie
int poolcount;  //Always points to next free Trienode

void init() //Initializer function
{
    poolcount = 0;
    root = &nodepool[poolcount++];
    root->data = '/';
    for(register int i=0;i<26;++i)
        root->child[i] = NULL;
}

Trienode *getNode(char c)
{
    Trienode *newnode = &nodepool[poolcount++];
    newnode->data = c;
    for(register int i=0;i<26;++i)
        newnode->child[i] = NULL;
    newnode->wc=0;
    return newnode;
}

void insert(char *s)
{
    Trienode *curr = root;
    int index;
    for(int i=0; s[i]!='\0'; ++i)
    {
        index = s[i]-'a';
        if(curr->child[index]==NULL)
            curr->child[index] = getNode(s[i]);
        curr->child[index]->wc += 1;
        curr = curr->child[index];
    }
}

bool search(char *s)
{
    Trienode *curr = root;
    int index;
    for(int i=0; s[i]!='\0'; ++i)
    {
        index = s[i]-'a';
        if(curr->child[index]==NULL || curr->child[index]->wc == 0)
            return false;
        curr = curr->child[index];
    }
    return true;
}

bool Triedelete(char *s)
{
    if(search(s))
    {
        Trienode *curr = root;
        int index;
        for(int i=0; s[i]!='\0'; ++i)
        {
            index = s[i]-'a';
            curr->child[index]->wc -=1;
            curr = curr->child[index];
        }
    }
}

int countPrefix(string s)
{
    Trienode *curr = root;
    int index;
    for(int i=0; s[i]!='\0'; ++i)
    {
        index = s[i]-'a';
        if(curr->child[index]==NULL || curr->child[index]->wc == 0)
            return 0;   //No string with given prefix is present
        curr = curr->child[index];
    }
    return curr->wc;
}

int main()
{
    init();
    char a[5] = {'a','r','m','y'};
    char b[5] = {'a','r','m'};
    char c[5] = {'a','r','m','s'};
    char d[5] = {'a','r','y'};
    char e[5] = {'a','m','y'};
    char f[5] = {'a','p','i'};


    insert(a);
    insert(b);
    insert(c);
    insert(d);
    insert(e);
    insert(f);

    //cout<<search(b)<<"\n";

    printf("No of strings with given prefix = %d\n",countPrefix("a"));
    printf("No of strings with given prefix = %d\n",countPrefix("ar"));
    printf("No of strings with given prefix = %d\n",countPrefix("arm"));
    printf("No of strings with given prefix = %d\n",countPrefix("army"));
    printf("No of strings with given prefix = %d\n",countPrefix("armi"));
    printf("No of strings with given prefix = %d\n",countPrefix("ary"));

    cout<<"Deletion...STARTED\n";
    Triedelete(a);
    Triedelete(d);
    cout<<"DONE...\n\n";


    printf("No of strings with given prefix = %d\n",countPrefix("a"));
    printf("No of strings with given prefix = %d\n",countPrefix("ar"));
    printf("No of strings with given prefix = %d\n",countPrefix("arm"));
    printf("No of strings with given prefix = %d\n",countPrefix("army"));
    printf("No of strings with given prefix = %d\n",countPrefix("armi"));
    printf("No of strings with given prefix = %d\n",countPrefix("ary"));

    return 0;
}

```

# 9. What is the hardest challenge you’ve faced and how did you overcome it?

# 10. Why do you want to join BNY Mellon?

I've seen your company consistently listed as one of the top places to work, I've read employee testimonials and heard of your enthusiasm for encouraging employee growth through education, training and vast resources. I already know that engaged employees produce better work, and that is evident in the most recent campaign you created. I would love to join your innovative team, continue to create great work, and grow within the company by learning new skills.


# 11. [Minimum Number of Taps to Open to Water a Garden](https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/)


```cpp
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int min = 0;
        int max = 0;
        int open = 0;
        
        //run until you will not reach end of garden
        while(max<n){
            //on each iteration take the one covering maximum from inital point of garden
            for(int i=0; i<ranges.size(); i++){
                if(i-ranges[i]<=min && i+ranges[i]>max){
                    max = i+ranges[i];
                }
            }
            //not possible to cover whole garden
            if(min == max) return -1;
            open++;
            //update min, as now you have to find the tap which will start covering the garden from minimum
            min = max;
        }
        return open;
    }
};
```


```cpp
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        for(int i=1;i<ranges.size();i++){
            if(ranges[i] == 0) ranges[i]=i;
            else{
                int range = max(0, i-ranges[i]);
                ranges[range] = max(i+ranges[i],ranges[range]);
            }
        }
        
        int maxIdx = 0;
        int pos = 0;
        int jump = 0;
        
        for(int i=0;i<n;i++){
            if(maxIdx<i) return -1;
            
            maxIdx = max(maxIdx, ranges[i]);
            
            if(i==pos){
                jump++;
                pos = maxIdx;
            }
        }
        
        return maxIdx>=n ? jump : -1;
        
    }
};

```



```cpp
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        //dp[i] represents min of taps to open to water if the garden be from [0,i]
        //So, the required answer is dp[n] if it has been modified
        //else not possible and so we return -1
        vector<int> dp(n+1, n+2); //initialise all values with more than max no. of taps possible
        dp[0] = 0;
        for(int i = 0; i<=n; ++i){
            int leftMost = max(i - ranges[i]+1, 0);
            int rightMost = min(i+ranges[i], n);
            for(int j = leftMost; j<=rightMost; ++j){
                dp[j] = min(dp[j], dp[max(0,leftMost-1)]+1);
            }
        }
        return dp[n] < n+2 ? dp[n] : -1;  
    }
};
```

# 12. Tell me about your favorite algorithms, explain one of them, and write the code for the same.

## Kadane's Algorithm - Largest Sum Contiguous Subarray

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;
        for(auto it : nums){
            sum += it;
            maxSum = max(maxSum, sum);
            if(sum<0) sum = 0;
        }
        return maxSum;
    }
};
```

# 13. What is a BST, what are other types of trees?

Binary Search Tree is a node-based binary tree data structure which has the following properties:

* The left subtree of a node contains only nodes with keys lesser than the node’s key.
* The right subtree of a node contains only nodes with keys greater than the node’s key.
* The left and right subtree each must also be a binary search tree.

### Other types of trees:
* **General Tree**: If no constraint is placed on the tree’s hierarchy, a tree is called a general tree. Every node may have infinite numbers of children in General Tree. The tree is the super-set of all other trees.

* **Binary Tree**: The binary tree is the kind of tree in which most two children can be found for each parent. The kids are known as the left kid and right kid. This is more popular than most other trees. When certain constraints and characteristics are applied in a Binary tree, a number of others such as AVL tree, BST (Binary Search Tree), RBT tree, etc. are also used.

* **Binary Search Tree**: Binary Search Tree (BST) is a binary tree extension with several optional restrictions. The left child value of a node should in BST be less than or equal to the parent value, and the right child value should always be greater than or equal to the parent’s value. This Binary Search Tree property makes it ideal for search operations since we can accurately determine at each node whether the value is in the left or right sub-tree. This is why the Search Tree is named.

* **AVL Tree**: AVL tree is a binary search tree self-balancing. On behalf of the inventors Adelson-Velshi and Landis, the name AVL is given. This was the first tree that balanced dynamically. A balancing factor is allocated for each node in the AVL tree, based on whether the tree is balanced or not. The height of the node kids is at most 1. AVL vine. In the AVL tree, the correct balance factor is 1, 0 and -1. If the tree has a new node, it will be rotated to ensure that it is balanced. It will then be rotated. Common operations such as viewing, insertion, and removal take O(log n) time in the AVL tree. It is mostly applied when working with Lookups operations.

* **Red-Black Tree**: Another kind of auto-balancing tree is red-black. According to the red-black tree’s properties, the red-black name is given because the Red-black tree has either red or Black painted on each node. It maintains the balance of the forest. Even though this tree is not fully balanced, the searching operation only takes O (log n) time. When the new nodes are added in Red-Black Tree, nodes will be rotated to maintain the Red-Black Tree’s properties.

* N-ary Tree: The maximum number of children in this type of tree with a node is N. A binary tree is a two-ary tree, as at most 2 children in every binary tree node. A complete N-ary tree is a tree where kids of a node either are 0 or N.

* Advantages of Tree

   * The tree reflects the data structural connections.
   * The tree is used for hierarchy.
   * It offers an efficient search and insertion procedure.
   * The trees are flexible. This allows subtrees to be relocated with minimal effort.

# 14. Theoretical questions based on the Graph data structure. 

# 15. What are the most important things in Graph theory?

Graph Theory is ultimately the study of relationships . Given a set of nodes & connections, which can abstract anything from city layouts to computer data, graph theory provides a helpful tool to quantify & simplify the many moving parts of dynamic systems
Graph theory plays a critical role in many computer science problems – critical enough that many computer languages have been developed to facilitate the use of these graphs, such as SPANTREE or GTPL

Graphs can be used to model many types of relations and processes in physical, biological, social and information systems, and has a wide range of useful applications such as e.g.
* Finding communities in networks, such as social media (friend/connection recommendations), or in the recent days for possible spread of COVID19 in the community through contacts.
* Ranking/ordering hyperlinks in search engines.
* GPS/Google maps to find the shortest path home.
* Study of molecules and atoms in chemistry.
* DNA sequencing
* Computer network security
* ….. and many more….

What is the importance of graph theory in real life applications?

Graph theory and probability make it possible to guarantee a reliable service, for example by finding diversions when a particular connection is busy. All roads and motorways also form a large network, which is used by navigation services like Google Maps when working out the shortest route between two given points.

# 16. Where graph traversals algorithms are used? Tell about different traversal algorithms and write the order of printing of nodes in the inorder and pre-order traversal.

# 17. Coding question: https://leetcode.com/problems/linked-list-cycle-ii/

# 18. Coding question: https://leetcode.com/problems/palindromic-substrings/

# 19. SQL query –> Employee and department table is given you need to find the salary of employees in each department

# 20. What is Lambda?
Some definitions:
* Lambda expressions (or lambda functions) are essentially blocks of code that can be assigned to variables, passed as an argument, or returned from a function call, in languages that support high-order functions. They have been part of programming languages for quite some time.
* In mathematics and computer programming, the Lambda symbol is used to introduce "anonymous functions." Lambda notation distinguishes between variables used as mathematical arguments and variables that stand for predefined values.
* In computer programming, an anonymous function (function literal, lambda abstraction, lambda function, lambda expression or block) is a function definition that is not bound to an identifier.
* Essentially a lambda is a block of code that can be passed as an argument to a function call.([explanation](https://martinfowler.com/bliki/Lambda.html)), 

# 21. What is a virtual function?

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
* They are always defined in the base class and overridden in a derived class. It is not mandatory for the derived * class to override (or re-define the virtual function), in that case, the base class version of the function is used.
* A class may have virtual destructor but it cannot have a virtual constructor.

# 22. What is docker? What is cloud computing? (I didn’t mention these in my resume)

### Docker
Docker is an application build and deployment tool. It is based on the idea of that you can package your code with dependencies into a deployable unit called a container. 

For a visual explanation, think of the shipping containers used for intermodal shipping. You put your package (code and dependencies) in the container, ship it using a boat or train (laptop or cloud) and when it arrives at its destination it works (runs) just like it did when it was shipped.

basically Docker is an open platform for developing, shipping, and running applications. Docker enables you to separate your applications from your infrastructure so you can deliver software quickly. With Docker, you can manage your infrastructure in the same ways you manage your applications.

### Cloud computing
Cloud computing is a technology that uses the internet for storing and managing data on remote servers, and then access data via the internet. ... One such example is Google cloud – It is a suite of public cloud services offered by Google. All the application development run on Google hardware.

There are 3 main types of cloud computing services: Infrastructure-as-a-Service (IaaS), Platforms-as-a-Service (PaaS), and Software-as-a-Service (SaaS).

# 23. Do you know Java? I said I know the basics, so – What is the entry point of a code in Java? Tell the syntax? Why main is static?

# 24. Tell me about Switch & Hub. Which data structure is used in switches?

A Hub is a networking device that allows you to connect multiple PCs to a single network, whereas a Switch connects various devices together on a single computer network. A Hub operates on the physical layer, whereas Switch operates on the data link layer.[in mor edetail](https://www.geeksforgeeks.org/difference-between-hub-and-switch/)

I think graph data structure is used in switches

# 25. TCP vs UDP

# 26. Find how you can generate a given sequence of numbers from the BST shown on the whiteboard.

# 27. Which databases have you used? Difference between SQL and NoSQL.

# 28. What servers have you used?

# 29. What is the CAP theorem?

# 30. Tell me about the previous rounds.

# 31. Favourite programming language?

# 32. Do you know about the maps? Tell me something about it.

# 33. How hashing is done?

# 34. What is the Hash function? What will happen if a hash function returns 1 always?

# 35. Difference between map and unordered map

# 36. The interviewer discussed a lot about maps.

# 37. What are the challenges that you’ve faced till now?

# 38. What technology you’ve worked on? Why you choose Django? What is ORM?

# 39. Which databases have you used? Where have you used it?

I have used Mysql

Greater benefits have been achieved in Mysql, for being open sourced and providing, for the operational environment, the same functionality as any DBMS (cost-benefit ratio)

# 40. Do you have any leadership experience?

# 41. What do you know about BNY Mellon and why you want to join it?

The Bank of New York Mellon Corporation, commonly known as BNY Mellon, is an American investment banking services holding company headquartered in New York City. BNY Mellon was formed from the merger of The Bank of New York and the Mellon Financial Corporation in 2007. It is the world's largest custodian bank and asset servicing company, with $2.2 trillion in assets under management and $41.7 trillion in assets under custody as of the second quarter of 2021. It is considered a systemically important bank by the Financial Stability Board. BNY Mellon is incorporated in Delaware

BNY Mellon is a provider of investment management and investment services and we are a world-renowned leader in each. When combined, the power of our extensive capabilities can help drive your success in markets around the world.

What are the four values of BNY Mellon?
Businesses, communities and global economies rely on us because we prioritize client experience, collaboration, innovation and resilience. As the “bank of banks,” our unique perspective, informed by one of the largest datasets in the world, powers the financial industry.

What is BNY doing in India?
For over 234 years, as the investment company for the world, we have been leading change in the global financial services industry. BNY Mellon Technology Private Limited, established in 2000, is a group company of BNY Mellon operating in India, providing technology solutions to the bank.







.

.

.

.

.

.

.


# [42](https://www.geeksforgeeks.org/bny-mellon-interview-experience-for-6-month-internship-2020-virtual/?ref=rp)To swap 0 and 5 without the use of any condition, loop, or extra space

```answer-> 5-Input number ```

```code
#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin>>num;
    
    int ans = 5-num;
    cout<<ans;
    return 0;
}
```
# 43. To find the duplicate element in an array of size n with elements from 1 to n-1.
``` striver list ```
```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        slow = nums[slow];
        fast = nums[nums[fast]];
        
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
```

# 44. Print all the possible permutations of a string (will not contain duplicate alphabets)


# 45. he also asked me a puzzle on my approach to finding the defective ball (of lighter weight) from a group of 8 balls of similar weights with the help of a physical balance using minimum turns on it.


# ONCAMPUS

# [1](https://www.geeksforgeeks.org/bny-mellon-internship-interview-experience-for-software-developer-on-campus-2022/). Write a code to remove duplicates from the given linked list on provided HackerRank code pair link.
# 2. Compiled and interpreted language differences.
# 3. What is a constructor?
# 4. Give me an example where you can do constructor overloading
# 5. What is Exception Handling – what is need for this
# 6. Explain the flow of the program in the try, catch and finally block
# 7. What is the purpose of finally block
# 8. C++ and Python difference
# 9. Which data structure you would use to design a traffic signal and why?
# 10. Give me a real-life scenario where you see stack implemented
# 11. Identify which data structure is used for the following implementations –  1)Memory allocation and deallocation in the compiler – Ans: heap  2)Browser history – Ans: stack
# 12. What is multithreading in java?
# 13. ArrayList and Vector difference
# 14. What is namespace in C++?
# 15. How much do you know python? Do you know NumPy library?
# 16. Which question do you feel you could have answered better in Round 1
# 17. What are threads?
# 18. In C, if we write while(true) as a loop, what will happen and why?
# 19. What is the function pointer in C – where we can use this?
# 20. Declared array of size 5 and if I try to access 7th location, What will happen?
# 21. What is a static keyword in java?
# 22. What is a singleton in java?
# 23. The project, resume discussion, and follow up questions
# 24. What is core dump, thread dump?
# 25. Do you know Apache Tomcat? Have you worked on it? (I used this in one of my projects)
# 26. What are adaptive and responsive websites?
# 27. What is JDK, JRE, JVM?
# 28. HTTP and HTTPS difference
# 29. What is Big O notation? Do you know any other notations?
# 30. Which data structure you will use to store different country names such as India, US, UK, and then their respective state names and then respective city names.   Ans – Tree  Why? – As the given data is hierarchical
# 31. What are GET and POST methods
# 32. Tell me approach to code the following question
```
Testcase 1) Input -  abcd@gmail.com
Expected output - a*@gmail.com
Testcase 2) Input - pq@gmail.com
Expected output - p*@gmail.com
```
# 33. Give a brief summary about yourself, what all things you have done so far – technical, no technical both
# 34. Java and python difference – which one do you think is better?
# 35. Why do you prefer to code in Java?
# 36. What are all projects you have done and implementations?
# 37. Why did you choose this problem statement as your project, what was your thought process to come with this problem statement specifically?
# 38. How you tested your project?
# 39. Tell me about a time when you could not do well in academics and how you tackled this situation.
# 40. Do you think that doing all these projects was beneficial? If yes then how?
# 41. What are your future plans?
# 42. Have been involved in any technical discussion forums – how do you keep yourself updated?
# 43. Do you want to highlight any point which we missed to discuss which will add value to your candidature?

---------------------------------------------------------------------

# [44](https://www.geeksforgeeks.org/bny-mellon-internship-interview-experience-on-campus-2022/?ref=rp). A coding question- https://www.geeksforgeeks.org/count-words-in-a-given-string/ and one more that was also basic question on stack. Then he asked me about my projects and detailed discussion on technologies I have used.
# 45. He asked some DBMS and OOPS questions –

* Operator Overloading, Polymorphism, early/late binding, virtual memory etc.
* Also asked me to write an SQL Query (Joins and aggregate functions).
* Then, I was told that I am selected for next Interview Rounds.

# 46. Started with introductions, he asked coding questions – https://www.geeksforgeeks.org/minimum-number-increment-operations-make-array-elements-equal/ and https://www.geeksforgeeks.org/count-distinct-pairs-with-given-sum/.
Then he gave me SQL question to solve on HackerRank and a question on code related to API’s and some discussion on languages.
In few minutes, I was told I am selected for final round.








