//八皇后问题用递归实现
#include<stdio.h>
int count=0;
int notDanger(int row ,int j,int (*chess)[8])
{
    int i,k,flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
    //判断列方向
    for(i=0;i<8;i++)
    {
        if(*(*(chess+i)+j)!=0)
        {
            flag1=1;
            break;
        }
    }
    //判断左上方
    for(i=row,k=j;i>=0&&k>=0;i--,k--)
    {
        if(*(*(chess+i)+k)!=0)
        {
            flag2=1;
            break;
        }
    }
        //判断右下方
    for(i=row,k=j;i<8&&k<8;i++,k++)
    {
        if(*(*(chess+i)+k)!=0)
        {
            flag3=1;
            break;
        }
    }
        //判断右上方
    for(i=row,k=j;i>=0&&k<8;i--,k++)
    {
        if(*(*(chess+i)+k)!=0)
        {
            flag4=1;
            break;
        }
    }
        //判断左下方
    for(i=row,k=j;i<8&&k>=0;i++,k--)
    {
        if(*(*(chess+i)+k)!=0)
        {
            flag5=1;
            break;
        }
    }
    if(flag1||flag2||flag3||flag4||flag5)
    return 0;
    else 
    return 1;
}
//参数(*chess)[8]:表示指向棋盘每一行的指针
void EightQueeen(int row,int col,int (*chess)[8])
{
    int chess2[8][8],i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            chess2[i][j]=chess[i][j];
        }
    }
    if(8==row)
    {
        printf("第%d 种\n",count+1);
        for(i=0;i<8;i++)
        { 
            for(j=0;j<8;j++)
            {
                printf("%d ",*(*(chess2+i)+j));
            }
            printf("\n");
        }
        printf("\n");
        count++;
    }
    else
    {
        for(j=0;j<col;j++)
         {
            if(notDanger(row,j,chess))
            {
                for(i=0;i<8;i++)
                {
                    *(*(chess2+row)+i)=0;//把第row行赋值为零
                }
            *(*(chess2+row)+j)=1;//第row行col列不危险就赋值为1
            EightQueeen(row+1,col,chess2);//用递归对每一行进行判断
            }
        }
    }
}
int main()
{
    int chess[8][8],i,j;
    for(i=0;i<8;i++)
     { 
        for(j=0;j<8;j++)
        chess[i][j]=0;
     }
    EightQueeen(0,8,chess);
    printf("共有%d种解决方法\n\n",count);
    return 0;
}