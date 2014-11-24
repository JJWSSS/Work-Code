#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a=1;
struct Snack   //ջ
{
    struct node *data[100];
    int top;
};
struct Queue  //����
{
    struct node *data[100];
    int bottom;
    int top;
};
struct node   //�ڵ�
{
    char data;
    int number;
    struct node *lchild;
    struct node *rchild;
};
void Emptyq(struct Queue q);   //�ж϶����Ƿ�Ϊ��
struct node *Insert(struct node *head,char data1,int number1,char choice);  //������
void PreOrder(struct node *head);   //�������
void InOrder(struct node *head);     //�������
void SeqOrder(struct node *head);   //�������
void PostOrder(struct node *head);   //�������
void PostOrder(struct node *head)
{
    struct node *pr;
    pr=head;
    if (pr!=NULL)
    {
        PostOrder(pr->lchild);
        PostOrder(pr->rchild);
        printf("%c",pr->data);
    }
}
void SeqOrder(struct node *head)
{
    struct Queue q;
    struct node *pr;
    int i,bottom1,top1;
    Emptyq(q);
    q.bottom=0;
    q.top=0;
    pr=head;
    q.data[0]=pr;
    for (;;)
    {
        bottom1=q.bottom;
        top1=q.top;
        for (i=bottom1;i<=top1;i++)
        {
            pr=q.data[i];
            printf("%c",pr->data);
            if(pr->lchild!=NULL)
            {
                q.top++;
                q.data[q.top]=pr->lchild;
            }
            if(pr->rchild!=NULL)
            {
                q.top++;
                q.data[q.top]=pr->rchild;
            }
            q.bottom++;
        }
        if (q.bottom>q.top)
        {
            break;
        }
    }
    printf("\n");
}
void InOrder(struct node *head)
{
    struct Snack s;
    struct node *pr;
    int i;
    pr=head;
    s.top=0;
    for (i=0;i<100;i++)
    {
        s.data[i]=NULL;
    }
    while(pr!=NULL || s.top!=0)
    {
        if (pr!=NULL)
        {
            s.top++;
            s.data[s.top]=pr;
            pr=pr->lchild;
        }
        else
        {
            pr=s.data[s.top];
            s.top--;
            printf("%c",pr->data);
            pr=pr->rchild;
        }
    }
    printf("\n");
}
void PreOrder(struct node *head)
{
    struct node *pr;
    pr=head;
    if (head!=NULL)
    {
        printf("%c",pr->data);
        PreOrder(pr->lchild);
        PreOrder(pr->rchild);
    }
}
void Emptyq(struct Queue q)
{
    int i;
    for (i=0;i<100;i++)
    {
        q.data[i]=NULL;
    }
}
struct node *Insert(struct node *head,char data1,int number1,char choice)
{
    struct Queue q;
    struct node *p,*pr;
    int i,bottom1,top1;
    Emptyq(q);
    a++;
    q.bottom=0;
    q.top=0;
    p = (struct node *)malloc(sizeof(struct node));
    pr=head;
    q.data[0]=pr;
    for (;;)
    {
        bottom1=q.bottom;
        top1=q.top;
        for (i=bottom1;i<=top1;i++)
        {
            pr=q.data[i];
            if (pr->number==number1)
            {
                if (choice=='l' || choice=='L')
                {
                    pr->lchild=p;
                    goto END;
                    p->number=a;
                    p->data=data1;
                }
                if (choice=='r' || choice=='R')
                {
                    pr->rchild=p;
                    goto END;
                }
            }
            else
            {
                if(pr->lchild!=NULL)
                {
                    q.top++;
                    q.data[q.top]=pr->lchild;
                }
                if(pr->rchild!=NULL)
                {
                    q.top++;
                    q.data[q.top]=pr->rchild;
                }
                q.bottom++;
            }
        }
        if (q.bottom>q.top)
        {
            break;
        }
    }
    END:p->data=data1;
    p->number=a;
    p->lchild=NULL;
    p->rchild=NULL;
    if (q.bottom>q.top)
    {
        printf("Number is wrong!");
        free(p);
    }
    return head;
}
int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->data='A';
    head->number=1;
    head->lchild=NULL;
    head->rchild=NULL;
    int number;
    char order[15],data,choice;
    for (;;)
    {
        printf("������ָ��:");
        scanf("%s",&order);
        if (strcmp(order,"Insert")==0)
        {
            printf("������ýڵ�����:");
            scanf(" %c",&data);
            printf("�����븸�ڵ����:");
            scanf("%d",&number);
            printf("������Ϊ���ӻ��Һ���:");
            scanf(" %c",&choice);
            printf("%c %d %c\n",data,number,choice);
            head=Insert(head,data,number,choice);
        }
        else if(strcmp(order,"PreOrder")==0)
        {
            PreOrder(head);
            printf("\n");
        }
        else if(strcmp(order,"InOrder")==0)
        {
            InOrder(head);
        }
        else if(strcmp(order,"PostOrder")==0)
        {
            PostOrder(head);
            printf("\n");
        }
        else if(strcmp(order,"SeqOrder")==0)
        {
            SeqOrder(head);
        }
        else if(strcmp(order,"Exit")==0)
        {
            break;
        }
        else{printf("Wrong order!\n");}
    }
    return 0;
}
