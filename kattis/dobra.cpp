#include <bits/stdc++.h>
using namespace std;

int main()
{
    string word; cin >> word;

    unordered_map<char, bool> isVowel;
    unordered_map<char, bool> isCons;

    isVowel['A'] = isVowel['E'] = isVowel['I'] = isVowel['O'] = isVowel['U'] = true;

    for (char a = 'A'; a <= 'Z'; ++a)
    {
        isCons[a] = !isVowel[a];
    }

    long long ansWithL = 0;
    long long ansNoL = 0;

    auto gen = [&](auto& str, int idx, long long noL, long long withL, auto&& self) -> void
    {
        if (idx == str.size())
        {
            ansWithL += withL;
            ansNoL += noL;
            return;
        }

        if (str[idx] != '_')
        {
            self(str, idx + 1, noL, withL, self);
        }
        else
        {
            bool canVowel = true;

            bool b1 = idx - 2 >= 0 && isVowel[str[idx - 2]];
            bool b2 = idx - 1 >= 0 && isVowel[str[idx - 1]];
            bool b3 = idx + 1 < str.size() && isVowel[str[idx + 1]];
            bool b4 = idx + 2 < str.size() && isVowel[str[idx + 2]];

            if (b1 && b2) canVowel = false;
            if (b2 && b3) canVowel = false;
            if (b3 && b4) canVowel = false;

            if (canVowel)
            {
                str[idx] = 'A';
                self(str, idx + 1, noL * 5, withL * 5, self);
            }

            bool canCons = true;

            b1 = idx - 2 >= 0 && isCons[str[idx - 2]];
            b2 = idx - 1 >= 0 && isCons[str[idx - 1]];
            b3 = idx + 1 < str.size() && isCons[str[idx + 1]];
            b4 = idx + 2 < str.size() && isCons[str[idx + 2]];

            if (b1 && b2) canCons = false;
            if (b2 && b3) canCons = false;
            if (b3 && b4) canCons = false;

            if (canCons)
            {
                str[idx] = 'B';
                self(str, idx + 1, noL * 20, withL * 21, self);
            }

            str[idx] = '_';
        }
    };

    if (word.find('L') == -1) gen(word, 0, 1, 1, gen);
    else gen(word, 0, 0, 1, gen);

    cout << ansWithL - ansNoL << '\n';
}
