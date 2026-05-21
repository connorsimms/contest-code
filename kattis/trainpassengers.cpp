#include <iostream>
using namespace std;

int main()
{
    int C, n; cin >> C >> n;

    long long cnt = 0;
    bool poss = true;
    for (int i = 0; i < n; ++i)
    {
        int l, e, s; cin >> l >> e >> s;
        cnt += e;
        cnt -= l;

        if (cnt > C) poss = false;
        if (cnt < 0) poss =  false;
        if (cnt < C && s > 0) poss = false;

        if (i == n - 1) {
            if (e != 0 || cnt != 0 || s != 0) poss = false;
        }
    }

    cout << (poss ? "possible\n" : "impossible\n");
}
