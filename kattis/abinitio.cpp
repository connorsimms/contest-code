#include <bits/stdc++.h>

using namespace std;

int main()
{
    int V, E, Q; cin >> V >> E >> Q;

    vector<vector<bool>> adj(4001, vector<bool>(4001, false));

    for (int i = 0 ; i < E; ++i)
    {
        int a, b; cin >> a >> b;

        adj[a][b] = true;
    }

    bool transpose = false;
    bool complement = false;

    for (int i = 0 ; i < Q; ++i)
    {
        int q; cin >> q;
        switch (q)
        {
            case 1:
            {
                V++;
                for (int r = 0 ; r < V; ++r) adj[r][V-1] = complement;
                for (int c = 0 ; c < V; ++c) adj[V-1][c] = complement;
                break;
            }
            case 2:
            {
                int x, y; cin >> x >> y;
                if (transpose) adj[y][x] = !complement;
                else adj[x][y] = !complement;
                break;
            }
            case 3:
            {
                int x; cin >> x;
                for (int r = 0 ; r < V; ++r) adj[r][x] = complement;
                for (int c = 0 ; c < V; ++c) adj[x][c] = complement;
                break;
            }
            case 4:
            {
                int x, y; cin >> x >> y;
                if (transpose) adj[y][x] = complement;
                else adj[x][y] = complement;
                break;
            }
            case 5:
            {
                transpose = !transpose;
                break;
            }
            case 6:
            {
                complement = !complement;
                break;
            }
        }
    }

    cout << V << '\n';

    for (int i = 0 ; i < V; ++i)
    {
        long long pow = 1; int size = 0; long long sum = 0;
        
        for (int j = 0 ; j < V; ++j)
        {
            if (i == j) continue; 

            const auto& val = transpose ? adj[j][i] : adj[i][j];

            if (val == !complement)
            {
                ++size;
                sum += (j * pow) % 1000000007;
                pow *= 7;

                sum %= 1000000007;
                pow %= 1000000007;
            }
        }

        cout << size << " " << sum << '\n';
    }
}

