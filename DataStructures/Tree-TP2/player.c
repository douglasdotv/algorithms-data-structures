#include "player.h"
#include <stdio.h>
#include <string.h>

Player player_init(char *name, char *position, int age, int skill, int number)
{
    Player player;

    strcpy(player.name, name);
    strcpy(player.position, position);
    player.age = age;
    player.skill = skill;
    player.number = number;

    return player;
}

void player_print(Player player)
{
    printf("Nome: %s\t", player.name);
    printf("Posicao: %s\t", player.position);
    printf("Idade: %d\t", player.age);
    printf("Habilidade: %d\t", player.skill);
    printf("Numero: %d\t", player.number);
    printf("\n");
}
