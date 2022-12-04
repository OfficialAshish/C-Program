#include <stdio.h>

void print(int ar[], int l)
{
    printf("{");
    for (int i = 0; i < l; i++)
    {
        printf("%d , ", ar[i]);
    }
    printf("}\n");
}

void insert(int ar[], int size, int elem, int index)
{
    if (index > size - 1)
    {
        printf("index is not of arr size");
        return;
    }

    for (int i = size - 1; i >= index; i--)
    {
        ar[i + 1] = ar[i];
    }

    /* int temp_i = size - 1;
    while (index < temp_i)
    {
        ar[temp_i] = ar[temp_i - 1];
        temp_i = temp_i - 1;
    }
    */

    ar[index] = elem;
}

int main(int argc, char const *argv[])
{
    int arr[6] = {0};

    print(arr, 6);

    insert(arr, 6, 10, 0);
    print(arr, 6);

    insert(arr, 6, 20, 1);
    print(arr, 6);

    insert(arr, 6, 30, 2);
    print(arr, 6);

    insert(arr, 6, 40, 3);
    print(arr, 6);

    insert(arr, 6, 50, 4);
    print(arr, 6);

    insert(arr, 6, 60, 5);

    print(arr, 6);

    insert(arr, 6, 555, 3);
    print(arr, 6);

    insert(arr, 6, 3453, 7);

    return 0;
}
