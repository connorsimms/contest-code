#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;

    vector<long long> values(7);
    for (int i = 1 ; i <= 6; ++i) cin >> values[i];

    vector<vector<int>> v(7, vector<int>(N + 1));

    string types(N + 1, ' '); 

    for (int i = 1 ; i <= N; ++i)
    {
        cin >> types[i];

        int id = types[i] - '0';

        for (int j = i; j < N + 1; j += (j & -j))
        {
            ++v[id][j];
        }
    }

    for (int i = 0 ; i < Q; ++i)
    {
        int q; cin >> q;

        switch (q)
        {
            case 1:
            {
                int k, p; cin >> k >> p;

                int id = types[k] - '0';

                for (int j = k; j < N + 1; j += (j & -j))
                {
                    --v[id][j];
                }

                for (int j = k; j < N + 1; j += (j & -j))
                {
                    ++v[p][j];
                }

                types[k] = '0' + p;

                break;
            }
            case 2:
            {
                int p, v; cin >> p >> v;

                values[p] = v;

                break;
            }
            case 3:
            {
                int l, r; cin >> l >> r;

                long long sum = 0;
                for (int id = 1 ; id <= 6; ++id)
                {
                    int count = 0;
                    for (int j = r; j > 0; j -= (j & -j))
                    {
                        count += v[id][j];
                    }
                    for (int j = l - 1; j > 0; j -= (j & -j))
                    {
                        count -= v[id][j];
                    }
                    sum += count * values[id];
                }

                cout << sum << '\n';

                break;
            }
        }
    }
}
