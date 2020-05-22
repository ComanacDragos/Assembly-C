#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("lgput.in");
ofstream fout ("lgput.out");
using namespace std;
#define MOD 1999999973

long unsigned power (long unsigned n, long unsigned p)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return n%MOD;

    if(p%2 == 0)
        return power(n,p/2)%MOD*power(n,p/2)%MOD;

    return power(n,p/2)%MOD*power(n,p/2)%MOD* n%MOD;

}

int main()
{
    long unsigned n,p;
    fin>>n>>p;

    fout<<power(n,p);
    return 0;
}

//1284616625
//140628111
