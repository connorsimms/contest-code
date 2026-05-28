#include <bits/stdc++.h>

using namespace std;

class UnionFind {
private:
  vector<int> prnt, rank, size;
  int numSets;

public:
  UnionFind(int N) : prnt(N, 0), rank(N, 0), size(N, 1), numSets(N) {
    iota(prnt.begin(), prnt.end(), 0);
  }

  int findSet(int i) { return (prnt[i] == i) ? i : (prnt[i] = find(prnt[i])); }

  bool sameSet(int i, int j) { return find(i) == find(j); }

  int numDisjoint() { return numSets; }

  int sizeOf(int i) { return size[find(i)]; }

  void unionSet(int i, int j) {
    if (sameSet(i, j))
      return;

    int x = findSet(i);
    int y = findSet(j);

    if (rank[x] > rank[y])
      swap(x, y);

    prnt[x] = y;
    if (rank[x] == rank[y])
      ++rank[y];

    size[y] += size[x];
    --numSets;
  }
};
