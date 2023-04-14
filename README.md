# Process Scheduler (Escalonador de Processos)

Application Area : Data Structure ( Estrutura de Dados ); 
Gabriel Gonçalves Sá ;
Email: gabrielgoncalves55@gmail.com ; 
Contact: +55 (61) 993776707 ;

# Description (Descrição) 

_-(English)_
To manage CPU usage, the operating system relies on the process scheduler, which determines the order in which each process will use the CPU. Its purpose is to ensure that all processes are eventually serviced (avoiding starvation)
One technique used is round-robin. This technique establishes a quantum, a small slice of time that each process will use on the CPU. After the end of the quantum, the scheduler removes the process that used the CPU and puts it behind all the others that are waiting to use the resource. In this project a process scheduler that uses the round-robin technique was simulated
The data structure used was FILA, which follows the universal order FIFO (First in First out).
-> QUEUE:
  It is based on the idea of linked lists, since enqueuing elements corresponds to an insertion in the tail and dequeuing elements corresponds to a removal in the head.
  Relevant and efficient, since all operations on queues are completed in constant time.
  
_-(Português)_
Para gerenciar o uso da CPU, o sistema operacional conta com o agendador de processos, que determina a ordem em que cada processo usará a CPU. Sua finalidade é garantir que todos os processos sejam eventualmente atendidos (evitando starvation)
Uma técnica usada é o round-robin. Essa técnica estabelece um quantum, uma pequena fatia de tempo que cada processo usará na CPU. Após o término do quantum, o escalonador remove o processo que utilizou a UCP e o coloca atrás de todos os outros que estão aguardando para utilizar o recurso. Neste projeto foi simulado um escalonador de processo que utiliza a técnica round-robin
A estrutura de dados utilizada foi a FILA, que segue a ordem universal FIFO (First in First out).
-> FILA:
   Baseia-se na ideia de listas encadeadas, pois enfileirar elementos corresponde a uma inserção na cauda e desenfileirar elementos corresponde a uma remoção na cabeça.
   Relevante e eficiente, pois todas as operações nas filas são concluídas em tempo constante.
 ******************************************************************************************** 
 
# Folder and Files (Pasta e Arquivos)
The program was modularized in 4 files sent in attachment (Programa modularizado em 4 arquivos):
- The README.md document for documentation and project details (documentação)
- The Makefile file, for compiling the program (compilação)
- queue.h - header for queue structure (cabeçalho para estrutura da fila)
- queue.c - implementation of functions (implementa funções)
- main.c - Main code (main)

************************************************************* 
# Compilation and Execution (Compilação e Execução)
_-(English)_
Compilation instructions are applied on the Linux system.
To compile C code, we will use the gcc compiler. The compiler is responsible for translating the source code written in a specific language to a file that the computer can interpret, that is, an executable.
If the compiler is not present on the Linux machine, type the command:
sudo apt install build-essential
After saving the files, we will open the directory where the folder was saved with the command: cd "name_of_folder".
With the help of the Makefile, only 2 commands are needed: "make" and "./main". We will compile the program in c in the terminal, for that type the command: make. Finally to run the file, type the command: ./main

_-(Português)_
As instruções de compilação são aplicadas no sistema Linux.
Para compilar o código C, usaremos o compilador gcc. O compilador é responsável por traduzir o código-fonte escrito em uma linguagem específica para um arquivo que o computador possa interpretar, ou seja, um executável.
Se o compilador não estiver presente na máquina Linux, digite o comando:
sudo apt install build-essential
Depois de salvar os arquivos, abriremos o diretório onde a pasta foi salva com o comando: cd "nome_da_pasta".
Com a ajuda do Makefile, são necessários apenas 2 comandos: "make" e "./main". Iremos compilar o programa em c no terminal, para isso digite o comando: make. Por fim, para executar o arquivo, digite o comando: ./main
