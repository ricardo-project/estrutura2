/*2. Implemente um programa que manipule uma pilha. O programa deve ser desenvolvido com as seguintes regras:
� Criar um menu com as op��es:
o Criar pilhar � O usu�rio deve informar o tamanho da pilha; caso a pilha j� tenha sido criada
anteriormente, antes de criar uma pilha nova, a pilha antiga deve ser removida e a mem�ria deve
ser desalocada.
o Inserir � O usu�rio deve informar um valor a ser inserido; caso a pilha esteja cheia, uma mensagem
deve ser exibida.
o Remover � Remover um elemento da pilha e mostrar o elemento removido; caso a pilha esteja
vazia, uma mensagem deve ser exibida.
o Consultar � Verificar se a pilha cont�m um determinado valor informado pelo usu�rio.
o Mostrar � Mostar a pilha.
o Sair � Sair do programa.
� N�o permitir a inclus�o de valores duplicados;
� Imprimir uma mensagem de erro caso a pilha n�o tenha sido criada e o usu�rio tente executar uma das
seguintes opera��es: inserir, remover, consultar ou mostrar.*/

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "pilha.hpp"

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int menu = -1;
    int *pilha = NULL;
    int *tam = new int;
    int *top = new int(-1);

    do
    {
        system("cls");
        cout << "####MENU DE OP��ES###" << endl;
        cout << "# 0 - Sair          #" << endl;
        cout << "# 1 - Criar pilha   #" << endl;
        cout << "# 2 - Inserir       #" << endl;
        cout << "# 3 - Remover       #" << endl;
        cout << "# 4 - Consultar     #" << endl;
        cout << "# 5 - Mostrar pilha #" << endl;
        cout << "#####################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
            cout << "Programa finalizado.";
            break;

            case 1: // CRIA��O DE PILHAA

                do {
                    cout << ">> Insira o tamanho da nova pilha: ";
                    cin >> *tam; // Usu�rio informa o tamanho, que n�o pode ser nulo ou negativo!!
                    if(*tam <= 0) cout << "!!! VALOR INSERIDO INV�LIDO !!!\n";
                    else break;
                } while(true);
                if(pilha != NULL) { // Se j� houver uma pilha, fazer a exclus�o dela na mem�ria para inserir a nova
                    delete[] pilha;
                    *top = -1;
                }
                pilha = new int[*tam]; // Nova pilha criada!!! B)
                cout << "Nova pilha criada!!!";
                getchar();

            break;

            case 2: // INSERIR ELEMENTO NA PILHA

                if(pilha != NULL) {
                    if(*top == *tam - 1) {
                        cout << "!!! PILHA J� EST� CHEIA (Retire elementos para poder colocar mais) !!!";
                    } else {
                        do {
                            int elem;
                            cout << ">> Insira um elemento para a pilha: ";
                            cin >> elem;
                            int jaExiste = 0;
                            int *i = new int;
                            for(*i = 0; *i <= *top; *i += 1) {
                                if(pilha[*i] == elem) {
                                    cout << "!!! ESTE ELEMENTO J� FOI INSERIDO... INSIRA OUTRO !!!\n";
                                    jaExiste = 1;
                                    break;
                                }
                            } if(!jaExiste) { // Se usu�rio inseriu elemento que N�O existe na pilha, la�o "do.. while" � ENCERRADO!!!
                                *top += 1;
                                pilha[*top] = elem;
                                cout << "!!! Elemento inserido com MUITO SUCESSO B-) !!!";
                                getchar();
                                break;
                            }
                        } while(true);
                    }
                } else {
                    cout << "!!! VOC� N�O CRIOU UMA PILHA (Fa�a isso na op��o 1!) >:( !!!";
                }

            break;

            case 3: // REMOVER ELEMENTO
                if(pilha != NULL) {
                    if(*top == -1) {
                        cout << "!!! Pilha VAZIA... Preencha com elementos !!!";
                    } else {
                        cout << "!!! Elemento de �ndice " << *top << " removido: " << pilha[*top] << " !!!";
                        *top -= 1;
                    }
                } else {
                    cout << "!!! VOC� N�O CRIOU UMA PILHA (Fa�a isso na op��o 1!) >:( !!!";
                }
            break;

            case 4: // CONSULTAR
                if(pilha != NULL) {
                    if(*top == -1) {
                        cout << "!!! Pilha VAZIA... Preencha com elementos !!!";
                    } else {
                        int num;
                        cout << ">> Insira um elemento: ";
                        cin >> num;
                        int encontrado = 0;
                        int *i = new int(0);
                        for(*i = 0; *i <= *top; *i += 1) {
                            if(pilha[*i] == num) {
                                cout << "!!! ELEMENTO ENCONTRADO no �ndice " << *i << " !!!";
                                encontrado = 1;
                                break;
                            }
                        } if(!encontrado) {
                            cout << "!!! OI, MEU AMOR, O SISTEMA N�O ENCONTROU O N�MERO QUE TU INSERIU, MAS N�O DESISTA DE SEUS SONHOS !!!";
                        } getchar();
                    }
                } else {
                    cout << "!!! VOC� N�O CRIOU UMA PILHA (Fa�a isso na op��o 1!) >:( !!!";
                }

            break;

            case 5: // MOSTRAR PILHA
                if(pilha != NULL) {
                    if(*top == -1) {
                        cout << "!!! Pilha est� VAZIA... Insira elementos!!!";
                    } else {
                        cout << "!!! Pilha (com " << (*top + 1) << " elemento";
                        if(*top > 0) {
                            cout << "s): ";
                            int *i = new int(0);
                            for(*i = 0; *i <= *top; *i += 1) {
                                cout << "| " << pilha[*i] << " ";
                            } cout << "|";
                        } else {
                            cout << "): | " << pilha[0] << " |";
                        }
                    }
                } else {
                    cout << "!!! VOC� N�O CRIOU UMA PILHA (Fa�a isso na op��o 1!) >:( !!!";
                }

            break;

            default:
                cout << "Op��o inv�lida.";
                break;
        }; getchar();
    }
    while(menu != 0);
}
