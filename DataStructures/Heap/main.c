//
// Created by Douglas on 4/2/2023.
//

#include <stdio.h>
#include "heap.h"

// 1, 2
void build_min_heap_and_max_heap(void);

// 3
void remove_insert_insert_remove_min_heap(void);

// 4, 5
void check_if_min_heap_or_max_heap(void);

// 6
void perform_heapsort(void);

// 7
void get_k_largest_elements(void);

int main(void) {
    // build_min_heap_and_max_heap();
    // remove_insert_insert_remove_min_heap();
    check_if_min_heap_or_max_heap();
    // perform_heapsort();
    return 0;
}

void build_min_heap_and_max_heap(void) {
    int a[7] = {10, 4, 6, 1, 5, 8, 3};
    int b[9] = {6, 2, 7, 9, 1, 8, 10, 4, 11};

    // min
    build_min_heap(a, 7);
    build_min_heap(b, 9);
    printf("min heap a: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("min heap b: ");
    for (int i = 0; i < 9; i++) {
        printf("%d ", b[i]);
    }

    // max
    build_max_heap(a, 7);
    build_max_heap(b, 9);
    printf("\n");
    printf("max heap a: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("max heap b: ");
    for (int i = 0; i < 9; i++) {
        printf("%d ", b[i]);
    }
}

void remove_insert_insert_remove_min_heap(void) {
    Heap heap;
    int v[8] = {1, 6, 3, 10, 15, 8, 4, 12};
    create_heap_from_given_array(&heap, v, 8);
    int *value = malloc(sizeof(int));

    printf("heap before removing: ");
    print_heap(&heap);
    printf("\n");

    remove_min_heap(&heap, value);
    printf("heap after removing: ");
    print_heap(&heap);
    printf("\n");

    insert_min_heap(&heap, 2);
    printf("heap after inserting 2: ");
    print_heap(&heap);
    printf("\n");

    insert_min_heap(&heap, 5);
    printf("heap after inserting 5: ");
    print_heap(&heap);
    printf("\n");

    remove_min_heap(&heap, value);
    printf("heap after removing: ");
    print_heap(&heap);
    printf("\n");
}

void check_if_min_heap_or_max_heap(void) {
    int v[8] = {1, 6, 3, 10, 15, 8, 4, 12};
    printf("is heap min: %s\n", is_heap_min_recursive(v, 0, 8) ? "yes" : "no");
    printf("is heap max: %s\n", is_heap_max_recursive(v, 0, 8) ? "yes" : "no");
}

void perform_heapsort(void) {
    int v[8] = {1, 6, 3, 10, 15, 8, 4, 12};
    printf("before heapsort: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    heapsort(v, 8);

    printf("after heapsort: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", v[i]);
    }
}

void get_k_largest_elements(void) {
    int arr[8] = {1, 6, 3, 10, 15, 8, 4, 12};
    int k = 3, n = sizeof(arr) / sizeof(arr[0]);

    build_max_heap(arr, n);

    for (int i = n - 1; i >= n - k; i--) {
        printf("%d ", arr[0]);
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i);
    }
    printf("\n");
}