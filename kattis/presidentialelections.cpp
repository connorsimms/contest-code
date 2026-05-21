#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;

    vector<int> D;
    vector<int> C;

    vector<int> conv;
    int dels = 0;
    int winnable = 0;

    for (int i = 0 ; i < n ; ++i)
    {
        int d, c, f, u;
        cin >> d >> c >> f >> u;

        dels += d;

        int conv;

        if (c == f) 
        { 
            conv = (u == 0) ? -1 : u / 2 + 1; 
        }
        else if (c > f)
        {
            conv = (c - f > u) ? 0 : (u - (c - f)) / 2 + 1;
        }
        else 
        {
            conv = (f - c >= u) ? -1 : f - c + (u - (f - c)) / 2 + 1;
        }

        if (conv != -1)
        {
            winnable += d;
            D.push_back(d);
            C.push_back(conv);
        }
    }

    if (D.empty() && C.empty()) { cout << "impossible\n"; return 0; }

    if (winnable < dels / 2) { cout << "impossible\n"; return 0; }

    vector<int> ans(dels + 1, 1e9 + 1);

    ans[D[0]] = C[0]; 

    for (int i = 1 ; i < D.size(); ++i)
    {
        for (int j = dels; j - D[i] >= 0; --j)
        {
            if (ans[j - D[i]] == 1e9 + 1) continue; 

            ans[j] = min(ans[j], ans[j - D[i]] + C[i]);
        }

        ans[D[i]] = min(ans[D[i]], C[i]);
    }

    int res = 1e9 + 1;
    for (int d = dels / 2 + 1; d < dels + 1; ++d)
    {
        res = min(res, ans[d]); 
    }

    if (res == 1e9 + 1)
    {
        cout << "impossible\n";
    }
    else
    {
        cout << res << '\n'; 
    }
}
