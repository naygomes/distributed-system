# Trabalho Prático - Sistemas Distribuídos 24.1

Universidade Federal do Rio de Janeiro

<br/>

![Badge](https://img.shields.io/badge/c++-31426b?style=for-the-badge&logo=c++&logoColor=white)

## Conteúdo

- [Introdução](#introdução)
- [Signals](#signals)
- [Pipes](#pipes)
- [Sockets](#sockets)
- [Autoras](#autoras)

## Introdução

Um processo é a execução de um software em um computador, o que requer que o SO (sistema operacional) crie um contexto que abstrai o processo dos componentes físicos do sistema. Devido à virtualização dos recursos, os processos não trocam informações entre si, pois não têm conhecimento dos outros processos em execução.

A comunicação entre processos (IPC) é o conjunto de mecanismos que permite a transferência de informações entre processos. O objetivo deste trabalho é desenvolver uma maior familiaridade com os principais mecanismos de IPC, como **sinais**, **pipes** e **sockets**.

Vale ressaltar que a linguagem de programação C++ foi a escolhida para o desenvolvimento do trabalho, não somente por ser a recomendação do professor, mas também por sua estreita relação com o SO dos computadores, facilitando o acesso a processos por meio de bibliotecas. Embora não seja uma linguagem de baixo nível, ela proporciona maior controle sobre as operações realizadas e garante um bom desempenho.

Em cada uma das pastas, existe não só os arquivos com a solução do mecanismo de IPC determinado, como também um arquivo denominado **Makefile**. Esse arquivo contém comandos _shell_ com a finalidade de compilar todos os arquivos .cpp da pasta, deixando-os prontos para serem executados.

## Signals

Um sinal é uma notificação enviada de forma assíncrona a um processo ou a uma parte específica dentro do mesmo processo para alertá-lo sobre a ocorrência de algum evento.

Para utilizar esse mecanismo, é necessário executar alguns comandos. A ideia é deixar o receptor "em espera", seja por _blocking_ ou _busy wait_, e então enviar um sinal para ele através do remetente.

No caso do _blocking wait_, o processo fica suspenso até que o evento ocorra, não consomindo recursos da CPU durante a espera. Já no _busy wait_, o processo fica em um loop ativo verificando a condição, consomindo recursos da CPU durante toda a espera.

Os sinais escolhidos foram os seguintes:

- **SIGTRAP**: Tem o número de sinal 5 e é emitido quando ocorre uma exceção (ou armadilha), ou seja, uma condição que um depurador solicitou para ser informado.
- **SIGFPE**: Tem o número de sinal 8 e é emitido se uma operação matemática ilegal é tentada.
- **SIGALRM**: Tem o número de sinal 14 e é emitido por um temporizador.

### Intruções de uso

Para executar o processo:

1. Abra o terminal no diretório raiz do projeto;

2. Execute o comando abaixo:

```bash
$ cd ./TP1/signals
```

3. Para compilar os arquivos, execute o seguinte comando:

```bash
$ make all
```

4. Para executar o _receiver.o_ e esperar o sinal, execute o comando abaixo:

```bash
$ ./receiver.o
```

5. Para saber qual o pID do _receiver.o_, execute o comando abaixo:

```bash
$ ps aux
```

6. Para executar o _sender.o_ e enviar o sinal, execute o comando abaixo:

```bash
$ ./sender.o <pID> <signal number>
```

### Resultados

## Pipes

### Intruções de uso

### Resultados

## Sockets

### Intruções de uso

### Resultados

## Autoras

Mariana Meirelles<br/>
[![Gmail Badge](https://img.shields.io/badge/-mariana.s.p.meirelles@poli.ufrj.br-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:mariana.s.p.meirelles@poli.ufrj.br)](mailto:mariana.s.p.meirelles@poli.ufrj.br)

Nayara Gomes<br/>
[![Gmail Badge](https://img.shields.io/badge/-nayara.gomes13@poli.ufrj.br-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:nayara.gomes13@poli.ufrj.br)](mailto:nayara.gomes13@poli.ufrj.br)
