#include <bits/stdc++.h>

using namespace std;

vector<int> getFactors(int x)
{
    vector<int> res;
    for(int i = 1 ; i <= x / 2 ; ++i)
    {
	if(x % i == 0)
	{
	    res.push_back(i);
	}
    }
    return res;
}

bool isAnagram(string w1, string w2)
{
    vector<int> a1(26);
    vector<int> a2(26);

    for(auto c: w1)
    {
	++a1[c - 'a'];	
    }

    for(auto c: w2)
    {
	++a2[c - 'a'];	
    }

    bool res = true;
    for(int i = 0 ; i < 26 ; ++i)
    {
	if(a1[i] != a2[i])
	{
	    res = false;
	    break;
	}
    }
    return res;
}

int main()
{
    string word;
    cin >> word;

    auto factors = getFactors(word.size());

    for(auto len: factors)
    {
	bool valid = true;
	string firstWord = word.substr(0, len);
	for(int begin = len; (begin + len <= word.size()) && valid; begin += len)
	{
	    bool res = isAnagram(firstWord, word.substr(begin, len));
	    if(!res)
	    {
		valid = false;
		break;
	    }
	}
	if(valid)
	{
	    cout << firstWord << '\n';
	    return 0;
	}
    }
    cout << "-1\n";
}
