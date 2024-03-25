# Atlas Simple Shell🐚

## Description:

The Simple Shell project is a minimalist command-line interpreter written in C. It provides a basic interface for users to interact with their operating system by accepting commands and executing them. This shell supports functionalities such as executing external commands, handling built-in commands, displaying prompts, and tokenizing user input.

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

### get_user_input.c 

### init_shell.c 

###  handle_command.c

## Usage

Clone this repository
```bash
git clone https://github.com/Daaaaahling/atlas-simple_shell.git
```

Compile
```bash
gcc -o hsh copy_string.c display_env.c display_prompt.c get_user_input.c handle_command.c init_shell.c run_child.c search_and_execute.c simple_shell.c split_string.c main.h


```

Run the compiled executable
```bash
./hsh
```

Enter the commands in the shell and observe the output:

![image](https://github.com/Daaaaahling/atlas-simple_shell/assets/155494852/abcb8f52-0a48-4257-bb93-8f276a1bd1a8)

