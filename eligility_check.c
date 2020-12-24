#include<stdio.h>
#include<stdlib.h>
void eligibility(int k,struct student *e)
{
    FILE *p;
    p=fopen("eligible_for_admission.bin","r");
    
    if ((e->rank)<=k)
    {
        printf("\t%s IS ELIGIBLE\n",e->name);
        if(p==NULL)
        {
            p=fopen("eligible_for_admission.bin","w");
            fprintf(p,"%s\t%s\t%d\n",e->name,e->place,e->rank);
        }
        else
        {
            p=fopen("eligible_for_admission.bin","a");
            fprintf(p,"%s\t%s\t%d\n",e->name,e->place,e->rank);
        }
    }
    else
    {
        printf("\t%s IS NOT ELGIBILE\n",e->name);
    }
    fclose(p);
    return ;

}
