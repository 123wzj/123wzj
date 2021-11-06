//链表的插入和删除

/*
printf("line:%d",__LINK__);                当前行数
printf("filename:%s",__FILE__);            当前文件名
printf("founction:%s",__FUNCTION__);       当前函数
printf("time:%s",__TIME__);                 当前时间
printf("data:%s",__DATE__);                 当前日期
*/

#include<stdio.h>
#include<stdlib.h>
#define uint unsigned int//无符号常数

typedef struct Listlink
{
    int data;//数据域
    struct Listlink  *next;//指针域
}listlink;

listlink*head=NULL;//头指针
listlink*end=NULL;//尾指针
void Addnode(int data);//增加节点
uint GetlistSize(void);//获取大小
listlink*Findnode(uint index);//查找节点
void Readnode(uint index);//读取节点
void Readlist(void);//读取链表
void Setnode(uint idex, int data);//设置节点
void Deletelist(void);//删除链表
void Deletenodez(uint index);//删除节点
void Insertnode(uint idex, int data);//插入节点

listlink *Creatnode(int data)//创建节点
{
    listlink* node=(listlink*)malloc(sizeof(listlink));
    if(node==NULL)
    printf("内存获取失败！");
    node->data=data;
    node->next=NULL;
    return node;
}

void Addnode(int data)
{
    listlink*node=Creatnode(data);
    if(head==NULL)
    head=node;
    else//链表已存在
    end->next=node;
    end=node;
}

uint GetlistSize(void)
{
    listlink *node=head;
    uint size=0;
    while(node!=NULL)
    {
        node=node->next;
        size++;
    }
    return size;
}

listlink*Findnode(uint index)//定位结点
{
    listlink*node=head;
    uint currentIndex=0;
    if(node==NULL)
    {
        printf("链表为空\n");
        return NULL;
    }
    while(node!=NULL)
    {
        if(index==currentIndex)
        {return node;}
        node=node->next;
        currentIndex++;
    }
    return NULL;
}

void Readnode(uint index)
{
    listlink*node=Findnode(index);//查找此节点
    if(node==NULL)
    {printf("无此节点\n");}
    printf("%s :listlink%d's data=%d\n",__FUNCTION__,index,node->data);
}

void Readlist(void)
{
    listlink*node=head;
    if(node==NULL)
    {printf("链表为空\n");}
    for(int index=0;index<GetlistSize();index++)
    {
        printf("%s:listlink%d' data=%d\n",__FUNCTION__,index,node->data);
        node=node->next;
    }
    printf("\n");
}

void Setnode(uint index,int data)
{
    listlink*node=Findnode(index);
    if(node==NULL)
    {
        printf("无此节点\n");
        return ;
    }
    node->data=data;
}

void Deletenode(uint index)
{
    listlink*foundnode=Findnode(index);//查找此节点
    if(foundnode==NULL)//无此节点
    {
        printf("无此节点\n");
        return ;
    }
    else
    {
        listlink*node=head;
        if(head==end)//只有一个节点
        {
            free(head);
            head=NULL;
            end=NULL;
        }
        else//节点大于一
        {
            if(foundnode==head)//删除头结点
            {
                listlink*oldhead=head;//暂存旧节点
                head=head->next;//将第二个节点设置为头结点
                free(oldhead);//释放久头结点
            }
            else if(foundnode==end)//删除尾节点
            {
                while(node->next!=foundnode)
                {node=node->next;}
                node->next=NULL;//将倒数第二个节点设置为NULL后相当于变成尾节点
                free(foundnode);
            }
            else//删除中间某个节点
            {
                while(node->next!=foundnode)
                {node=node->next;}
            node->next=foundnode->next;//将 被删除节点 的 上一个节点的next设置为被删除的下一个节点
            free(foundnode);
            }
        }
    }
    printf("listlink%d has delete\n",index);
}

void Insertnode(uint index ,int data)
{
    listlink*newnode=Creatnode(data);
    listlink*insertnode=Findnode(index);
    if(head==NULL)
    {
        printf("此链表为空\n");
        return ;
    }
    else if(insertnode==NULL)
    {
        printf("插入失败\n");
        return ;
    }
    else
    {
        newnode->next=insertnode->next;//将 新节点的next设置为当前被插入位置节点的下一个节点
        insertnode->next=newnode;//将新插入位置节点的next设置为新节点
    }
}

void Deletelist(void)
{
    listlink*node=head;
    if(node==NULL)
    {
        printf("此节点不存在\n");
        return ;
    }
    while(node!=NULL)
    {
        listlink*temp=node;
        node=node->next;
        free(temp);
    }
    head=NULL;
    end=NULL;
    printf("%s:链表已被清空\n",__FUNCTION__);
}

int main()
{
    //增加节点
    Addnode(11);
    Addnode(22);
    Addnode(33);
    Addnode(44);
    Addnode(55);
    Addnode(66);
    //设置节点
    Setnode(3,99);
    //获取大小
    printf("linked list size:%d\n",GetlistSize());
    //读取链表
    Readlist();
    //读取节点
    Readnode(2);
    //删除节点
    Deletenode(0);
    Deletenode(2);
    Deletenode(GetlistSize()-3);
    //获取大小
    printf("linked list size:%d\n",GetlistSize());
    //增加节点
    Insertnode(0,77);
    Insertnode(2,88);
    Insertnode(GetlistSize()-1,90);
    //读取链表
    Readlist();
    //情况链表
    Deletelist();
    return 0;
}
