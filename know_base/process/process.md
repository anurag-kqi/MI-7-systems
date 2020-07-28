Q1. What is a process?
- instance of program running
- a single thread of execution unless you start using multi thread libraries

Q2. Do you need to create a new process on your own?
- if the task requires multiple threads of execution, then you need to create
  a new process.

Q3. How do you create a process?
- fork system call you create a new process.

Q4. What is an env variable?
-   (Prajwal)-An environment variable is a variable whose value is set outside the program,
    typically through functionality built into the operating system.
    An environment variable is made up of a name/value pair, and any number may
    be created and available for reference at a point in time.

Q5. What is a shell in unix?
-   (Prajwal)-Shell is an environment in which we can run our commands, programs, and
    shell scripts. There are different flavors of a shell, just as there are
    different flavors of operating systems. Each flavor of shell has its own
    set of recognized commands and functions.
-   In Unix, there are two major types of shells −
    1. Bourne shell − If you are using a Bourne-type shell, the $ character is the default prompt.

    2. C shell − If you are using a C-type shell, the % character is the default prompt.

-   https://www.tutorialspoint.com/unix/unix-what-is-shell.htm

Q6. What are different shell programs in Unix?
-   (Prajwal)-In Unix, there are two major types of shells −
    1. Bourne shell − If you are using a Bourne-type shell, the $ character is the default prompt.
    2. C shell − If you are using a C-type shell, the % character is the default prompt.

-   The Bourne Shell has the following subcategories −

    1. Bourne shell (sh)
    2. Korn shell (ksh)
    3. Bourne Again shell (bash)
    4. POSIX shell (sh)

    The different C-type shells follow −

    1. C shell (csh)
    2. TENEX/TOPS C shell (tcsh)
-   https://www.tutorialspoint.com/unix/unix-what-is-shell.htm


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

Q8. What is process ID? How does one find it?
-   (Prajwal)-A PID (i.e., process identification number) is an identification number that
    is automatically assigned to each process when it is created on a Unix-like operating system.

    1. ps
    2. pstree
    3. ps -af

Q9. What is parent process ID? How does one find it?

Q10. How does one create a new process?

Q11. How process is terminated?

Q12. At the starting of a new process, how does child process gets memory structure to continue execution?

Q13. How can you differential between code running in parent process and child process?

Q14. How do I create 50 processes from a single process?

Q15. How many processes can I create? Is there any limit as how many processes one can create?
