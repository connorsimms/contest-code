#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    int n; cin >> n;

    unordered_map<string, int> freq;

    int best = 0;

    for (int i = 0 ; i < n ; ++i)
    {
        vector<int> courses(5);

        for (auto& x : courses)
        {
            cin >> x;
        }

        sort(courses.begin(), courses.end());

        string comb = "";
        for (auto x : courses)
        {
            comb += to_string(x);
        }

        ++freq[comb];

        if (freq[comb] > best)
        {
            best = freq[comb];
        }
    }

    int ans = 0;
    for (auto [_, num]: freq)
    {
        if (num == best)
        {
            ans += num;
        }
    }

    cout << ans << '\n';
}
