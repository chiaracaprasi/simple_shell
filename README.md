#  🌊🐚 C SHELL 
#### By Chiara, Declan and Matthew

## 🤿 What is the C Shell? 

C Shell is a reproduction of the original UNIX shell in C. Same as the orginal shell, it's a program that takes commands by the user via the keyboard and gives them to the OS (operating system) to perform. 

This project is part of Holberton School Australia curriculum. 

## 🦪 How to use it 

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

## 🪲 Known bugs

None for now!

## ✍🏽 Authors

- Chiara Caprasi
- Declan Noble
- Matthew Brinkmann 

## 🧹🧺 Housekeeping


.gitignore
- *~ (all emacs buffer files)
- local_* (all local testing files)

### REPO STANDARDS
**Commit Messages:**   
**usage:**   <type>: subject line in lower case.   
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
- Day_1 Folder - contains all tasks done in day 1, and is kept to be used as a reference for all future work.
- playground - for testing and experimenting during the planning phase of the project. Kept long term as a refresher if needed.
