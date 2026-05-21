#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <sstream>
#include <functional>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;

        map<int, int, greater<int>> bids;
        map<int, int> asks;

        int a{-1}, b{-1}, s{-1};

        for (int i = 0 ; i < n ; ++i)
        {
            string type, junk; int size, price;
            cin >> type >> size >> junk >> junk >> price;

            if (type == "buy")
            {
                bids[price] += size;
            }
            else
            {
                asks[price] += size;
            }

            while (asks.begin()->first <= bids.begin()->first)
            {
                if (asks.empty() || bids.empty()) break;

                int amt = min(asks.begin()->second, bids.begin()->second);
                asks.begin()->second -= amt;
                bids.begin()->second -= amt;

                s = asks.begin()->first;

                if (!asks.begin()->second) { asks.erase(asks.begin()); }
                if (!bids.begin()->second) { bids.erase(bids.begin()); }
            }

            if (asks.empty()) a = -1;
            else a = asks.begin()->first;
            if (bids.empty()) b = -1;
            else b = bids.begin()->first;

            cout << (a == -1 ? "-" : to_string(a)) << " ";
            cout << (b == -1 ? "-" : to_string(b)) << " ";
            cout << (s == -1 ? "-" : to_string(s)) << "\n";
        }
    }
}
