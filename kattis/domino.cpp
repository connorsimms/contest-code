using namespace std;

constexpr long long inf = 8000000000;

int N, K;

long long ans = -1;

enum Direction {
    hor,
    ver,
};

void solve(const vector<tuple<int,int,int,bool>>& dominoes, vector<bool>& covered, int dom_idx, int k_left, long long sum)
{
    if(k_left == 0)
    {
	ans = max(ans, sum);
	return;
    }

    if(dom_idx == dominoes.size())
    {
	return;
    }

    auto dom = dominoes[dom_idx];
    int value = get<0>(dom);
    int row = get<1>(dom);
    int col = get<2>(dom);
    bool dir = (get<3>(dom) == hor);

    if(sum + k_left * value <= ans)
    {
	return;
    }

    int row2, col2;
    
    if(dir)
    {
	row2 = row;
	col2 = col + 1;
    } else {
	row2 = row + 1;
	col2 = col;
    }

    if(!covered[N * row + col] && !covered[N * row2 + col2])
    {
	covered[N * row + col] = true;
	covered[N * row2 + col2] = true;
	solve(dominoes, covered, dom_idx + 1, k_left - 1, sum + value);
	covered[N * row + col] = false;
	covered[N * row2 + col2] = false;
    }

    solve(dominoes, covered, dom_idx + 1, k_left, sum); // did not use dom-idx
}
int main()
{
    cin >> N >> K;

    vector<vector<int>> grid(N, vector<int>(N));
    vector<bool> covered(N * N);

    long long total = 0;

    for(int i = 0 ; i < N ; ++i)
    {
	for(int j = 0 ; j < N ; ++j)
	{
	    cin >> grid[i][j];
	    total += grid[i][j];
	}
    }

    vector<tuple<int,int,int,bool>> domVec;

    for(int i = 0 ; i < N ; ++i) // horizontal dominoes
    {
	for(int j = 0 ; j < N - 1 ; ++j)
	{
	    int sum = grid[i][j] + grid[i][j + 1];
	    domVec.emplace_back(sum, i, j, hor);
	}
    }

    for(int i = 0 ; i < N - 1; ++i) // vert dominoes
    {
	for(int j = 0 ; j < N; ++j)
	{
	    int sum = grid[i][j] + grid[i + 1][j];
	    domVec.emplace_back(sum, i, j, ver);
	}
    }

    sort(domVec.rbegin(), domVec.rend());

    solve(domVec, covered, 0, K, 0);

    cout << total - ans << '\n';
}
