#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char, int> val;
    val['A'] = 11;
    val['K'] = 4;
    val['Q'] = 3;
    val['J'] = 2;
    val['T'] = 10;
    val['9'] = 0;
    val['8'] = 0;
    val['7'] = 0;

    unordered_map<char, int> dom;
    dom['J'] = 18;
    dom['9'] = 14;

    int N; cin >> N;
    char B; cin >> B;

    int sum = 0;
    for(int i = 0 ; i < 4 * N ; ++i)
    {
	char n, s; cin >> n >> s;
	sum += val[n] + (s == B) * dom[n]; 
    }

    cout << sum << '\n';
}
