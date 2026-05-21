#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sum; cin >> sum;
    for (int a = 0; a <= 20; ++a)
    {
    for (int ma = 1; ma <= 3; ++ma)
    {
        for (int b = 0; b <= 20 ; ++b)
        {
        for (int mb = 1; mb <= 3; ++mb)
        {
            for (int c = 0; c <= 20; ++c)
            {
            for (int mc = 1; mc <= 3; ++mc)
            {
                if (a * ma + b * mb + c * mc == sum)
                {
                    if (a)
                    {
                        switch (ma)
                        {
                            case 1: cout << "single "; break;
                            case 2: cout << "double "; break;
                            case 3: cout << "triple "; break;
                        }
                        cout << a << '\n';
                    }

                    if (b)
                    {
                        switch (mb)
                        {
                            case 1: cout << "single "; break;
                            case 2: cout << "double "; break;
                            case 3: cout << "triple "; break;
                        }
                        cout << b << '\n';
                    }

                    if (c)
                    {
                        switch (mc)
                        {
                            case 1: cout << "single "; break;
                            case 2: cout << "double "; break;
                            case 3: cout << "triple "; break;
                        }
                        cout << c << '\n';
                    }

                    return 0;
                }
            }
            }
        }
        }
    }
    }

    cout << "impossible\n";
}
