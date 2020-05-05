#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
unsigned a[1525][1525];
int main()
{
    unsigned v1[1525],v2[1525],v3[1525],m,n,k=0;
    fin>>m>>n;
    for(unsigned i=1;i<=m;i++)fin>>v1[i];
    for(unsigned i=1;i<=n;i++)fin>>v2[i];
    /*
    if(v1[m]==v2[n]){
    a[n][m]=1;
    v3[++k]=v1[m];}
    for(unsigned i=m-1;i>=1;i--)
        if(v1[i]==v2[n]){a[n][i]=a[n][i+1]+1;v3[++k]=v2[n];}
        else
        a[n][i]=a[n][i+1];
    for(unsigned i=n-1;i>=1;i--)
        if(v2[i]==v1[m]){a[i][m]=1+a[i+1][m];v3[++k]=v1[m];}
        else
        a[i][m]=a[i+1][m];
*/
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(v1[j]==v2[i])a[i][j]=1+a[i-1][j-1];
            else {
                if(a[i-1][j]>a[i][j-1])a[i][j]=a[i-1][j];
                else a[i][j]=a[i][j-1];
            }

    cout<<"   ";
    for(int i=1;i<=m;i++)
        if(i<=9)cout<<i<<"  ";
    else cout<<i<<" ";
    cout<<'\n';
    for(int i=1;i<=n;i++){
         if(i<=9)cout<<i<<"  ";
    else cout<<i<<" ";
        for(int j=1;j<=m;j++)
            cout<<a[i][j]<<"  ";
        cout<<'\n';
    }

    unsigned i=n,j=m;
    while(i>0 && j>0)
        if(v1[j]==v2[i]){v3[++k]=v1[j];i--;j--;}
    else {
        if(a[i-1][j]<a[i][j-1])j--;
        else i--;}
     fout<<k<<'\n';
    for(int i=k;i>=1;i--)fout<<v3[i]<<' ';

    return 0;
}
