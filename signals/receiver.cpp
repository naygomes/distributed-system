#include <stdlib.h>
#include <iostream>
#include <signal.h>
#include <string>
#include <csignal>
#include <unistd.h>

using namespace std;

void signalHandler(int signum)
{

    switch (signum)
    {
    case SIGFPE:
        // Operação aritmética errada, como uma divisão por zero ou uma operação que resulta em overflow.
        cout << "Sinal SIGFPE recebido com sucesso!" << endl;
        break;
    case SIGALRM:
        // Solicitação de encerramento enviada ao programa.
        cout << "Sinal SIGALRM recebido com sucesso!" << endl;
        break;
    case SIGTRAP:
        // Sinal enviado ao processo quando ocorre uma exceção.
        cout << "Sinal SIGTRAP recebido com sucesso!" << endl;
        break;
    default:
        cout << "Sinal (" << signum << ") não identificado. Tente Novamente" << endl;
        break;
    }

    cout << "Interrompendo sinal (" << signum << ").\n";

    exit(signum);
}

int main()
{

    int wait_type;

    cout << "Informe o número que corresponde ao modo de espera desejado:" << endl;
    cout << "0 - Busy Wait" << endl;
    cout << "1 - Blocking Wait" << endl;

    cin >> wait_type;

     for (int i = 1; i < 32; ++i) {
        signal(i, signalHandler);
    }

    if (wait_type == 0)
    {
        while (true)
        { // busy wait
            cout << "Aguardando sinal..." << endl;
            sleep(1);
        }
    }
    else if (wait_type == 1)
    {
        while (true)
        { // blocking wait
            cout << "Aguardando sinal..." << endl;
            pause();
        }
    }
    else
    {
        cout << "Modo inválido" << endl;
    }

    return 0;
}