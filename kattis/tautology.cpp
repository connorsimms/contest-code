#include <bits/stdc++.h>

using namespace std;

enum SymbolBit {
    pb,
    qb,
    rb,
    sb,
    tb,
    symbol_size
};

unordered_map<char, bool> isVar {{
    {'p', true},
    {'q', true},
    {'r', true},
    {'s', true},
    {'t', true}
}};

unordered_map<char, bool> isUnary {{
    {'N', true},
}};

unordered_map<char, bool> isBinary {{
    {'K', true},
    {'A', true},
    {'C', true},
    {'E', true}
}};

bool evaluate(const string& wff, int& idx, unordered_map<char,bool>& varValues)
{
    char symbol = wff[idx++];

    if(isVar[symbol])
    {
	return varValues[symbol];
    }

    if(isUnary[symbol])
    {
	return !evaluate(wff, idx, varValues);
    }

    if(isBinary[symbol])
    {
	bool op1 = evaluate(wff, idx, varValues);
	bool op2 = evaluate(wff, idx, varValues);

	switch(symbol)
	{
	    case 'K': return op1 && op2;
	    case 'A': return op1 || op2;
	    case 'C': return !op1 || op2;
	    case 'E': return op1 == op2;
	    default: return false;
	}
    }

    return false;
}

int main()
{
    string input;
    while(cin >> input && input != "0")
    {
	bool taut = true;
	for(int value = 0 ; value < (1 << symbol_size) ; ++value)
	{
	    string word = input;	    

	    bool p, q, r, s, t;
	    p = ((value & (1 << pb)) != 0);
	    q = ((value & (1 << qb)) != 0);
	    r = ((value & (1 << rb)) != 0);
	    s = ((value & (1 << sb)) != 0);
	    t = ((value & (1 << tb)) != 0);

	    unordered_map<char, bool> varValue {{
		{'p', p},
		{'q', q},
		{'r', r},
		{'s', s},
		{'t', t}
	    }};

	    int idx = 0;
	    bool res = evaluate(word, idx, varValue);
	    if(!res) { taut = false; }
	}
	if(taut)
	{
	    cout << "tautology\n";
	} else { cout << "not\n"; }
    }
}
