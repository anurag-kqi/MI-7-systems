Q1. What is a process?
- instance of program running
- a single thread of execution unless you start using multi thread libraries

Q2. Do you need to create a new process on your own?
- if the task requires multiple threads of execution, then you need to create
  a new process.

Q3. How do you create a process?
- fork system call you create a new process.

Q4. What is an env variable?
-  An environment variable is a variable whose value is set outside the program,
    typically through functionality built into the operating system, mostly shell program.
    An environment variable is made up of a name/value pair, and any number may
    be created and available for reference at a future point in time.

Q5. What is a shell in unix?
-   Shell is an environment in which we can run our commands, programs, and
    shell scripts. There are different flavors of a shell, just as there are
    different flavors of operating systems. Each flavor of shell has its own
    set of recognized commands and functions.
-   In Unix, there are two major types of shells −
    1. Bourne shell − If you are using a Bourne-type shell, the $ character is the default prompt. (Bash)

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
-  -A PID (i.e., process identification number) is an identification number that
    is automatically assigned to each process when it is created on a Unix-like operating system.

    1. ps
    2. pstree
    3. ps -af

Q9. What is parent process ID? How does one find it?
   - A parent process is a process that has created one or more child processes. Each child process is
     given a Parental Process ID (PPID), and child when it completes their operation, terminates itself by calling exit
   - In an unique process ID, each process is assigned a parent process ID (PPID) that tells which process started it.
     The PPID is the PID of the process’s parent.

   - it can be find from following commands:
      1. echo $PPID
      2. ps -o ppid=
      3. ps -efj
      4. pstree
      5. ps -af

Q10. How does one create a new process?
   - A new process can be created by the fork() system call.
   - The new process consists of a copy of the address space of the original process.
   - fork() creates new process from existing process.
   - Existing process is called the parent process and the process that is created newly is called child process.
   - The function is called from parent process. Both the parent and the child processes continue
     execution at the instruction after the fork(),the return code for the fork() is zero for the new process,
     whereas the process identifier of the child is returned to the parent.

Q11. How process is terminated?
    - Explicit terminaition by calling Exit:
            A process may be terminated after its execution is naturally completed.
    - Implicit termination by main function calling returns
    - Some internal exception occurs:
        - illegal Address
        - divide by zoro
    - Someone sends process a kill signal or some other signal, that expects the process to die
   - A process can be terminated if it tries to use a resource that it is not allowed to. This is not entirely true.
     For example - A process can be terminated for trying to write into a read only file. Read will return into EACCESS, but process will not die.
   - If an I/O failure occurs for a process, it can be terminated. This will not result into proces dying, you will get an ioerror from read/write
   - For example: you are making a call to malloc, and system is running low on memory resources, then malloc might return null. And if you are not checking for null value from malloc, and then trying to access it in future, you will have memory violation

Q12. At the starting of a new process, how does child process gets memory structure to continue execution?

Q13. How can you differential between code running in parent process and child process?

Q14. How do I create 50 processes from a single process?

Q15. How many processes can I create? Is there any limit as how many processes one can create?

Q16. What part of code after fork is executed only by child process and why?

Q17. What part of code after fork is executed only by parent process and why?

Q18. What part of code after fork is executed by both the processes?

Q19: What is typical life cycle for a process?
- Parent process creates a new child process using fork, at this point the child process and parent process shares the same address space
- Child process can continue executing the same program or
    child process can start running a new program, using exec system call.
- process can terminate using return from main or exit call any where in the programs. While terminating, it can pass a status to the parent process.
- parent process can wait for the child process to terminate using wait system call.

Q20: assignment: Create 10 children processes, and wait for 5 of them, and then parent will do some thing for some time and then wait for the remaining 5 proceses.

Q21: How does wait work?
- for example:
    - parent process id 1001 has created a new procees 1020 using fork
    - Both parent process and child process are doing something
    - Now if parent process wants to figure out completion of child process, then it will make wait system call
    - wait system call with block until the child 1020 terminates (exit, or return or signal or excetion)
    - child process can pass exit code to parent, provided parent has given the address to memory location

Q22: How does a process starts running a new program?
- Process needs to call exec system call, that takes path of the executable as paramter and argument
