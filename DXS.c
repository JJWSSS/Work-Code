#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct polynode
{
	int coef,exp;
	struct polynode *next;
};
struct polynode * Combine(struct polynode *head1,struct polynode *head2);
struct polynode * Create(struct polynode *head, int c,int e);
/*struct link * Delete(struct link *head, int x);
struct link * Insert(struct link *head, int x);
void Search(struct link *head, int x);*/
//void Display(struct link *head);
/*int Count(struct link *head);
struct link * Rever(struct link *head);
struct link * Rever(struct link *head)
{
	int t, m, i, x, num[1000];
	struct link *p = head, *pr = head, *q = NULL;
	i = 0;
	while (p->next != NULL)
	{
		num[i] = p->data;
		p = p->next;
		i++;
	}
	num[i] = p->data;
	i++;
	pr = pr->next;
	while (pr != NULL)
	{
		q = pr;
		pr = pr->next;
		free(q);
	}
	head = NULL;
	for (m = i - 1; m >= 0; m--)
	{
		head = Create(head, num[m]);
	}
	return head;
}
int Count(struct link *head)
{
	int i = 0;
	struct link *p = head;
	while (p->next != NULL)
	{
		p = p->next;
		i++;
	}
	return i + 1;
}*/
struct polynode * Combine(struct polynode *head1,struct polynode *head2)
{
    int i=0;
    struct polynode *p1,*p2,*pr1 = NULL,*pr2=NULL;
    p1 =head1;
    p2= head2;
    pr2=p1;
    for(;;)
    {
        if (head1 == NULL || head2 == NULL)
        {
            printf("Error!\n");
            break;
        }
        else
        {
            while(p1!=NULL && p2!=NULL)
            {
                if ((i==0) && (p1->exp < p2->exp))
                {
                    struct polynode *pr;
                    pr = (struct polynode *)malloc(sizeof(struct polynode));
                    pr->coef = p2->coef;
                    pr->exp=p2->exp;
                    head1 =pr;
                    pr->next =pr2;
                    p1 = pr;
                    p2 = p2->next;
                }
                else if (p1->exp > p2->exp)
                {
                    pr1=p1;
                    p1 = p1->next;
                    i++;
                }
                else if ((i!=0) && (p1->exp < p2->exp))
                {
                    struct polynode *pr;
                    pr = (struct polynode *)malloc(sizeof(struct polynode));
                    pr->coef = p2->coef;
                    pr->exp=p2->exp;
                    pr1->next =pr;
                    pr->next =p1;
                    p2 = p2->next;
                    pr1= pr1->next;
                }
                else
                {
                    p1->coef += p2->coef;
                    p2 = p2->next;
                }
            }
            if (p1== NULL && p2!=NULL)
            {
                while(p2!=NULL)
                {
                    struct polynode *pr;
                    pr = (struct polynode *)malloc(sizeof(struct polynode));
                    pr->coef = p2->coef;
                    pr->exp=p2->exp;
                    pr1->next =pr;
                    pr->next =p1;
                    p2 = p2->next;
                    pr1= pr1->next;
                }
            }
        }
        break;
    }
    return head1;
}
struct polynode * Create(struct polynode *head, int c,int e)
{
	struct polynode *p = NULL,*pr = head;
	p = (struct polynode *)malloc(sizeof(struct polynode));
	if (p == NULL)
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
		while (pr->next != NULL)
		{
			pr = pr->next;
		}
		pr->next = p;
	}
	p->coef = c;
	p->exp = e;
	p->next = NULL;
	return head;
}
/*struct link * Delete(struct link *head, int x)
{
	struct link *p = head, *pr = head;
	while (p->data != x && p->next != NULL)
	{
		pr = p;
		p = p->next;
	}
	if (x == p->data)
	{
		if (p == head)
		{
			head = p->next;
		}
		else
		{
			pr->next = p->next;
		}
		free(p);
	}
	else
	{
		printf("This Node has not been found!\n");
	}
	return head;
}
struct link * Insert(struct link *head, int x)
{
	struct link *pr = head, *p = NULL, *temp = NULL;
	p = (struct link *)malloc(sizeof(struct link));
	if (p == NULL)
	{
		printf("No enough memory!\n");
		exit(0);
	}
	p->data = x;
	p->next = NULL;
	while (pr->data<x && pr->next != NULL)
	{
		temp = pr;
		pr = pr->next;
	}
	if (pr->data >= x)
	{
		if (pr == head)
		{
			p->next = head;
			head = p;
		}
		else
		{
			p->next = pr;
			temp->next = p;
		}
	}
	else
	{
		pr->next = p;
	}
	return head;
}
void Search(struct link *head, int x)
{
	struct link *p = head;
	int i = 1;
	while (p->next != NULL && i<x)
	{
		p = p->next;
		i++;
	}
	if (i == x){ printf("number is %d\n", p->data); }
	else
	{
		printf("Not found!\n");
	}
}*/
void Display(struct polynode *head)
{
	struct polynode *p = head;
	for(;;)
    {
        if (head == NULL)
        {
            printf("list is null!");
            break;
        }
        while (p->next != NULL)
        {
            printf("%d %d\n", p->coef,p->exp);
            p = p->next;
        }
        printf("%d %d\n", p->coef,p->exp);
        break;
    }
}
int main()
{
    int z;
	char mingling[10];
	struct polynode *head[20];
	for (z=0;z<20;z++)
    {
        head[z]= NULL;
    }
	for (;;)
	{
		printf("please input your order:");
		scanf("%s", &mingling);
		if (strcmp(mingling, "Exit") == 0)
		{
			break;
		}
		else if (strcmp(mingling, "Create") == 0)
		{
		    int i,exp,coef;
			printf("Which polynode you want to edit:");
			scanf("%d",&i);
			printf("please input coef and exp:");
			scanf("%d %d",&coef,&exp);
			head[i]=Create(head[i],coef,exp);
		}
		/*else if (strcmp(mingling, "Delete") == 0)
		{
			int x;
			printf("please input a number:");
			scanf("%d", &x);
			if (head == NULL)
			{
				printf("list is empty!\n");
			}
			else
			{
				head = Delete(head, x);
			}
		}
		else if (strcmp(mingling, "Insert") == 0)
		{
			int x;
			printf("please input a number:");
			scanf("%d", &x);
			if (head == NULL)
			{
				printf("list is empty!\n");
			}
			else
			{
				head = Insert(head, x);
			}
		}
		else if (strcmp(mingling, "Search") == 0)
		{
			int x;
			printf("please input a number:");
			scanf("%d", &x);
			if (head == NULL)
			{
				printf("list is empty!\n");
			}
			else
			{
				Search(head, x);
			}
		}
		else if (strcmp(mingling, "Display") == 0)
		{
			if (head == NULL)
			{
				printf("list is empty!\n");
			}
			else
			{
				Display(head);
			}
		}
		else if (strcmp(mingling, "Count") == 0)
		{
			int x;
			if (head == NULL)
			{
				printf("list is empty!\n");
			}
			else
			{
				x = Count(head);
				printf("The list number is %d\n", x);
			}
		}
		else if (strcmp(mingling, "Rever") == 0)
		{
			if (head == NULL)
			{
				printf("list is empty!\n");
			}
			else
			{
				head = Rever(head);
			}
		}*/
		else if (strcmp(mingling, "Free") == 0)
		{
		    int i;
            struct polynode *p, *pr = NULL;
		    printf("which list do you free:");
		    scanf("%d",&i);
            p = head[i];
			while (p != NULL)
			{
				pr = p;
				p = p->next;
				free(pr);
			}
			printf("Free finish!\n");
		}
		else if (strcmp(mingling, "Combine") == 0)
        {
            int a,b;
            printf("please input two list number:");
            scanf("%d %d",&a,&b);
            if (head[a]== NULL || head[b]== NULL)
            {
                printf("list is empty!\n");
            }
            else
            {
                printf("First:\n");
                Display(head[a]);
                printf("Second:\n");
                Display(head[b]);
                head[a] = Combine(head[a],head[b]);
                printf("Last:\n");
                Display(head[a]);
            }
        }
		else{ printf("Wrong order!\n"); }
	}
	return 0;
}
