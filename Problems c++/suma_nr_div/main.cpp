#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
ifstream fin ("ssnd.in");
ofstream fout ("ssnd.out");
#define N 1000005
#define MOD 9973
long long unsigned ciur[N], aux[N];
void prime ()
{
    long long unsigned i, j, k=0;
    for(i=2;i<N;i++)
    {
        if(aux[i] == 0)
        {
            ciur[k] = i;
            k++;
            j = i+i;
            while(j < N)
            {
                aux[j] = 1;
                j += i;
            }
        }
    }
}
long long unsigned power (long long unsigned n , long long unsigned p)
{
    if(p==0)
        return 1;
    if (p==1)
        return n;

    if(p%2==0)
        return (power(n, p/2)%MOD*power(n, p/2)%MOD)%MOD;
    else
        return ((power(n, p/2)%MOD)*(power(n, p/2)%MOD)%MOD*n%MOD)%MOD;
}
void divisors (long long unsigned n)
{
    long long unsigned exponent, base, len=0, i, j, k, card = 1, sum = 1, aux=n;
    i=0;
    while(n != 1 && i < sqrt(n))
    {
        if(n%ciur[i] == 0)
        {
            exponent = 0;
            base = ciur[i];
            while(n%ciur[i] == 0)
            {
                exponent += 1;
                n /= ciur[i];
            }
            card *= (exponent+1);
            sum *= (power(base, exponent+1)-1)/(base-1);
        }
        i++;
    }
    //for(i=0;i<j;i++)
   //     cout<<bases[i]<<' '<<exponents[i]<<'\n';
   if(n != 1)
   {
        sum += aux;
        card += 1;
   }
    fout<<card<<' '<<sum<<'\n';

}
int main()
{
    prime();
    long long unsigned t;
    fin>>t;

    for(unsigned i=0;i<t;i++)
    {
        long long unsigned n;
        fin>>n;
        divisors(n);
    }
    return 0;
}
