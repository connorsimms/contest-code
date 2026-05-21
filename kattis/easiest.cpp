#include <bits/stdc++.h>
using namespace std;

int main()
{
    string N;
    while (cin >> N && N != "0")
    {
        int sum = 0;
        for (auto& x: N)
        {
            sum += x - '0';
        }

        int n = stoi(N);

        int x = 11;
        while (true)
        {
            int y = x * n;

            string Y = to_string(y);

            int sumY = 0;
            for (auto& z: Y)
            {
                sumY += z - '0';
            }

            if (sumY == sum)
            {
                cout << x << '\n';
                break;
            }

            ++x;
        }
    }
}
