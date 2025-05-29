# xv6-ps-system-call

This project involves adding a new system call and a 'ps' command to the xv6 operating system. The 'ps' command displays the current status of processes in the system.

Task #1 for the 20594 course of the Open University.

The full assignment (in Hebrew) is in the [Task 1.pdf](Task%201.pdf) file.

## Table of Contents

* [Project Description](#project-description)
* [Objectives](#objectives)
* [Implementation Details](#implementation-details)
* [Usage](#usage)
* [Files Included](#files-included)
* [Author](#author)

## Project Description

This project extends the xv6 operating system by implementing a new system call and a corresponding 'ps' command. The 'ps' command provides a snapshot of the currently running processes, including details such as process ID, state, and parent process ID. This enhancement allows for better monitoring and understanding of system processes within the xv6 environment.

## Objectives

The main objectives of this project are:

* To gain a deeper understanding of the xv6 operating system.
* To learn about the practical aspects of implementing system calls.
* To become familiar with various operating system data structures.
* To add a new system call to xv6.
* To add a new system command (`ps`) that prints the status of processes.
* To gain experience in building and running an operating system in a realistic environment.

## Implementation Details

The implementation involves modifying several xv6 system files and adding a new file:

* `defs.user.h`
* `sysproc.c`
* `usys.S`
* `syscall.c`
* `proc.c`
* `ps.c`

Key aspects of the implementation include:

* Adding a new system call that retrieves process information.
* Creating the `ps` command to format and display the process information.
* Ensuring the correct output format, including process name, PID, state, and PPID.
* Handling the special case for the `init` process's PPID.

## Usage

1.  Compile the xv6 operating system with the added system call and `ps` command.
2.  Run xv6.
3.  Execute the `ps` command in the xv6 shell to view the process status.

## Files Included

* `defs.user.h`: Header file containing user-space definitions.
* `sysproc.c`: System process-related functions.
* `usys.S`: User system call interface.
* `syscall.c`: System call table.
* `proc.c`: Process management code.
* `ps.c`: Source code for the `ps` command.
* `Makefile`: Build file for xv6.
* `original xv6-1`: The original xv6 source code provided for the assignment.

## Author

Sagi Menahem.
