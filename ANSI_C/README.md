### Wiki: 

>> **return 0 ;** It is a indicator that program succeeded, done by ***exit status***

>> **Compiling** : ```gcc -o hii hello.c -Wall ```
- -o enable you to name the complied file
- -Wall enable you to be warned about the suspicious code
- To run: ./

>> **Statement**: are the text that will be turned into executable instructions. 
- ``int i = 3;``
- ";" has to be placed at the end of statement

>> **Whitespace** it surrounds the statements to organize the code which is ignored by the compiler.

>> **Scope** : There 2 types of scope
-*** Local Scope***: can be manipualted only within the block it was declerad
- **Glocal Scope:** can be manipulated from anywhere in the program.
- Global variables are not considered good programming practice, and should be avoided whenever possible. They inhibit code readability, create naming conflicts, waste memory,   and can create difficult-to-trace bugs

>> **Functions** : special block that performs a well-defined task. It usually returns a value to the caller.

>> **Compiling** : It is basically a native compiler read every source code and translate everthing into machine code that is comprehensible to a microprocessor.
- It comes with 2 problems: 
- 1. in the large project the compuler may not have enought memory to read all the source code.
- 2. If you make a change in a single source code you have to recompile the entire application.
- Solution: Use of Object Files and Linker.
- **Object File:** occurs when each .c file is translated into machine code with its references (#include)
- **Linker** collects all the objects files and writes a actual program. If you can change only a file, then only that file needs to be re-compiled and re-linked.


>> **Preprocessor** : Directive instruct a part of the compiler the to modify the code written before it is compiled. For example: it is used in #include <stdio.h> or functions that are used after main().

>> **Line Breks:** : After precompiler declerations. After new variable are declared.

>> **Indentation** : Every conde inside a block should be intended

>> **Comments**
```- // Single line comment```
- /* Multi 
- line   
- comment*/

>> **Data Type Modifiers**
- short: 2 bytes, -32.768 bis +32.767. 2 to the power of 16
- int: 4 bytes
- long: 8 bytes

>> **const** : are read-only variables , must be initialized at decleration and not allowed to be changed.
- Therefore, some compiler can optimize 
- ```const data_type var_name = value;```
-  ```const int name = 5;```
-  ```const char letter = 'A';```

>> **#define** used to create -macros- in case of they are used in the rest of the code then they will replaced by the specified expression
- It is good convention to write #defined words in all capitals, so a programmer will know that this is not a variable that you have declared but a #defined macro.

>> **Static** variables preserve their values after even after they are out of its scope. Meaning, they retain their value from previous state, not initialized again.
- ```static data_type var_name = value ;```
- Alttough they are keeping its state even it is out of its scope, it cannot be accessed from out of scope. So-called ***static storage duration.***
- They are initiazed as 0 (garbage value) when they not.
- Cannot access the function or variable through the extern (see below). so called ***static_linkage***


>> **extern** it is used when the variable should be accessed from another file that it may not have #included directly. By default value is zero. It lasts till the program comes to an end.

>> **volatile** special case that indicates compiler that the variable can be change by external entities othere than the program itself. I.e: optimization problems. Espacially relavant in embedded systems since a program may not have complete control of a varible and multi-threaded applications.

>> **auto** local to the block that is defined and persist till the control remains within, by default it is garbege value.

>> **register** it is hint to the compiler to attempt to optimize the storage of the given variable.

>> **Error Handling**
- preveting 0 division error: 
if (divisor == 0 ){
    fprintf(stderr, "Division by 0")
    exit(EXIT_FAILURE);
}

- ***singnals*** : are event that raised by operating systems to indicate specific errors or event has occured(division_by_zero, interrupts and so on..)

- ***setjump*** : can be used to emulate the exception of handling feature of other languages. setjump() and longjpm() may used for error handling, but also for often cases they are used for returning a value of a funtion to indicate a possible error.

### Simple I/O
Placeholder codes, 
%d : int, same as %i
%lf : long int 
%f : float
%lf : double
%c : char
%s : string
%x : hexadecimal
- printf() : requires stdio.h used to put text. String called argument. printf("2+2 is '%d'", 2+2)
- puts() : specialised printf that only outputs string
- scanf() : used for inputs and requires a memory address of the varible that is coming from inputter.
    simplified example: "
    int main(void){

        int a; 
        scanf("%d", &a)
    }

### Type Casting

float pi = 3.141592;
int truncated_pi = (int)pi; // truncated_pi == 3

char my_char = 'A';
int my_int = (int)my_char; // my_int == 65, which is the ASCII value of 'A'

### Bitwise Operators
Provides simplier and faster way to implement arithmetic operations and directly supported by processor.
![alt text](image-29.png) 
??ni

### Further Math
- **Trigonometric functions** A range error occurs if the magnitude of x is too large.
#include <math.h> 
float asinf(float x)
float acosf(float x)
atan() : returns arctan value of its arguments
atan2() : return the arctangent of y/x in radians

- **Exponential and logarithmic function**
#include <math.h>
float logf(float x); /* C99 */
double log(double x);
The exp functions compute the base-e exponential function of x (e^  x). 
float expf(float x); /* C99 */
double exp(double x);

- **Power functions** : Compute x raised to the power y and return the result. A domain error
occurs if x is negative and y is not an integral value. A domain error occurs if the result
cannot be represented when x is zero and y is less than or equal to zero. A range error may
occur.

#include <math.h>
float powf(float x, float y); /* C99 */
double pow(double x, double y);

- **Nearest Integer, absolute value, reminder functions**
Ceil & Floor Functions
```
#include <math.h>
float ceilf(float x);
double ceil(double x);
float floorf(float x);
double ceil(double x);

float fabsf(float x);  // fabs function compute the absoloute value
double fabs(double x);

float fmodf(float x, float y);
double modf(double x, double y);
```


## Control
C treats logic as being arithmetic, meaning zero (0) represents false, all other values represent true, 
For decision with multiple logical expressions the first expresseion has to be true for interpreting the other express.

### Bitwise Boolean Operations
Bitwise operators work bit by bit on the operands.

- a & b -AND
- 0xc & 0xa produces the value 0x8 (in binary, 1100 & 1010 produces 1000)

- a | b -OR
- 0xc | 0xa produces the value 0xe (in binary, 1100 | 1010 produces 1110)

- a ^ b -XOR
- if inputs are the same then outputs are 0 otherwise 1
- 0xc ^ 0xa produces the value 0x6 (in binary, 1100 ^ 1010 produces 0110)

### If-else

```
if (conditions goes here){

}
else if (){

}
else{

}

```

### Switch - Case
```
switch (/* integer or enum goes here */) {
case /* potential value of the aforementioned int or enum */:
/* code */
case /* a different potential value */:
/* different code */
/* insert additional cases as needed */
default:
/* more code */
}
```

### Loops
It is handy when you want to execute a certain action for certain amount of time until a certain condition is met.

### While Loop
```
int a = 1;

while(42){ // loop untill break statement in the loop is executed
    printf("a is %d ", a);
    a = a * 2;
    if (a > 100) {
        break;
    } else if (a == 64) {
        continue; // Immediately restarts at while, skips next step
    }
}
```

### For Loops
for (){
    // code here
}

### Do - While 
it is a while loop but it runs at least once even  while is not met
```
do {
/* do stuff */
} while (condition);
```

## Procedures and Functions
Functions can be called several times and from several places. 
Function's inputs are known as arguments.


### Digital Logic Fundatmentals
![alt text](image.png)

### Big-Endian vs Little-Endian
Suppose you are given {N}2 = (00100110) but not told the order. The meaning of the bit string could be either Nbig-endian = 32 or Nlittle-endian = 100.

### Representing negative values in Binary
**Two's Complement**: Let n = 8. The representation for 77 is (01001101), just like in all other cases. To get -77 in the two’s complement code, we negate the number, which means we invert all the bits and add 1, so (10110011).
![alt text](image-30.png)


// cont 101 -- Wiki C

## ANSI C
- If we write software using only ANSI C, then it will build to run on any target platform with ANSI C compiler.
- Every microprocessor has its own unique set of machine instructions

Goals of a software project should be to place as much code into the Application Layer as possible to reduce the amount of effort necessary for porting code to other platforms.
![alt text](image-2.png)

### Conversation Characters and Interpretations
![alt text](image-3.png)

### Formatted Printing Character Constants
![alt text](image-4.png)

### Standart and Unsigned Integer C Types
![alt text](image-5.png)
![alt text](image-6.png)

### Decimal Constant Values in statements
![alt text](image-7.png)

### Logical Operations
![alt text](image-10.png)

### Bit-Wise Operations
![alt text](image-8.png)

### Difference between Logical and Bitwise Operations
![alt text](image-9.png)

### Assigment Operators
![alt text](image-11.png)

## Conditional Expression
### IF ELSE IF
![alt text](image-12.png)

### SWTICH-CASE
![alt text](image-13.png)
![alt text](image-14.png)


## LOOPS
expression1 is an initialization assignment (e.g., i=0)
expression2 is some ending condition (e.g., i < MAGIC_NUMBER).
expression3 is an increment (e.g., i += MAGIC_INCREMENT, or i++).

### For
![alt text](image-16.png)

### While
![alt text](image-15.png)

### Do - While
The do-while loop presented in Ex. 2.37 repeats statement as long as expression != 0. A nice
feature of this loop style is that statement is always executed at least once prior to the expression
evaluation.
![alt text](image-17.png)


## Infinite Loops
Loops that repeat execution “forever” are called infinite loops. You might be wondering why such a
construct exists, as once the algorithm enters an infinite loop it doesn’t exit (until execution is halted
by outside force). However, an infinite loop is a very important and fundamental concept necessary
to many applications
Embedded applications
are fundamentally the same. Imagine how useless an alarm clock that didn’t sit in an infinite loop
would be.
![alt text](image-18.png)
![alt text](image-19.png)
![alt text](image-20.png)

Arduino Integrated Development Environment (IDE) hides the
main() function from the engineer. Instead, they present the two functions setup() and loop(),
which allow the developer to initialize various conditions, and then loop forever. For example, the
text in Ex.2.41 is an Arduino-based “Hello world” program as viewed through the IDE

### Miscelalaneous : DON’T USE
The following are a part of ANSI C but should “never” be used for the sake of maintainable code

### Break
A break allows for the early exit from a loop. It is useful (and actually required for maintainable
code) within a switch statement so the code in subsequent cases is not executed.
Example 2.43 After the loop executes in this example, i == 5 and x == 4.
![alt text](image-21.png)

### Continue
A continue is similar to break in that when executed the remaining code in the loop block is
skipped. However, it differs from break in that the loop continues to execute.
Example 2.44 After the loop executes in this example, i == 10 and x == 4
![alt text](image-22.png)

### Scope Rules
It is considered good coding practice to make global functions and variables available via
header files, as example below:
![alt text](image-24.png)
Then other files will use this header  file to communicate global information to each other, When other files A or B contain the following code 
fileA 
    #include include include "fileC.h"

fileB
    #define _FILE_B
    #include include include "fileC.h"
By placing the #define _FILE_B in fileB.c before the header file is included, it causes the
preprocessor to define a blank macro. This causes the compiler to allocate the necessary memory for
variable x. fileA.c simply includes the header file without defining anything, and so x is declared
as an external variable within that file.

>> The keyword **static**  limits the scope of a global variable to just within the file declaring it.
<<<<<<< HEAD
Below, in the first call to the test() function initiliazes i == 0,
In the next call it is not re-initiliazed to zero, instead, it cointains the value it had when the function exited previosly (i.e: 1).
![alt text](image-25.png)

### Example Coding Convention Rules
![alt text](image-26.png)

### Variable keywords
>> register int x ; 
Meaning, advises compiler that variable will be accesed a lot and should be placed in machine register
>> volatile int x ;
Meaning, so it can be useful when you want to trick compiler into preserving some statements that you dint want removed. Compiler is then unable to optimize certain statements due to memory caching

 
=======

## Pointers and Arrays
Pointer contain an address usually of an another variable
**To Define** a pointer 
'p = &c;'
Now p is the adress of the "c"
![alt text](image-27.png)

**To Declare** 
'char *p'
'short *q'
'long *r'
Pointers can be created for many types such as (to other pointers, to functions, to any type of array, to structre type)

```
short *p;
short a[10];

p = &(a[2]);

/* followings are correct*/
*(p) = a[2];
*(p+1) = a[3];

```

### Compiling
```
gcc -o hi hi.c -Wall

```
### Running 
./hi

>> -o : allows to give a name to the compiled c program, otherwise default it named as "a"
>> -Wall : indicated that gcc should warn about many types of suspicious code that are likely to be incorrect

## Dynamic Memory Allocation
We can dynamically allocate memory at run-time and have the base be referred via pointer.
That means compiler doesnot reverse the consecutive bytes of memory as for am array decleration. 
Instead, CPU is directed to find a block of consecitive bytes in memory that are not being used dand return the base address.
>> malloc : Allocates size bytes of uninitilialized (garbage value) storage
>> calloc : Allocates memory for an array of num objects of size and initializes all bytes to 0
>> free : De-allocates previously allocated memory

**! Warning** : If you don't "free" the dynamic memory, it causes *"memory leak"* which means repeated call to the function will consume all of the available memory, then program crashes.

**! Warning** : Run-Time Allocation is not the best practice in embedded programs since even in PC applications, with all of the powerful debugging tools, it is still hard to track down the *leaks*. Embedded systems tools are quite limited and mostly debugging an embedded memory is exceptionally diffucult.

```
#include <stdio.h>   
#include <stdlib.h> 
 
int main(void) 
{
    int *p1 = malloc(4*sizeof(int));  // allocates enough for an array of 4 int
    int *p2 = malloc(sizeof(int[4])); // same, naming the type directly
    int *p3 = malloc(4*sizeof *p3);   // same, without repeating the type name
 
    if(p1) {
        for(int n=0; n<4; ++n) // populate the array
            p1[n] = n*n;
        for(int n=0; n<4; ++n) // print it back out
            printf("p1[%d] == %d\n", n, p1[n]);
    }
 
    free(p1);
    free(p2);
    free(p3);
}
```

### Multi-Dimensional Arrays
```
#define MAX_ROWS 2
#define MAX_COLS 3

const short table[MAX_ROWS][MAX_COLS] = {
    {1,2,3,4,5},
    {6,7,8,9,10}
};

Followings are true:
table[0][1] == 2;
table[1][4] == 10;


```
**Decleration**
```
return_type (* variableName)(argument_list);
```

Ex:
```
int (*comp) (void*, void*) ;
char * (* weird) (void) ;
```
>> Variable ***comp*** is a pointer to a function that returns an ***int*** and takes ***two generic pointers***
>> Variable ***weird*** is a pointer to a function that returns an ***char pointer*** and takes ***no arguments***

## Structure
Collection of one or more variable, possible of different types grouper together under a single name for convenient handling.
Similar to "classes" in C++

Definition/Notation
```
struct TagPoint
{
    int x;
    int y;
}
```
**Build a Structure with another Structure**
```
struct TagRectangle{
    struct TagPoint upperLeft;
    struct TagPoint lowerRight;
};

struct TagRectangle polygon;
polygon.upperLeftCorner.x = 320;
```
---
