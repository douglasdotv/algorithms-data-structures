//
// Created by Douglas on 4/2/2023.
//

#ifndef E_HEAP_H
#define E_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int size;
    int count;
} Heap;

void heapify_min(int arr[], int n, int i);

void build_min_heap(int arr[], int n);

void heapify_max(int arr[], int n, int i);

void build_max_heap(int arr[], int n);

void swap(int *a, int *b);

void create_heap(Heap *heap, int size);

void create_heap_from_given_array(Heap *heap, const int arr[], int size);

bool insert_min_heap(Heap *heap, int value);

bool remove_min_heap(Heap *heap, int *value);

int get_heap_size(Heap *heap);

bool is_heap_max_h(Heap *heap);

bool is_heap_min_h(Heap *heap);

bool is_heap_max(int v[], int n);

bool is_heap_min(int v[], int n);

bool is_heap_max_recursive(int arr[], int i, int n);

bool is_heap_min_recursive(int arr[], int i, int n);

void heapsort(int *arr, int n);

void print_heap(Heap *heap);

#endif //E_HEAP_H
