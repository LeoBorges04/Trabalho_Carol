#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>
#include <string.h>
#define MAX 101
#define TEL 21
#define CPF 20
#define SEN 11
#define FE 10
#define VERMELHO \033[1;31m
#define VERDE \033[1;32m
#define RESET \033[0;0m
//Acho que vou fazer uma locadora de filmes.
//precisa ter cadastro de cliente também.
//acho que to maluco

typedef struct Cliente{
    int id;
    bool status;
    char nome[MAX];
    char telefone[TEL];
    char cpf[CPF];
    char endereco[MAX];

} TCliente;

typedef struct Filme {
    int id;
    bool status;
    char faixaEtaria[FE];
    char nome[MAX];
    char categoria[MAX];
    int quantidade;
    float preco;

} TFilme;

//função legal para cortar o \n que atrapalha pra comparar string
void cortaFinal(char *s){
    if (!s) return;
    size_t len = strlen(s);
    if (len > 0 && s[len-1] == '\n') s[len-1] = '\0';
}

char toLowerCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
    return str;
}
00
//Acho que vou criar o atualizaCliente ainda, não sei.
void cadastraCliente(TCliente *cliente, int pos){
    int i;
    system("cls");
    cliente[pos].status = true;
    cliente[pos].id = 0;

    printf("--Cadastro Cliente--\n\n");
    printf("Nome: ");
    fgets(cliente[pos].nome, MAX-1, stdin);
    printf("\nTelefone: ");
    fgets(cliente[pos].telefone, TEL-1, stdin);
    printf("\nCPF: ");
    fgets(cliente[pos].cpf, CPF-1, stdin);
    //Cortei o \n
    cortaFinal(cliente[pos].cpf);
    printf("\nEndereco: ");
    fgets(cliente[pos].endereco, MAX-1, stdin);

    //A condição de '\0' significa chegar ao fim do cpf
    for(i = 0; cliente[pos].cpf[i] != '\0'; i++){
            if(cliente[pos].cpf[i] >= '0' && cliente[pos].cpf[i] <= '9'){
                cliente[pos].id += (cliente[pos].cpf[i] - '0'); // conversão marota
            }
    }

    printf(VERDE"\n\nCadastro realizado com sucesso!"RESET);
    Sleep(500);

}

void atualizaCliente(TCLiente *cliente, int n){}

void removeCliente(TCliente *cliente, int n){}

void imprimeTodosCli(TCliente *cliente, int n){}

void pesquisarCliente(TCliente *cliente, int n){}

void cadastraFilme(TFilme *filme, int pos){
    system("cls");
    filme[pos].id = pos;
    filme[pos].status = true;

    printf("--Cadastrar filme--\n\nNome do filme: ");
    fgets(filme[pos].nome, MAX - 1, stdin);
    cortaFinal(filme[pos].nome);

    printf("\nCategoria do filme: ");
    fgets(filme[pos].categoria, MAX-1, stdin);
    printf("\nFaixa Etária: ");
    fgets(filme[pos].faixaEtaria, FE-1, stdin);
    printf("\nPreço: ");
    scanf("%f", &filme[pos].preco);
    getchar();
    printf("\nQuantidade disponível: ");
    scanf("%d", &filme[pos].quantidade);
    getchar();

    printf(VERDE"\n\nCadastro realizado com sucesso!"RESET);
    Sleep(500);

}

int imprimeMenu(){
    system("cls");
    int op;
    printf("1-Cadastrar filme\n2-Cadastrar cliente\n3-Pesquisar filme\n4-Exibir lista de filmes\n5-Atualizar filme\n6-Remover filme\n7-Alugar filme\n8-Sair");
    printf("\n\nOpção: ");
    scanf("%d", &op);
    getchar();
    Sleep(1000);
    return op;
}

void imprimeTodos(TFilme *filme, int n){
    system("cls");
    printf("--Lista de filmes--\n\n");
    int i,j;

    printf("\n---------------------------------------------------\n");
    for(i = 0; i < n; i++){
        Sleep(500);
        if(filme[i].status == true){
            printf("ID: %d\n", filme[i].id);
            printf("\nNome: %s", filme[i].nome);
            printf("\nCategoria:  %s", filme[i].categoria);
            printf("\nFaixa Etária: %s", filme[i].faixaEtaria);
            printf("\nPreço: %.2f\n", filme[i].preco);
            printf("\nQuantidade disponível: %d", filme[i].quantidade);
            printf("\n---------------------------------------------------\n");
            }
    }
    printf("\n\n");
    system("pause");

}

void pesquisaFilme(TFilme *filme,int n){
    system("cls");
    bool encontrado = false;
    int i;
    char resposta[MAX];
    char respostaMin[MAX];
    char nomeMin[MAX];
    printf("--Pesquisar filme--\n\nDigite o nome do filme: ");
    fgets(resposta, MAX-1, stdin);
    cortaFinal(resposta);
    //To fazendo essa fuleragem pq quero comparar o nome do filme como condição na pesquisa
    //MAS não quero que seja "case sensitive" pro usuario poder digitar o nome do jeito que quiser
    strcpy(respostaMin, toLowerCase(resposta));

    for(i = 0; i < n; i++){

        strcpy(nomeMin, toLowerCase(filme[i].nome));

        if((strcmp(resposta, nomeMin) == 0) &&filme[i].status == true){
            printf("\n\nID: %d", filme[i].id);
            printf("\nNome: %s", filme[i].nome);
            printf("\nCategoria:  %s", filme[i].categoria);
            printf("\nFaixa Etária: %s", filme[i].faixaEtaria);
            printf("\nPreço: %.2f", filme[i].preco);
            printf("\nQuantidade disponível: %d\n\n", filme[i].quantidade);

            encontrado = true;
            break;
        }
    }

    if(!encontrado)printf(VERMELHO"\nFilme não encontrado!\n\n"RESET);
    system("pause");

}

void removerFilme(TFilme *filme, int n){
    system("cls");
    int id, i;
    printf("--Remover filme--\n\nDigite o ID do filme: ");
    scanf("%d", &id);
    getchar();

    if(id < 0 || id >= n){
        printf(VERMELHO"\n\nID inválido!"RESET);
        Sleep(1000);
        return;
    }
    if(!filme[id].status){
        printf(VERMELHO"\n\nFilme já apagado!"RESET);
        Sleep(1000);
        return;
    }

    filme[id].status = false;
    printf(VERDE"\nCadastro de filme apagado!"RESET);
    Sleep(1000);

}

void atualizaFilme(TFilme *filme, int n){
    system("cls");
    int id,i, op,sair;
    printf("\n--Atualizar filme--\n\nDigite o ID do filme: ");
    scanf("%d", &id);
    getchar();

    if(id < 0 || id >=n || !filme[id].status){
        printf(VERMELHO"\n\nID inválido!"RESET);
        atualizaFilme(filme,n);
        return;
    }


    do{
    printf("\nAlterar: \n1-Nome\n2-Categoria\n3-Faixa Etária\n4-Preço\n5-Quantidade disponível\nOpção: \n");
    scanf(" %d", &op);
    getchar();

    switch(op){

        case 1:
            printf("Nome: ");
            fgets(filme[id].nome, MAX-1, stdin);
            printf(VERDE"\n\nNome alterado com sucesso!"RESET);
            break;

        case 2:
            printf("Categoria: ");
            fgets(filme[id].categoria, MAX - 1, stdin);
            printf(VERDE"\n\nCategoria alterada com sucesso!"RESET);
            break;

        case 3:
            printf("Faixa etária: ");
            fgets(filme[id].faixaEtaria, 5, stdin);
            printf(VERDE"\n\nFaixa etária alterada com sucesso!"RESET);
            break;

        case 4:
            printf("Preço: ");
            scanf("%f", &filme[id].preco);
            getchar();
            printf(VERDE"\n\nPreço alterado com sucesso!"RESET);
            break;

        case 5:
            printf("Quantidade disponível: ");
            scanf("%d", &filme[id].quantidade);
            printf(VERDE"\n\nQuantidade alterada com sucesso!"RESET);
            getchar();
            break;
    }
        printf("\n\nDeseja alterar outro campo? (1-Sim/2-Não)\nOpção: ");
        scanf("%d", &sair);
        getchar();
        system("cls");

   } while(sair != 2);
            Sleep(1000);

}

void alugaFilme(TFilme *filme, TCliente *cliente, int n, int m){
    system("cls");

    bool encontrou = false;
    int i, chave, id;
    char cpf[CPF];

    printf("\n--Alugar filme--\nEntre com o cpf do cliente: ");
    fgets(cpf, CPF-1, stdin);
    cortaFinal(cpf);
    //não tive coragem de ir atrás de tabela hash pra isso
    //entao só somei cada número do cpf do cliente e chamei de chave
    chave = 0;
    for(i = 0; cpf[i] != '\0'; i++){
        if (cpf[i] >= '0' && cpf[i] <= '9'){
            chave += (cpf[i] - '0');  // conversão marota char '0'-'9' em int 0-9
        }
    }

    for(i = 0; i < m; i++){

        if(cliente[i].id == chave){
            printf(VERDE"\n\nCliente encontrado!"RESET);
            encontrou = true;
            break;
        }
    }


    if(!encontrou){
            printf(VERMELHO"\n\nCliente não encontrado!"RESET);
            Sleep(1000);
            return;
        }

    Sleep(1000);
    system("cls");
    printf("--Alugar filme--\n");
    printf("\nDigite o ID do filme: ");
    scanf("%d", &id);
    getchar();
    if(id < 0 || id >=n || !filme[id].status){
        printf(VERMELHO"\n\nFilme não encontrado!"RESET);
        Sleep(1000);
        return;
    }

    if(filme[id].quantidade == 0){
        printf(VERMELHO"\n\nSem estoque para esse filme!"RESET);
        Sleep(1000);
        return;
    }

    filme[id].quantidade--;
    printf(VERDE"\n\nAluguel realizado com sucesso!"RESET);
    printf("\n\nNome: %s", filme[id].nome);
    printf("\nPreço: %.2f", filme[id].preco);
    printf("\n\n");
    system("pause");
}

int main (){
    setlocale(LC_ALL, "Portuguese");
    TFilme *filme = NULL;
    TCliente *cliente = NULL;
    int m,n, op;
    n = 0,m = 0;

    do{
        op = imprimeMenu();

        switch(op){


        case 1:
            n++;
            if(n == 1){
                filme = (TFilme *) malloc(sizeof(TFilme));
            }else{
                filme = (TFilme *) realloc(filme, n * sizeof(TFilme));
            }
            cadastraFilme(filme, n-1);

            break;

        case 2:

            m++;
            if(m==1){
                cliente = (TCliente *) malloc(sizeof(TCliente));
            }else{
                cliente = (TCliente *) realloc(cliente, m * sizeof(TCliente));
            }
            cadastraCliente(cliente,m-1);
            break;

        case 3:
            if(n == 0){
                printf(VERMELHO"\n\nNão há filmes cadastrados!"RESET);
               break;
            }
            pesquisaFilme(filme, n);
            break;

        case 4:

            if(n == 0){
                printf(VERMELHO"\n\nNão há filmes cadastrados!"RESET);
                break;
            }
            imprimeTodos(filme, n);
            break;

        case 5:
            if(n == 0){
                printf(VERMELHO"\n\nNão há filmes cadastrados!"RESET);
                break;
            }
            atualizaFilme(filme,n);
            break;

        case 6:
            if(n == 0){
                printf(VERMELHO"\n\nNão há filmes cadastrados!"RESET);
                break;
            }
            removerFilme(filme,n);
            break;

        case 7:
            if(n == 0){
                printf(VERMELHO"\n\nNão há filmes cadastrados!"RESET);
                break;
            }
            alugaFilme(filme,cliente,n,m);
            break;

        case 8:
            printf(VERDE"\n\nOperações encerradas!"RESET);
            break;
        default:
            printf(VERMELHO"\n\nOpção inválida!"RESET);

        }

    }while(op != 8);

    return 0;
}
