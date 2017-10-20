#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"head.h"
#include"func.h"
using namespace std;
int nextstep(pgene Gene[7])
{
    int posi,i,j;
    for(j=3;j<7;j++)
    {
        for(i=0;i<Nx;i++)
        {
            Gene[j]->c1[i]=Gene[j]->c0[i];
        }
    }
    for(posi=0;posi<Nx;posi++)
    {
        diff(Gene,posi);
        deg(Gene,posi);
        react(Gene,posi);
//        getchar();
    }
}
int diff(pgene Gene[7],int posi)
{
    int j;
    if(posi==0)
    {
        for(j=3;j<7;j++)
        {
            Gene[j]->c1[0]+=d*(Gene[j]->c0[1]-Gene[j]->c0[0]);
        }
    }
    else if(posi==Nx-1)
    {
        for(j=3;j<7;j++)
        {
            Gene[j]->c1[Nx-1]+=d*(Gene[j]->c0[Nx-2]-Gene[j]->c0[Nx-1]);
        }
    }
    else
    {
        for(j=3;j<7;j++)
        {
            Gene[j]->c1[posi]+=d*(Gene[j]->c0[posi-1]+Gene[j]->c0[posi+1]-2*Gene[j]->c0[posi]);
        }
    }
}
int deg(pgene Gene[7],int posi)
{
    int j;
    for(j=3;j<7;j++)
    {
        Gene[j]->c1[posi]-=dt*beta*Gene[j]->c0[posi];
    }
}
int react(pgene Gene[7],int posi)
{
    int a,b;
    double tmp,tmp2;
    for(b=3;b<7;b++)
    {
        tmp=alpha[b]*dt;
        tmp2=1;
        for(a=0;a<7;a++)
        {
            if(topolo[a][b]!=1)
                tmp*=AactB(Gene,a,b,posi);
            else if(topolo[a][b]==1)
                tmp2*=(1-AactB(Gene,a,b,posi));
        }
        if (tmp2!=1)
            tmp*=(1-tmp2);
        Gene[b]->c1[posi]+=tmp;
    }

//    tmp=alpha[6]*dt;
//    for(a=2;a<7;a++)
//    {
//        tmp*=AactB(Gene,a,6,posi);
//    }
//    tmp*=(1-(1-AactB(Gene,0,6,posi))*(1-AactB(Gene,1,6,posi)));
//    Gene[6]->c1[posi]+=tmp;

    }

/*
double AactB(pgene Gene[7],int a,int b,int posi)
{
    if(topolo[a][b]==0)
        return 1.0;
    else
    {
        double tmp=k[a][b]*Gene[a]->c0[posi];
        if(topolo[a][b]==1)
            return(tmp/(1+tmp));
        else if(topolo[a][b]==-1)
            return (1/(1+tmp));
        else if(topolo[a][b]==2)
            return(tmp/((1+tmp)*(1+tmp)));
        else
            return 1;
    }
}
*/


double AactB(pgene Gene[7],int a,int b,int posi)
{
    if(topolo[a][b]==0)
    {
        return 1;
    }
    else
    {
        double tmp=pow(1+C*k[a][b]*Gene[a]->c0[posi],n);
        if(topolo[a][b]==1)
        {
            return((tmp-1)/(tmp+C-1));
        }
        else if(topolo[a][b]==-1)
        {
            return(C/(tmp+C-1));
        }
        else if(topolo[a][b]==2)
        {
            return((C*(tmp-1))/((tmp+C-1)*(tmp+C-1)));
        }
        else
            return 1;
    }

}










