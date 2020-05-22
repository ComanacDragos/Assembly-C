#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("scmax.in");
ofstream fout("scmax.out");

int main()
{
	long unsigned n, i, j, mx_index, mx_val;
	fin >> n;
	long long unsigned arr[2000],v[2000], daddys[2000], aux;

	for (i = 1; i <= n; i++)
	{
		fin >>aux;
		arr[i] = aux;
	}

	daddys[1] = 0;
	v[1] = 1;

	for (i = 2; i <= n; i++)
	{
		mx_index = 1;
		mx_val = arr[1];

		for (j = 2; j < i; j++)
		{
			if()
		}
	}



	return 0;
}