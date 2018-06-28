/* 7-2 一元多项式的乘法与加法运算 */
/* 使用单链表实现 */

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int coe;
    int index;
    struct node* next;
}*list;

list read(void);
void print(list a);
list add(list a,list b);
list mul(list a,list b);

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
    list a,b,multi,addin;

    a=read();
    b=read();
    multi=mul(a,b);
    addin=add(a,b);
    print(multi);
    printf("\n");
    print(addin);

    return 0;
}

list add(list a,list b)
{
    list p,q,s,m;
    p=a;
    q=b->next;
    while(p->next!=NULL&&q!=NULL)
    {
        m=q->next;
        if(q->index>p->next->index)
        {
            s=p->next;
            p->next=q;
            q->next=s;
            q=m;
        }
        else if(q->index==p->next->index)
        {
            p->next->coe+=q->coe;
            q=m;
        }
        else
        {
            p=p->next;
        }
    }
    if(p->next==NULL&&p==a)
        return b;
    else if(p->next==NULL)
        p->next=q;
    return a;
}

list mul(list a,list b)
{
    list multi;
    list l[1000];
    int i,j;
    list p,q;
    list m,s;

    p=a->next;
    q=b->next;
    multi=(list)malloc(sizeof(struct node));
    multi->next=NULL;

    i=0;
    while(p!=NULL)
    {
        l[i]=(list)malloc(sizeof(struct node));
        m=l[i];
        while(q!=NULL)
        {
            s=(list)malloc(sizeof(struct node));
            s->coe=p->coe*q->coe;
            s->index=p->index+q->index;

            m->next=s;
            m=s;
            q=q->next;
        }
        m->next=NULL;

        q=b->next;
        i++;
        p=p->next;
    }

    for(j=0;j<i;j++)
    {
        multi=add(multi,l[j]);
    }

    return multi;
}

list read(void)
{
    int K;
    int i;
    list h,s,p;
    scanf("%d",&K);
    h=(list)malloc(sizeof(struct node));
    p=h;
    for(i=0;i<K;i++)
    {
        s=(list)malloc(sizeof(struct node));
        scanf("%d%d",&s->coe,&s->index);
        p->next=s;
        p=s;
    }
    p->next=NULL;
    return h;
}

void print(list a)
{
    int sam=0;
    list p;
    p=a->next;
    while(p!=NULL)
    {
        if(p->coe!=0)
        {
            sam=1;
            printf("%d %d ",p->coe,p->index);
        }
        else
            ;
        p=p->next;
    }
    if(sam==0)
        printf("0 0 ");
    printf("\b");
}
