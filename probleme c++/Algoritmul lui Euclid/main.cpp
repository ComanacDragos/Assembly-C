#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
long long unsigned euclid (long long unsigned a , long long unsigned b){
    while(a%b!=0){
            long long int aux=b;
            b=a%b;
            a=aux;
    }
    return b;
}
int main()
{
    long long int a,b,T;
    fin>>T;
    for(long long int i=1;i<=T;i++){
        fin>>a>>b;
        if(a>b) fout<<euclid(a,b)<<'\n';
        else fout<<euclid(b,a)<<'\n';
    }
    return 0;
}
