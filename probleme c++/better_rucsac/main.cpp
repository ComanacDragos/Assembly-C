#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("rucsac.in");
ofstream fout ("rucsac.out");


int main()
{
    unsigned long n,g;
    fin>>n>>g;
    unsigned long val[n+1], greutati[n+1], v[n+1][g+1];
    for(unsigned long i=1;i<=n;i++)
    {
        fin>>greutati[i]>>val[i];
    }
    for(unsigned long i=1;i<=g;i++)
        {
       if(i<greutati[1])
            v[1][i]=0;
        else
            v[1][i]=val[1];

        }
    v[1][0]=0;
    for(unsigned long i=2;i<=n;i++)
    {   v[i][0]=0;
        for(unsigned long j=1;j<=g;j++)
    {
        unsigned long m1,m2;
        m1=v[i-1][j];
        if(j<greutati[i])
            m2=0;
        else
            m2=v[i-1][j-greutati[i]]+val[i];

        if(m1>m2)
            v[i][j]=m1;
        else
            v[i][j]=m2;
    }
    }
/*
   for(unsigned i=1;i<=n;i++)
    {for(unsigned j=1;j<=g;j++)
        cout<<v[i][j]<<' ';
        cout<<'\n';}
*/

fout<<v[n][g];
    return 0;
}
