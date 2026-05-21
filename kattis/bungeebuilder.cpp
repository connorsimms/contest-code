#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{

    int n; cin >> n;

    vector<int> heights(n);

    for (int i = 0 ; i < n ; ++i)
    {
        cin >> heights[i];
    }

    stack<pair<int, int>> s;

    vector<int> left = heights;

    for (int i = 0 ; i < n ; ++i)
    {
        if (s.empty())
        {
            s.emplace(i, heights[i]);
            left[i] = heights[i];
            continue;
        }

        auto [idx, h] = s.top();

        if (heights[i] >= h)
        {
            for (int j = idx ; j < i ; ++j)
            {
                left[j] = h;
            }
            s.emplace(i, heights[i]);
            left[i] = heights[i];
        }
    }

    while (!s.empty()) { s.pop(); }

    vector<int> right = heights;
    for (int i = n - 1 ; i >= 0 ; --i)
    {
        if (s.empty())
        {
            s.emplace(i, heights[i]);
            right[i] = heights[i];
            continue;
        }

        auto [idx, h] = s.top();

        if (heights[i] >= h)
        {
            for (int j = i + 1 ; j < idx ; ++j)
            {
                right[j] = h;
            }
            s.emplace(i, heights[i]);
            right[i] = heights[i];
        }
    }

    int best = 0;

    //for (auto x : left)
    //{
    //    cout << x << " ";
    //}
    //cout << '\n';
    //for (auto x : right)
    //{
    //    cout << x << " ";
    //}
    //cout << '\n';

    for (int i = 0 ; i < n ; ++i)
    {
        best = max(best, max(left[i] - heights[i], right[i] - heights[i]));
    }
    
    cout << best << '\n';
}

