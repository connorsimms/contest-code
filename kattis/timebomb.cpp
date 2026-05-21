#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    vector<string> digs = {{
        "***   * *** *** * * *** *** *** *** ***",
        "* *   *   *   * * * *   *     * * * * *",
        "* *   * *** *** *** *** ***   * *** ***",
        "* *   * *     *   *   * * *   * * *   *",
        "***   * *** ***   * *** ***   * *** ***"
    }};

    auto isDigit = [&](vector<string>& data, int i, int d) { 
        bool res = true;
        for (int r = 0; r < 5; ++r)
        {
            for (int c = 0; c < 3; ++c) 
            {
                if (data[r][4 * i + c] != digs[r][4 * d + c])
                    res = false;
            }
        }
        return res;
    };
        

    vector<string> inp; string line;
    for (int i = 0; i < 5; ++i) { getline(cin, line); inp.push_back(line); }

    vector<int> vals;

    for (int i = 0 ; i <= line.size() / 4; ++i) {
        bool valid = false;
        for (int d = 0 ; d < 10; ++d) {
            if(isDigit(inp, i, d)) {
                valid = true;
                vals.push_back(d);
            }
        }
        if (!valid) { cout << "BOOM!!\n"; return 0; }
    }

    int tot = accumulate(begin(vals), end(vals), 0);
    if (*(end(vals) - 1) % 2 != 0 || tot % 3 != 0) {
        cout << "BOOM!!\n";
    } else {
        cout << "BEER!!\n";
    }
}
