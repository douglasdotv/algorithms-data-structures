#include "tree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Função de inserção de jogadores
 * Chama recursivamente até encontrar um nó nulo e insere o jogador
 */
bool tree_insert_player(TreeNode **root, Player player)
{
    // Se o nó atual for nulo, criar um novo nó com o jogador e inserir
    if (*root == NULL)
    {
        *root = tree_create_node(player);
        return true;
    }
    // Se o nó atual não for nulo
    else
    {
        // Comparar o nome do jogador com o nome do nó atual
        int comp = stricmp(player.name, (*root)->player.name);
        // Se o nome do jogador for "menor" que o nome do nó atual, chamar a função na subárvore da esquerda
        if (comp < 0)
        {
            tree_insert_player(&(*root)->left, player);
        }
        // Se o nome do jogador for "maior" que o nome do nó atual, chamar a função na subárvore da direita
        else if (comp > 0)
        {
            tree_insert_player(&(*root)->right, player);
        }
        // Se os nomes forem iguais, não inserir
        else
        {
            return false;
        }
    }
}

/**
 * Função de busca de jogadores
 * Chama recursivamente até encontrar o jogador ou chegar a um nó nulo
 */
bool tree_search_player(TreeNode *root, char *name, Player *player)
{
    // Se o nó atual for nulo, o jogador não foi encontrado
    if (root == NULL)
    {
        return false;
    }
    // Se o nó atual não for nulo
    else
    {
        // Comparar o nome do jogador com o nome do nó atual
        int comp = strcmp(name, root->player.name);
        // Se o nome do jogador for "menor" que o nome do nó atual, chamar a função na subárvore da esquerda
        if (comp < 0)
        {
            return tree_search_player(root->left, name, player);
        }
        // Se o nome do jogador for "maior" que o nome do nó atual, chamar a função na subárvore da direita
        else if (comp > 0)
        {
            return tree_search_player(root->right, name, player);
        }
        // Se os nomes forem iguais, o jogador foi encontrado e deve ser retornado
        else
        {
            *player = root->player;
            return true;
        }
    }
}

/**
 * Função de listagem de jogadores
 * Lista em ordem alfabética por meio de uma in-order traversal/travessia em ordem
 */
void tree_print_players(TreeNode *root)
{
    if (root != NULL)
    {
        tree_print_players(root->left);
        player_print(root->player);
        tree_print_players(root->right);
    }
}

/**
 * Função de exclusão de jogadores
 * Chama recursivamente até encontrar o jogador ou chegar a um nó nulo
 *
 * Se o jogador for encontrado, remover o nó
 * Se o jogador não for encontrado, não remover
 *
 * Caso a remoção seja efetuada, reorganizar a árvore
 * (Caso 1: nó folha, caso 2: nó com um filho, caso 3: nó com dois filhos)
 */
bool tree_remove_player(TreeNode **root, char *name)
{
    // Se o nó atual for nulo, o jogador não foi encontrado
    if (*root == NULL)
    {
        return false;
    }
    // Se o nó atual não for nulo
    else
    {
        // Comparar o nome do jogador com o nome do nó atual
        int comp = strcmp(name, (*root)->player.name);
        // Se o nome do jogador for "menor" que o nome do nó atual, chamar a função na subárvore da esquerda
        if (comp < 0)
        {
            tree_remove_player(&(*root)->left, name);
        }
        // Se o nome do jogador for "maior" que o nome do nó atual, chamar a função na subárvore da direita
        else if (comp > 0)
        {
            tree_remove_player(&(*root)->right, name);
        }
        // Se os nomes forem iguais, o jogador foi encontrado e deve ser removido
        else
        {
            // Se o nó atual for um nó folha, remover o nó
            if ((*root)->left == NULL && (*root)->right == NULL)
            {
                free(*root);
                *root = NULL;
            }
            // Se o nó atual tiver um filho, remover o nó e substituí-lo pelo filho
            else if ((*root)->left == NULL || (*root)->right == NULL)
            {
                TreeNode *aux = *root;
                if ((*root)->left != NULL)
                {
                    *root = (*root)->left;
                }
                else
                {
                    *root = (*root)->right;
                }
                free(aux);
            }
            // Se o nó atual tiver dois filhos, remover o nó e substituí-lo pelo menor nó da subárvore da direita
            else
            {
                TreeNode *aux = (*root)->right;
                while (aux->left != NULL)
                {
                    aux = aux->left;
                }
                (*root)->player = aux->player;
                tree_remove_player(&(*root)->right, aux->player.name);
            }
            return true;
        }
    }
}

// Funções auxiliares

void tree_init(TreeNode **root)
{
    *root = NULL;
}

TreeNode *tree_create_node(Player player)
{
    TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
    if (new_node == NULL)
    {
        return NULL;
    }

    new_node->player = player;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// (Liberar a memória alocada com post-order traversal/travessia pós-ordem)
void tree_free(TreeNode *root)
{
    if (root != NULL)
    {
        tree_free(root->left);
        tree_free(root->right);
        free(root);
    }
}
