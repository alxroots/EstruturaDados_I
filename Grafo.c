//
//  Grafo.c
//  
//
//  Created by Alex Sousa on 08/07/18.
//

#include <stdio.h>
#include <stdlib.h>
#define maximo 10

//vGlobais
int tamanho = 0;
int grafo[maximo];
int ares[maximo][maximo];

int grafo_tamanho();
void aresta_inserir();
void aresta_remover();
void grafo_imprime();
void arestas_imprime();
int mostrar_menu();

int main(void){
    tamanho = grafo_tamanho();
    int opcao = 9;
    while (opcao != 0) {
        opcao = mostrar_menu();
        switch (opcao) {
            case 1:
                aresta_inserir();
                break;
            case 2:
                aresta_remover();
                break;
            case 3:
                grafo_imprime();
                break;
            case 4:
                arestas_imprime();
                break;
            case 0:
                opcao = 0;
                break;
        }
    }
    
    return 0;
}


int grafo_tamanho(){
    int tamanho;
    printf("Escolher qt de vértices: \n");
    scanf("%d", &tamanho);
    return tamanho;
}


//Defini arestas
void aresta_inserir(){
    int v1, v2;
    system("clear");
    printf("Escolha o vertice de origem. Valor entre 0 e %d\n", tamanho-1);
    scanf("%d", &v1);
    printf("Escolha o vertice de destino. Valor entre 0 e %d\n", tamanho-1);
    scanf("%d", &v2);
    if (v1 > tamanho-1 || v2 > tamanho-1 || v1 < 0 || v2 < 0){
        printf("Você digitou um valor inválido");
    }else{
        ares[v1][v2] = 1;
        ares[v2][v1] = 1;
    }
}
//Eliminar arestas
void aresta_remover(){
    int v1, v2;
    system("clear");
    printf("Escolha o vertice de origem. Valor entre 0 e %d\n", tamanho-1);
    scanf("%d", &v1);
    printf("Escolha o vertice de destino. Valor entre 0 e %d\n", tamanho-1);
    scanf("%d", &v2);
    if (v1 > tamanho-1 || v2 > tamanho-1 || v1 < 0 || v2 < 0){
        printf("Você digitou um valor inválido");
    }else{
        ares[v1][v2] = 0;
        ares[v2][v1] = 0;
    }
}

//Mostrar vertice
void grafo_imprime(){
    printf("Lista de vertice.\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d", grafo[i]);
    }
    printf("\n\n");
}

//Mostrar arestas
void arestas_imprime(){
    printf("Matrizes de adjacencia\n");
    for (int i = 0; i < tamanho; i++){
        for (int j =0; j < tamanho; j++){
            printf("%d", ares[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

//Menu
int mostrar_menu(){
    int x;
    printf("Escolha uma opção\n");
    printf("1 - inserir arestas\n");
    printf("2 - remover arestas\n");
    printf("3- imprime grafo\n");
    printf("4 - imprime arestas\n");
    printf("0 - sair\n\n");
    scanf("%d", &x);
    return x;
}
