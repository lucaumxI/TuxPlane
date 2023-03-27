#include "arvore.h"
#include "arvore.cpp"
#include <cstdlib>
#include <unistd.h>
using std::cout,std::endl,std::flush,std::cin;
int main(){
    int voo;
    int prioridade;
    ABBPtr arvore;
    int espera;
    arvore = new ABB(-1,-1);
    bool loop = true;
    cout << "========================================================" << endl;
    cout << "                        TUXPLANE                        " << endl;
    cout << "         Gerenciador de pousos com prioridade           " << endl;
    cout << "========================================================" << endl;
    sleep(1);
    system("CLS");
    int escolha=0;
    while(loop){
        
        cout << "========================================================" << endl;
        cout << "           Escolha uma função das disponíveis           " << endl;
        cout << "              1 - Ver lista ordenada dos vôos           " << endl;
        cout << "              2 - Cadastrar um vôo                      " << endl;
        cout << "              3 - Registrar pouso                       " << endl;
        cout << "              4 - Fechar Tuxplane                       " << endl;
        cout << "========================================================" << endl;
        std::cin>>escolha;
        system("CLS");
        if(escolha!=0){
            switch (escolha){
                case 1:
                    cout << "========================================================" << endl;
                    arvore->imprime();
                    cout << "                                                        " << endl;
                    cout << "          Selecione qualquer número para sair           " << endl;
                    cout << "========================================================" << endl;
                    std::cin>>espera;
                    system("CLS");
                    break;
                case 2:
                    cout << "========================================================" << endl;
                    cout << "                  Numero do vôo:                        " << endl;
                    cout << "========================================================" << endl;
                    cin>>voo;
                    system("CLS");
                    cout << "========================================================" << endl;
                    cout << "              Prioridade do vôo                         " << endl;
                    cout << "              1 - Ordem de cadastro                     " << endl;
                    cout << "              2 - Emergência sem rico de vida (Pan-Pan) " << endl;
                    cout << "              3 - Emergência com risco de vida(Mayday)  " << endl;
                    cout << "========================================================" << endl;
                    cin>>prioridade;
                    system("CLS");
                    arvore->insere(voo,prioridade);
                    cout << "========================================================" << endl;
                    cout << "                Voo cadastrado com sucesso!             " << endl;
                    cout << "========================================================" << endl;
                    sleep(1);
                    system("CLS");
                    break;
                case 3:
                    arvore->remove();
                    cout << "========================================================" << endl;
                    cout << "               Pouso cadastrado com sucesso!            " << endl;
                    cout << "========================================================" << endl;
                    sleep(2);
                    system("CLS");
                    break;
                case 4:
                    loop=false;
                default:
                    break;
            }
        }

    }
}