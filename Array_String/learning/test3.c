#include <stdio.h>

/* void size(int arr[])
{
    int s = sizeof(arr);
    printf("\ninside function : %d", s);
} */

int incr(int i)
{
    static int count = 0;
    count = count + i;
    return count;
}
int main(int argc, char const *argv[])
{
    int i, j;
    for (int i = 0; i <= 4; i++)
    {
        j = incr(i);
    }
    printf("%d", j);

    /*
    int ar[5];
    size(ar);
    int s = sizeof(ar);
    printf("\nint main :%d", s);

    return 0; */
}
