#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    string line; cin >> line;
    stringstream ss{ line };
    vector<int> v(3); char dl;
    ss >> v[0] >> dl >> v[1] >> dl >> v[2];

    sort(v.begin(), v.end());

    vector<int> dm = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    vector<tuple<int,int,int>> cand;

    if (v[2] > 1000)
    {
        int y = v[2];
        if (y % 4 == 0) { dm[1]++; }
        if (y % 100 == 0) { dm[1]--; }
        if (y % 400 == 0) { dm[1]++; }
        v.pop_back();
        do { // m  d
            int m = v[0]; 
            int d = v[1]; 

            if (y < 2000 || y > 2999) { continue; }
            if (m < 1 || m > 12) { continue; }
            if (d < 1 || d > dm[m - 1] ) { continue; }

            cand.emplace_back(y, m, d);
        } while (next_permutation(v.begin(), v.end()));
    }
    else
    {
        do { // y  m  d
            int y = v[0]; 
            int m = v[1]; 
            int d = v[2]; 

            y += 2000;

            if (y % 4 == 0) { dm[1]++; }
            if (y % 100 == 0) { dm[1]--; }
            if (y % 400 == 0) { dm[1]++; }

            if (y < 2000 || y > 2999) { continue; }
            if (m < 1 || m > 12) { continue; }
            if (d < 1 || d > dm[m - 1] ) { continue; }

            if (y % 4 == 0) { dm[1]--; }
            if (y % 100 == 0) { dm[1]++; }
            if (y % 400 == 0) { dm[1]--; }

            cand.emplace_back(y, m, d);
        } while (next_permutation(v.begin(), v.end()));
    }

    if (cand.empty())
    {
        cout << line << " is illegal\n";
    }
    else
    {
        auto [y,m,d] = cand[0];
        string M = to_string(m);
        string D = to_string(d);

        if (M.size() == 1) { M.insert(0, "0"); }
        if (D.size() == 1) { D.insert(0, "0"); }

        cout << y << '-' << M << '-' << D << '\n';
    }
}
