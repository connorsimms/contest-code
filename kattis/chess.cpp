#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    for(int i = 0 ; i < n ; ++i)
    {
	char l1, l2; int v1, v2;
	cin >> l1 >> v1 >> l2 >> v2;
	int x1 = l1 - 'A';
	int y1 = v1 - 1;
	int x2 = l2 - 'A';
	int y2 = v2 - 1;

	if(((x1 + y1) % 2) != ((x2 + y2) % 2))
	{
	    //cout << x1 << " " << x2 << " " << x2 << " " << y2 << '\n';
	    cout << "Impossible\n";
	    continue;
	}

	if(x1 == x2 && y1 == y2) { 
	    cout << 0 << " " << l1 << " " << v1 << '\n'; 
	    continue; 
	}
	
	int d11 = x1 - y1;
	int d12 = x1 + y1;

	int d21 = x2 - y2;
	int d22 = x2 + y2;

	if(d11 == d21 || d12 == d22) { 
	    cout << 1 << " " << l1 << " " << v1 << " " << l2 << " " << v2 << '\n';
	    continue;
	}

	char im1; int im2;
	for(int i = 0 ; i < 8 ; ++i)
	{
	    for(int j = 0 ; j < 8 ; ++j)
	    {
		if(i - j == d11 && i + j == d22)
		{
		    im1 = i + 'A';
		    im2 = j + 1;
		    break;
		}
		if(i + j == d12 && i - j == d21)
		{
		    im1 = i + 'A';
		    im2 = j + 1;
		    break;
		}
	    }
	}
	cout << 2 << " " << l1 << " " << v1 << " " << im1 << " " << im2 << " " << l2 << " " << v2 << '\n';
    }
}
