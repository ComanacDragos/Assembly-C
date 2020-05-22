#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("ssm.in");
ofstream fout ("ssm.out");

int main()
{
    long long int n, i, mx_val, mx_index, s=0;
    fin>>n;
    long long int arr[n+1], prev_val;
    for(i=0;i<n;i++)
        fin>>arr[i];
    prev_val = arr[0];
    mx_val = prev_val;
    mx_index = 0;
    //cout<<prev_val<<' ' ;
    for(i=1;i<n;i++)
    {
        if(prev_val+arr[i] < arr[i])
            prev_val = arr[i];
        else
            prev_val = prev_val + arr[i];
      //  cout<<prev_val<<' ' ;

        if(mx_val < prev_val)
        {
            mx_val = prev_val;
            mx_index = i;
        }
    }
    //cout<<'\n';
    i = mx_index;
    s = arr[i];
    while(s != mx_val || arr[i-1] == 0)
    {
        i--;
        s += arr[i];
    }
    fout<<mx_val<<' '<<i+1<<' '<<mx_index+1;
}
