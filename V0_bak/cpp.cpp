#include<stdio.h>
#include<stdlib.h>
#include"head.h"
using namespace std;


gene::gene()
{
    int i;
    for(i=0;i<Nx;i++)
    {
        c0[i]=0.1;
        c1[i]=0.0;
    }
}
gene::gene(double ini_c[Nx])
{
    int i;
    for(i=0;i<Nx;i++)
    {    
        c0[i]=ini_c[i];
        c1[i]=0.0;
    }
}
void gene::next()
{
    int i;
    for(i=0;i<Nx;i++)
    {
        c0[i]=c1[i];
        c1[i]=0.0;
    }
}
void gene::print(char name[20])
{
    FILE *fp;
    fp=fopen(name,"a");
    int i;
    for(i=0;i<Nx;i++)
    {
        fprintf(fp,"%f\t",c0[i]);
    }
    fprintf(fp,"\n");
    fclose(fp);
}



