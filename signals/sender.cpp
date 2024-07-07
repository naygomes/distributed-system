#include <stdlib.h>
#include <iostream>
#include <signal.h>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{

    if (argc < 3)
    {
        cout << "Informe o número do processo receptor e o sinal desejado" << endl;
        exit(1);
    }

    int PID = stoi(argv[1]);
    int signal = stoi(argv[2]);

    string signalName = (signal == 5) ? "SIGTRAP" : (signal == 8) ? "SIGFPE"
                                                : (signal == 14)  ? "SIGALRM"
                                                                  : "SINAL DESCONHECIDO";

    cout << "Processo selecionado: " << PID << endl;
    cout << "Sinal selecionado: " << signal << " (" << signalName << ")" << endl;

    // Função kill recebe o ID do processo e o signal number
    // 0 verifica se o processo existe
    int process_exists = kill(PID, 0);

    if (process_exists != 0)
    {
        cout << "Processo inexistente" << endl;
        exit(1);
    }
    else
    {
        cout << "Processo existente" << endl;
        kill(PID, signal);
        cout << "Sinal enviado" << endl;
    }

    return 0;
}