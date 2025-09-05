#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#define MAX 101
#define TEL 21
#define TAM 11
#define SEN 11
//Acho que vou fazer uma locadora de filmes.
//precisa vender (vinicius soares)
//precisa ter cadastro de cliente.

typedef struct Cliente(){
    int id;
    bool status;
    char nome[MAX];
    char telefone[TEL];
    char cpf[CPF];
    char senha[SEN];
    char endereco[MAX];
    
} TCliente;

typedef struct Filme {
    int id;
    bool status; 
    char faixaEtaria[6];
    char nome[MAX];
    char categoria[MAX];
    int quantidade;
    double preco;

} TFilme;

void cadastraCliente(TCliente *cliente, int pos){
    int i;
   
    cliente[pos].status = true;
    
    printf("\nCadastro Cliente: ");
    printf("\n\nNome: ");
    fgets(cliente[pos].nome, MAX-1, stdin);
    printf("\nTelefone: ");
    fgets(cliente[pos].telefone, TEL-1, stdin);
    printf("\nCPF: ");
    fgets(cliente[pos].cpf, CPF-1, stdin);
    
    printf("\nSenha: ");
    fgets(cliente[pos].senha, SEN -1, stdin);
    printf("\nEndereco: ");
    fgets(cliente[pos].endereco, MAX-1, stdin);
    
    for(i = 0; i < CPF; i++){
        cliente[pos].id += cliente[pos].cpf[i];
    }
   
    printf("\n\nCadastro realizado com sucesso!");
    
}



void cadastraFilme(TFilme *filme, int pos){
    
    filme[pos].id = pos;
    filme[pos].status = true;
    
    printf("Nome do filme: ");
    fgets(filme[pos].nome, MAX - 1, stdin);
    print("\nCategoria do filme: ");
    fgets(filme[pos].categoria, stdin);
    printf("\nFaixa Etária: ");
    fgets(filme[pos].faixaEtaria, 5, stdin);
    printf("\nPreço: ");
    scanf("%d", &filme[pos].preco);
    printf("\nQuantidade disponível: ");
    scanf("%d", &filme[pos].quantidade);
    getchar();
}

void imprimeMenu(){
    printf("1-Cadastrar filme\n2-Cadastrar cliente\n3-Pesquisar filme\n4-Exibir lista de filmes\n5-Atulalizar filme\n6-Remover filme\n7-Alugar filme\n8-Sair");
}
void imprimeTodos(TFilme *filme, int n){
    
    for(i = 0; i < n; i++){
        if(filme[i].status == true){
            printf("ID: %d", filme[i].id);
            printf("Nome: %s", filme[i].nome);
            printf("\nCategoria:  %s", filme[i].categoria);
            printf("\nFaixa Etária: %s", filme[i].faixaEtaria);
            printf("\nPreço: %.2d", filme[i].preco);
            printf("\nQuantidade disponível: %d", filme[i].quantidade);
        }
    }
}

void pesquisaFilme(TFilme *filme,int n){
    bool encontrado = false;
    int id,0;
    printf("Digite o id do filme: ");
    scanf("%d", &id);
    getchar();
    for(i = 0; i < n; i++){
        if(filme[i].id == id && filme[i].status == true){ 
            printf("ID: %d", filme[i].id);
            printf("Nome: %s", filme[i].nome);
            printf("\nCategoria:  %s", filme[i].categoria);
            printf("\nFaixa Etária: %s", filme[i].faixaEtaria);
            printf("\nPreço: %.2d", filme[i].preco);
            printf("\nQuantidade disponível: %d", filme[i].quantidade);
            
            encontrado = true;
        }
    }

    if(!encontrado)printf("\nFilme não encontrado!");
        
}

void removerFilme(TFilme *filme, int n){
    int id, i;
    printf("Digite o ID do filme: ");
    scanf("%d", &id);
    getchar();
    if(id < 0 || id >= n || !filme[id].status){
        printf("ID inválido!");
        removerFilme(filme, n);
        return;
    }
        filme[id].status = false;
        printf("Cadastro de filme apagado!");

}

void atualizaFilme(TFilme *filme, int n){
   
    int id, op,sair;
    printf("\nDigite o ID do filme: ");
    scanf("%d", &id);
    getchar();
   
    if(id < 0 || id >=n || !filme[id].status){
        printf("\nID inválido!");
        atualizaFilme(filme);
        return;
    }
    
    printf("\nNome: %s", filme[i].nome);
    
    do{
    printf("\nAlterar: \n1-Nome\n2-Categoria\n3-Faixa Etária\n4-Preço\n5-Quantidade disponível\nOpção: \n");
    scanf(" %d", &op);
    getchar();
    
    switch(op){
        
        case 1:
            printf("Nome: ");
            fgets(filme[id].nome, MAX-1, stdin);
            printf("\nNome alterado com sucesso!");
            break;
        
        case 2:
            printf("Categoria: ");
            fgets(filme[id].categoria, MAX - 1, stdin);
            printf("\nCategoria alterada com sucesso!");
            break;
            
        case 3:
            printf("Faixa etária: ");
            fgets(filme[id].faixaEtaria, 5, stdin);
            printf("\nFaixa etária alterada com sucesso!");
            break;
      
        case 4:
            printf("Preço: ");
            scanf("%d", &filme[id].preco);
            getchar();
            printf("\nPreço alterado com sucesso!");
            break;

        case 5:
            printf("Quantidade disponível: ");
            scanf("%d", &filme[id].quantidade);
            break;
    }
        printf("Deseja alterar outro campo? (1-Sim/2-Não)");
        scanf("%d", &sair);
   } while(sair != 2);
    
}
///////////////////////////////TERMINAR AINDA
void alugaFilme(TFilme *filme, int n, int m){
    //tabela hash nessa porra mesmo fodase
    bool encontrou = false;
    int i, chave;
    char cpf[CPF];
    printf("Entre com o cpf do cliente: ");
    fgets(cpf, CPF-1, stdin);
    
    for(i = 0; i < CPF; i++){
        chave += cpf[i];
    }
    
    for(i = 0; i < n; i++){
        if(cliente[i].id == chave){
            printf("Cliente encontrado!");
            encontrou = true;
            break;
        }
    }
    //ainda falta o aluguel ja que encontrou e dps o !encontrou...
    
    if(encontrou){
        
        
    }
}
    
    
int main (){
    setlocale(LC_ALL, "Portuguese");
    TFilme *filme;
    TCliente *cliente;
    int m,n, op;
    n,m = 0;
    
    do{
        imprimeMenu();
        scanf("%d", &op);
        getchar();
        
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
                printf("Não há cadastro de filmes!");
                return;
            }
            pesquisaFilme(filme, n);
            break;
        
        case 4:
            if(n == 0){
                printf("Não há cadastro de filmes!");
                return;
            }
            imprimeTodos(filme, n);
            break;
        
        case 5:
            if(n == 0){
                printf("Não há cadastro de filmes!");
                return;
            }
            atualizaFilme(filme,n);
            break;
        
        case 6:
            if(n == 0){
                printf("Não há cadastro de filmes!");
                return;
            }
            removerFilme(filme,n);
            break;
        
        case 7:
            if(n == 0){
                printf("Não há cadastro de filmes!");
                return;
            }
            alugaFilme(filme,n);
            break;

        case 8:
            printf("Operações encerradas!");
            break;
        default:
            printf("Opção inválida!");

        }

    }
    
    return 0;
}
