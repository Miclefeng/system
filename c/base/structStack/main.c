#include <stdio.h>


typedef struct _Stack
{
    char mem[1024];
    int top; // top指向栈顶(mem末尾下一个元素)
}Stack;

int isFull(Stack *ps);

int isEmpty(Stack *ps);

void push(Stack *ps, char e);

char pop(Stack *ps);

int main()
{
    Stack s = {{0},0};

    for (char ch='a';ch<='z';ch++) {
        if (!isFull(&s)) {
            push(&s, ch);
        }
    }
    printf("%d\n", s.top);
    printf("%c\n", s.mem[s.top]);
    while (!isEmpty(&s)) {
        putchar(pop(&s));
    }
    puts("");
    return 0;
}

int isFull(Stack *ps)
{
    return ps->top == 1024;
}

int isEmpty(Stack *ps)
{
    return ps->top == 0;
}

void push(Stack *ps, char e)
{
    ps->mem[(ps->top)++] = e;
}

char pop(Stack *ps)
{
//    ps->top--;
//    char e = ps->mem[ps->top];
//    printf("%c\t", e);
//    return e;
    return ps->mem[--(ps->top)];
}
