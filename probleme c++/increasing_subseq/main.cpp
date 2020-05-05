#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("scmax.in");
ofstream fout ("scmax.out");


void lis (unsigned long int n, unsigned long long int arr[])
{
    long long int v[n], daddys[n], new_seq[n];
    long int max_len, max_daddy, i, j;


    daddys[0] = -1;
    v[0] = 1;
    for(i=1;i<n;i++)
    {
        max_len = 1;
        max_daddy = -1;

        for(j=0;j<i;j++)
        {
         if(arr[j] < arr[i] && max_len <= v[j])
         {
            max_len = v[j];
            max_daddy = j;
         }
        }
        if(max_daddy == -1)
            v[i] = 1;
         else
        {
            v[i] = max_len+1;
        }
         daddys[i]  = max_daddy;
    }
    max_len = 1;
    max_daddy = 0;
    for(i=1;i<n;i++)
         if(max_len < v[i])
         {
             max_len = v[i];
             max_daddy = i;
         }
    fout<<max_len<<'\n';
    i = 0;
    while(max_daddy != -1)
    {
        new_seq[i] = arr[max_daddy];
        i++;
        max_daddy = daddys[max_daddy];
    }
    for(j=i-1;j>=0;j--)
    {
        fout<<new_seq[j]<<' ';
    }


}

int main()
{
    unsigned long int n,i;
    fin>>n;
    unsigned long long int arr[n];
    for(i=0;i<n;i++)
    {
        fin>>arr[i];
    }
    lis(n, arr);
    return 0;
}
