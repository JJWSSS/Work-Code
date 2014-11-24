#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct link
{
    int data;
    struct link *next;
};
struct link * Create(struct link *head,int i);
struct link * Delete(struct link *head,int x);
struct link * Insert(struct link *head,int x);
void Search(struct link *head,int x);
void Display(struct link *head);
int Count(struct link *head);
struct link * Rever(struct link *head);
struct link * Rever(struct link *head)
{
    int t,m,i,x,num[1000];
    struct link *p=head,*pr=head,*q=NULL;
    i=0;
    while(p->next!=NULL)
    {
        num[i]=p->data;
        p=p->next;
        i++;
    }
    num[i]=p->data;
    i++;
    pr=pr->next;
    while(pr!=NULL)
    {
        q=pr;
        pr=pr->next;
        free(q);
    }
    head=NULL;
    for (m=i-1;m>=0;m--)
    {
       head=Create(head,num[m]);
    }
    return head;
}
int Count(struct link *head)
{
    int i=0;
    struct link *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
        i++;
    }
    return i+1;
}
struct link * Create(struct link *head,int i)
{
    struct link *p=NULL,*pr=head;
    p = (struct link *)malloc(sizeof(struct link));
    if (p==NULL)
    {
        printf("No enough memory to allocate!\n");
        exit(0);
    }
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        while(pr->next!=NULL)
        {
            pr = pr->next;
        }
        pr->next=p;
    }
    p->data=i;
    p->next=NULL;
    return head;
}
struct link * Delete(struct link *head,int x)
{
    struct link *p =head,*pr=head;
    while (p->data!=x && p->next!=NULL)
    {
        pr=p;
        p=p->next;
    }
    if (x==p->data)
    {
        if (p==head)
        {
            head = p->next;
        }
        else
        {
            pr->next=p->next;
        }
        free(p);
    }
    else
    {
        printf("This Node has not been found!\n");
    }
    return head;
}
struct link * Insert(struct link *head,int x)
{
    struct link *pr=head,*p=NULL,*temp=NULL;
    p= (struct link *)malloc(sizeof(struct link));
    if (p==NULL)
    {
        printf("No enough memory!\n");
        exit(0);
    }
    p->data=x;
    p->next=NULL;
    while (pr->data<x && pr->next!=NULL)
    {
        temp=pr;
        pr=pr->next;
    }
    if (pr->data>=x)
    {
        if (pr==head)
        {
            p->next=head;
            head=p;
        }
        else
        {
            p->next=pr;
            temp->next=p;
        }
    }
    else
    {
        pr->next=p;
    }
    return head;
}
void Search(struct link *head,int x)
{
    struct link *p=head;
    int i=1;
    while(p->next!=NULL && i<x)
    {
        p=p->next;
        i++;
    }
    if (i==x){printf("number is %d\n",p->data);}
    else
    {
        printf("Not found!\n");
    }
}
void Display(struct link *head)
{
    struct link *p=head;
    while(p->next!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
}
int main()
{
    char mingling[10];
    struct link *head=NULL;
    for (;;)
    {
        printf("please input your order:");
        scanf("%s",&mingling);
        if (strcmp(mingling,"Exit")==0)
        {
            break;
        }
        else if (strcmp(mingling,"Create")==0)
        {
            FILE *fp;
            char filename[10];
            int  f,t,k,num,m,i,number[100];
            printf("please input filename:");
            scanf("%s",&filename);
            if ((fp=fopen(filename,"r"))==NULL)
            {
                printf("failture to open %s\n",filename);
                exit(0);
            }
            i=0;
            while(!feof(fp))
            {
                fscanf(fp,"%d",&number[i]);
                i++;
            }
            for (k=0;k<i;k++)
            {
                for(t=k+1;t<i;t++)
                {
                    if (number[k]>number[t])
                    {
                        num=number[k];
                        number[k]=number[t];
                        number[t]=num;
                    }
                }
            }
            for (m=0;m<i;m++)
            {
                //printf("%d",number[m]);
                head=Create(head,number[m]);
            }
            fclose(fp);
        }
        else if (strcmp(mingling,"Delete")==0)
        {
            int x;
            printf("please input a number:");
            scanf("%d",&x);
            if (head ==NULL)
            {
                printf("list is empty!\n");
            }
            else
            {
                head=Delete(head,x);
            }
        }
        else if (strcmp(mingling,"Insert")==0)
        {
            int x;
            printf("please input a number:");
            scanf("%d",&x);
            if (head ==NULL)
            {
                printf("list is empty!\n");
            }
            else
            {
                head=Insert(head,x);
            }
        }
        else if (strcmp(mingling,"Search")==0)
        {
            int x;
            printf("please input a number:");
            scanf("%d",&x);
            if (head ==NULL)
            {
                printf("list is empty!\n");
            }
            else
            {
                Search(head,x);
            }
        }
        else if (strcmp(mingling,"Display")==0)
        {
            if (head ==NULL)
            {
                printf("list is empty!\n");
            }
            else
            {
                Display(head);
            }
        }
        else if (strcmp(mingling,"Count")==0)
        {
            int x;
            if (head ==NULL)
            {
                printf("list is empty!\n");
            }
            else
            {
                x=Count(head);
                printf("The list number is %d\n",x);
            }
        }
        else if (strcmp(mingling,"Rever")==0)
        {
            if (head ==NULL)
            {
                printf("list is empty!\n");
            }
            else
            {
                head=Rever(head);
            }
        }
        else if (strcmp(mingling,"Free")==0)
        {
            struct link *p=head,*pr=NULL;
            while(p!=NULL)
            {
                pr=p;
                p=p->next;
                free(pr);
            }
            printf("Free finish!\n");
        }
        else{printf("Wrong order!\n");}
    }
    return 0;
}
