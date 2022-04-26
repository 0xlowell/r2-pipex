# r2-pipex

*Code the Pipex program : the discovery in detail and by programming of a 
UNIX mechanism that you already know.*

Mimic the 'pipe' => | <= command in shell terminal.

Basically, 

* the 'pipe' will read from input files
* use it with 1st command (ex: "ls" command of input file)
* send the result of 1st command(ls result) 
* as input to the 2nd command, use it (ex: "wc" command, of "ls" output)
* then write it in output file

__________________

It should be executed in this way:
```
* $> ./pipex file1 cmd1 cmd2 file2
```
Just in case: *file1* and *file2* are **file names**, *cmd1* and *cmd2* are **shell commands**
with **their parameters**. The execution of the pipex program should do the same
as the next shell command:
```
 * $> < file1 cmd1 | cmd2 > file2
```
example :
```
 * $> ./pipex infile "ls" "wc" outfile
```
need to be equal to :
```
 * < file1 ls | wc > file2
```
__________________
Pipex program:
```
* ./pipex file1 cmd1 cmd2 file2
```
* av[0] = ./pipex (program, as PARENT process)
* av[1] = file1 (READ from this input)
* av[2] = cmd1 (we need connect it to the PATH in our env to launch it, as 1st CHILD process)
* av[3] = cmd2 (we need connect it to the PATH in our env to launch it, as 2nd CHILD process)
* av[4] = files2 (WRITE in this output)

* ac == 5
__________________
Pseudocode : 

1. Check if there is 5 arguments
2. Use ```open()``` for input file descriptor (fd) and output file descriptor 
* Standard input (stdin) is by default set at 0, Standard output (stdout) at 1, Standard error (stderr)
3. Check for error about open()
4. Use ```pipe()``` to create 2 fd who will be used for CHILD's process
* fd[0] to READ fd[1] to WRITE *
5. Get the ```PATH="..."``` from environnement, split it with ':' 
* You will have a char** with ```char[0] = "/Users/.../bin"```, ```char[1] = "/usr/local/bin"``` redirecting to command already fonctionnal in shell (type "env" in terminal to see PATH line : PATH=/Users/...../.brew/bin:/usr/local/bin:...)
6. Use ```fork()``` for 1st CHILD process: if success, launch FIRST_CHILD_PROCESS
* Store PID of fork into a pid_t type (to see PID running on your computer, type ```ps -aux``` in term)
7. Use ```fork()``` for 2st CHILD process: if success, launch SECOND_CHILD_PROCESS
* Store PID of fork into a pid_t type (to see PID running on your computer, type ```ps -aux``` in term)
8. FIRST_CHILD_PROCESS



```C
open (file1, READ);
open (file2, WRITE);
```

Stored in *(int)pipex.in* and *(int)pipex.out*
to use it later, in CHILD process.

*pipex.in* in 1st CHILD process: now our file1 is ready to be readed.

*pipex.out* in 2nd CHILD process: our file2 is ready to be written in.

__________________


file1 is open with READ


__________________



open()
fd


fonctions main: 

open

pipe



fonction child process:

fork

tips: error gestion print : fprintf(stderr, "pipex.cmd1= %s\n", pipex.cmd);
