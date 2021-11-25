
# i) ASKED FROM ME

# My round 1 interview Questions :

* Gave his Introduction
* Introduce yourself
* Tell briefly about your project(mine was web based compiler and pet adoption website) 
* Tell that project which is completely working( told web based compiler)
* If you have used compilex(for compiler) and ace.js(for editor) then what did you do in this project
* Show the code(showed him github repo)
* Show where have you implemented in code that your input will be saved
* One oops question on hackerrank code pair:
	* question: you are given a class which contains a vector, you'll have a function and parameter passed in that function is two vectors, you have to swap the content of the first vector and put it into the second vector

* In which langauge you are proficient(i said c++)
* difference between c and c++
* what else you are good at( i said ds algo)
* what is file structure and storage structure

Storage structure: It is the representation of the data structure in the computer memory. - File structure: It is the representation of the storage structure in the auxiliary memory.


* friend function
* stack and its application
* linear and non linear ds, examples and application
* what is queue, linear or non linear
* queue and its application
* implement queue using stack
* What is Hashtable
* Situation based: 
	* What if you are team lead and only you know how to do that particular work, and you have a deadline to meet
	* What if 3 of your team members are showing attitude 
	* What if 1 of them will agree to work with you but other 2 have a problem with you being the team leader
	* what if all the three of them are as much skilled as you, would you leave the position of team leader

* Have you done anything which shows your leaderhsip quality
* Do you have any question from me

---------------------------------------------------------------------------------------------------------------------------------------

# My round 2 Interview Questions:



* Introduce yourself

	> My name, degree pursuing, college, cgpa, interships, projects, mentorship programmes, hobbies

* Time complexity of update, insert, delete on linked list and array

	> explained him the tc by taking all the edge cases, example if head and tail both of LL is given, if only head of LL is given, in case of insertion at anywhere in the middle if the address of the position where I want to insert is given in LL, etc


* Tell me about all data structures and their applications and how to implement them

	> Told him about all the data structures i.e stack, queue, linked list, hashmap, tree and graph, told him the operations and how to implement these data structures and real life applications of all data structures

* Binary search operation and its time complexity
	> Explained binary search, took an example and dry run on it, told him the time complexity then he asked why the time complexity is O(log n) therefore explained him, he tried to deviate me by saying that "is it O(log n) or O(n log n) :P

* Tell me about hashmap, How hashing is done, How can we reduce collision
	> Told him about hashmap, and in what scenario we can use it, took two examples, one of array and one using string of strings


* Tell me about graph data structure

	> Told him about the graph data structure, classification on the basis of weighted, non weighted, directed, non directed, told him all the real life applications of graph, told him all the traversal techniques of the graph, and what are the uses of BFS and DFS in other algorithms


* Tell me about the algorithms of dp, greedy

	> i told him knapsack(both 0-1 and fractional), kadanes, bfs, dfs), explained these algorithms by taking examples, and by dry running them verbally on small examples

* Asked me to explain my project

	> Told him about the project, what was the idea behind the project, tech stacks used and why it is used, working of project, in future what else I have 
* One coding question- given a linked list in which nodes are containing number in binary form, calculate the decimal value(present on gfg)

	> I told him two approache: one by taking two pointers and traversing twice, first time to find the size and second time to calculate the value, Second approach is by multiplying the answer by 2 each time and adding data of head, until you'll reach the end of linked list, told him the time complexity of both the approaches and how the second one is better from the first one

* Any questions for me



----------------------------------------------------------------------------------------------------------------------------------------------------------

# ii) ASKED FROM OTHERS(2021)


## Calculate the angle between hour hand and minute hand

```cpp
class Solution {
public:
    double angleClock(int h, int m) {
        // invalid inputs
        if(h<0 || m<0 || h>24 || m>60) cout<<"Wrong input";
        
        
        if(h == 12 || h == 24) h =0;
        if(m == 60){
            h += 1;
            m = 0;
            if(h>12){
                h = h-12;
            }
        }
        
        // it is same as (h + m/60)*30
        //as each hour is 30 degrees
        ///and each minute is 6 degrees
        double hAngle = (h*60 + m)*0.5;
        double mAngle = m*6;
        
        double ans = abs(hAngle - mAngle);
        if(ans > 180)
            ans = 360-ans;
        
        return ans;
    }
};
```

## Knapsack problem

```cpp
#include<iostream>
#include<algorithm>

using namespace std;
struct item{            //This is a structure to contain profit and weight of objects
  float profit, weight;
};
bool cmp(item d1, item d2){ //comparison function for descending order
  int r1 = d1.profit / d1.weight; //sorting profit by weight ratio.
  int r2 = d2.profit / d2.weight;
  return r1 > r2;
}
float knapsack(float m,struct item a[], int size){
  sort(a, a+size, cmp);    //sort fuction for sorting in descending order.
  cout<<"Your data after sorting"<<endl;
  cout<<"PROFIT | WEIGHT | PROF/WT"<<endl;
  for(int k=0; k<size; k++){
    cout<<"    "<<a[k].profit<<"    "<<a[k].weight<<"    "<<a[k].profit/a[k].weight<<endl;
  }
  float current = 0.00;   //current weight filled in knapsack.
  float profit = 0.00;   //Final maximum profit.
  float remain;         //Remaining weight in knapsack.
  for(int i=0; i<size; i++){
    if(current + a[i].weight <= m){  //If there is space in the knapsack for filling the object fully then proceed

      current += a[i].weight; //increase the current weight
      profit += a[i].profit; //increase the profit
    }
    else{                    //When we want to keep fraction of object in knapsack.
      remain = m - current;
      profit += a[i].profit * remain/a[i].weight;
      break;
    }
  }
  cout<<endl<<"Your maximum profit will be ";
  return profit;
}
int main(){
  float m = 15.00; //This is the capacity of knapsack.
  item a[] = {{10, 2}, {5,3}, {15, 5}, {7, 7}, {6, 1}, {18, 4}, {3, 1}};//Items in the knapsack i.e, profit along with it's corresponding weight.
  int size = sizeof(a) / sizeof(a[0]);
  cout<<"PROFIT | WEIGHT | PROF/WT"<<endl;
  for(int i=0; i<size; i++){
    cout<<"    "<<a[i].profit<<"    "<<a[i].weight<<"    "<<a[i].profit/a[i].weight<<endl;
  }
  cout<<knapsack(m, a, size)<<endl;
  return 0;
}

```

## Number of substrings with count of each character as k

```cpp
// C++ program to count number of substrings
// with counts of distinct characters as k.
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// Returns true if all values
// in freq[] are either 0 or k.
bool check(int freq[], int k)
{
	for (int i = 0; i < MAX_CHAR; i++)
		if (freq[i] && freq[i] != k)
			return false;
	return true;
}

// Returns count of substrings where frequency
// of every present character is k
int substrings(string s, int k)
{
	int res = 0; // Initialize result

	// Pick a starting point
	for (int i = 0; s[i]; i++) {

		// Initialize all frequencies as 0
		// for this starting point
		int freq[MAX_CHAR] = { 0 };

		// One by one pick ending points
		for (int j = i; s[j]; j++) {

			// Increment frequency of current char
			int index = s[j] - 'a';
			freq[index]++;

			// If frequency becomes more than
			// k, we can't have more substrings
			// starting with i
			if (freq[index] > k)
				break;

			// If frequency becomes k, then check
			// other frequencies as well.
			else if (freq[index] == k &&
				check(freq, k) == true)
				res++;
		}
	}
	return res;
}

// Driver code
int main()
{
	string s = "aabbcc";
	int k = 2;
	cout << substrings(s, k) << endl;

	s = "aabbc";
	k = 2;
	cout << substrings(s, k) << endl;
}

```
-------------------------------------------------------------------------------------------------------

# iii) LAST YEAR ASKED QUESTIONS IN INTERVIEW

# Third round prep.
# [HR Prep](https://www.interviewbit.com/hr-interview-questions/)

# 1. Introduce yourself.

* Thank You sir/ma'am for giving this opportunity to introduce myself, I am Tannu Kumari, currently I am pursuing B tech from University College of Engineering and Technology Vinoba Bhave University in Information technolgy.


*  apart from my curriculum I have done a paid internship at coding Ninjas as a Teaching Assistant, My job there was to debug the code of students, suggesting them the optimal approach and algorithms for the problems,


*   in addition to that I have also done freelancing job in Chegg India as an expert for computer science, where I have solved more than 200 problems in computer science asked by students from all over the world.




* Also I have done  a project on Employee database management system using Tkinter framework of python,this is a GUI application in python which supports CRUD(create, read, update,   delete) operations and I had created various widgets including Frame, Entry, Buttons, Labels etc. this also supports reseting, displaying and pritning the data of the employee. for backend I had used MYSQL.

* Also I have Developed a pet adoption website named ADOPET to encourage people to adopt stray animals.

* I have also done a mentorship program at Girlscript Foundation where I Mentored a group of students in building a project on a Library management system which was a C++ based software illustrating OOPS (Object Oriented Programming) concepts and supports CRUD operation, and is used to issue books which maintains the database in a binary file.

* Apart from studies I am pretty much interested in chess and I have also won gold medal in state level chess championship.


# 2. What tech stack are you most comfortable with?
Data structures and Algortihms
# 3. Which data structure is used to implement auto-complete feature?
# 4. Brief discussion about Tries.
# 5. Implement Trie.
# 6. What is the hardest challenge you’ve faced and how did you overcome it?


# 7. Why do you want to join BNY Mellon?

* Whatever I have learnt is a theoritical knowledge, so by joining BNY mellon, I would have an opportunity to implement things practically

I've seen your company consistently listed as one of the top places to work, I've read employee testimonials and heard of your enthusiasm for encouraging employee growth through education, training and vast resources. I already know that engaged employees produce better work, and that is evident in the most recent campaign you created. I would love to join your innovative team, continue to create great work, and grow within the company by learning new skills.

Besides, I have researched your company and found that it has impressive and promising projections which made me excited to be a part of the amazing future.I would take pride in working under the great leadership of this company and I found this place to be a perfect fit for utilizing my expertise along with the promising aspect of personal growth.


* Global Company, Global Opportunities
With a dedicated business presence on six continents and in 35 countries, BNY Mellon delivers global scale at the local level. The depth and breadth of our organisation provides exciting opportunities for career and global mobility. Recognition programmes highlight individuals from our offices around the world who exemplify our company’s strategy and culture.

* Build Your Professional Experience
At BNY Mellon we believe continued education and development is paramount at every stage of your career. All employees benefit from our extensive Talent and Development framework, to access training opportunities and participate in a number of career development initiatives. If you are at the beginning of your career, we offer a Graduate Accelerator Programme over 18 – 24 months to enrich your skills and experience.

* Wellbeing Programme
We are dedicated to helping our colleagues be their best at home and at work through our holistic approach to wellbeing. BNY Mellon’s award-winning Wellbeing Programme provides a variety of options and resources to help our employees improve and maintain their physical health, emotional resilience, financial security and social connections. The programme supports employees with their unique health and wellbeing needs and makes it easier to achieve their goals.

* Flexible Benefits Package
We offer an attractive, flexible benefits package, allowing you to tailor your benefit choices to meet your personal circumstances. These include medical insurance, health screening, pension, life assurance, employee assistance programme, digital wellbeing app, fitness discount programme, on-site childcare and a parental buddy programme, to name a few.

* Diverse and Inclusive Environment
Our Diversity and Inclusion vision goes beyond deriving benefit and impact for our business. We are committed to creating the conditions where all can achieve their full potential.


Members of our Employee Resource Groups help drive our D&I strategy across business lines and regions. These groups provide employees with opportunities to share, collaborate and support one another through shared interests, common attributes and cultural heritage.


# 7.1 Why should we hire you?

 the most important thing which I believe I have is, I am striver and I am always hungry to learn, I am passionate about work, I am passionate about life, and this is not just true in the field of computer science, I am passionate towards learning every aspect of life

and If you give me an opportunity to prove myself that I have that hunger, I have that zeal in me than I promise you that I will prove you that your decision of selecting me was not wrong.

# 8. Tell me about the previous rounds.
* Tell about interviewer
* Kind of questions they asked
* Time se jada interview liya gaya th
* Judge krne k lie usne pura time liye, he took double time
* I was very happy due to this, as interviewer gave me proper time to explain my answer

# 9. Favourite programming language?
	C++
# 10. Do you know about the maps? Tell me something about it.
# 11. How hashing is done?
# 12. What is the Hash function? What will happen if a hash function returns 1 always?
# 14. Difference between map and unordered map
# 15. The interviewer discussed a lot about maps.
# 16. Discussed project which was mentioned in my resume. 

# 17. What are the challenges that you’ve faced till now?
Challenges I have faced till now:

In acaedemics:
* No senior support
* Not good faculties
* Environment was not good
* No guidance, No one to tell which path to follow
* No on campus opportunities
* Was always doing backtracking to find the best path



# 18. What technology you’ve worked on?
* I have worked on frontend(web dev)
* I have worked on backend(web dev)
* Tkinter framework of python
* 
# 19. Which databases have you used? Where have you used it?
# 20. Do you have any leadership experience?
# 21. What do you know about BNY Mellon and why you want to join it?

## Founder - Alexander Hamilton ( Bank of new york) + 
## CEO - Thomas P Gibbons
## the largest inside owner is Gerald Hassell
## Founded: 1 July 2007, New York, New York, United States

* The Bank of New York Mellon Corporation, commonly known as BNY Mellon, is an American investment banking services holding company headquartered in New York City. BNY Mellon was formed from the merger of The Bank of New York and the Mellon Financial Corporation in 2007. It is the world's largest custodian bank and asset servicing company, with $2.2 trillion in assets under management and $41.7 trillion in assets under custody as of the second quarter of 2021. It is considered a systemically important bank by the Financial Stability Board. BNY Mellon is incorporated in Delaware

* BNY Mellon is a provider of investment management and investment services and we are a world-renowned leader in each. When combined, the power of our extensive capabilities can help drive your success in markets around the world.

* BNY Mellon is a global investments company dedicated to helping its clients manage and service their financial assets throughout the investment lifecycle. Whether providing financial services for institutions, corporations or individual investors

* What are the four values of BNY Mellon?

Businesses, communities and global economies rely on us because we prioritize client experience, collaboration, innovation and resilience. As the “bank of banks,” our unique perspective, informed by one of the largest datasets in the world, powers the financial industry.

What is BNY doing in India?
For over 234 years, as the investment company for the world, we have been leading change in the global financial services industry. BNY Mellon Technology Private Limited, is a group company of BNY Mellon operating in India, providing technology solutions to the bank.

![Screenshot from 2021-11-08 14-17-22](https://user-images.githubusercontent.com/42698268/142071188-487ee403-abda-433a-9459-0d77e5368073.png)

![Screenshot from 2021-11-08 14-10-44](https://user-images.githubusercontent.com/42698268/142071211-331bce85-ec0a-48d0-b941-04331baa12ff.png)

## [Awards won by BNY](https://www.bnymellon.com/us/en/about-us/awards.html)

Most Important: BNY Mellon has received recent accolades for corporate social responsibility and diversity and inclusion. We are included in Bloomberg’s Gender Equality Index, CDP’s Climate Change ‘A List’, Fortune’s World’s Most Admired Companies list and the Human Rights Campaign’s Corporate Equality Index.

* BNY Mellon Included In The 2021 Bloomberg Gender-Equality Index For The Fourth Year In A Row
* For the seventh consecutive year BNY Mellon was awarded a position on the Climate Change ‘A List’ 
* BNY Mellon has been named one of the “World’s Most Admired Companies” by Fortune Magazine.
* Best Technology Service provider in 2021
* Best Places to Work for Disability Inclusion, Disability:IN and the American Association of People with Disabilities (AAPD), 2021
* World’s Most Admired Companies, Fortune Magazine, 2020
* Industry Person of the Year, Caroline Butler (Global Head of Custody), Global Custodian, 2021 
* Most Powerful Women in Banking, Emily Portney (BNY Mellon Chief Financial Officer) and Paulette Mullings Bradnock (BNY Mellon Chief Audit Executive), American Banker, 2020
* Most Powerful Women in Banking, Paulette Mullings Bradnock (BNY Mellon Chief Audit Executive), American Banker, 2019
* Industry Legend, Hani Kablawi (Head of International at BNY Mellon), Global Custodian's Leaders In Custody Awards, 2020

## iNautix Technologies Private Limited 
iNautix Technologies Private Limited is a subsidiary of Bank of New York (BNY) Mellon that provides technology solutions and software solutions for clients of BNY Mellon. Their work philosophy is based upon continuous improvement and cost-effectiveness through technology. It provides services such as infrastructure hosting, automating processes, business analytics, and human factors engineering among others. The company mainly deals with compensation management, datawarehousing and BI, document management, customer application and software consulting. The Bank of New York Mellon is committed to provide the services like flexible technology, robust trading services and operational support.

# 22. [Puzzle - 8 ball problem](https://www.geeksforgeeks.org/puzzle-8-balls-problem/)
# 23. A detailed discussion on my fields of interest.- the technologies which I have worked on and would like to in the future.
# 24. He asked about problems faced in doing projects technologically wise and managing wisely too.
* Adopet:
	* Saw problem
	* couldnt decide, what I can do to solve this problem
	* then thought of creating a website
	* Now, this was totally new thing, as i can't take a reference as there isn't any kind of website on the internet
	* so I had to think evrything from the scratch
	* from the name of the website to the logo
	* I have designed everything by myself
	* 
# 25. [how will I tackle a dispute among my team members while working on a group project](https://www.sandler.com/blog/professional-development-blog/ways-to-deal-with-team-conflict-effectively/)

How to handle disagreement: https://hbr.org/2017/07/how-to-handle-a-disagreement-on-your-team

# 26. where do I want to see myself after 5 years
Ans : Senior program manager:
* SDE
* Senior SDE
* Tech lead
* Associate program manager
* Program manager
* Senior program manager


# 27. how do I fit for the role and my expectations from BNY.

# 28. What actions have you taken to achieve your long and short-term goals so far?
# 29. Do you use any online platforms for learning about the latest developments in the field?
# 30. Are you a member of any professional society or research organisation?
# 31. My areas of interest? I answered ML and DL.
# 32. Tell me something about ML that fascinates you.
# 33. How would you handle a dispute in your project team? What would you do if your team members are disinterested and lazy?
# 34. Why is Java preferred in the industry?

* One of the biggest reasons why Java is so popular is the platform independence.
*  Programs can run on several different types of computer; 
*  as long as the computer has a Java Runtime Environment (JRE) installed, a Java program can run on it. 
*  Java is fundamentally object-oriented.
*  critical areas in which it is used:
	* Building Android apps
	* Java web applications
	* Software tools
	* Scientific applications

* Java has the best collection of frameworks even today in comparison to Python. For example, the Spring framework is the reason why big companies prefer to use Java as it is easy for the small development teams to collaborate and work in a more organized way
* Java is used to build applications and platforms for a number of devices, including computers, laptops, gaming consoles, Blu-ray players, car navigation systems, medical monitoring devices, parking meters, lottery terminals and smartphones
* 90% of the Fortune 500 companies still rely on Java for their development projects. Globally, there are over 8 million Java developers.
* Java is user-friendly - ava has an English-like syntax, which makes it the perfect language for beginners
* Java for everything - For long, Java has been the staple programming language for developing Web apps, Android apps, and software tools like Eclipse, IntelliJ IDEA, NetBeans IDE, etc. Today, Java’s use cases have expanded to Data Science applications, Machine Learning applications, and even IoT. Developers and programmers prefer Java for designing all such applications because Java has a suite of high-level concurrency tools and packages that make it possible to create highly scalable solutions. Also, Java is multi-platform compatible.
* ava boasts of rich API - Although Java contains around fifty keywords, its Application Programming Interface (API) is both extensive and rich – it is replete with numerous methods that you can directly use in any code. Java API comprises methods that can cater to every purpose, including networking, connecting to databases, parsing XML, handling input-output, and so on. Furthermore, Java has plenty of open-source libraries such as Google Guava, Apache Xerxes, Apache POI, Apache Commons, OpenCV, Gson, ETC.
* A robust community backs Java - One of the biggest reasons for Java’s popularity is its strong and active community support. It boasts of being the second-largest among the Stack Overflow community. So, rest assured, you can rely on the Java community to help you out if you ever get stuck in a programming rut.
* ava has excellent documentation - Java is an open-source programming language, which means it is absolutely free. Another excellent quality of the language is that Java is well-documented. It has a detailed guide that will clarify the problems that you may face while coding in Java. 
* Java has a suite of powerful development tools - One of Java’s most interesting aspects is its Integrated Development Environment (IDE). Java’s IDE is an extensive suite of various automation tools, editors, and debuggers. NetBeans, Eclipse, and IntelliJ IDEA are the three most popular Java IDEs. As for tools, Java has Maven and ANT for developing Java applications, Jenkins for Continuous Integration and delivery, and JConsole and Visual VM for monitoring Heap usage. 

# 35. What is inheritance?
# 36. What is multiple inheritance?
# 37. What is memory sequencing?
# 38. Practical applications of ML and Dl.
# 39. Puzzle: 10 people shake hands with each other. How many handshakes will be there in total?

The formula for the number of handshakes possible at a party with n people is

# handshakes = n*(n - 1)/2.
This is because each of the n people can shake hands with n - 1 people (they would not shake their own hand), and the handshake between two people is not counted twice.

# 40. Any questions for me?
# 41. why I chose Computer Science as my career
* I can explore my passion of mathematics and problem solving, as I have always loved maths
* To solve real life problems using code
* It is a field, where everyday I will have new thing to learn
* Can automate small and boring tasks
* Everything shows instant results, which fascinates a lot
* Teaches you Technical skills such as programming, and non-technical skills such as problem-solving and leadership
* I can contribute in making the world a better place


# 42. Then he asked all about my projects and internships and every other detail on my resume.
# 43. He gave me some situations and asked me how would I react or manage in such situations.
# 44. Then he asked some situations from my life in which I’ve exceeded my expectations

* During a competitive coding, solved graph problem
* Solved problem in pressure in group at last moment


# 45. How I managed to stay motivated.
# 46. Make sure to read about the company, especially for the Bar-Raiser round. Facts like CEO and Founders of the company, principles followed by the company, awards received by the company etc. must be considered while reading about the company.
# 47. I was asked to sort a list using a single line using stream Api .
# 48. Asked about projects and some Hr related questions like tell me about yourself .
# 49. Asked me to explain the code which I had solved in Round 1 on paper.
# 50. Give a brief summary about yourself, what all things you have done so far – technical, no technical both
# 51. Java and python difference – which one do you think is better?
# 52. Why do you prefer to code in Java?
# 53. What are all projects you have done and implementations?
# 54. Why did you choose this problem statement as your project, what was your thought process to come with this problem statement specifically?
# 55. How you tested your project?
# 56. Tell me about a time when you could not do well in academics and how you tackled this situation.
# 57. Do you think that doing all these projects was beneficial? If yes then how?
# 58. What are your future plans?
# 59. Have been involved in any technical discussion forums – how do you keep yourself updated?
# 60. Do you want to highlight any point which we missed to discuss which will add value to your candidature?
# 61. He asked tech stack-related questions
# 62. A simple puzzle: Given 2 jars one of 4 liters, the other 5 liters, and an infinite water supply, how to measure 7 liters of water using these 2 jars. and
# 63. Tell me about a time where you displayed leadership skills.” and few similar HR questions and
# 64. What I knew about BNY Mellon. and If I had any questions for him.
# 65. How will you learn something which is not in your syllabus?
# 66. What will you do when your team is performing very poorly although having great members ??He expected honest answers rather than ideal ones…
# 67. Then he asked some questions related to the operating system.
# 68. How do you implement a Graph?
# 69. Discussion on the pointer in c++
# 70. Memory leak
# 71. Discussion on Dynamic memory allocation and new operator in c++
# 72. How do you represent 2D array using pointer
# 73. What are constructors and destructors?
# 74. Which algorithms are generally used in  DBMS. (Searching and sorting )
# 75. Different types of Searching algorithms.
# 76. Detailed Discussion on Project
# 77. What is your hobby?
# 78. Tell me the situation where you got beyond your expectations?
# 79. Do you know about BNY?
# 80. Where do you see yourself in 5 years?
# 81. Tell me about yourself? 
# 82. Discussion on questions solved in the coding round. Asked about my approach and he told my score. I described my approaches, and he was satisfied with them. 
# 83. How do you keep yourself motivated? 
# 84. Detailed discussion on the project. 
# 85. Do you know about BNY? 

# 86. [Tell me difference Between Library  And Module](https://stackoverflow.com/questions/4099975/difference-between-a-module-library-and-a-framework)
# 87. Write Code of any one module of  your project you know.

# 88. Write function for Binary tree  to check  whether  its  different  nodes value that are present in different paths   in a tree are equal to number X when values of nodes are being added.

# 89. Tell me about the latest Technology you are working on, and how it is going to affect the human beings.

# 90. Again write a function  for question 

-given  m, n where 

m -is no.of  9’s

n- is no .of  0’s

a number is formed by combining m & n and it can have any no. of 9’s and 0’s like-(9, 90, 999, 9090, 9000…etc) and it is starting from 9

you are given X a number where you have to find the smallest number that is formed by the combination of m & n and is divisible by  X

# 91. You are working on the project  and have completed it and during its presentation the project fails, how you are going to handle the situation.

# 92. Where you see Yourself after 5 years, how you are going to achieve that 

# 93. LAST QUESTION -(which was like final nail in the coffin)

 Logical based–

You are provided a work which usually take 10 days to finish, you have to complete that work in  7 days without  doing any extra hours and this work have to be done alone, how you are going to do that?

Ans– First, I smiled because this is the same question which I had  discussed with my friends the day before the interview.

I answered within 2-3 seconds back, and the look on the face of the interviewer was really  intriguing.

 I answered–“” First we are going to schedule are task according to our priority, and then we are going to maintain record of  each task,   if any task during the work is going to be repeated, I am going to look for it in the  record table and not going to work again on that task.This Approach follows Dynamic  Programming approach of global optimization.”  
 
 # 94. Before  the interview  I had gone through the   whole “” TOP 10 Algorithms in the Interview  Questions””

link : “https://www.geeksforgeeks.org/top-10-algorithms-in-interview-questions/“

# 95. Given a triangle and 3 ants at each edge. They can move in any direction. Find out the probability of ants not colliding with each other. 

-------------------------------------------------------------------------------------------------------------
Note: 
* Question I can ask: life as an SWE in the finance sector. 
* Be confident, even if you’re not sure of your answers. The interviewer will test your patience and endurance by making you second guess your answers but don’t let your nerves get the best of you. 
* HR will try to put in various challenging situations but your attitude should always be positive and confident. They can see who is being natural, genuine, and who isn’t. Most importantly, ask unique and role-related questions from your interviewer. 
*  be honest. Don’t try to lie because the interviewer can catch it. Show genuine interest in the company and the work that they do. 
*  Bar-Raiser Interviews are majorly managerial, but this fact mustn’t be taken lightly. You should prepare yourself well enough for this round too.
*  Make sure to read about the company, especially for the Bar-Raiser round. Facts like CEO and Founders of the company, principles followed by the company, awards received by the company etc. must be considered while reading about the company.
*  Keep in mind Time matters so much in all the interviews and do not lie for any reason.




.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.



-------------------------------------------------------------------------------------------------------------

---------------------------------------------------------------------------------------------------------------

# 0. Introduce yourself.
# 1. Brief discussion about my final year project.
# 2. [Decimal Equivalent of Binary Linked List](https://www.geeksforgeeks.org/decimal-equivalent-of-binary-linked-list/)

## My approach(01): 
Take two pointers, traverse both of them until all the initial zero passed and then move first pointer upto the end to calculate the size of the LL and then start moving the second pointer and along with that, keep caluclating the value by ```ans += pow(2, size) * head->value```

OR

Take two pointers, calculate size of LL using one pointer and then use the second pointer to find the value of the binary ```ans += (head->value * pow(2, count)) ``` and then decrease count each time.

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
    int getDecimalValue(ListNode* head) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        
        int count = 0;
        while(ptr2->next != NULL){
            ptr2 = ptr2->next;
            count++;
        }
        int ans = 0;
        while(ptr1 != NULL){
            ans += (ptr1->val * pow(2, count));
            count--;
            ptr1 = ptr1->next;
        }
        return ans;
    }
};
```

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
* family pressure, and did education against them
* they wanted to marry me
* made them proud by being top in university
* performed well in chess
* I am first girl child from my family to attend university


# 10. Why do you want to join BNY Mellon?

I've seen your company consistently listed as one of the top places to work, I've read employee testimonials and heard of your enthusiasm for encouraging employee growth through education, training and vast resources. I already know that engaged employees produce better work, and that is evident in the most recent campaign you created. I would love to join your innovative team, continue to create great work, and grow within the company by learning new skills.

* kuch facts company ka batao(epam k ek delivery manager h sandeep joshi jiska quote h "if engineering is in your dna, then come and join epam" this is the slogan of sandeep joshi who is representing india to the world level")
* also epam garaje developed mask similar to m95, for poor people which is part of social work 

* just find out these kind of facts of bny
* i have offer letter of apisero but i want to join bny mellon, because

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
## BFS and all of its advantages
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

# 16. Where graph traversals algorithms are used? 
Graph traversal algorithms: 
* BFS
* DFS

These are used in:
* checking whether a graph is bipartite or not
* cycle detection
* Topological sort
* Finding shortest path in undirected graph with unit weights

# 17. Tell about different traversal algorithms
## Graph:
* DFS
* BFS

## Tree
* Inorder
* Preorder
* Postorder
* Level order

# 18. write the order of printing of nodes in the inorder and pre-order traversal.

* Inorder : left root right
* Preorder: root left right

# 19. Coding question: https://leetcode.com/problems/linked-list-cycle-ii/

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};
```

# 20. Coding question: https://leetcode.com/problems/palindromic-substrings/

We perform a "center expansion" among all possible centers of the palindrome.

Let N = len(S). There are 2N-1 possible centers for the palindrome: we could have a center at S[0], between S[0] and S[1], at S[1], between S[1] and S[2], at S[2], etc.

To iterate over each of the 2N-1 centers, we will move the left pointer every 2 times, and the right pointer every 2 times starting with the second (index 1). Hence, left = center / 2, right = center / 2 + center % 2.

From here, finding every palindrome starting with that center is straightforward: while the ends are valid and have equal characters, record the answer and expand.

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int N = s.length();
        int ans = 0;
        //find out all the 2n-1 centers
        for(int center=0; center<(2*N-1); center++){
            int left = center/2;
            int right = left + center%2;
            //and find out for each center, how many palindromes are there
            while(left>=0 && right<N && s[left] == s[right]){
                ans++;
                left--;
                right++;
            }
        }
        return ans;
    }
};
```

# 19. SQL query –> Employee and department table is given you need to find the maximum salary of employees in each department

``` SELECT DEPT_ID, MAX(SALARY) FROM department GROUP BY DEPT_ID;```
## [Answer](https://www.geeksforgeeks.org/sql-query-to-find-the-highest-salary-of-each-department/)

# 20. What is Lambda?
* Example

``` python
# Double all numbers using map and lambda
  
numbers = (1, 2, 3, 4)
result = map(lambda x: x + x, numbers)
print(list(result))

```
``` output [2, 4, 6, 8] ```

You can also square them instead of doubling them like this:

``` python
# square all numbers using map and lambda
  
numbers = (1, 2, 3, 4)
result = map(lambda x: x * x, numbers)
print(list(result))

```
``` output [1, 4, 9, 16] ```

Some definitions:
* Lambda expressions (or lambda functions) are essentially blocks of code that can be assigned to variables, passed as an argument, or returned from a function call, in languages that support high-order functions. They have been part of programming languages for quite some time.
* In mathematics and computer programming, the Lambda symbol is used to introduce "anonymous functions." Lambda notation distinguishes between variables used as mathematical arguments and variables that stand for predefined values.
* In computer programming, an anonymous function (function literal, lambda abstraction, lambda function, lambda expression or block) is a function definition that is not bound to an identifier.
* Essentially a lambda is a block of code that can be passed as an argument to a function call.([explanation](https://martinfowler.com/bliki/Lambda.html)), 

* Example:

Essentially a lambda is a block of code that can be passed as an argument to a function call. I'll illustrate this with a simple example. Imagine I have a list of employee objects and I want a list of those employees who are managers, which I determine with an IsManager property.

```ruby
def managers(emps)
  return emps.select {|e| e.isManager}
end
```

Essentially select is a method defined on the Ruby collection class. It takes a block of code, a lambda, as an argument. In ruby you write that block of code between curlies (not the only way). If the block of code takes any arguments you declare those between the vertical bars. What select does is iterate through the input array, executes the block of code with each element, and returns an array of those elements for which the block evaluated as true.

Now if you're a C programmer you probably think "I could do that with a function pointer", if you're a Java programmer you probably think "I could do that with an anonymous inner class". These mechanisms are similar to lambdas, but there are two telling differences.

The first one is a formal difference, lambdas usually define closures - which means they can refer to variables visible at the time they were defined. Consider this method
```
def highPaid(emps)
  threshold = 150
  return emps.select {|e| e.salary > threshold}
end
 ```
Notice that the code in the select block is referring to a local variable defined in the enclosing method. Many of the alternatives to lambdas in languages that don't have real closures can't do that. Lambdas allow you to do even more interesting stuff. Consider this function.
```
def paidMore(amount)
  return lambda {|e| e.salary > amount}
end
```
The second difference is less of a defined formal difference, but is just as important, if not more so in practice. Languages that support lambdas allow you to define them with very little syntax. While this might not seem an important point, I believe it's crucial - it's the key to make it natural to use them frequently.

### Some more definitions of lambda

* In very simple, informal words to someone that knows very little or nothing on math or programming, I would explain it as a small "machine" or "box" that takes some input, makes some work and produces some output, has no particular name, but we know where it is and by just this knowledge, we use it.

Practically speaking, for a person that knows what a function is, I would tell them that it is a function that has no name, usually put to a point in memory that can be used just by referencing to that memory (usually via the usage of a variable - if they have heard about the concept of the function pointers, I would use them as a similar concept) - this answer covers the pretty basics (no mention of closures etc) but one can get the point easily.

* In short, a lambda is just an anonymous and inline function.
* Lambda is an anonymous function. This means lambda is a function object in Python that doesn't require a reference before. 

* Imagine that you have a restaurant with a delivery option and you have an order that needs to be done in under 30 minutes. The point is clients usually don't care if you send their food by bike with a car or barefoot as long as you keep the meal warm and tied up. So lets convert this idiom to Javascript with anonymous and defined transportation functions.

Below we defined the way of our delivering aka we define a name to a function:

```
// ES5 
var food = function withBike(kebap, coke) {
return (kebap + coke); 
};
```
What if we would use arrow/lambda functions to accomplish this transfer:
```
// ES6    
const food = (kebap, coke) => { return kebap + coke };
```
You see there is no difference for client and no time wasting to think about how to send food. Just send it.

# 21. What is a virtual function?
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

# 22. What is docker? What is cloud computing? (I didn’t mention these in my resume)

### Docker
Docker is an application build and deployment tool. It is based on the idea of that you can package your code with dependencies into a deployable unit called a container. 

For a visual explanation, think of the shipping containers used for intermodal shipping. You put your package (code and dependencies) in the container, ship it using a boat or train (laptop or cloud) and when it arrives at its destination it works (runs) just like it did when it was shipped.

basically Docker is an open platform for developing, shipping, and running applications. Docker enables you to separate your applications from your infrastructure so you can deliver software quickly. With Docker, you can manage your infrastructure in the same ways you manage your applications.

### Cloud computing
* basically Cloud computing is the delivery of different services through the Internet, including data storage, servers, databases, networking, and software.

These can be stored on cloud and can be accessed from anywhere: E-mail, Documents, Blogs, Spreadsheets, Video, Pictures, Calender, Chat, Presentations, Address Book

We can access them using: Desktop, Laptop, smartphone, Tablet
Cloud computing is a technology that uses the internet for storing and managing data on remote servers, and then access data via the internet. ... One such example is Google cloud – It is a suite of public cloud services offered by Google. All the application development run on Google hardware.

There are 3 main types of cloud computing services: Infrastructure-as-a-Service (IaaS), Platforms-as-a-Service (PaaS), and Software-as-a-Service (SaaS).

# 23. Do you know Java? I said I know the basics, so – What is the entry point of a code in Java? Tell the syntax? Why main is static?

## Entry point
In computer programming, an entry point is a point in a program where the execution of a program begins, and where the program has access to command line arguments. To start a program's execution, the loader or operating system passes control to its entry point.

## The main method is the entry point of a Java application.
Specifically、when the Java Virtual Machine is told to run an application by specifying its class (by using the java application launcher), it will look for the main method with the signature of public static void main(String[]).

## Code in java, file : HelloWorld.java
```java
/* This is a simple Java program.
FileName : "HelloWorld.java". */
class HelloWorld
{
	// Your program begins with a call to main().
	// Prints "Hello, World" to the terminal window.
	public static void main(String args[])
	{
		System.out.println("Hello, World");
	}
}

```
* **Class definition**:This line uses the keyword class to declare that a new class is being defined.
class HelloWorld 
HelloWorld is an identifier that is the name of the class. The entire class definition, including all of its members, will be between the opening curly brace  {  and the closing curly brace  } .

* **main method**: In Java programming language, every application must contain a main method whose signature is:
public static void main(String[] args)

   * public: So that JVM can execute the method from anywhere.
   * static: Main method is to be called without object. 
   The modifiers public and static can be written in either order.
   * void: The main method doesn't return anything.
   * main(): Name configured in the JVM.
   * String[]: The main method accepts a single argument: 
             an array of elements of type String.
Like in C/C++, main method is the entry point for your application and will subsequently invoke all the other methods required by your program.

* The next line of code is shown here. Notice that it occurs inside main( ).
``` 
System.out.println("Hello, World");
```
This line outputs the string “Hello, World” followed by a new line on the screen. Output is actually accomplished by the built-in println( ) method. System is a predefined class that provides access to the system, and out is the variable of type output stream that is connected to the console.

* Comments: They can either be multi-line or single line comments.

```java
/* This is a simple Java program. 
Call this file "HelloWorld.java". */
```
This is a multiline comment. This type of comment must begin with /* and end with */. For single line you may directly use // as in C/C++.

## Java Program to add two numbers: file : Main.java
```java
import java.util.Scanner;

class Main{
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        System.out.println("Hello world");
        
        int a = scan.nextInt();
        int b = scan.nextInt();
        int sum = a+b;
        System.out.println("Sum is " + sum);
        
    }
};
```

# 24. Tell me about Switch & Hub. Which data structure is used in switches?
[in mor edetail](https://www.geeksforgeeks.org/difference-between-hub-and-switch/)

**Hub:**

A Hub is a networking device that allows you to connect multiple PCs to a single network, whereas a Switch connects various devices together on a single computer network. A Hub operates on the physical layer, whereas Switch operates on the data link layer.

**Switch:**

Switch is a network device which is used to enable the connection establishment and connection termination on the basis of need. Switch is operated on Data link layer. In this packet filtering is available. It is type of full duplex transmission mode and it is also called efficient bridge. 

hub - jo request jayega uska result wo sbko bhej dega jo v connected h, koi filtering ni krega 
jo v packet aya h, wo saarey ports pe bhej dega jo v connected h aur computer decide krega ki ye mere lie h ya nahi

* Hashmap is used in switches
* switches: kaun sa mac address kaun sa port se connected h, 

![Screenshot from 2021-11-06 18-07-20](https://user-images.githubusercontent.com/42698268/140609974-e69e5763-6354-4899-8fd8-868d43362a0e.png)



agar 2 computer connected h aur hm request bhej rhe h google ko to wo jab bhejega information to check krega mera mac address kis port se connected h aur mera mac address jis port se connected h uspe bhej dega.
* hashtble - mac address key, aur port ko value rkhna hoga
* ek switch se utne computer connected hongey jitne port hongey
## In short: 
### OSI model and their 7 layers
* Physical layer wroks on - Bits(0,1)
* Data link - Mac adrs
* Network laye - IP address( internet protocol - ipv4, ipv6)
* Transport layer - port number(tcp, udp), (agar ip address aur amc address diya jaye to wo computer tak phch jayega lkin kis process ko dena h to port number batayega) example- jab courier ayega to address aur house number k alawa apko us person ka name dena hoga jisko parcel dena h
* session layer - if i am connecting to google, to mere aur google k bich session baneg ajust like session
* presentation - compression hota h jaise kisi data ko secure krke bhejna h to compress krke bhejte h
* Application - saara application kaam kr rha h jo v net se connected h, http, ftp, smtp(simple mail transfer protocol)

![7 layers](https://user-images.githubusercontent.com/42698268/140606486-48fa8a54-60e5-414d-ba99-7a1c847333cc.jpeg)


![osi model](https://user-images.githubusercontent.com/42698268/140606456-1b3b51c3-62a6-410e-b0c1-1787b118fbf0.jpeg)

## [Explanantion of OSI Model](https://www.geeksforgeeks.org/layers-of-osi-model/)




# 26. Find how you can generate a given sequence of numbers from the BST shown on the whiteboard.

# 27. [Which databases have you used? Difference between SQL and NoSQL.](https://www.geeksforgeeks.org/difference-between-sql-and-nosql/)


![Screenshot from 2021-11-06 18-05-07](https://user-images.githubusercontent.com/42698268/140609852-27b19a62-4586-4c19-b0a7-a70dbe980162.png)


# 28. What servers have you used?
* i've used apache server to host my project locally on my computer
* local host - is an ip (127. 0. 0. 1 ip will be used to access locally hosted files)
* agar aise host krna padey to server kharidna padega to wo isp(intenet service provider) wo tmko ek ip dega




# 29. What is the CAP theorem?

* consitency - accurate results
* atomicity/ availability(take a look)- ALL OR NONE
* partition tolerance - cluster of nodes, they all communicate and if communication is not happening dur to something still system chalna chahiye, i.e combined system chalte rhna chahiye( it is a kind of durability)

i.e koi node fail kr jaye fir v tmhara system kaam krna chahiye

* this is used in non relational database


# 30. Tell me about the previous rounds.

# 31. Favourite programming language?
C++

* Advantage of c++ over java
	* advantages of C++ over Java:

		1- C++ is compiled language whereas Java code is compiled as well as interpreted. That means execution of C++ programs is faster than Java program.

		2- C++ supports operator overloading (ad hoc polymorphism) it means we can perform computation on objects. Whereas Java does not support operator overloading.

		3- C++ supports multiple inheritance but Java does not support multiple inheritance using classes, which is accomplished using “interface”.

		4- C++ use pointers whereas Java does not use pointers. So, directly we cannot do system level programming using Java (rather we can embed c or c++ code in java using JNI).
	* C++ is powerfull because you can control everything, run faster and have a great performance. C++ programs are faster. C++ is a multiparadigm language i.e. we can write either object oriented or procedural programs. But in java we can only write object oriented programs.
	
* Advanatge over python
* General advantages
	* very fast
	* One of the biggest advantages of C++ is the feature of object-oriented programming which includes concepts like classes, inheritance, polymorphism, data abstraction, and encapsulation that allow code reusability and makes a program even more reliable.
	* Supports most C features
	* Memory management
	* Statically typed

# 32. Do you know about the maps? Tell me something about it.

* A map is a data structure that's designed for fast lookups. Data is stored in key-value pairs with every key being unique. Each key maps to a value hence the name. These pairs are called map entries.
* A Map is a type of fast key lookup data structure that offers a flexible means of indexing into its individual elements. These keys, along with the data values associated with them, are stored within the Map. ... Each entry of a Map contains exactly one unique key and its corresponding value.
* Map is dictionary like data structure. It is a sequence of (key, value) pair, where only single value is associated with each unique key. It is often referred as associative array.
* Keys are in sorted order in map, and the value associated with them are the frequency of the element

# 33. How hashing is done?

* Hashing is a technique or process of mapping keys, values into the hash table by using a hash function. It is done for faster access to elements. The efficiency of mapping depends on the efficiency of the hash function used.

* Hashing is a technique that is used to uniquely identify a specific object from a group of similar objects. Some examples of how hashing is used in our lives include:

	* In universities, each student is assigned a unique roll number that can be used to retrieve information about them.
	* In libraries, each book is assigned a unique number that can be used to determine information about the book, such as its exact position in the library or the users it has been issued to etc.
In both these examples the students and books were hashed to a unique number.

Assume that you have an object and you want to assign a key to it to make searching easy. To store the key/value pair, you can use a simple array like a data structure where keys (integers) can be used directly as an index to store values. However, in cases where the keys are large and cannot be used directly as an index, you should use hashing.

In hashing, large keys are converted into small keys by using hash functions. The values are then stored in a data structure called hash table. The idea of hashing is to distribute entries (key/value pairs) uniformly across an array. Each element is assigned a key (converted key). By using that key you can access the element in O(1) time. Using the key, the algorithm (hash function) computes an index that suggests where an entry can be found or inserted.

Hashing is implemented in two steps:

  1. An element is converted into an integer by using a hash function. This element can be used as an index to store the original element, which falls into the hash table.
	
  2. The element is stored in the hash table where it can be quickly retrieved using hashed key.
```
  hash = hashfunc(key)
  index = hash % array_size
 ```

In this method, the hash is independent of the array size and it is then reduced to an index (a number between 0 and array_size − 1) by using the modulo operator (%).


# 34. What is the Hash function? What will happen if a hash function returns 1 always?

* A hash function is any function that can be used to map a data set of an arbitrary size to a data set of a fixed size, which falls into the hash table. The values returned by a hash function are called hash values, hash codes, hash sums, or simply hashes.

To achieve a good hashing mechanism, It is important to have a good hash function with the following basic requirements:

  1. Easy to compute: It should be easy to compute and must not become an algorithm in itself.

  2. Uniform distribution: It should provide a uniform distribution across the hash table and should not result in clustering.

  3. Less collisions: Collisions occur when pairs of elements are mapped to the same hash value. These should be avoided.

Note: Irrespective of how good a hash function is, collisions are bound to occur. Therefore, to maintain the performance of a hash table, it is important to manage collisions through various collision resolution techniques.


* If the equals method is implemented as per the contract and the hashcode method returns a constant value, then we will still be able to retrieve the value for the key from a hashMap, but the performance will be slow compared to the method returning a unique hashcode.


# 35. Difference between map and unordered map


**Use std::map when**

  * You need ordered data.
  * You would have to print/access the data (in sorted order).
  * You need predecessor/successor of elements.
  * See advantages of BST over Hash Table for more cases.

```cpp
// CPP program to demonstrate use of std::map
#include <bits/stdc++.h>

int main()
{
	// Ordered map
	std::map<int, int> order;

	// Mapping values to keys
	order[5] = 10;
	order[3] = 5;
	order[20] = 100;
	order[1] = 1;

	// Iterating the map and
	// printing ordered values
	for (auto i = order.begin(); i
		!= order.end(); i++) {
		std::cout << i->first
				<< " : "
				<< i->second << '\n';
	}
}
```
```
output:
1 : 1
3 : 5
5 : 10
20 : 100
```
**Use std::unordered_map when** 

  * You need to keep count of some data (Example – strings) and no ordering is required.
  * You need single element access i.e. no traversal.

```cpp
// CPP program to demonstrate use of
// std::unordered_map
#include <bits/stdc++.h>

int main()
{
	// Unordered map
	std::unordered_map<int, int> order;

	// Mapping values to keys
	order[5] = 10;
	order[3] = 5;
	order[20] = 100;
	order[1] = 1;

	// Iterating the map and
	// printing unordered values
	for (auto i = order.begin();
		i != order.end(); i++)
	{
		std::cout << i->first
				<< " : "
				<< i->second << '\n';
	}
}

```

```
1 : 1
20 : 100
5 : 10
3 : 5
```

# 36. The interviewer discussed a lot about maps.

# 37. What are the challenges that you’ve faced till now?

# 38. What technology you’ve worked on? Why you choose Django? What is ORM?

# 39. Which databases have you used? Where have you used it?

* relational and non relational
* I have used Mysql

Greater benefits have been achieved in Mysql, for being open sourced and providing, for the operational environment, the same functionality as any DBMS (cost-benefit ratio)


# 40. Do you have any leadership experience?
* coding ninjas
* girlscript

# 41. What do you know about BNY Mellon and why you want to join it?



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

# 46. [Count ways to express a number as sum of consecutive numbers](https://www.geeksforgeeks.org/count-ways-express-number-sum-consecutive-numbers/)

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
# 47. Basic java input-output questions related to operators.
# 48. Language preferred, and the reason for it. Difference between java and c++.
# 49. Difference between method overloading and overriding.
# 50. Super keyword in java and its uses.
# 51. Do you know how the code is actually deployed on machines in the real world?
# 52. A very brief discussion on projects.
# 53. An SQL Query.
# 54. 2 logical puzzles –  https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/ 
# 55. Detailed discussion on my projects
# 56. What is a tuple in python?
# 57. SQL queries
# 58. What are cookies?
# 59. What is scope in a programming language?
# 60. Explain outer join in DBMS
# 61. Run time polymorphism
# 62. Inner class vs sub class
# 63. Interface vs abstract class
# 64. Design a DBMS for the School attendance System
# 65. Where do you see yourself in 5 years?
# 66. What actions have you taken to achieve your long and short-term goals so far?
# 67. Do you use any online platforms for learning about the latest developments in the field?
# 68. Are you a member of any professional society or research organisation?
# 69. My areas of interest? I answered ML and DL.
# 70. Tell me something about ML that fascinates you.
# 71. How would you handle a dispute in your project team? What would you do if your team members are disinterested and lazy?
# 71. Why is Java preferred in the industry?
# 72. What is inheritance?
# 73. What is multiple inheritance?
# 74. What is memory sequencing?
# 75. Practical applications of ML and Dl.
# 76. Puzzle: 10 people shake hands with each other. How many handshakes will be there in total?


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








