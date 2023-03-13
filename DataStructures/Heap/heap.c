//
// Created by Douglas on 4/2/2023.
//

#include "heap.h"

void heapify_min(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify_min(arr, n, smallest);
    }
}

void build_min_heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_min(arr, n, i);
    }
}

void heapify_max(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify_max(arr, n, largest);
    }
}

void build_max_heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_max(arr, n, i);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void create_heap(Heap *heap, int size) {
    heap->arr = (int *) malloc(sizeof(int) * size);
    heap->size = size;
    heap->count = 0;
}

void create_heap_from_given_array(Heap *heap, const int arr[], int size) {
    heap->arr = (int *) malloc(sizeof(int) * size);
    heap->size = heap->count = size;
    for (int i = 0; i < size; i++) {
        heap->arr[i] = arr[i];
    }
}

bool insert_min_heap(Heap *heap, int value) {
    /*
    if (heap->count == heap->size) {
        printf("Heap is full. Could not insert %d \n", value);
        return false;
    }
     */

    heap->arr[heap->count] = value;
    heap->count++;

    int i = heap->count - 1;
    while (i != 0 && heap->arr[i] < heap->arr[(i - 1) / 2]) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    return true;
}

bool remove_min_heap(Heap *heap, int *value) {
    if (heap->count == 0) {
        printf("Heap is empty.\n");
        return false;
    }

    *value = heap->arr[0];
    heap->arr[0] = heap->arr[heap->count - 1];
    heap->count--;

    heapify_min(heap->arr, heap->count, 0);

    return true;
}

int get_heap_size(Heap *heap) {
    return heap->count;
}

bool is_heap_max_h(Heap *heap) {
    for (int i = 0; i < heap->count / 2; i++) {
        if ((2 * i + 1 < heap->count && heap->arr[i] < heap->arr[2 * i + 1]) ||
            (2 * i + 2 < heap->count && heap->arr[i] < heap->arr[2 * i + 2])) {
            return false;
        }
    }
    return true;
}

bool is_heap_min_h(Heap *heap) {
    for (int i = 0; i < heap->count / 2; i++) {
        if ((2 * i + 1 < heap->count && heap->arr[i] > heap->arr[2 * i + 1]) ||
            (2 * i + 2 < heap->count && heap->arr[i] > heap->arr[2 * i + 2])) {
            return false;
        }
    }
    return true;
}

bool is_heap_max(int v[], int n) {
    for (int i = 0; i < (n / 2); i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if ((left < n && v[left] > v[i]) || (right < n && v[right] > v[i])) {
            return false;
        }
    }
    return true;
}

bool is_heap_min(int v[], int n) {
    for (int i = 0; i < (n / 2); i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if ((left < n && v[left] < v[i]) || (right < n && v[right] < v[i])) {
            return false;
        }
    }
    return true;
}

bool is_heap_max_recursive(int arr[], int i, int n) {
    if (i >= n) {
        return true;
    }

    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < n && arr[i] < arr[left_child]) {
        return false;
    }

    if (right_child < n && arr[i] < arr[right_child]) {
        return false;
    }

    return is_heap_max_recursive(arr, left_child, n) && is_heap_max_recursive(arr, right_child, n);
}

bool is_heap_min_recursive(int arr[], int i, int n) {
    if (i >= n) {
        return true;
    }

    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < n && arr[i] > arr[left_child]) {
        return false;
    }

    if (right_child < n && arr[i] > arr[right_child]) {
        return false;
    }

    return is_heap_min_recursive(arr, left_child, n) && is_heap_min_recursive(arr, right_child, n);
}

void heapsort(int *arr, int n) {
    // (ascending order)
    build_max_heap(arr, n);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify_max(arr, i, 0);
    }
}

void print_heap(Heap *heap) {
    for (int i = 0; i < heap->count; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}
