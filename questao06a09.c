#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> 

// Exercício 06 

typedef struct voo {
    int numVoo;
    int dataVoo;
    int hora;
    int minuto;
    int aeroportoSaida;
    int aeroportoChegada;
    int rota;
    float tempoEstimado;
    int passageiros;
    struct voo* prox;
} Voo;

void cadastrarVoo(Voo** lista);
void consultaVoo(Voo* lista);
void removeVoo(Voo** lista);
int somaRecursiva(int n);

int main() {
    Voo* listaVoos = NULL; //lista vazia
    int opcao, n;

    setlocale(LC_ALL, "Portuguese");

    do {
        printf("--------------------- MENU VOEBEM ---------------------\n");
        printf("1. Cadastrar Voo\n");
        printf("2. Consultar Voo\n");
        printf("3. Remover Voo\n");
        printf("4. Sair\n");
        printf("\nEscolha uma Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarVoo(&listaVoos); //questao 7
                break;
            case 2:
                consultaVoo(listaVoos); //questao 8
                break;
            case 3:
                removeVoo(&listaVoos); //questao 9
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("OpÃ§Ã£o invÃ¡lida!\n");
        }
    } while (opcao != 4);

    while (listaVoos != NULL) {
        Voo* temp = listaVoos;
        listaVoos = listaVoos->prox;
        free(temp);
    }

    return 0;
}

// Exercício 07 - Cadastrar um voo

void cadastrarVoo(Voo** lista) {
    Voo* novo = (Voo*)malloc(sizeof(Voo));
    if (novo == NULL) {
        printf("Não foi possível alocar na memória!\n");
        return;
    }

    printf("Nº do Voo: ");
    scanf("%d", &novo->numVoo);
    
    printf("Data do Voo (1 - seg): ");
    scanf("%d", &novo->dataVoo);
    
    printf("Horário do Voo (HH:MM): ");
    scanf("%d:%d", &novo->hora, &novo->minuto);
    
    printf("Aeroporto de Saída (ID): ");
    scanf("%d", &novo->aeroportoSaida);
    
    printf("Aeroporto de Chegada (ID): ");
    scanf("%d", &novo->aeroportoChegada);
    
    printf("Rota (ID): ");
    scanf("%d", &novo->rota);
    
    printf("Tempo estimado de voo (H): ");
    scanf("%f", &novo->tempoEstimado);
    
    printf("Passageiros a bordo: ");
    scanf("%d", &novo->passageiros);

    novo->prox = *lista;
    *lista = novo;

    printf("\n--------Voo cadastrado com sucesso!--------\n");
}

// Exercício 08 - Consultar um voo

void consultaVoo(Voo* lista) {
    int numero;
    printf("Digite o número do voo: ");
    scanf("%d", &numero);

    while (lista != NULL) {
        if (lista->numVoo == numero) {
            printf("\n------------Informações do Voo:------------\n");
            printf("Número do Voo: %d\n", lista->numVoo);
            printf("Data do Voo: %d\n", lista->dataVoo);
            printf("Horário do Voo: %02d:%02d\n", lista->hora, lista->minuto);
            printf("Aeroporto de Saída: %d\n", lista->aeroportoSaida);
            printf("Aeroporto de Chegada: %d\n", lista->aeroportoChegada);
            printf("Rota: %d\n", lista->rota);
            printf("Tempo estimado: %.2f horas\n", lista->tempoEstimado);
            printf("Passageiros a bordo: %d\n\n", lista->passageiros);
            return;
        }
        lista = lista->prox;
    }

    printf("\n--------Voo não encontrado--------\n");
}

// Exercício 09 - Remover um voo

void removeVoo(Voo** lista) {
    int numero;
    printf("Nº do voo REMOVIDO: ");
    scanf("%d", &numero);

    Voo* atual = *lista;
    Voo* anterior = NULL;

    while (atual != NULL) {
        if (atual->numVoo == numero) {
            if (anterior == NULL) {
                *lista = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("\n--------Voo removido com sucesso!--------\n");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("\n--------Voo não encontrado!--------\n");
}
