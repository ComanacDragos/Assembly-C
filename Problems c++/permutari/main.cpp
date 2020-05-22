#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("permutari.in");
ofstream fout ("permutari.out");
int n, v[9];

int consistent (int k)
{
    for(int i=0;i<k;i++)
        if(v[k] == v[i])
            return 0;
    return 1;
}

int valid (int k)
{
    if(k == n-1)
        return 1;
    return 0;
}

void afisare()
{
    for(int i=0;i<n;i++)
        fout<<v[i]<<' ';
    fout<<'\n';
}

void bkt (int k)
{
    for(int i=1;i<=n;i++)
    {
        v[k]=i;

        if(consistent(k) == 1)
        {
            if(valid(k) == 1)
                afisare();
            else
                bkt(k+1);
        }
    }
}

int main()
{
    fin>>n;
    bkt(0);
    return 0;
}
