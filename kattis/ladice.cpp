#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, L; cin >> N >> L;

    vector<int> p(L + 1); 
    vector<long long> s(L + 1, 1);
    iota(p.begin(), p.end(), 0);

    auto find_set = [&](int a, auto& self) {
        if (a == p[a]) return a;
        p[a] = self(p[a], self);
        s[a] = s[p[a]];
        return p[a];
    };

    auto join_set = [&](int a, int b) {
        auto A = find_set(a, find_set);
        auto B = find_set(b, find_set);

        if (A == B) return;

        p[B] = A;
        s[A] += s[B];
        s[B] = s[A];
    };

    for (int i = 0 ; i < N; ++i)
    {
        int a, b; cin >> a >> b;

        auto A = find_set(a, find_set);
        auto B = find_set(b, find_set);
        
        if (s[A] > 0 || s[B] > 0)
        {
            cout << "LADICA\n";

            join_set(A, B);

            s[A]--;
        }
        else
        {
            cout << "SMECE\n";
        }
    }
}
