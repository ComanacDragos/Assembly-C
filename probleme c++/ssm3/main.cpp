	#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

const char iname[] = "ssm.in";
const char oname[] = "ssm.out";

const int MAXN = 7000005;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++ i)
#define Max(a, b)  ((a) > (b) ? (a) : (b))

int main(void) {
    ifstream in(iname);
    int n, S;
    int bestSum = -int(2e9), sum = 0, beg, end, idx;
    in >> n;
    FOR (i, 1, n) {
        in >> S;
        if (sum < 0)
            sum = S, idx = i;
        else
            sum += S;
        if (bestSum < sum)
            bestSum = sum, beg = idx, end = i;
    }
    ofstream out(oname);
    cout << bestSum << " " << beg << " " << end;

    in.close(), out.close();
    return 0;
}
