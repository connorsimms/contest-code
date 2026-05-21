#include <bits/stdc++.h>

using namespace std;

constexpr int inf = 1000000000;

int N;
long long ans = 0;

void generate(const vector<int>& fw, int fidx, int bw, int rw)
{
    //cout << fidx << " " << bw << " " << rw << '\n';
    if(fidx == N)
    {
	if(bw >= 200)
	{
	    ans += bw;
	}
	return;
    }

    if(bw >= 200)
    {
	int numRemaining = N - fidx;
	ans += (1LL << numRemaining) * bw + (1LL << (numRemaining - 1)) * rw;
    }
    else 
    {
	generate(fw, fidx + 1, bw + fw[fidx], rw - fw[fidx]);
	generate(fw, fidx + 1, bw, rw - fw[fidx]);
    }
}

int main()
{
    cin >> N;

    vector<int> fw(N);

    long long fullBasket = (1 << N) - 1;
    int fullWeight = 0;

    for(int i = 0 ; i < N ; ++i)
    {
    cin >> fw[i];
    fullWeight += fw[i];
    }

    generate(fw, 0, 0, fullWeight);

    cout << ans << '\n';
}
