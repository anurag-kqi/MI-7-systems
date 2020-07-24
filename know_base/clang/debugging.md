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

Q5: What are the different debugging strategies?

    1. Find the scenario in which code is breaking, identify the failure case.
    2. Is failure case repeatable?
    3. Make a hypothesis about what might be going wrong, based on the data
       you have observed so far.
    4. Add printf in those code path to understand the behavior, collect more
       data, refine your hypothesis. And in few iteration you can find the
       problem.
