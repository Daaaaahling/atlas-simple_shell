# Atlas Simple Shell🐚

## Description:

This is a simple shell implementation written in C language. The shell provides basic command-line functionalities such as executing commands, handling environment variables, and displaying prompts.

## Overview:

The simple shell project is aimed at creating a minimalistic shell program that emulates some functionalities of the Unix shell. It allows users to interact with the system by executing commands, managing environment variables, and navigating directories.

## Features:

**Command Execution:**
Executes commands entered by the user.

**Environment Variable Display:**
Displays environment variables using the env command.

**Prompt Display:**
Displays a prompt indicating that the shell is ready to receive input.

**Input Parsing:**
Parses user input into separate command arguments.

**Path Resolution:**
Searches for commands in directories listed in the PATH environment variable.

## Files:

### simple_shell.c
This file contains the main entry point of the simple shell program. It handles user input, tokenization, and execution of commands.

### main.h
The main.h header file contains declarations for functions and includes necessary system headers and definitions.

### copy_string.c
This file contains the implementation of the copy_string function, which duplicates a given string.


### display_prompt.c
This file contains the implementation of the display_prompt function, which checks if standard input is connected to a terminal and prompts the user accordingly.

### run_child.c
This file contains the implementation of the run_child function, which executes a command in a child process.
It creates a child process using fork and executes the specified command using execve. It waits for the child process to complete and returns the exit status of the executed command.

### search_and_execute.c
This file contains the implementation of the search_and_execute function, which searches for a command in directories specified by the PATH environment variable and executes it.


### split_string.c
This file contains the implementation of the split_string function, which tokenizes a string using specified delimiters.

### display_env.c
This file contains the display_env function, which displays environment variables. It takes in the env parameter, which is an array of strings containing environment variables. The function iterates through each environment variable and prints it to the standard output.

### get_user_input.c 
This file contains the get_user_input function, which retrieves input from the user. It takes in pointers to a character array (input) and a size_t variable (size).The function utilizes the getline function to read a line of input from the standard input stream (stdin). User input is stored in the input array, and the size of the input is stored in the size variable.

### init_shell.c 
This file contains the init_shell function, which initializes the shell environment.
It takes in the env, path, and paths parameters. The function searches for the PATH environment variable within the env array and extracts its value.The extracted PATH value is stored in the path variable. The path value is then split into individual directory paths and stored in the paths array.

###  handle_command.c
This file contains the handle_command function, which handles user commands. It takes in the env, path, paths, and tokens parameters. The function checks for built-in commands such as exit and env, and handles them accordingly.
If the command is not built-in, it checks if the command exists in any of the directories listed in the PATH variable.
If the command is found, it is executed using the run_child function. If the command is not found, an exit status of 127 (command not found) is returned.

## Usage

Clone this repository:

```bash
git clone https://github.com/Daaaaahling/atlas-simple_shell.git
```

Compile your scripts:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -o hsh copy_string.c display_env.c display_prompt.c get_user_input.c handle_command.c init_shell.c run_child.c search_and_execute.c simple_shell.c split_s
tring.c main.h
```
gcc: Invokes the GNU Compiler Collection (GCC) to compile C code.

-Wall: Enables most warning messages.

-Werror: Treats all warnings as errors.

-Wextra: Enables additional warning messages.

-pedantic: Issues warnings about non-standard language constructs.

-std=gnu89: Sets the C language standard to GNU C89.

-o hsh: Specifies the output file name as hsh.

copy_string.c display_env.c display_prompt.c get_user_input.c handle_command.c init_shell.c run_child.c search_and_execute.c simple_shell.c split_string.c main.h: Specifies the source files and the header file to be compiled.


Run the compiled executable:

```bash
./hsh
```

Enter the commands in the shell and observe the output:

![image](https://github.com/Daaaaahling/atlas-simple_shell/assets/155494852/24356958-2e4f-488f-bd3f-a09fb189787a)
