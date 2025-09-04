#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#define MAX 50
#define TAM 10

//Acho que vou fazer uma locadora de filmes.
typedef struct Filme {
    int id;
    bool status; 
    char faixaEtaria[6];
    char nome[MAX];
    char categoria[MAX];
    int quantidade;
    double preco;

} TFilme;


void cadastraFilme(TFilme *filme, int pos){
    int i;
    filme[i].id = pos;
    filme[i].status = true;
    
    printf("Nome do filme: ");
    fgets(filme[i].nome, MAX - 1, stdin);
    print("\nCategoria do filme: ");
    fgets(filme[i].categoria, stdin);
    printf("\nFaixa Etária: ");
    fgets(filme[i].faixaEtaria, 5, stdin);
    printf("\nPreço: ");
    scanf("%d", &filme[i].preco);
    printf("\nQuantidade disponível: ");
    scanf("%d", &filme[i].quantidade);
    
}

void imprimeMenu(){
    printf("1-Cadastrar filme\n2-Pesquisar filme\n3-Exibir lista de filmes\n4-Atulalizar filme\n5-Remover filme\n6-Alugar filme\n7-Sair");
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

void atualizaFilme(TFilme *filme){
    int id;
    printf("Digite o ID do filme: ");
    scanf("%d", &id);
    getchar();
    if(!filme[id].status){
        printf("");
    }

}


int main (){
    setlocale(LC_ALL, "Portuguese");
    TFilme *filme;
    int n, op;
    imprimeMenu();
    scanf("%d", &op);
    getchar();
    n = 0;
    
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

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;

    case 7:

        break;
    default:
        printf("Opção inválida!");
      

    }


}
