#include<stdio.h>
#include<stdlib.h>
struct student
{
    char name[30];
    char place[40];
    int rank;
    int inter_percntage;
    char course_applied[30];
};
void registration()
{struct student *s;
int a;
int k=0;
FILE *p;
p=fopen("data.bin","r");
if (p==NULL)
    {p=fopen("data.bin","w+");
    s=(struct student*)malloc(sizeof(struct student));
    printf("ENTER THE NAME  :     ");
    scanf("%s",&s->name);
    printf("\nENTER THE PLACE  : ");
    scanf("%s",&s->place);
    printf("\nENTER THE RANK    :");
    scanf("%d",&s->rank);
    fprintf(p,"%s\t%s\t%d\n",s->name,s->place,s->rank);
    }
    else
    {
        p=fopen("data.bin","a");
    s=(struct student*)malloc(sizeof(struct student));
    printf("ENTER THE NAME    :");
    scanf("%s",&s->name);
    printf("\nENTER THE PLACE  :");
    scanf("%s",&s->place);
    printf("\nENTER THE RANK    :");
    scanf("%d",&s->rank);
    fprintf(p,"%s\t%s\t%d\n",s->name,s->place,s->rank);
    }
    fclose(p);
    return ;
}