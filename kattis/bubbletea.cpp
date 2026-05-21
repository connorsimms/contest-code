#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> tea(N);
    for(int i = 0 ; i < N ; ++i)
    {
	cin >> tea[i];
    }
    int M; cin >> M;
    vector<int> top(M);
    for(int i = 0 ; i < M ; ++i)
    {
	cin >> top[i];
    }

    int minPrice = 1e9;

    for(int i = 0 ; i < N; ++i)
    {
	int K; cin >> K;
	int tp = tea[i];
	for(int j = 0 ; j < K; ++j)
	{
	    int tpi; cin >> tpi; --tpi;
	    int tpp = top[tpi];
	    minPrice = min(minPrice, tp + tpp);
	}
    }

    int X; cin >> X;
    cout << max(0, X / minPrice - 1) << '\n';
}
