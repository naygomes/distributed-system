# Trabalho Prático - Sistemas Distribuídos 24.1

Universidade Federal do Rio de Janeiro

<br/>

![Badge](https://img.shields.io/badge/c++-31426b?style=for-the-badge&logo=c++&logoColor=white)

## Conteúdo

- [Introdução](#introdução)
- [Signals](#signals)
- [Autoras](#autoras)

## Introdução

Um processo é a execução de um software em um computador, o que requer que o SO (sistema operacional) crie um contexto que abstrai o processo dos componentes físicos do sistema. Devido à virtualização dos recursos, os processos não trocam informações entre si, pois não têm conhecimento dos outros processos em execução.

A comunicação entre processos (IPC) é o conjunto de mecanismos que permite a transferência de informações entre processos. O objetivo deste trabalho é desenvolver uma maior familiaridade com os mecanismos de IPC. Nesse caso, escolhemos o mecanismo de **sinais** para explorarmos essa comunicação.

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
$ cd ./signals
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
$ ps aux | grep ./receiver.o
```

**\*OBS:** o pID é o valor numérico que aparece na segunda coluna\*.

6. Para executar o _sender.o_ e enviar o sinal, execute o comando abaixo:

```bash
$ ./sender.o <pID> <signal number>
```

### Resultados

Executaremos alguns casos de uso do mecanismo escolhido para demonstrarmos o seu funcionamento.

1. **ENVIANDO SIGALRM COM O RECEPTOR EM BUSY WAIT**

   No caso abaixo, percebe-se que ao colocarmos o receptor em busy wait, ele fica em _loop_ ativo para verificar periodicamente se o sinal já foi enviado pelo emissor. Quando esse sinal é recebido, ele indica o seu recebimento e interrompe o sinal.

   Vale ressaltar também que no caso do emissor, é verificado se o processo do receptor existe antes do sinal ser enviado.

   <img width="1125" alt="image" src="https://github.com/user-attachments/assets/fe4d56da-374d-4bd3-87fc-94253ee78f03">

2. **ENVIANDO SIGFPE COM O RECEPTOR EM BLOCKING WAIT**

   Em blocking wait percebe-se que o processo fica suspenso até que o sinal seja enviado pelo emissor. Quando esse sinal é recebido, o processo volta e indica o recebimento do sinal, interrompendo-o logo em seguida.

   <img width="1126" alt="image" src="https://github.com/user-attachments/assets/ae9b55f8-0974-4b51-895d-9543b3df907e">

3. **ENVIANDO SIGTRAP COM O RECEPTOR INATIVO**

   Percebe-se que, apesar do processo _./receiver.o_ não estar em execução, o comando _ps aux | grep ./receiver.o_ retorna uma linha na saída. Isso ocorre porque o comando _ps aux_ inclui o próprio comando _grep ./receiver.o_ em sua lista de processos, porque o _grep_ está em execução enquanto o _ps_ está coletando informações sobre os processos. Entretanto, vê-se na figura abaixo que ao pegar esse _pID_ ou até mesmo inventar um valor, ele retorna que o processo é inexistente.

<img width="1124" alt="image" src="https://github.com/user-attachments/assets/963c17f4-7a20-45b7-9f17-09bcaf275685">

4.  **ENVIANDO UM SINAL DESCONHECIDO**

   Por fim, vemos que ao enviar um sinal desconhecido, esse sinal chega ao receptor mas o mesmo é incapaz de identificá-lo, então ele retorna uma mensagem ao usuário e interrompe o sinal.

   <img width="1127" alt="image" src="https://github.com/user-attachments/assets/31cc69ba-b02b-4e53-a30c-7eb2f5438424">

## Autoras

Mariana Meirelles<br/>
[![Gmail Badge](https://img.shields.io/badge/-mariana.s.p.meirelles@poli.ufrj.br-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:mariana.s.p.meirelles@poli.ufrj.br)](mailto:mariana.s.p.meirelles@poli.ufrj.br)

Nayara Gomes<br/>
[![Gmail Badge](https://img.shields.io/badge/-nayara.gomes13@poli.ufrj.br-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:nayara.gomes13@poli.ufrj.br)](mailto:nayara.gomes13@poli.ufrj.br)
