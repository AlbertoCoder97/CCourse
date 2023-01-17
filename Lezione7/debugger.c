/* The Debugger allows you to make programs run step-by-step in order to monitor the functioning of
* your program to check whether everything is executing correctly/in the intended way. All of this
* from the command line. You can inspect the current state of the process, like call stack, global
* variables or local variables.
* In order to use the debugger you need to compile the program with a specific flag. If you don't
* the only way you have to debug is with prints and it's not that good. The flag is: -g. 
* After that you need to invoke the debugger using the gdb command: gdb <out file>. 
* In the manual you can find all the commands you can use but some common ones are:
* - run <arg> runes the program with the specified arguments.
* - call <function> calls function in program.
* - step n steps n times in execution.
* - n that goes next to the next instruction and stops again.
* - next n steps n times over functions.
* - where that tells you where you are in the execution.
* - p i prints the value of i.
* - break <line> puts a breakpoint to a specific line. 
* - clear <line> deletes a breakpoint.
* - cont continues execution until next breakpoint. 
* - display z display variable at each step.
* 
* Make sure you execute the compiler while having the executable. gdb is not that great with
* multi-threading processes. Can be used to debug core dumps. A core dump is the memory image while
* it was running before getting killed. The dump is done post-mortem of the process. */