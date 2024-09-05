# C1 - Intro
> https://users.ece.utexas.edu/~valvano/Volume1/E-Book/C1_EmbeddedSystemsShapeTheWorld.htm
ADC and DAC are the methods to bridge computers with electronics.
Electrical eng. concepts include Ohms Law, LED voltage/current, resistance measurement and motor control.
Computer engineering concepts include I/O device drivers, debugging, stacks, FIFO queues, local variables and interrupts.
The hardware construction is performed on breadboards and debugging using a multimeter (measuring voltage).
SW developed in C, always first simulation then run on microcontroller. 
SW debugging occurs during simulation. Verification occurs in both stages.

# C2 - Fundamental Concepts

## 2.0 Intro

Embedded system is a system that performs specific task and has a computer embedded inside.
Why embedded systems are evolving, growing and getting more complexier: 
- needs for increased number of line
- faster calculation  per sec. requirements
- system verification for safety critical applications
Therefore systems nowadays should employ, parallel programming, high-speed synch, RTOS, fault tolerant design, priority interrupt handling and networking.

## 2.1 Binary Number Systems
Example of decimal number system:
- 273.15 = 2•10^2 + 7•10^1 + 3•10^0 + 1•10^-1 + 5•10^-2

Microcontrollers can operate in binary numbers in 8, 16, 32 bits. 8 bit is a byte.
For humans, things are simplified and used ***hexadecimal*** which use base 16 and its values is selected from the set {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F}
To express hex, we put ***0x*** or ***$*** before the number to mean hex.
A **"nibble"** is defined as 4 binary bits or one hexadecimal digit or half of byte. Each nibble below assigned to one hex digit.






 