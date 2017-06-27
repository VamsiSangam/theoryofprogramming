Directory Structure
----
The general directory structure is as follows -
```
category_name
        |------ post_name
                     |------ C
                             |------- algorithm.c
                             |------- input1.txt
                             |------- output1.txt
                             |------- input2.txt
                             |------- output2.txt
                     |------ C++
                             |------- algorithm.cpp
                             |------- input1.txt
                             |------- output1.txt
                             |------- input2.txt
                             |------- output2.txt
```
Here ```category_name``` would be names such as -
* Graph Theory
* Dynamic Programming
* Searching Algorithms

They are not something you would create by yourself. Inside these category folders, there's a folder for each post which comes into that category. The ```post_name``` folders would go by names such as -
* Edit Distance
* Kadane's Algorithm
* Binary Heaps

They too are not something you would create by yourself. Under each post is the language specific implementation code, which is separately placed into the folder named by its language.

Suppose you wish to add the python implementation for the above example directory structure, then you would create a new folder named ```Python``` under the ```post_name``` directory. There you would add your ```.py``` files and the sample input and output files.

While this is the regular structure, some posts may have a structure such as -
```
category_name
        |------ post_name
                     |------ C
                             |------- algorithm.c
                     |------ C++
                             |------- algorithm.cpp
                     |------ Test Cases
                             |------- input1.txt
                             |------- output1.txt
                             |------- input2.txt
                             |------- output2.txt
```
So, here the test cases are separated out into a separate folder. Example, have a look at the [Snakes and Ladders Game Code](https://github.com/VamsiSangam/theoryofprogramming/tree/master/Graph%20Theory/Snakes%20and%20Ladders%20Game%20Code) structure. The reason this is done for some posts is because, posts such as these, or say Snakes and Ladders are posted as problems in online judges such as Hackerrank, Spoj, LeetCode, etc. The test cases can be downloaded from there, and these are very well-crafted test cases. So, all the language implementations must follow these test cases for input and and must give the correct output.

If all this seems too overwhelming to you, don't worry! Make a new pull request/issue before you contribute and have your doubts cleared there!
