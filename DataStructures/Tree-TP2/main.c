// Grupo: Douglas Vieira, Leonardo Almeida, Luis Henrique

#include <stdio.h>
#include <string.h>
#include "tree.h"

TreeNode *root;
Player player;
char name[30], position[20];
int age, skill, number, option;
bool success;

void insert_player();
void search_player();
void list_players();
void remove_player();
void read_player_name(char *name);

int main(void)
{
    printf("____ Dino Sports Club _____\n\n");

    tree_init(&root);

    do
    {
        printf("Escolha uma das opcoes abaixo: \n");
        printf("1 - Cadastrar jogador\n");
        printf("2 - Buscar jogador\n");
        printf("3 - Listar jogadores\n");
        printf("4 - Remover jogador\n");
        printf("5 - Sair\n\n");

        scanf(" %d", &option);
        while((getchar()) != '\n');

        switch (option)
        {
        case 1:
            insert_player();
            break;
        case 2:
            search_player();
            break;
        case 3:
            list_players();
            break;
        case 4:
            remove_player();
            break;
        case 5:
            printf("Saindo do sistema.\n");
            break;
        default:
            printf("Opção inválida?\n");
            break;
        }
        puts("\n");
    } while (option != 5);

    tree_free(root);

    return 0;
}

void insert_player()
{
    printf("Insira os dados do jogador que deseja adicionar: \n");

    printf("Nome: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;  // remove a nova linha no final da string

    printf("Posicao: ");
    fgets(position, sizeof(position), stdin);
    position[strcspn(position, "\n")] = 0;  // remove a nova linha no final da string

    printf("Idade: ");
    scanf(" %d", &age);
    while((getchar()) != '\n');

    printf("Habilidade: ");
    scanf(" %d", &skill);
    while((getchar()) != '\n');

    printf("Numero: ");
    scanf(" %d", &number);
    while((getchar()) != '\n');

    player = player_init(name, position, age, skill, number);

    success = tree_insert_player(&root, player);
    if (success)
    {
        printf("Jogador inserido com sucesso!\n");
    }
    else
    {
        printf("Jogador ja existente no sistema…\n");
    }
}

void search_player()
{
    printf("Nome do jogador a ser buscado: ");
    scanf("%s", name);

    success = tree_search_player(root, name, &player);
    if (success)
    {
        player_print(player);
    }
    else
    {
        printf("Jogador nao encontrado!\n");
    }
}

void list_players()
{
    printf("Lista de jogadores em ordem alfabetica: \n");
    tree_print_players(root);
}

void remove_player()
{
    printf("Nome do jogador a ser removido: ");
    scanf("%s", name);

    success = tree_remove_player(&root, name);
    if (success)
    {
        printf("Jogador removido com sucesso!\n");
    }
    else
    {
        printf("Jogador nao encontrado!\n");
    }
}
