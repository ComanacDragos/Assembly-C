#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("combinari.in");
ofstream fout ("combinari.out");

unsigned N, K, v[20];

unsigned consistent(unsigned k)
{
    if(k>=K)
        return 0;

    for(unsigned i=0;i<k;i++)
        if(v[i] >= v[k])
            return 0;
    return 1;
}
unsigned valid(unsigned k)
{
    if(k == K-1)
        return 1;
    return 0;
}
void afisare()
{
    for(unsigned i=0;i<K;i++)
        fout<<v[i]<<' ';
    fout<<'\n';
}

void bkt(unsigned k)
{
    for(unsigned i=1;i<=N;i++)
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
    fin>>N>>K;
    bkt(0);
    return 0;
}
