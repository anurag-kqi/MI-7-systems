Debugging C lang program:

Q1. What is core dump?

Q2. How to use gdb?
    gdb <binary_name> core
    #gdb without core file parameter does not take the core file by default,
    #it will start program without core file, so be careful
Q3. I am not able to see core file?
    check if ulimit for core is set properly
    $ulimit -c
    #if it is 0
    ulimit -c unlimited
Q4. How to print line number?

