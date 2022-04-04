#  🌊🐚 C SHELL 
#### By Chiara, Declan and Matthew

## 🤿 What is the C Shell? 

C Shell is a simple reproduction of the original UNIX shell in C. Same as the orginal shell, it's a program that takes commands by the user via the keyboard and gives them to the OS (operating system) to perform. 
To learn more about how the shell works, you can read our blog at [insert link]

This project has been created using **C Programming Language** and is part of Holberton School Australia curriculum. 


## 🧜🏻 Project Requirements 

### List of allowed functions and system calls
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

### Coding Style

Must follow the ```Betty``` style guide. To install the linter: 

```
$ git clone https://github.com/holbertonschool/Betty.git

$ cd Betty; ./install.sh
```

### Other 

- Shell should not have memory leaks
- No more than 5 functions per file


## 🦪 How to use the C Shell 

> Step 1 - Clone the repo locally using this command
```
gh repo clone chiaracaprasi/simple_shell
```
> Step 2 - Navigate to the folder 
```
cd simple_shell
```
> Step 3 - Compiling using this command 
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh 
```

> Step 4 - Run the C Shell
```
./hsh
```
> Step 5 - Type a command e.g.
```
ls -l 
```
> Step 6 - Exit the shell 
```
exit 
```

## 🦀 Example of usage  
Full Path name E.G:   
-> /bin/ls    

## 🪲 Known bugs
### seperator bug
the ';' seperator will only work if there is a space either side of it   
- (ls ; rm *.c) will work      
- (ls;rm *.c) will not work.     
### Blank input fault    
segmentation fault if press enter with no input    

## ✍🏽 Authors

- Chiara Caprasi
- Declan Noble
- Matthew Brinkmann 

## 🧹🧺 Housekeeping


### REPO STANDARDS
**Commit Messages:**   
**usage:** type: subject line in lower case.   
**example:** docs: update readme file   

**Allowed** <type> values: #
- **feat** for a new feature for the user, not a new feature for build script. Such commit will trigger a release bumping a MINOR version.
- **fix** for a bug fix for the user, not a fix to a build script. Such commit will trigger a release bumping a PATCH version.
- **perf** for performance improvements. Such commit will trigger a release bumping a PATCH version.
- **docs** for changes to the documentation.
- **style** for formatting changes, missing semicolons, etc.
- **refactor** for refactoring production code, e.g. renaming a variable.
- **test** for adding missing tests, refactoring tests; no production code change.
- **build** for updating build configuration, development tools or other changes irrelevant to the user.
   
**Branch Naming:**   
**Usage:**   shell_<tasknumber>   
**Example:** shell_0.1   

### files/folder information 
- .gitignore containing: 
-- *~ (all emacs buffer files)
-- local_* (all local testing files)
- Day_1 Folder - contains all tasks done in day 1, and is kept to be used as a reference for all future work.
- playground - for testing and experimenting during the planning phase of the project. Kept long term as a refresher if needed.
