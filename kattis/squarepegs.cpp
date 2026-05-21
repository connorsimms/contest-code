#include <bits/stdc++.h>
using namespace std;

int main()
{
    // s sqrt(2) < 2r
    // 2 s^2 < 4r^2
    // s * s < 2 * r * r

    size_t N, M, K; cin >> N >> M >> K;

    deque<int> p; 
    deque<int> r;

    for (size_t i = 0 ; i < N; ++i) 
    {
        int x; cin >> x;
        p.push_back(2 * x * x);
    }

    for (size_t i = 0 ; i < M; ++i) 
    {
        int x; cin >> x;
        r.push_back(2 * x * x);
    }

    for (size_t i = 0 ; i < K; ++i) 
    {
        int s; cin >> s;
        r.push_back(s * s);
    }

    sort(p.begin(), p.end());
    sort(r.begin(), r.end());

    int ans = 0;

    while (!p.empty() && !r.empty())
    {
        auto hr = r.front();
        auto pr = p.front();

        if (hr < pr)
        {
            ++ans; r.pop_front(); p.pop_front();
        }
        else
        {
            p.pop_front();
        }
    }

    cout << ans << '\n';
}
