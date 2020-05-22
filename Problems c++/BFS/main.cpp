#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("bfs.in");
ofstream fout ("bfs.out");
#define MAX 10000
unsigned long long a[MAX][MAX], weight[MAX], ap[MAX], q[MAX];
long long unsigned n;

void pop(long long unsigned v[])
{
    long long unsigned i=0;

    while(v[i] != 0)
    {
    v[i]=v[i+1];
     i+=1;
    }

}

void push(long long unsigned v[], long long unsigned val)
{
    long long unsigned i=0;

    while(v[i] != 0)
    {
     i+=1;
    }
    v[i] = val;
    v[i+1] = 0;
}


void BFS(long long unsigned node)
{
    long long unsigned i,first,last;
    ap[node] = 1;
    first = last = 1;
    q[first] = node;
    while(first <= last)
    {
        node = q[first];
        for(i=1;i<=n;i++)
        {
            if(a[node][i] == 1 && ap[i]==0)
            {
                ap[i] = 1;
                last ++;
                q[last] = i;
                weight[i] = weight[node] + 1;
            }
        }
        first += 1;
    }

}

int main()
{
    long long unsigned m,s,i,j,x,y;
    fin>>n>>m>>s;

    for(i=1;i<=m;i++)
    {
        fin>>x>>y;
        a[x][y] = 1;
    }
    /*
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        cout<<a[i][j]<<' ';

        cout<<'\n';
    }
*/
BFS(s);

for(i=1;i<=n;i++)
    if (i!=s && weight[i] == 0)
        fout<<-1<<' ';
    else
        fout<<weight[i]<<' ';
}
