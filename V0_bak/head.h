#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define kkk printf("!!!\n");
#define Nx 100
extern int topolo[7][7];
extern double k[7][7];
extern double C;
extern double alpha[7];
extern double beta;
extern int n;
extern double D;
extern double dx;
extern double dt;
extern double d;
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
        void next();
        void print(char name[20]);
};
#endif
