### Digital Logic Fundatmentals
![alt text](image.png)

### Big-Endian vs Little-Endian
Suppose you are given {N}2 = (00100110) but not told the order. The meaning of the bit string could be either Nbig-endian = 32 or Nlittle-endian = 100.

### Representing negative values in Binary
**Two's Complement**: Let n = 8. The representation for 77 is (01001101), just like in all other cases. To get -77 in the two’s complement code, we negate the number, which means we invert all the bits and add 1, so (10110011).

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

