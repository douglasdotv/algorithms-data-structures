/*
Initializing an array with 'n' elements 'val'.
*/

void init_vetor(int, int[], int);
void print_array(int[], int n);

int main()
{
    int n, value;
    printf("Enter array length and a default value for each element: ");
    scanf("%d %d", &n, &value);

    printf("Initializing array...\n");
    int array[n];
    init_vetor(n, array, value);
    printf("Array initialized!\n");

    printf("Printing our array: \n");
    print_array(array, n);
    return 0;
}

void init_vetor(int n, int a[], int val)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = val;
    }
}

void print_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", array[i], (i < n - 1) ? ' ' : '\n');
    }
}