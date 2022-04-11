#  🌊🐚 C SHELL 
#### By Chiara, Declan and Matthew

![image](https://user-images.githubusercontent.com/91517809/162679712-709fb667-2104-4ae7-ba2d-a6ebc898f9dc.png)


## 🦀 What is the C Shell? 

C Shell is a simple reproduction of the original UNIX shell in C. Similar to the orginal shell, it's a program that takes commands by the user via the keyboard and gives them to the OS (operating system) to perform. 
To learn more about how the shell works, you can read our blog at [here 🔗](https://medium.com/@chiaracaprasi/how-the-shell-works)

This project has been created using **C Programming Language** and is part of Holberton School Australia curriculum. 


## 🧜🏻 Project Requirements 

### List of allowed functions and system calls
````
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
````

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

## 🤿 Operation Modes

#### Interactive mode
In the interactive mode, the C Shell will display -> prompting the user to type in and execute a command. After the command is run, the prompt -> will appear again in a new line waiting for a new command to be entered. As long as the user doesn't exit the shell (by typing exit and pressing enter), this will go indefinitely. 
Example: 
```
./hsh
-> /bin/ls
```

#### Non-interactive mode

In the non-interactive mode, the C Shell is run with a command pipped into into its execution - this way the command is run as soon as the shell starts. In this mode no prompt -> appears, and no further input is expected from the user.
Example:

```
echo "ls" | ./a.out 
```

## 🐙 Built ins
 
The following build ins were implemented: 

- ```exit``` - exit the shell 
- ```env``` - print the current environment
- ```cd``` - change the current directory of the process.
- ```help``` - display help page for the above builtins 

## 🦦 Functions (or file name??)

|  Function Name |         Description         |
|----------------|----------------------------------------------|
|`prompt??`|Function that prints a prompt, waits for a commnad and reads it form the stream.|                 |
|`_strlen`|Funtion that takes a string and returns its length.|
|`_strcmp`|Funtion that takes two strings compares them and returns the number of different characters.|
|`_strncat`|Function that concatenates two strings and returns a pointer to the concatenated string. 
|`exit`|Shell Built-function that exits the program and returns an status.|



## 🪲 Known bugs
### Seperator bug
the ';' seperator will only work if there is a space either side of it   
- (ls ; rm *.c) will work      
- (ls;rm *.c) will not work.     

## ✍🏽 Authors

- Chiara Caprasi
- Declan Noble
- Matthew Brinkmann 


## 🧹🧺 Housekeeping


### Repo Standards
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

### Files/Folder Organization 
- .gitignore containing: 
-- *~ (all emacs buffer files)
-- local_* (all local testing files)
- Day_1 Folder - contains all tasks done in day 1, and is kept to be used as a reference for all future work.
- playground - for testing and experimenting during the planning phase of the project. Kept long term as a refresher if needed.
   
![image](https://user-images.githubusercontent.com/91517809/162389572-c197bc8a-315a-4c22-8c3b-aac698625e25.png)

  
  
