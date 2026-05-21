#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int T; cin >> T;

    while (T--)
    {
        int n; cin >> n;

        vector<string> names;
        vector<string> infos;
        vector<int> indices(n);

        string junk;
        getline(cin, junk); // junk
        for (int i = 0 ; i < n ; ++i)
        {
            indices[i] = i;
            string line;
            getline(cin, line);

            istringstream input{ line };

            string name; getline(input, name, ':');

            input.ignore(2, ' ');

            string item;
            string info;
            while (getline(input, item, '-'))
            {
                if (item.empty()) continue;

                info.push_back(item[0]);
            }

            getline(input, junk);

            reverse(info.begin(), info.end());

            names.push_back(name);
            infos.push_back(info);
        }

        iota(indices.begin(), indices.end(), 0);

        auto comp = [&](const auto& A, const auto& B)
        {
            if (infos[A] == infos[B]) return names[A] < names[B];

            auto a = infos[A].begin();
            auto b = infos[B].begin();

            while (a != infos[A].end() && b != infos[B].end())
            {
                if (*a != *b)
                {
                    return *a > *b;    
                }

                ++a; ++b;
            }

            while (a != infos[A].end())
            {
                if (*a != 'm') return *a == 'u'; 

                ++a;
            }

            while (b != infos[B].end())
            {
                if (*b != 'm') return *b == 'l'; 

                ++b;
            }

            return names[A] < names[B];
        };

        sort(indices.begin(), indices.end(), comp);

        for (auto x : indices)
        {
            cout << names[x] << '\n';
        }
        cout << "==============================\n";
    }
}
