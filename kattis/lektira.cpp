#include <bits/stdc++.h>
using namespace std;

int main()
{
    string word; cin >> word;

    string best = "";

    for (int i = 1 ; i < word.size(); ++i)
    {
        for (int j = i + 1 ; j < word.size(); ++j)
        {
            string w1 = word.substr(0, i);
            string w2 = word.substr(i, j - i);
            string w3 = word.substr(j);

            reverse(w1.begin(), w1.end());
            reverse(w2.begin(), w2.end());
            reverse(w3.begin(), w3.end());

            string res = w1 + w2 + w3;

            if (best == "" || res < best) best = res;
        }
    }

    cout << best << '\n';
}
