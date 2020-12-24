#include<stdio.h>
#include<stdlib.h>
void arrange(int number_of_students)
{
    struct student *a;
    a=(struct student *)malloc(sizeof(struct student)*number_of_students);
    int i=0;
    FILE *p;
    p=fopen("eligible_for_admission.bin","r");
    while(1)
    {
        int r=fscanf(p,"%s\t%s\t%d\n",&(a[i].name),&(a[i].place),&(a[i].rank));
        if(r==-1)
        {
            break;
        }
        i=i+1;
        
    }
    fclose(p);
    int j,k;
    struct student temp;
    for(j=0;j<i-1;j++)
    {
        for(k=0;k<=i-j-1;k++)
        {
            if (a[k].rank>a[k+1].rank)
            {
                temp=a[k];
                a[k]=a[k+1];
                a[k+1]=temp; 
            }
        }
    }
    printf("\tCHECK WHEATHER THE STUDENTS ATTENDED THE COUNSELING SESSION OR NOT \n");
    p=fopen("sorted_data.bin","r");
    int choice;
    int y=0;
    while(1)
    {
        if(y==i)
        {
            break;
        }
    printf("\tENTER 1.FOR STUDENT PRESENT IN THE COUNSELING\n");
    printf("\tENTER 2. FOR THE STUDENT IS NOT PRESENT FOR THE COUNSELING\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            if(p==NULL)
            {
                p=fopen("sorted_data.bin","w");
                fprintf(p,"%s\t%s\t%d\n",a[y].name,a[y].place,a[y].rank);
                y=y+1;

            }
            else
            {
                p=fopen("sorted_data.bin","a");
                fprintf(p,"%s\t%s\t%d\n",a[y].name,a[y].place,a[y].rank);
                y=y+1;
            }
            fclose(p);
            break ;}
        case 2:    
            {
                printf("\n\tTHE STUDENT IS NOT PRESENT IN THE COUNSELING\n");
                y=y+1;
                break;
            }
            default:
            {printf("INVALID CHOICE");
            break ;}
    }
}
return;
}