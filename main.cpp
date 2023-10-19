#include <iostream>
#include "includes/func.h"

int main(){
    head lista;
    lista.comeco=nullptr;
    lista.cont=0;

    lerArquivo(&lista);
    int opcao;
    pet *aux;

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
        cout << "[9] - Salvar e sair" <<endl;
        cout << "[10] - Formatar Sistema Cadastral" <<endl;
        
        cout << "Digite uma opção: ";
        cin >> opcao;
        system("clear");
        switch (opcao)
        {
        case 1: // Inserir lista
            cout << endl<< "Digite o ID do Pet: ";
            do{ //Tratamento de erro, se o usuário coloca uma matrícula já cadastrada
                cin >> matricula;
                if(matDisponivel(&lista,matricula)==1){
                    cout<<"Essa matrícula já está em uso, digite outra!"<<endl<<endl;
                    limparConsole();
                    cout<<"Digite o novo ID do Pet: ";}
            }while(matDisponivel(&lista,matricula)==1);
            
            getline(cin,nomePet); //getline para evitar estouro de buffer
            cout << endl<< "Digite o nome do Pet: ";
            getline(cin,nomePet);
            cout << endl<< "Digite o nome do dono do Pet: ";
            getline(cin,nomeDono);
            cout << endl<< "Digite o tipo do Pet: ";
            getline(cin,tipo);
            cout << endl<< "Digite o sexo do Pet: ";
            cin >> sexo;
            cout << endl<< "Digite a idade do Pet: ";
            cin >> idade;
            adicionar(&lista, matricula, cxAlta(nomePet), cxAlta(nomeDono), cxAlta(tipo), cxAlta(sexo), idade);
            cout<<endl<<endl<<"O Pet foi cadastrado com sucesso!";
            limparConsole();
            break;
       
        case 2: // Alterar Cadastro com base na matricula
            cout << endl<< "Digite o ID do Pet em que deseja Alterar Cadastro: " <<endl;
            cin >> matricula;
            cout <<endl;
            system("clear");
            
            aux = pesquisarMatricula(&lista, matricula); //Pesquisa a matricula e armazena o ponteiro para a struct da matricula
            if (aux->matricula == matricula) {
                char conf;
                cout<<"Deseja manter o ID antigo? (S/N): ";
                cin>>conf;
                conf=toupper(conf);
                if(conf=='N'){ //Tratamento de erro para o usuário não digitar uma matrícula existente
                    cout << "Digite o novo ID do Pet: ";
                    do{
                       cin >> matricula;
                        if(matDisponivel(&lista,matricula)==1){
                            cout<<"Essa matrícula já está em uso, digite outra!"<<endl<<endl;
                            limparConsole();}
                        cout<<"Digite o novo ID do Pet: ";
                    }while(matDisponivel(&lista,matricula)==1);
                    }
                
                getline(cin,nomePet);
                cout << "Digite o novo nome do Pet: " <<endl<<endl;
                getline(cin,nomePet);
                cout << "Digite o novo nome do dono do Pet " <<endl<<endl;
                getline(cin,nomeDono);
                cout << "Digite o novo tipo do Pet: " <<endl<<endl;
                getline(cin,tipo);
                cout << "Digite o novo sexo do Pet: " <<endl<<endl;
                cin >> sexo;
                cout << "Digite a nova idade do Pet: " <<endl<<endl;
                cin >> idade;
                alterar(aux,matricula, nomePet, nomeDono, tipo, sexo, idade);
                cout<<"O Pet foi cadastrado com sucesso!";
            }
            else {
                cout << "Pet não encontrado" <<endl;
            }
            limparConsole();
            break;
       
        case 3: // Excluir com base na matricula
            cout << endl<< "Digite o ID do Pet em que deseja Excluir Cadastro: " <<endl;
            cin >> matricula;
            remover(&lista, matricula);
            limparConsole();
            break;
        
        case 4: // Imprimir Listagem 
            cout << endl;
            printarLista(&lista);
            break;
        
        case 5: //Buscar por matricula
            cout << endl;
            cout<<"Digite o ID do Pet que deseja procurar: ";
            cin>>matricula;
            aux = pesquisarMatricula(&lista, matricula);
            if (aux){ //Se aux tiver algo
                imprimir(aux);
            }
             else {
                cout << "Pet não encontrado" <<endl;
            }
            limparConsole();
            break;

        case 6: //Buscar por nome do dono
            cout << endl;
            cout<<"Digite o nome do dono do pet que deseja procurar: ";
            getline(cin,nomeDono); //getline para evitar o estouro de buffer (entrada do tipo int indo para tipo string)
            getline(cin,nomeDono);
            aux = pesquisarDono(&lista, nomeDono);
            if (aux){
                imprimir(aux);
            }
             else {
                cout << "Pet não encontrado!" <<endl;
            }
            limparConsole();
            break;
       
        case 7: 
            // ordernar1
            break;
        
        case 8:
            // ordernar2
            break;
        
        case 9: // salvar no arquivo
            salvarArquivo(&lista);
            break;
        
        case 10: //limpar lista e arquivo
            char c;
            cout<<"Tem certeza que deseja limpar toda a base de dados (ação irreversível!)? (S/N): ";
            cin>>c;
            toupper(c);
            if (c=='S')
                limparLista(&lista);
            limparConsole();
            break;
        
        default:
            cout << "Dígito Inválido!" <<endl;
            break;
        }

    } while(opcao != 9);
}