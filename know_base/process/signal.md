Q1. What is signal in unix?
- Signal are soft interrupt, these are designed to intimate that an event of
  a specific type has occurred.
- signal on its own does not pass much information beyond theatre
- For each signal that a process wants to handle, it needs to install something
   called signal handler

Q2. What is a signal handler?
- Signal handler is a function, that gets called when a process receives a specific signal.

Q3. How do you send signal to a process?
- you can use kill command and signal number to send a signal to process. You
need to know the process id. You can use ps -aef to find the process id.

Q4. Is kill the only way to generate signals?
- There are other reasons by which signal is generated
    - termination of a child will send SIGCHLD to the parent processes
    - segmentatio fault will generate SIGABORT (need to verify the name) for the same process
    - divide by zero, will also generate a signal

Q5. How do you find different signals and their expected behaviors?
-


Q6. Will every signal terminate the process?
- No, it depends on the signal number and the default behavior fof that signo. 
Q7.
