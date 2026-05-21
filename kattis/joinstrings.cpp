#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<string> words(n);

    unordered_map<int, int> next;
    unordered_map<int, int> head;
    unordered_map<int, int> tail;

    for (int i = 0 ; i < n ; ++i)
    {
        cin >> words[i];
    }

    int start;

    for (int i = 0 ; i < n - 1; ++i)
    {
        int a, b; cin >> a >> b;

        if (!head[a]) head[a] = a; 
        if (!head[b]) head[b] = b;
        if (!tail[a]) tail[a] = a; 
        if (!tail[b]) tail[b] = b;

        if (!next[a]) next[a] = b;
        else next[tail[a]] = b;

        if (head[a]) head[b] = head[a];
        if (tail[b]) tail[a] = tail[b];

        if (i == n - 2) { start = a; }
    }

    int curr = start;

    while (curr)
    {
        cout << words[curr-1];

        curr = next[curr];
    }

    cout << '\n';
}

