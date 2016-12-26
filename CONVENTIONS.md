Coding Conventions
----
* For any language, your file must begin with comments in style given below (the comments must start at line 1 before any line of code) -
``` C
/* ===== ===== =====

Theory of Programming

<mention_the_algorithm_or_data_structure_name>
<give_the_link_to_corresponding_theory_of_programming_post>
GitHub - https://github.com/VamsiSangam/theoryofprogramming
Code Contributor - <contributor_name>, <other_contributor_name_if_any>

===== ===== ===== */
```
* Your file name (or public class name in languages like Java, C#) must be the name of the algorithm or the data structure.
* For languages like C, your method names and variable names must follow [Camel Case](https://en.wikipedia.org/wiki/Camel_case) naming convention (starts with lower case). For other languages like Java (follow Camel case for methods and variables, Pascal case for classes) or Python (follow the underscore separation style) etc., please follow the language recommended naming convention.
* Your code must be fully indented. You may follow [any indentation style](http://theoryofprogramming.com/2016/11/14/writing-professional-code-c/). Make sure your code is absolutely legible and elegant.
* Your code must be well commented. It is generally recommended to have at least one line of comment for every 3-5 lines of code. Comments must explain any complex logic or various cases.
* Avoid using unnecessary variables.
* Please use proper variable names.
* Please use the minimum possible scope for your variables.
* Please use new lines to separate various parts of your function.
* New line must be present before and after every loop. Example -
``` C

for (i = 0; i < 10; ++i) {
    // code
}

```
* If your loop has an explanatory comment, place it above the loop and a new line must be added before the comments. Example -
``` C

// Comments explaining loop
for (i = 0; i < 10; ++i) {
    // code
}

```
* Please separate the declaration and the non-declaration lines of code with a new line. Example -
``` C
// code

int arr[] = {1, 2, 3, 4, 5};    // array of integers
int size = 5;                   // size of array 'arr'

printf("Size of array = %d\n", size);
// more code
```
* Binary operators must have spaces on either side of them. Example -
``` C
if (a < 10 && b > 20) {
    x = (func(a + b) % b) - (a * b);
}
```
* A ```return``` statement must always have a new line before it. Example -
``` C
// code

return 0;
```
* But you don't need to add a new line before the ```return``` statement if it is the only statement in the block. Example -
``` C
if (a < 10) {
    return 0;
}

if (a < 5) {
    // comment
    return 0;
}

a = a + b * c;

return 0;
```
* When you are using an end of line comment, please start with a space. Example -
``` C
// right
//wrong
```
