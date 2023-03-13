//
// Created by Douglas on 3/29/2023.
//

#include "list.h"

#include <stdio.h>
#include <stdlib.h>

void lst_imprimir(List l) {
    for (int i = 0; i < l.n; i++) {
        printf("%d ", l.items[i]);
    }
    printf("\n");
}

int lst_procurar(List l, lst_info val) {
    for (int i = 0; i < l.n; i++) {
        if (l.items[i] == val) {
            return i;
        }
    }
    return -1;
}

bool lst_ins_ordenado(List *l, lst_info val) {
    if (l->n == MAX) {
        return false;
    }

    int i = l->n - 1;
    while (i >= 0 && l->items[i] > val) {
        l->items[i + 1] = l->items[i];
        i--;
    }

    l->items[i + 1] = val;
    l->n++;
    return true;
}

bool lst_concatenar(List lst1, List lst2, List *lst3) {
    if (lst1.n + lst2.n > MAX) {
        return false;
    }

    int i = 0, j = 0, k = 0;

    while (i < lst1.n && j < lst2.n) {
        lst3->items[k++] = (lst1.items[i] < lst2.items[j]) ? lst1.items[i++] : lst2.items[j++];
    }
    while (i < lst1.n) {
        lst3->items[k++] = lst1.items[i++];
    }
    while (j < lst2.n) {
        lst3->items[k++] = lst2.items[j++];
    }

    lst3->n = k;
    return true;
}

bool lst_inserir_final(List *l, lst_info x) {
    if (l->n == MAX) {
        return false;
    }

    l->items[l->n++] = x;
    return true;
}

bool lst_inserir_inicio(List *l, lst_info x) {
    if (l->n == MAX) {
        return false;
    }

    for (int i = l->n; i > 0; i--) {
        l->items[i] = l->items[i - 1];
    }

    l->items[0] = x;
    l->n++;
    return true;
}

bool lst_gerar(List *l, int n, int max) {
    if (n > MAX) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        l->items[i] = rand() % max + 1;
    }

    l->n = n;
    return true;
}

bool lst_ordenada(List l) {
    for (int i = 0; i < l.n - 1; i++) {
        if (l.items[i] > l.items[i + 1]) {
            return false;
        }
    }
    return true;
}

int lst_remover_menores(List *l, lst_info x) {
    int i = 0, j = 0, k = 0;

    while (i < l->n) {
        if (l->items[i++] > x) {
            k++;
        } else {
            l->items[j++] = l->items[i++];
        }
    }

    l->n = j;
    return k;
}

bool lst_inverter(List *l) {
    int i = 0, j = l->n - 1;

    while (i < j) {
        lst_info temp = l->items[i];
        l->items[i++] = l->items[j];
        l->items[j--] = temp;
    }

    return true;
}

bool lst_fatiar(List l, int k, List * lst1, List * lst2) {
    if (k > l.n || k < 0 || l.n == 0) {
        return false;
    }

    for (int i = 0; i < k; i++) {
        lst1->items[i] = l.items[i];
    }
    lst1->n = k;

    for (int i = k; i < l.n; i++) {
        lst2->items[i - k] = l.items[i];
    }
    lst2->n = l.n - k;

    return true;
}

bool lst_soma(List *l, lst_info x) {
    if (l->n == 0) {
        return false;
    }

    for (int i = 0; i < l->n; i++) {
        l->items[i] += x;
    }

    return true;
}

void lst_init(List *l) {
    l->n = 0;
}

void lst_print(List l) {
    for (int i = 0; i < l.n; i++) {
        printf("%d ", l.items[i]);
    }
    printf("\n");
}