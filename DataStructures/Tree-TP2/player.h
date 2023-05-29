typedef struct
{
    char name[30];
    char position[20];
    int age;
    int skill;
    int number;
} Player;

Player player_init(char *name, char *position, int age, int skill, int number);

void player_print(Player player);