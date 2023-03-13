//
// Created by Douglas on 3/29/2023.
//

#include <stdbool.h>

#ifndef E_LIST_H
#define E_LIST_H

#define MAX 100

typedef int lst_info;

typedef struct {
    lst_info items[MAX];
    int n;
} List;

void lst_imprimir(List l);

int lst_procurar(List l, lst_info val);

bool lst_ins_ordenado(List * l, lst_info val);

bool lst_concatenar(List lst1, List lst2, List * lst3);

bool lst_inserir_final(List * l, lst_info x);

bool lst_inserir_inicio(List * l, lst_info x);

bool lst_remover_final(List * l, lst_info * x);

bool lst_remover_inicio(List * l, lst_info * x);

bool lst_gerar(List * l, int n, int max);

bool lst_ordenada(List l);

int lst_remover_menores(List * l, lst_info x);

bool lst_inverter(List * l);

bool lst_fatiar(List l, int k, List * lst1, List * lst2);

bool lst_soma(List * l, lst_info x);

#endif //E_LIST_H
