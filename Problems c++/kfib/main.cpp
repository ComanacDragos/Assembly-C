#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("kfib.in");
ofstream fout ("kfib.out");
#define MOD 666013
long long unsigned n, aux[2][2] = {{0,1},{1,1}};
void mul (long long unsigned a[2][2], long long unsigned b[2][2])
{
    unsigned i,j,k;
    long long unsigned c[2][2]={{0,0},{0,0}};
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            for(k=0;k<2;k++)
                c[i][j]+=(a[i][k]%MOD * b[k][j]%MOD);
                c[i][j] = c[i][j]%MOD;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            a[i][j] = c[i][j];
}

long long unsigned better_power (long long unsigned F[2][2], long long unsigned p)
{
    if(p==1)
    {
        return 0;//(F[0][1]+F[1][1])%MOD;
    }
    better_power(F, p/2);
    mul(F,F);
    if(p%2==1)
    {
        mul(F,aux);
    }
    return(F[0][1]+F[1][1])%MOD;

}
long long unsigned find_nth (long long unsigned n)
{
    long long unsigned a[2][2] = {{0,1},{1,1}};
    if(n==0)
        return 0;
    if(n==1 || n ==2)
        return 1;
    return better_power(a, n-2);
}
int main()
{

    //for(int i=1;i<=100;i++)
    fin>>n;
    fout<<find_nth(n);
}
