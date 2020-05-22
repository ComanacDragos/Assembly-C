#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("damesah.in");
ofstream fout ("damesah.out");
int v[30], n, cont;
int consistent (int k)
{
    for(int i=1;i<k;i++)
        if(v[k] == v[i] || (v[i]-v[k] == k-i || v[k]-v[i] == k-i))
            return 0;
    return 1;
}
int valid (int k)
{
    if(k==n)
        return 1;
    return 0;
}
void print ()
{

    if(cont == 0)
    {
    for(int i=1;i<=n;i++)
        fout<<v[i]<<' ';
    fout<<'\n';
    }
    cont += 1;
}
void bkt (int k)
{
    for(int i=1;i<=n;i++)
    {
        v[k]=i;
        if(consistent(k) == 1)
        {
            if(valid(k) == 1)
                print();
            else
                bkt(k+1);
        }
    }
}


int main()
{
    fin>>n;
    bkt(1);
    fout<<cont;
}
