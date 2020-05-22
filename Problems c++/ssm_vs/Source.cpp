#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("ssm.in");
ofstream fout("ssm.out");

int main()
{
    long long int n, i, mx_val, mx_index, s = 0;
    fin >> n;
    long long int arr[n + 1], prev_val;
    for (i = 0; i < n; i++)
        fin >> arr[i];
    prev_val = arr[0];
    mx_val = prev_val;
    mx_index = 0;
    for (i = 1; i < n; i++)
    {
        if (arr[i] + prev_val <= prev_val)
            prev_val = arr[i];
        else
            prev_val = arr[i] + prev_val;

        if (prev_val > mx_val)
        {
            mx_val = prev_val;
            mx_index = i;
        }
        cout << prev_val << ' ';
    }
    /*
    i = mx_index;
    s=arr[mx_index];
    while(s != mx_val && i>=1)
    {
        s += arr[i-1];
        i--;
    }
*/

}
