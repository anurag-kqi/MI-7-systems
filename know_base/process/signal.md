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

Q7: What is unreliable signal?
- in the main function, for example, you have set my_sig_int as signal handler for SIGINT. At time T1
- At some time in future, time T2, some one send SIGINT to this process. At that time os does following:
    1. It resets the signal handler for the SIGINT to default
    2. It schedules the signal handler function execution for the process
- At time T3: the signal handler (my_sig_int) is called
- This leaves a gap between time T2 and T3. And if some one sends a signal, then my_sig_int will not get called. my_sig_int is called only once
- So reduce the problem, very first thing you do in the my_sig_int function is to call signal() function to set the signal handler again. But it still leaves a small window between T2 and T3, where a signal is potentially lost.