#include <stdio.h>
#include <stdlib.h>

#define Stack_Init_Size 10 // 初始化栈的最大长度
#define StackIncrement 10 // 若栈最大空间不够时，需要增加的长度
typedef int ElemType;
typedef int Status;

typedef struct {
    ElemType *base; // 栈底指针
    ElemType *top; // 栈顶指针
    int stack_size; // 栈的最大长度
} SqStack;

// 初始化栈
Status InitStack(SqStack *S) {
    // 分配初始空间
    S->base = (ElemType *) malloc(Stack_Init_Size * sizeof(ElemType));
    if (!S->base) {
        exit(0);
    }
    S->top = S->base; /// 栈顶与栈底相同
    S->stack_size = Stack_Init_Size; // 栈的最大长度等于初始长度
    return 1;
}

// 判断栈是否为空，只需要判断栈顶指针与栈底指针是否相同即可
Status EmptyStack(SqStack *S) {
    return S->base == S->top;
}

// 获取栈的实际长度，栈顶减去栈底指针即为栈的长度
Status LengthStack(SqStack *S) {
    if (S->top == S->base) {
        return 0;
    }
    return (Status) (S->top - S->base);
}

// 获取栈顶的元素，参数e用来存放栈顶的元素
Status GetTopStack(SqStack *S, ElemType *e) {
    if (S->top == S->base) {
        return 0;
    } 
    *e = *(S->top - 1);
    return *e;
}

// 进栈，参数e是要进栈的元素
Status PushStack(SqStack *S, ElemType e) {
    // 若栈的最大长度不会够用时，重新开辟，增大长度
    if (S->top - S->base >= S->stack_size) {
        S->base = (ElemType *)realloc(S->base, (S->stack_size + StackIncrement) * sizeof(ElemType));
        if (!S->base) {
            return 0;
        }
        // 栈顶指针为栈底指针加上栈之前的最大长度
        S->top = S->base + S->stack_size;
        // 栈当前的最大长度等于栈之前的最大长度与增加的长度之和
        S->stack_size += StackIncrement;
    }
    *S->top++ = e; // 先赋值，后栈顶指针上移
    return 1;
}

// 出栈，参数e用来存放出栈的元素
Status PopStack(SqStack *S, ElemType *e) {
    if (S->base == S->top) {
        return 0;
    }
    *e = *--S->top; // 栈顶指针先下移，后赋值
    return *e;
}

// 销毁栈，释放栈空间，栈顶栈底指针置为NULL，长度置为0
Status DestroyStack(SqStack *S) {
    free(S->base);
    S->base = S->top = NULL;
    S->stack_size = 0;
    return 1;
}

// 遍历栈，依次打印每个元素
Status StackTraverse(SqStack *S) {
    ElemType *p;

    if (S->top == S->base) {
        printf("Stack is NULL.\n");
        return 0;
    }
    p = S->top;
    // 由栈顶依次向下遍历
    while (p > S->base) {
        p--;
        printf("%d ", *p);
    }
    printf("\n");
    return 1;
}

int main() {
    SqStack q, *S;
    S = &q;

    int i, n, e,j;

    printf("Creat a NULL Stack :\n");
    InitStack(S);

    printf("input the length of the Stack :\n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &e);
        PushStack(S, e);
    }
    printf("Is the stack NULL?\n");

    if (EmptyStack(S)) {
        printf("Yes!\n");
    } else {
        printf("No!\n");
    }
    printf("The length of stack is %d.\n", LengthStack(S));

    printf("The stack is :\n");
    StackTraverse(S);

    e = GetTopStack(S, &e);
    printf("The top data is %d\n", e);

    printf("input the data to the stack :\n");
    scanf("%d", &e);
    PushStack(S, e);
    printf("The new stack is :\n");
    StackTraverse(S);

    printf("Delete the top data ,出栈元素个数: ");
	scanf("%d",&j);
	for(i=0;i<j;i++)
	{
		e = PopStack(S, &e);
		printf("%d\n", e);
	}

    printf("The new stack is :\n");
    StackTraverse(S);

    printf("Destroy the stack :\n");
    DestroyStack(S);
    StackTraverse(S);

    return 0;
}
