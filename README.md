# Minishell2 - EPITECH

## About

Minishell2 is the second project of the Shell Programming branch at EPITECH.
It's a minimum viable version of a real shell.
The main goal is to have a good understanding of process creation and
synchronisation using the C programmming language.

## Installation & Usage

### Requirements
The only requirements are:
- GNU make
- GCC

### Building the program

1. Download/Clone this repo

        git clone https://github.com/maximilien-alt/PSU_minishell2_2019.git
2. `cd` into the root directory and run `make`

        cd PSU_minishell2_2019
        make

### Running the program

After building the source, run `./minishell2` from the project root.

## Main Project Instructions

### Mandatory

- Can only use C
- Must respect the school imposed coding style
- No memory leaks
- Implement a series of builtins: `echo`, `cd`, `setenv`, `unsetenv`, `env`, `exit`
- Manage the errors without using `errno`, by displaying a message adapted
to the error output
- Can only use these standard library functions:
    - malloc, free
    - access
    - open, close, read, write
    - opendir, readdir, closedir
    - getcwd, chdir
    - stat, lstat, fstat
    - fork, execve
    - wait, waitpid, wait3, wait4
    - signal, kill
    - exit
- Must have a Makefile to build the program
- Handle program interruption (Ctrl + D)
- Handle complexes commands with multiples pipes and redirections
