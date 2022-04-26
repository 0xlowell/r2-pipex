# r2-pipex
__________________

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
Pseudocode : 

* ./pipex file1 cmd1 cmd2 file2

av[0] = ./pipex (program, as PARENT process)

av[1] = file1 (READ from this input)

av[2] = cmd1 (we need connect it to the PATH in our env to launch it, as 1st CHILD process)

av[3] = cmd2 (we need connect it to the PATH in our env to launch it, as 2nd CHILD process)

av[4] = files2 (WRITE in this output)

* Use open() for our input file descriptor (fd) and output file descriptor


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
