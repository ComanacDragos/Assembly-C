#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("ciur.in");
ofstream fout ("ciur.out");
char ciur[2000001];
int main()
{
    long unsigned n, i, j, primes = 0;
    fin>>n;
    for(i=2;i<=n;i++)
    {
        if(ciur[i] == 0)
        {
            primes += 1;
            j=i+i;
            while(j<=n)
            {
                ciur[j] = 1;
                j += i;
            }
        }
    }
    fout<<primes;


    return 0;
}
