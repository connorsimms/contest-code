#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> p(200'002);
    vector<long long> sum(200'002);
    vector<long long> s(200'002, 1);

    auto find_set = [&](int a, auto&& self) {
        if (a == p[a]) return a;

        p[a] = self(p[a], self);

        return p[a];
    };

    auto join_set = [&](int a, int b) {
        auto A = find_set(a, find_set);
        auto B = find_set(b, find_set);

        if (A == B) return;

        p[B] = A;
        s[A] += s[B];
        sum[A] += sum[B];
    };

    int n, m;

    while (cin >> n >> m)
    {
        iota(p.begin() + 1,         p.begin() + 1 + n,          100'001);
        iota(p.begin() + 100'001,   p.begin() + 100'001 + n,    100'001);

        iota(sum.begin() + 1,       sum.begin() + n, 1);
        iota(sum.begin() + 100'001, sum.begin() + 100'001 + n, 1);

        fill(s.begin() + 1, s.begin() + 100'001 + n, 1);

        for (int i = 0 ; i < m; ++i)
        {
            int cmd; cin >> cmd;
            switch (cmd)
            {
                case 1:
                {
                    int a, b; cin >> a >> b;
                    join_set(a, b);
                    break;
                }
                case 2:
                {
                    int a, b; cin >> a >> b;
                    auto A = find_set(a, find_set);
                    auto B = find_set(b, find_set);

                    if (A == B) break;

                    p[a] = B;
                    --s[A]; ++s[B];
                    sum[A] -= a; sum[B] += a;

                    break;
                }
                case 3:
                {
                    int a; cin >> a;
                    
                    auto A = find_set(a, find_set); 

                    cout << s[A] << " " << sum[A] << '\n';

                    break;
                }
            }
        }
    }
}
