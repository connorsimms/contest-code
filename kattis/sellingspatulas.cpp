#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        vector<int> tl(1500, -8);

        for (int i = 0 ; i < n ; ++i)
        {
            int m; string p;
            cin >> m >> p;
            stringstream ss{ p }; int mul = 1;
            int d; char del; int c;

            if (p[0] == '-') { ss >> del; mul = -1; }

            ss >> d >> del >> c;

            int prof = (d * 100 + c) * mul;

            tl[m] += prof;
        }

        int max = -8;
        int sum = 0;
        int start = 0;
        int end = 0;
        int bestStart = 0;
        int bestEnd = 0;

        for (int i = 0 ; i < 1500; ++i)
        {
            sum += tl[i];
            end = i;

            if (sum <= 0)
            {
                start = i + 1;
                sum = 0;
            }
            else
            {
                if (sum == max)
                {
                    if (end - start < bestEnd - bestStart)
                    {
                        bestStart = start;
                        bestEnd = end;
                    }
                }
                else if (sum > max)
                {
                    max = sum;
                    bestStart = start;
                    bestEnd = end;
                }
            }
        }

        if (max <= 0) { cout << "no profit\n"; }
        else
        {
            cout << max / 100 << ".";
            if (max % 100 < 10) { cout << "0"; }
            cout << max % 100;
            cout << " " << bestStart << " " << bestEnd << '\n';
        }
    }
}
