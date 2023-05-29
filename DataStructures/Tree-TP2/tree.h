#include <stdbool.h>
#include "player.h"

typedef struct TreeNode
{
    Player player;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/**
 * Função de inserção de jogadores
 */
bool tree_insert_player(TreeNode **root, Player player);

/**
 * Função de busca de jogadores
 */
bool tree_search_player(TreeNode *root, char *name, Player *player);

/**
 * Função de listagem de jogadores
 */
void tree_print_players(TreeNode *root);

/**
 * Função de exclusão de jogadores
 */
bool tree_remove_player(TreeNode **root, char *name);

// Funções auxiliares

void tree_init(TreeNode **root);

TreeNode *tree_create_node(Player player);

void tree_free(TreeNode *root);