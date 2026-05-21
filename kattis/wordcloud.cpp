#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    // P = 8 + ceil (40 * (occur - 4) / (maxOccur - 4) )
    int W, N;
    int tcase = 0;
    while (cin >> W >> N && !(W == 0 && N == 0))
    {
        vector<pair<string, int>> data;
        int maxO = 0;
        for (int i = 0 ; i < N ; ++i)
        {
            string word; cin >> word;
            int o; cin >> o;
            if (o < 5) { continue; }

            maxO = max(o, maxO);
            data.emplace_back(word, o);
        }

        sort(data.begin(), data.end());

        vector<long long> P(data.size());

        for (int i = 0 ; i < data.size(); ++i)
        {
            int occ = data[i].second;
            P[i] = 8 + (long long)ceil( (double)(40 * (occ - 4)) / (maxO - 4));
        }
        

        long long height = 0;
        long long currHeight = 0;
        long long currWidth = 0;
    // W = ceil( 9/16 * (# chars) * P )
        for (int i = 0 ; i < P.size() ; ++i)
        {
            string wrd = data[i].first;
            long long w = (long long)ceil( 9.0 / 16 * wrd.size() * P[i]);

            if (currWidth == 0) {
                currWidth += w;
                currHeight = max(currHeight, P[i]);
                continue;
            }

            if (currWidth + 10 + w == W) {
                currHeight = max(currHeight, P[i]);
                height += currHeight;
                currWidth = 0;
                currHeight = 0;
                continue;
            }

            if (currWidth + 10 + w < W) {
                currWidth += w + 10;
                currHeight = max(currHeight, P[i]);
                continue;
            } 

            if (currWidth + 10 + w > W) {
                height += currHeight;
                currWidth = w;
                currHeight = P[i];
            }
        }
        cout << "CLOUD " << ++tcase << ": " << height + currHeight << '\n';
    }
}
