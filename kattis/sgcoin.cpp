#include <bits/stdc++.h>
using namespace std;

long long H(long long previousHash, string &transaction, long long token) 
{
    long long v = previousHash;
    for (int i = 0; i < transaction.length(); i++) 
    {
        v = (v * 31 + transaction[i]) % 1000000007;
    }
    return (v * 7 + token) % 1000000007;
}


int main()
{
    long long h0; cin >> h0;

    string str = "charlie";

    long long token1 = 10'000'000 - (H(h0, str, 0) % 10'000'000); 

    cout << str << " " << token1 << '\n';

    long long h1 = H(h0, str, token1);

    long long token2 = 10'000'000 - (H(h1, str, 0) % 10'000'000);

    cout << str << " " << token2 << '\n';
}
