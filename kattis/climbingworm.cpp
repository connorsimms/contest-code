#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, h; cin >> a >> b >> h;
    if((h % (a - b)) == 0) {
	cout << h / (a - b) << '\n';
    } else {
	cout << (h / (a - b)) + 1 << '\n';
    }
}
