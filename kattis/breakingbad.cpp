#include <bits/stdc++.h>

using namespace std;

bool colorDFS(const vector<vector<int>>& adj, vector<int>& color, int at, int c)
{
    if(color[at] == 0)
    {
	color[at] = c; 
    } else if(color[at] == 3 - c)
    {
	return false;
    } else {
	return true;	
    }

    for(auto n: adj[at])
    {
	if(!colorDFS(adj, color, n, 3 - c))
	{
	    return false;
	}
    }

    return true;
}

int main()
{
    int N;
    cin >> N;

    unordered_map<string, int> itemInt;
    vector<string> item(N);
    vector<vector<int>> adj(N);
    vector<int> colorArr(N);

    for(int i = 0 ; i < N ; ++i)
    {
	cin >> item[i];
	auto x = item[i];
	itemInt[x] = i;
    }

    int M;
    cin >> M;

    for(int i = 0 ; i < M ; ++i)
    {
	string item1, item2;
	cin >> item1 >> item2;
	int id1 = itemInt[item1];
	int id2 = itemInt[item2];

	adj[id1].push_back(id2);
	adj[id2].push_back(id1);
    }

    for(int i = 0 ; i < N ; ++i)
    {
	if(colorArr[i] == 0)
	{
	    if(!colorDFS(adj, colorArr, i, 1))
	    {
		cout << "impossible\n";
		return 0;
	    }
	}
    }

    for(int i = 0 ; i < N ; ++i)
    {
	if(colorArr[i] == 1)
	{
	    cout << item[i] << " ";
	}
    }
    cout << '\n';

    for(int i = 0 ; i < N ; ++i)
    {
	if(colorArr[i] == 2)
	{
	    cout << item[i] << " ";
	}
    }
    cout << '\n';
}
