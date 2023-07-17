# pipex42_project_06

The 42 Pipex project aims to recreate the functionality of the "pipe" command in C language.
The pipe is a feature in the Unix operating system that allows connecting the output of one command to the input of another,
enabling chaining of multiple commands and transferring data between them.

The main objective of the project is to develop a C program that simulates the pipe functionality using appropriate system calls.
Students are required to create a child process for each command to be executed and establish bidirectional
communication between the processes using a pipe created with the pipe() system call. They then need to redirect the standard
inputs and outputs of the processes to the ends of the pipe, enabling them to communicate and exchange data.

Students must also handle error management, cases of input and output redirection,
as well as scenarios involving the "here document" command to read data from files.

In summary, the 42 Pipex project is a simulation of the pipe functionality in C language.
It allows students to explore process creation, interprocess communication,
and input/output management to recreate the functionality of the pipe terminal command.
This project provides them with a deep understanding of operating systems and system calls in C.
