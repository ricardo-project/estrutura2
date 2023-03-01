/*3. Faça um programa que cadastre em uma estrutura do tipo pilha vários números, sendo no máximo 6, ao remover
um número desta estrutura o mesmo deve ser empilhado em outra pilha, conforme o critério: se o número for
par na pilha dos pares, se for ímpar na pilha dos ímpares. No menu de opções deve ter uma alternativa para zerar
as três pilhas, mostrar pilha inicial, a dos pares e a dos ímpares.*/

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

    Pilha P, pP, pI;
    inicializaP(&P, 6);
    inicializaP(&pP, 6);
    inicializaP(&pI, 6);

    do
    {
        system("cls");
        cout << "###############MENU DE OPÇÕES###############" << endl;
        cout << "# 0 - Sair                                 #" << endl;
        cout << "# 1 - Inserir elementos na pilha principal #" << endl;
        cout << "# 2 - Remover valor da pilha principal     #" << endl;
        cout << "# 3 - Mostrar todas as pilhas              #" << endl;
        cout << "# 4 - Zerar todas as pilhas                #" << endl;
        cout << "############################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
            cout << "Programa finalizado.";
            break;

            case 1:
                if(cheiaP(&P)) {
                    cout << "!!! Pilha principal está CHEIA !!!";
                } else {
                    int num;
                    cout << "Insira um número, seu LIND@: ";
                    cin >> num;
                    empilhaP(&P, num);
                    cout << "!!! ELEMENTO INSERIDO COM SUCESSO !!!";
                } getchar();
            break;

            case 2:

            break;

            case 3:

            break;

            case 4:

            break;

        }; getchar();
    }
    while(menu != 0);
}
