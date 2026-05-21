#include <iostream>
#include <cmath>
#include <tuple>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    vector<pair<int,int>> jim;

    for (int i = 0 ; i < 10 ; ++i)
    {
        int u, r; cin >> u >> r;
        jim.emplace_back(u, r);
    }

    vector<int> o_ready(10);
    vector<pair<int,int>> o;
    for (int i = 0 ; i < 10 ; ++i)
    {
        int u, r; cin >> u >> r >> o_ready[i];
        o.emplace_back(u, r);
    }

    int time = 0;
    for (int cycle = 0 ; cycle < 3; ++cycle)
    {
        for(int m = 0 ; m < 10 ; ++m)
        {
            while (o_ready[m] + o[m].first + o[m].second <= time)
            {
                o_ready[m] += o[m].first + o[m].second;
            }

            if (time >= o_ready[m] + o[m].first) {
                o_ready[m] += o[m].first + o[m].second;
            }

            if (time >= o_ready[m]) {
                time = o_ready[m] + o[m].first;
                o_ready[m] += o[m].first + o[m].second;
            } 

            int jim_finish = time + jim[m].first;

            if (jim_finish > o_ready[m]) {
                o_ready[m] = jim_finish;
            }

            time += jim[m].first + jim[m].second;

            if (cycle == 2 && m == 9) { time -= jim[m].second; }
        }
    }
    cout << time << '\n';
}
