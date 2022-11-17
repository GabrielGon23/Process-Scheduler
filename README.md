# Escalonador-de-Processos

Área de aplicação: Estrutura de Dados 
Gabriel Gonçalves Sá 
Email: gabrielgoncalves55@gmail.com 
Contato: 61993776707 

******************      Escalonador de Processos       ***************** 

Para gerenciar o uso da CPU, o sistema operacional conta com o escalonador de processos, que determina a ordem na qual cada processo utilizará a CPU. O seu objetivo é garantir que todos os processos eventualmente sejam atendidos(evitando o starvation) 
Uma técnica utilizada é o round-robin. Esta técnica estabelece um quantum, pequena fatia de tempo que cada processo utilizará na CPU. Após o término do quantum, o escalonador retira o processo que utilizava a CPU e o coloca atrás de todos os outros que aguardam a utilização do recurso. Neste projeto um escalonador de processos que utiliza a técnica round-robin foi simulado 
A estrutura de dados utilizada foi FILA, que segue a ordem universal FIFO(First in First out). 
-> FILA: 
 Baseia-se na ideia de listas encadeadas, uma vez que enfileirar elementos corresponde a uma inserção na cauda e desenfileirar elementos corresponde a uma remoção na cabeça.
 Pertinente e eficiente, uma vez que todas as operações em filas são concluídas em tempo constante.
 
 ******************************************************************************************** 
# Pasta e Arquivos 
O programa enviado foi modularizado em 4 arquivos enviados em anexo: 
- O documento README.md para documentação e detalhes do projeto 
- O arquivo Makefile, para compilação do programa
- fila.h    - cabeçalho para estrutura da fila
- fila.c    - implementação das funções
- main.c   - Código principal

************************************************************* 
# Compilação e Execução 
As instruções de compilação são aplicadas no sistema Linux. 
Para compilar um código em C, usaremos o compilador gcc. O compilador é responsável por traduzir o código fonte escrito em uma linguagem específica para um arquivo que o computador saiba interpretar, ou seja, um executável. 
Caso o compilador não esteja presente na máquina Linux, digite o comando :
sudo apt install build-essential
Após salvar os arquivos, iremos abrir o diretório em que a pasta foi salva com o comando : cd "nome_da_pasta". 
Com o auxílio do Makefile, apenas 2 comandos são necessários : "make" e "./main". Iremos compilar o programa em c no terminal, para isso digite o comando: make. Finalmente para executar o arquivo, digite o comando: ./main
