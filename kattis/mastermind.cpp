#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n; cin >> n;
    string a, b; cin >> a >> b;
    vector<int> countA(26);
    vector<int> countB(26);

    int r = 0;
    
    for (int i = 0 ; i < n; ++i)
    {
        if (a[i] == b[i]) ++r;
        ++countA[a[i] - 'A'];
        ++countB[b[i] - 'A'];
    }

    int s = 0;
    for (int i = 0 ; i < 26 ; ++i)
    {
        s += min(countA[i], countB[i]);
    }

    s -= r;
    
    cout << r << " " << s << '\n';
}
