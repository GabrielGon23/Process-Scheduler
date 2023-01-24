# Process Scheduler

Application Area : Data Structure ;
Gabriel Gonçalves Sá ;
Email: gabrielgoncalves55@gmail.com ; 
Contato: +55 (61) 993776707 ;

# Description

To manage CPU usage, the operating system relies on the process scheduler, which determines the order in which each process will use the CPU. Its purpose is to ensure that all processes are eventually serviced (avoiding starvation)
One technique used is round-robin. This technique establishes a quantum, a small slice of time that each process will use on the CPU. After the end of the quantum, the scheduler removes the process that used the CPU and puts it behind all the others that are waiting to use the resource. In this project a process scheduler that uses the round-robin technique was simulated
The data structure used was FILA, which follows the universal order FIFO (First in First out).
-> QUEUE:
  It is based on the idea of linked lists, since enqueuing elements corresponds to an insertion in the tail and dequeuing elements corresponds to a removal in the head.
  Relevant and efficient, since all operations on queues are completed in constant time.
 
 ******************************************************************************************** 
# Folder and Files 
The program was modularized in 4 files sent in attachment:
- The README.md document for documentation and project details
- The Makefile file, for compiling the program
- queue.h - header for queue structure
- queue.c - implementation of functions
- main.c - Main code

************************************************************* 
# Compilation and Execution
Compilation instructions are applied on the Linux system.
To compile C code, we will use the gcc compiler. The compiler is responsible for translating the source code written in a specific language to a file that the computer can interpret, that is, an executable.
If the compiler is not present on the Linux machine, type the command:
sudo apt install build-essential
After saving the files, we will open the directory where the folder was saved with the command: cd "name_of_folder".
With the help of the Makefile, only 2 commands are needed: "make" and "./main". We will compile the program in c in the terminal, for that type the command: make. Finally to run the file, type the command: ./main
