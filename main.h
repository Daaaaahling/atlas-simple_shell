#ifndef MAIN_H
#define MAIN_H

#include <stdio.h> /* printf/input output functions */
#include <unistd.h> /* STDIN_FILENO, isatty, access, fork, execve, getpid */
#include <stdlib.h> /* memory and EXIT_SUCCESS/EXIT_FAILURE*/
#include <string.h> /* string functions*/
#include <fcntl.h> /* For access mode */
#include <sys/stat.h> /* For stat() */
#include <sys/types.h> /* For pid_t */
#include <sys/wait.h> /* For waitpid() */

char *copy_string(char *original);
void display_prompt(void);
int run_child(char *path_env, char *command_path, char **command_args);
int search_and_execute(char *path_env, char **dirs, char **args);
void split_string(char *string, char *delimiters, char **tokens);
void display_env(char **env);
int get_user_input(char **input, size_t *size);
int handle_command(char **env, char **path, char **paths, char **tokens);
void init_shell(char **env, char **path, char **paths);

#endif
