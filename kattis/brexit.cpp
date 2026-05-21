#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> minutes(n + 1);
    std::vector<std::vector<int>> incomingEdges(n + 1);
    std::vector<int> outgoingDegree(n + 1);
    for(int i = 1 ; i <= n ; ++i)
    {
	int min, numDep;
	std::cin >> min >> numDep;
	minutes[i] = min;
	for(int j = 0 ; j < numDep ; ++j)
	{
	    int dep;
	    std::cin >> dep;
	    outgoingDegree[i]++;
	    incomingEdges[dep].push_back(i);
	}
    }

    auto isGreater = [&](int x, int y) -> bool
    {
	return minutes[x] < minutes[y];
    };

    std::priority_queue<int, std::vector<int>, decltype(isGreater)> pq(isGreater);
    for(int i = 1 ; i <= n ; ++i)
    {
	if(outgoingDegree[i] == 0)
	{
	    pq.push(i);
	}
    }

    std::vector<int> ans;

    while(!pq.empty())
    {
	int f = pq.top();
	ans.push_back(f);
	pq.pop();
	for(auto x: incomingEdges[f])
	{
	    if(--outgoingDegree[x] == 0)
	    {
		pq.push(x);
	    }
	}
    }

    int longest = 0;

    for(int i = 0 ; i < ans.size() ; ++i)
    {
	longest = std::max(longest, minutes[ans[i]] + i);
    }
    std::cout << longest << '\n';
    return 0;
}
