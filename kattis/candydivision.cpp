#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<long long> friends; 

    long long N; cin >> N;

    for (long long i = 1 ; i * i <= N; ++i)
    {
        if (N % i) continue;

        friends.insert(i - 1);
        friends.insert(N / i - 1);
    }

    for (auto x: friends)
    {
        cout << x << " ";
    }
    cout << '\n';
}
