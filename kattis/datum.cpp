#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    vector<int> dm = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> wd = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    int j1 = 4; // thurs

    int d, m; cin >> d >> m;
    d--;
    m--;

    int days = accumulate(begin(dm), begin(dm) + m, 0);
    days += d + 4;

    days %= 7;

    cout << wd[days] << '\n';
}
