#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, B; 

    auto cmp = [](const auto& p1, const auto& p2) 
    {
        return p1.first * p2.second < p1.second * p2.first;
    };

    while (cin >> N >> B && !(N == -1 && B == -1))
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        B -= N;

        for (int i = 0 ; i < N; ++i)
        {
            int x; cin >> x;
            pq.emplace(x, 1); // one box
        }

        while (B)
        {
            auto t = pq.top();

            pq.pop();

            pq.emplace(t.first, ++t.second);
            
            --B;
        }

        auto& [bestPop, bestBox] = pq.top();

        cout << bestPop / bestBox + (bestPop % bestBox != 0) << '\n';
    }
}
