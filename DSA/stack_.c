#include <stdio.h>

typedef struct stack_
{
    int index;
    char arr[50];
} stack;

stack s;
// s.index = -1;
// arr start with 0 when push operation applied

void push(stack *, char);
char pop(stack *);
void printStack(stack *); // optional
char top(stack *);

int main()
{
    int option = 90; // random
    char ch;
    s.index = -1;

    while (option != 5)
    {
        printf("\n1 : Push.\n2 : Pop.\n3 : Print the Stack.\n4 : Top most element.\n5 : Exit.\n");
        printf("Select Option : ");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
            printf("\nEnter Character to Push: \n");
            scanf("%c", &ch);
            getchar();
            push(&s, ch);
            break;
        case 2:
            ch = pop(&s);
            printf("\nPoped Element is : %c .\n", ch);
            break;
        case 3:
            printStack(&s);
            break;
        case 4:
            ch = top(&s);
            printf("\nTop Most Element is : %c .\n", ch);
            break;
        default:
            printf("\nSelected Wrong Option ,%d \n", option);
            break;
        }
    }
    printf("\nStack Over!\n");
    return 0;
}

void push(stack *p, char ch)
{
    p->index += 1;
    p->arr[(p->index)] = ch;
    // printf("%c",p->arr[p->index]);
}

char pop(stack *p)
{
    char temp = p->arr[p->index];
    p->arr[p->index] = '\0';
    p->index -= 1;
    return temp;
}

void printStack(stack *p)
{
    printf("\nElements are :\n{ ");
    for (int i = 0; i <= p->index; ++i)
    {
        printf(" %c ,", p->arr[i]);
    }
    printf(" }\nPrinted All!\n");
}

char top(stack *p)
{
    return (p->arr[p->index]);
}
int isEmpty(stack *p)
{
    return (p->index == -1);
}
