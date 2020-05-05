#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
ifstream fin ("aria.in");
ofstream fout ("aria.out");

#define precision 100000
int main()
{
    double n, x , y , x1 , y1 , x2 , y2, i, s=0;
    fin>>n>>x>>y;
    x1=x;
    y1=y;

    for(i=2;i<=n;i++)
    {
        fin>>x2>>y2;
        s = s + x1*y2-x2*y1;
        x1=x2;
        y1=y2;
    }
    //cout<<s+x1*y-x*y1<<' ';
    s = s + x1*y-x*y1;
    s/=2;
    FILE *fout=fopen("aria.out", "w");
    fprintf(fout, "%.6f", s);

    return 0;
}
