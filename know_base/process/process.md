Q1. What is a process?
- instance of program running
- a single thread of execution unless you start using multi thread libraries

Q2. Do you need to create a new process on your own?
- if the task requires multiple threads of execution, then you need to create
  a new process.

Q3. How do you create a process?
- fork system call you create a new process.

Q4. What is an env variable?
-

Q5. What is a shell in unix?
-

Q6. What are different shell programs in Unix?
-

Q7. What are the different segments for a program?
 - Code or data
 - code is stored text segment / code segment
    - code should never get modified, so cs should be read only
 - data
    - global
        - data segment if global variable has some initial value
        - bss: if global variable does not have initial value
    - local
        - stack, a new stack is created only when a function is called
        - stack is deleted when function returns
    - dynamic
        - heap segment
        - malloc to allocate data from this segment
        - free retruns memory back to this segment
