/*#include<stdio.h>
#include<stdlib.h>

typedef struct StackNode{
	int data;
	struct StackNode* next;
}LinkStack;

void Push(LinkStack** lin)// Use second rand pointer to change the stack-top's position.
{
	int e = 0;
	LinkStack* p = (LinkStack*)malloc(sizeof(LinkStack));
	printf("Input the number you want to insert:\n");
	scanf("%d", &e);
	if ((*lin)->next != NULL) {
		if (p) {
			p->data = e;
			p->next = (*lin);
			(*lin) = p;
		}
	}
	else
	{
		(*lin)->data = e;
	}
}


void Pop(LinkStack** lin)  // Use second rand pointer to change the stack-top's position.
{
	int en;
	LinkStack* pn = (LinkStack*)malloc(sizeof(LinkStack));
	if ((*lin) == NULL) { printf("ERROR.\n"); }
	else {
		if (pn) {
			en = (*lin)->data;
			pn = (*lin);
			(*lin) = (*lin)->next;
			free(pn);
			printf("Element %d is poped out.\n", en);
		}
	}
	
}


void StackEmpty(LinkStack* lin) 
{ if (lin == NULL) 
	{ 
	printf("Empty.\n"); 
	} else { 
	printf("Not empty.\n"); 
	} 
}

void GetTop(LinkStack* lin)
{
	if (lin != NULL) {
		printf("The top element is: %d\n", lin->data);
	}
}

int main()
{
	LinkStack *Lst = (LinkStack*)malloc(sizeof(LinkStack));
	LinkStack** Lst1 = &Lst;
	Push(Lst1);// Input:1
	Push(Lst1);// Input:2
	GetTop(Lst);// Output:2
	Pop(Lst1);// Output:2
	Push(Lst1);// Input:3
	Push(Lst1);// Input:4
	GetTop(Lst);// Output:4
	Pop(Lst1);// Output:4
	GetTop(Lst);// Output:3
	Pop(Lst1);// Output:3
	Push(Lst1);// Input:5
	Pop(Lst1);// Output:5
	Pop(Lst1);// Output:1
	return 0;
}

/*typedef struct StackNode{
	int data;
	struct StackNode* next;
}LinkStack;
int main()
{
    LinkStack*p=(LinkStack*)malloc(sizeof(LinkStack));
    printf("%d\n",*p);
    printf("%d\n",&p);
    printf("%d\n",p);
    LinkStack**q=&p;
    printf("%d\n",*q);
    printf("%d\n",**q);
    printf("%d\n",q);
}*/



#include "stdio.h"
#include <malloc.h>
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
//#define MAXSIZE 20 /* 存储空间初始分配量 */
 
typedef int Status; 
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */
 
/* 链栈结构 */
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;
 
typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;
 
Status visit(SElemType c)
{
    printf("%d ",c);
    return OK;
}
 
/*  构造一个空栈S */
Status InitStack(LinkStack *S)
{ 
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if(!S->top)
    {
        return ERROR;
    }
 
    S->top = NULL;
    S->count = 0;
    return OK;
}
 
/* 把S置为空栈 */
Status ClearStack(LinkStack *S)
{ 
    LinkStackPtr p,q;
    p = S->top;
    while(p)
    {  
        q = p; /* "q" is the prev node of node "p"*/
        p = p->next;
        free(q);
    } 
    S->count=0;
 
    return OK;
}
 
/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status IsEmptyStack(LinkStack S)
{ 
    if (S.count == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
 
/* 返回S的元素个数，即栈的长度 */
int GetStackLength(LinkStack S)
{ 
    return S.count;
}
 
/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
Status GetTopElem(LinkStack S,SElemType *e)
{
    if (S.top == NULL)
    {
        return ERROR;
    }
    else
    {
        *e = S.top->data;
    }
    return *e;
}
 
/* 插入元素e为新的栈顶元素 */
Status Push(LinkStack *S,SElemType e)
{
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));
    if (!s)
    {
        return ERROR;
    }
    s->data = e;
    s->next = S->top;/* 把当前的栈顶元素赋值给新结点的直接后继 */
    S->top = s;      /* 将新的结点s赋值给栈顶指针*/
    S->count++;
 
    return OK;
}
 
/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(LinkStack *S,SElemType *e)
{ 
    LinkStackPtr p;
    if(IsEmptyStack(*S))
    {
        return ERROR;
    }
 
    *e = S->top->data;
    p = S->top; /* 将栈顶结点赋值给p */
    S->top = S->top->next;/* 使得栈顶指针下移一位，指向后一结点 */
    free(p);              /* 释放结点p */        
    S->count--;
 
    return OK;
}
 
Status StackTraverse(LinkStack S)
{
    LinkStackPtr p;
    p=S.top;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}
 
int main()
{
    int j;
    LinkStack s;
    int e,n,i;
    if(InitStack(&s)==OK)
    printf("分配成功\n");
    printf("入栈元素个数\n");
    scanf("%d",&n);
        for(j=1;j<=n;j++)
            {
                scanf("%d",&i);
                Push(&s,i);
            }
    printf("栈中元素依次为：");
    StackTraverse(s);
    printf("出栈元素个数\n");
    scanf("%d",&n);
    for(j=1;j<=n;j++)
    {
        Pop(&s,&e);
        printf("弹出的栈顶元素 e=%d\n",e);
    }
    printf("栈空否：%d(1:空 0:否)\n",IsEmptyStack(s));
    GetTopElem(s,&e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,GetStackLength(s));
    ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",IsEmptyStack(s));
 
    return 0;
}
