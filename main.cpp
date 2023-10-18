#include <iostream>
#include "includes/func.h"

int main(){
    head lista;
    lista.comeco=nullptr;
    lista.cont=0;
    return 0;

    int opcao, valor;
    
    int matricula, idade;
    string nomePet, nomeDono, tipo, sexo;

 
    do {
        cout << "       Sistema Cadastral        " <<endl;
        cout << "--------------------------------" <<endl;
        cout << "[1] - Cadastrar Pet" <<endl;
        cout << "[2] - Alterar Cadastro" <<endl;
        cout << "[3] - Excluir Cadastro" <<endl;
        cout << "[4] - Imprimir Listagem" <<endl;
        cout << "[5] - Buscar P/ Matricula" <<endl;
        cout << "[6] - Buscar P/ Nome do Dono" <<endl;
        cout << "[7] - Ordernar 1" <<endl;
        cout << "[8] - Ordernar 2" <<endl;
        cout << "[9] - Listagem Indivídual" <<endl;
        cout << "[10] - Listagem de Todas Entidades" <<endl;
        cout << "[11] - Sair e Salvar" <<endl;
        
        cout << "Digite uma opção" <<endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Digite o ID do Pet: " <<endl;
            cin >> matricula;
            cout << "Digite o nome do Pet: " <<endl;
            cin >> nomePet;
            cout << "Digite o nome do dono do Pet " <<endl;
            cin >> nomeDono;
            cout << "Digite o tipo do Pet: " <<endl;
            cin >> tipo;
            cout << "Digite o sexo do Pet: " <<endl;
            cin >> sexo;
            cout << "Digite a idade do Pet: " <<endl;
            cin >> idade;
            cout << "Digite o ID do Pet: " <<endl;
            cin >> matricula;
            break;
        
        default:
            break;
        }

    } while(opcao != 11);
}