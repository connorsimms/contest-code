#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int x; 

    while (cin >> x && x != 0)
    {
        string junk;
        std::getline(cin, junk);

        string S, P, C;
        getline(cin, S);
        getline(cin, P);
        getline(cin, C);

        int n = (int) C.size();

        int d = (int)(pow(n, 1.5) + x) % n;

        string M(C.size(), ' ');

        M[d] = P[S.find(C[d])];

        int known = d;

        while (true)
        {
            int j = (known - 1 + n) % n;

            if (M[j] != ' ') break;

            std::size_t pos = S.find(C[j]) ^ S.find(M[known]);

            M[j] = P[pos];

            known = j;
        }

        cout << M << '\n';
    }
}
