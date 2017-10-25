#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define kkk printf("!!!\n");
#define Nx 100
#define T 2000
//#define delta 0.001
#define traintime 3
#define ln_rate_max 0.9
#define ln_rate_min 0.2
extern int topolo[7][7];
extern double k[7][7];
extern double k_new[7][7];
extern double C;
extern double alpha[7];
extern double alpha_new[7];
extern double beta;
extern int n;
extern double D;
extern double dx;
extern double dt;
extern double d;
extern double ln_rate;
extern double D_rate;
extern double mhb[Nx];

class gene;
typedef gene *pgene;
class gene
{
    public:
        ~gene();
        gene();
        gene(double ini_c[Nx]);
        double c0[Nx];
        double c1[Nx];
        double target[Nx];
        
        void setinit();
        void next();
        void print(char name[20]);
        double error();
        void settarget(double t[Nx]);
        void setvar(double var[Nx]);
};
#endif
