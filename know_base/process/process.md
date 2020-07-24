Q1. What is a process?
- instance of program running
- a single thread of execution unless you start using multi thread libraries

Q2. Do you need to create a new process on your own?
- if the task requires multiple threads of execution, then you need to create
  a new process.

Q3. How do you create a process?
- fork system call you create a new process. 
