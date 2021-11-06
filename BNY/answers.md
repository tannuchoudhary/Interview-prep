# Decimal equivalent of binary linked list

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

# [Bubble Sort](https://www.geeksforgeeks.org/bubble-sort/)


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

# [Minimum Number of Taps to Open to Water a Garden](https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/)



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

# Count ways to express a number as sum of consecutive numbers

```
Approach: The idea is to represent N as a sequence of length L+1 as: 
N = a + (a+1) + (a+2) + .. + (a+L) 
=> N = (L+1)*a + (L*(L+1))/2 
=> a = (N- L*(L+1)/2)/(L+1) 
We substitute the values of L starting from 1 till L*(L+1)/2 < N 
If we get ‘a’ as a natural number then the solution should be counted.
```

```cpp
// C++ program to count number of ways to express
// N as sum of consecutive numbers.
#include <bits/stdc++.h>
using namespace std;

long int countConsecutive(long int N)
{
	// constraint on values of L gives us the
	// time Complexity as O(N^0.5)
	long int count = 0;
	for (long int L = 1; L * (L + 1) < 2 * N; L++) {
		double a = (1.0 * N - (L * (L + 1)) / 2) / (L + 1);
		if (a - (int)a == 0.0)
			count++;
	}
	return count;
}

// Driver Code
int main()
{
	long int N = 15;
	cout << countConsecutive(N) << endl;
	N = 10;
	cout << countConsecutive(N) << endl;
	return 0;
}

```

# [To swap 0 and 5 without the use of any condition, loop, or extra space](https://www.geeksforgeeks.org/bny-mellon-interview-experience-for-6-month-internship-2020-virtual/?ref=rp)

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

# To find the duplicate element in an array of size n with elements from 1 to n-1.
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

# Write a program to print all permutations of a given string

```cpp
#include <bits/stdc++.h>
#include <string>
using namespace std;

void permute(string s , string answer)
{
	if(s.length() == 0)
	{
		cout<<answer<<" ";
		return;
	}
	for(int i=0 ; i<s.length() ; i++)
	{
		char ch = s[i];
		string left_substr = s.substr(0,i);
		string right_substr = s.substr(i+1);
		string rest = left_substr + right_substr;
		permute(rest , answer+ch);
	}

}

int main()
{
	string s;
	string answer="";

	cout<<"Enter the string : ";
	cin>>s;

	cout<<"\nAll possible strings are : ";
	permute(s , answer);
	return 0;
}
```
# Inheritence
// C++ program to demonstrate implementation
// of Inheritance

#include <bits/stdc++.h>
using namespace std;

//Base class
class Parent
{
	public:
	int id_p;
};

// Sub class inheriting from Base Class(Parent)
class Child : public Parent
{
	public:
	int id_c;
};

//main function
int main()
{
	
		Child obj1;
		
		// An object of class child has all data members
		// and member functions of class parent
		obj1.id_c = 7;
		obj1.id_p = 91;
		cout << "Child id is " << obj1.id_c << endl;
		cout << "Parent id is " << obj1.id_p << endl;
		
		return 0;
}

# Polymorphism

