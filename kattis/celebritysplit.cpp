#include <bits/stdc++.h>

using namespace std;

unordered_map<long long, long long> setAData;
unordered_map<long long, long long> setBData;

void solveA(const vector<int>& set, vector<int> config, int idx)
{
    if(idx == set.size())
    {
	int total1{ 0 };
	int total2{ 0 };
	int total3{ 0 };
	for(int i = 0 ; i < set.size() ; ++i)
	{
	    switch(config[i])
	    {
	    case 1:
		total1 += set[i];
		break;
	    case 3:
		total2 += set[i];
		break;
	    case 2:
		total3 += set[i];
		break;
	    default:
		break;
	    }
	}
	int current = setAData[total1 - total2];
	setAData[total1 - total2] = max(current, total1 + total2);
	return;	
    }

    config[idx] = 1;
    solveA(set, config, idx + 1);
    config[idx] = 2;
    solveA(set, config, idx + 1);
    config[idx] = 3;
    solveA(set, config, idx + 1);
}

void solveB(const vector<int>& set, vector<int> config, int idx)
{
    if(idx == set.size())
    {
	int total1{ 0 };
	int total2{ 0 };
	int total3{ 0 };
	for(int i = 0 ; i < set.size() ; ++i)
	{
	    switch(config[i])
	    {
	    case 1:
		total1 += set[i];
		break;
	    case 3:
		total2 += set[i];
		break;
	    case 2:
		total3 += set[i];
		break;
	    default:
		break;
	    }
	}
	int current = setBData[total1 - total2];
	setBData[total1 - total2] = max(current, total1 + total2);
	return;	
    }

    config[idx] = 1;
    solveB(set, config, idx + 1);
    config[idx] = 2;
    solveB(set, config, idx + 1);
    config[idx] = 3;
    solveB(set, config, idx + 1);
}

int main()
{
    int N;
    while(cin >> N && N != 0)
    {
	setAData.clear();
	setBData.clear();

	if(N == 1)
	{
	    int x;
	    cin >> x;
	    cout << x << '\n';
	    continue;
	}

	long long total = 0;
	vector<int> setA(N / 2);
	vector<int> configA(N / 2);
	vector<int> setB(N - N / 2);
	vector<int> configB(N - N / 2);

	for(int i = 0 ; i < N / 2 ; ++i)
	{
	    cin >> setA[i];
	    total += setA[i];
	}

	for(int i = 0 ; i < N - N / 2; ++i)
	{
	    cin >> setB[i];
	    total += setB[i];
	}

	solveA(setA, configA, 0);
	solveB(setB, configB, 0);

	long long ans = 0;

	for(auto x: setAData)
	{
	    long long diff = x.first;

	    if(setBData.count(0 - diff) > 0)
	    {
		ans = max(ans, x.second + setBData[0 - diff]);
	    }
	}
	cout << total - ans << '\n';
    }
    return 0;
}
