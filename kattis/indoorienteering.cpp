#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> subsets1;
vector<vector<int>> subsets2;

int N;

void genSubsets(int idx, vector<int> bucket1, vector<int> bucket2, int size1, int size2)
{
    if(bucket1.size() == size1 && bucket2.size() == size2)
    {
	subsets1.push_back(bucket1);	
	subsets2.push_back(bucket2);	
	return;
    }

    if(bucket1.size() < size1)
    {
	bucket1.push_back(idx);
	genSubsets(idx + 1, bucket1, bucket2, size1, size2);
	bucket1.pop_back();
    }

    if(bucket2.size() < size2)
    {
	bucket2.push_back(idx);
	genSubsets(idx + 1, bucket1, bucket2, size1, size2);
	bucket2.pop_back();
    }
}

void solve(const vector<vector<long long>>& dist, vector<int> order, vector<unordered_set<long long>>& endDist, bool type)
{
    do {
	if(order.size() == 0) { return; }
	long long total = 0;
	int from = order[0];
	for(int i = 1 ; i < order.size() ; ++i)
	{
	    int to = order[i];
	    long long d = dist[from][to];
	    total += d;
	    from = to;
	}
	endDist[order.back()].insert(total + dist[order.front()][0]);
    } while(next_permutation(order.begin(), order.end()));
}

int main()
{
    long long L;
    cin >> N >> L;
    
    vector<vector<long long>> dist(N, vector<long long>(N));

    for(int i = 0 ; i < N ; ++i)
    {
	for(int j = 0 ; j < N ; ++j)
	{
	    cin >> dist[i][j];
	}
    }

    if(N == 2)
    {
	if(2 * dist[0][1] == L)
	{
	    cout << "possible\n";
	    return 0;
	} else 
	{
	    cout << "impossible\n";
	    return 0;
	}
    }

    vector<int> bucket1{};
    int size1 = (N - 1) / 2;
    vector<int> bucket2{};
    int size2 = (N - 1) - size1;

    genSubsets(1, bucket1, bucket2, size1, size2);

    for(int partIdx = 0 ; partIdx < subsets1.size() ; ++partIdx)
    {
	vector<unordered_set<long long>> s1(N);
	solve(dist, subsets1[partIdx], s1, true); 
	vector<unordered_set<long long>> s2(N);
	solve(dist, subsets2[partIdx], s2, false); 

	for(int i = 0 ; i < subsets1[partIdx].size(); ++i)
	{
	    int end1 = subsets1[partIdx][i];

	    for(int j = 0 ; j < subsets2[partIdx].size(); ++j)
	    {
		int end2 = subsets2[partIdx][j];

		for(auto dist1: s1[end1])
		{
		    long long total = dist1;
		    total += dist[end1][end2];
		    if(s2[end2].count(L - total) > 0)
		    {
			cout << "possible\n";
			return 0;
		    }
		}
	    }
	}
    }

    cout << "impossible\n";
    return 0;
}

