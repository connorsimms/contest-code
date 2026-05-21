#include <iostream>
using namespace std;

int main()
{
    int N, P; cin >> N >> P;

    int ans = 0;
    int sum = 0;

    for ( int i =  0 ; i < N ; ++i)
    {
        int x; cin >> x;
        x -= P;

        sum += x;
        ans = ans > sum ? ans : sum;
        if (sum < 0) sum = 0;
    }

    cout << ans << '\n';
}
