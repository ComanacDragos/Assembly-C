#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
struct {
unsigned l,v[1025];
}a[700][700];
int main()
{
    int m,n,v1[1025],v2[1025];
    fin>>m>>n;

    for(int i=1;i<=m;i++){
            fin>>v1[i];
            a[0][i].l=0;
    }
    for(int i=1;i<=n;i++){
            fin>>v2[i];
            a[i][0].l=0;
    }
    a[0][0].l=0;
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
        if(v1[i]==v2[j]){
                a[i][j]=a[i-1][j-1];
                a[i][j].l++;
                a[i][j].v[a[i][j].l]=v1[i];
    }
    else {
        if(a[i-1][j].l>a[i][j-1].l)a[i][j]=a[i-1][j];
        else a[i][j]=a[i][j-1];
    }
    fout<<a[m][n].l<<'\n';
    for(int i=1;i<=a[m][n].l;i++)
    fout<<a[m][n].v[i]<<' ';
    return 0;
}
