#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    size_t A = 0;
    size_t B = 0;
    bool found = false;
    for (size_t i = 0 ; i < a.size(); ++i)
    {
        for (size_t j = 0 ; j < b.size(); ++j)
        {
            if (a[i] == b[j]) { A = i; B = j; found = true; break; }
        }
        if (found) break;
    }

    string out(a.size() * b.size(), '.');

    for (size_t i = 0 ; i < a.size(); ++i)
    {
        out[a.size() * B + i] = a[i];
    }

    for (size_t i = 0 ; i < b.size(); ++i)
    {
        out[a.size() * i + A] = b[i];
    }

    for (int i = 0 ; i < b.size(); ++i)
    {
        cout << out.substr(a.size() * i, a.size()) << '\n';
    }
}
