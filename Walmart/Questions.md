
# 1. [INTERNSHIP (Round 1) - CODEHERS](https://www.geeksforgeeks.org/walmart-codehers-interview-experience/)
## 1. SQL query to find names of all employees that start with “Mu”

Ans - https://www.geeksforgeeks.org/sql-query-to-find-the-name-of-a-person-whose-name-starts-with-specific-letter/

``` SELECT * FROM employees WHERE NAME LIKE 'Mu%'; ```

![Screenshot from 2022-03-29 18-54-34](https://user-images.githubusercontent.com/42698268/160621560-9399e0f4-73d4-4386-a2fc-809d111efab6.png)

![Screenshot from 2022-03-29 18-56-55](https://user-images.githubusercontent.com/42698268/160621849-3c7bff9c-da79-4812-846f-016bbfb5d5bf.png)

## 2. SQL query to find second highest salary

![Screenshot from 2022-03-29 18-59-28](https://user-images.githubusercontent.com/42698268/160622396-c2a3e0ea-b95b-477c-9c96-e016cb6f8694.png)

## 3. A string is given of even length. Break it into 2 equal halves and find if 2 halves are alike or not. Here alike means that the number of vowels should be equal in both the halves.
    * book – alike
    * textbook – not alike
    
### Answer: 
* Approach 01: Divide the string into two half, and store them in two different strings of half size, and then find out the no. of vowels in each string and compare them, T.C = O(N), S.C = O(N)
* Approach 02: Don't use extra space, start traversing and find out the no of vowels in first half and second half and store them in two variables and then compare, T.C = O(N), S.C = O(1)

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    
    int sz = str.length();
    
    int first=0, second=0;
    for(int i=0; i<sz; i++){
        if(i<sz/2){
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
                first++;
        }
        else{
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
                second++;
        }
    }
    
    if(first == second) cout<<"yes";
    else cout<<"No";
    return 0;
}
```
* Approach 03: Find the size of string and start traversing from its half to the left and right simultaneously, store the no of vowels in left and right in two variables and compare at last, T.C = O(N/2), S.C = O(1)

    
 ## 4. Given array of strings find kth distinct string
    * s=[“a”, “b”, “c”, “a”], k=2   Output will be “c” (2nd distinct string)
    * s=[“aa”, “aaa”, “aaa”, “aaaa” ], k=2 Output will be “aaaa” (2nd distinct string)
    
 Answer :
 ```cpp
 class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        
        for(auto s : arr)
            mp[s]++;
        
        int t = 0;
        for(auto s : arr){
            if(mp[s] == 1)t++;
            if(t==k) return s;
        }
        return "";
        
    }
};
```
    
 ## 5. Bankers Algorithm
 The banker's algorithm is a resource allocation and deadlock avoidance algorithm that tests for safety by simulating the allocation for predetermined maximum possible amounts of all resources, then makes an “s-state” check or safe state check to test for possible activities, before deciding whether allocation should be allowed to continue
 ![Screenshot from 2022-04-11 03-36-31](https://user-images.githubusercontent.com/42698268/162641988-3260e268-4ce4-4c8f-a20f-c75fedffab59.png)

 ![Screenshot from 2022-04-11 03-37-07](https://user-images.githubusercontent.com/42698268/162641994-7dcd4dd4-6a82-4ded-b8df-dbb25c931983.png)

 ![Screenshot from 2022-04-11 03-36-57](https://user-images.githubusercontent.com/42698268/162641995-545a48ae-8b42-4d65-a47c-b2beeeb284c3.png)

 ## 6. What are scheduling algorithms with example

 ![Screenshot from 2022-04-11 03-53-21](https://user-images.githubusercontent.com/42698268/162642331-a4db824f-aa5d-4f66-9932-90d264ffb517.png)

 ![Screenshot from 2022-04-11 03-51-04](https://user-images.githubusercontent.com/42698268/162642333-acfa060f-ef0a-474b-a7c0-151cde1c8d5a.png)

 ![Screenshot from 2022-04-11 03-53-32](https://user-images.githubusercontent.com/42698268/162642341-ab9d8876-994e-4025-bd29-3774383e75ec.png)

 ![Screenshot from 2022-04-11 03-47-28](https://user-images.githubusercontent.com/42698268/162642352-c4c09a01-1e6f-4629-89fb-ad2b27b3d199.png)

 ![Screenshot from 2022-04-11 03-47-53](https://user-images.githubusercontent.com/42698268/162642353-4fd973f8-548a-406a-944d-28cedf9e513a.png)

![Screenshot from 2022-04-11 03-48-03](https://user-images.githubusercontent.com/42698268/162642359-e57e99de-53dc-4f1c-8889-f0b2eeca61b1.png)

![Screenshot from 2022-04-11 03-48-38](https://user-images.githubusercontent.com/42698268/162642361-548cfe0d-7e25-4811-9b47-849355f994b7.png)

![Screenshot from 2022-04-11 03-48-52](https://user-images.githubusercontent.com/42698268/162642363-8fbfee9f-3180-48ae-becf-8805b73433ee.png)

![Screenshot from 2022-04-11 03-49-11](https://user-images.githubusercontent.com/42698268/162642364-721eaa82-508a-4ad6-90e4-7ed26ab00291.png)

![Screenshot from 2022-04-11 03-49-25](https://user-images.githubusercontent.com/42698268/162642368-d1249831-4db7-4203-82b9-b661bf9efbeb.png)

![Screenshot from 2022-04-11 03-49-52](https://user-images.githubusercontent.com/42698268/162642370-6478ce18-5189-4dc0-99b1-6f172816ab8c.png)

![Screenshot from 2022-04-11 03-50-35](https://user-images.githubusercontent.com/42698268/162642371-1fabdc43-1731-4483-9fd7-3d5fb2d659de.png)

![Screenshot from 2022-04-11 03-50-50](https://user-images.githubusercontent.com/42698268/162642375-bc13a239-28f0-4fce-9645-f3e6eec068da.png)

 
 
 ## 7. 3-4 questions about projects that I have done
 
 # Round 2
 ## 8. Strength with real life example
 ## 9. Weaknesses
 ## 10. Where do you see yourself in 5 years
 ## 11. Why Walmart
 ## 12. What you will do if client is not satisfied
 ## 13. What will you do if you don’t agree with manager’s feedback
 ## 14. What is your biggest achievement
 ## 15. If you are given a chance what will you change in past
 
 # 2. FULL TIME (Round 1) - CODEHERS
 ## 16. Questions based on my internships and projects (Give an instance where you used Exception Handling and Polymorphism in your project).
 ## 17. Differences between threads and processes.
 ## 18. Explain TCP Handshake.
 ## 19. Differences between Queues and Stacks.
 ## 20. Differences between Arrays and Linked Lists.
 ## 21. Questions on Linux commands
 
 # Round 2
 ## 22. Explain the logic for this(https://leetcode.com/problems/delete-node-in-a-bst/) and this(https://leetcode.com/problems/subtree-of-another-tree/). Discussed time complexities.
 
 ## 23. Write a code for this(https://www.javatpoint.com/ds-array-implementation-of-stack) and this. Discussed time complexities.

## 24. Puzzle 1 : https://www.geeksforgeeks.org/puzzle-set-35-2-eggs-and-100-floors/

## 25. Puzzle 2: https://www.geeksforgeeks.org/puzzle-7-find-the-jar-with-contaminated-pills/
 
# Round 3 (Managerial round)
 
## 26. What are your non-technical interests?
## 27. What tech stack are you most comfortable with?
## 28. Questions about my internship and my final year project.
## 29. Explain File operations in C++.
## 30. How will you print numbers from 1 to 100 without using a loop? (Discussion only)
## 31. Explain the steps involved in SDLC.

# 3. Full time(round 1) - CODEHERS
## 32. Tell me about the projects you have worked on.
## 33. Find the maximum occurring number in as array. https://www.geeksforgeeks.org/find-the-maximum-repeating-number-in-ok-time/
## 34. Exception handling in C++ in detail.
## 35. What do you mean by OOPS
## 36. What is inheritance.
## 37. Create a database to store the information of employees and their salaries (just explain).
## 38. What are insertion, deletion and updation anomalies in DBMS. https://www.geeksforgeeks.org/anomalies-in-relational-model/
## 39. Find the equilibrium index of an array. https://www.geeksforgeeks.org/equilibrium-index-of-an-array/
## 40. Whats polymorphism -> compile and runtime.
## 41. Write code to show run time polymorphism. https://www.geeksforgeeks.org/polymorphism-in-c/
# Round 2
## 42. Tell me about yourself and projects you have worked on.
## 43. What’s polymorphism.
## 44. What are exceptions in Java – Since my primary language was C++, so I explained exception in C++ only.
## 45. What are collections in Java – list, map, set.
## 46. Find the maximum occurring number in as array. (yes I got the same que in previous round too)
## 47. Whats binary search – only explain.
## 48. Name all the sorting algorithm you have studied and which algorithm to be used for larger inputs.
## 49. Write a SQL query to print the highest salary in each department.
# Round 3
## 50. Tell me about yourself.
## 51. Have you got offer from another organization?
## 52. Why do you want to join Walmart?
## 53. Interviewer told me about what projects they work on. She told me about a system that estimates the time between 2 cities during a delivery. Then she asked me what do you think how we implement it. I gave my views related to graphs and shortest distance algorithms considering factors like traffic and all. Then she asked me how to use Machine Learning in this context.
## 54. What are things you are good at apart from technical skills.
## 55. What is the thing you are bad at?
## 56. What do you apart from studies?
## 57. Why should we hire you?
## 58. Rope burning puzzle:  https://kottke.org/06/11/rope-burning-logic-problem
## 59. Do you have any questions.

# 4. Full time(Round 1) - CODEHERS

## 60. The interview started with a short introduction of both of us. 
## 61. Post that, we had some discussions around my projects
## 62. Inheritance
## 63. Polymorphism
## 64. Virtual functions
## 65. Immutable classes
## 66. Storage classes
## 67. He asked me to show the use of virtual functions
## 68. I was asked to explain all types of inheritance with examples
## 69. He asked me differences between Process and Threads

# Round 2
## 70. It started with short introductions of both of us and some discussions around my projects
## 71. Then he asked me searching algorithms
## 72. Sorting algorithms
## 73. And one coding question
## 74. Then he moved to a few puzzles. I could solve both the puzzles, but first one took more time compared to the second one. 

# Round 3
## 75. It started with a short introduction of me. 
## 76. Then she went deep into my internship experience - my responsibilities as an intern, mistakes committed by me, ability to complete tasks within deadline, challenges faced during internship period etc. 
## 77. Then she asked me a puzzle which I was able to solve quickly. 
## 78. She wanted to know why I want to join Walmart.
## 79. What challenges have I faced in real life.
## 80. She also asked a technology that I would like to learn apart from my current skill set

# 5. Intern (Round 1)  -CODEHERS
## 81. Short Introduction
## 82. A coding question on Permutation of Strings
## 83. Theoretical Questions revolving around SQL, DBMS, and OOPs
## 84. Difference between binary trees and balanced binary trees.
## 85. A coding question on Binary Trees (count total number of nodes)
## 86. DFS vs BFS and conceptual questions on them
## 87. Some more questions on different Data Structures and core CS fundamentals (can’t remember …)
## 88. We discussed various technologies used and products at Walmart and the vast learning scope.

# Round 2
## 89. Short Introduction
## 90. Hobbies
## 91. A small explanation of projects.
## 92. Relocation choices and a few more general HR questions.

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
    
