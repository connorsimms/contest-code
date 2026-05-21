#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> ascii = 
    {
        "xxxxx"
        "x...x"
        "x...x"
        "x...x"
        "x...x"
        "x...x"
        "xxxxx"
        ,
        "....x"
        "....x"
        "....x"
        "....x"
        "....x"
        "....x"
        "....x"
        ,
        "xxxxx"
        "....x"
        "....x"
        "xxxxx"
        "x...."
        "x...."
        "xxxxx"
        ,
        "xxxxx"
        "....x"
        "....x"
        "xxxxx"
        "....x"
        "....x"
        "xxxxx"
        ,
        "x...x"
        "x...x"
        "x...x"
        "xxxxx"
        "....x"
        "....x"
        "....x"
        ,
        "xxxxx"
        "x...."
        "x...."
        "xxxxx"
        "....x"
        "....x"
        "xxxxx"
        ,
        "xxxxx"
        "x...."
        "x...."
        "xxxxx"
        "x...x"
        "x...x"
        "xxxxx"
        ,
        "xxxxx"
        "....x"
        "....x"
        "....x"
        "....x"
        "....x"
        "....x"
        ,
        "xxxxx"
        "x...x"
        "x...x"
        "xxxxx"
        "x...x"
        "x...x"
        "xxxxx"
        ,
        "xxxxx"
        "x...x"
        "x...x"
        "xxxxx"
        "....x"
        "....x"
        "xxxxx"
        ,
        "....."
        "..x.."
        "..x.."
        "xxxxx"
        "..x.."
        "..x.."
        "....."
    };

    unordered_map<string, string> val;
    unordered_map<char, string> str;
    for (int i = 0 ; i < ascii.size() - 1; ++i)
    {
        val[ascii[i]] = to_string(i);
        str[(char)('0' + i)] = ascii[i];
    }
    val[ascii[ascii.size() - 1]] = "-1";
    
    string line;
    getline(cin, line);

    vector<string> data((line.size() + 1) / 6, "");

    for (int j = 0 ; j < line.size(); j += 6)
    {
        data[j/6] += line.substr(j, 5);
    }

    for (int i = 0 ; i < 6 ; ++i)
    {
        getline(cin, line);
        
        for (int j = 0 ; j < line.size(); j += 6)
        {
            data[j/6] += line.substr(j, 5);
        }
    }

    string a = "", b = "";
    bool swi = false;

    for (auto x : data)
    {

        if (val[x] == "-1") {swi = true; continue; }

        if (swi) { b += val[x]; }
         else { a += val[x]; }
    }

    int sum = stoi(a) + stoi(b);

    string res = to_string(sum);

    for (int i = 0 ; i < 7; ++i)
    {
        for (int j = 0 ; j < res.size(); ++j)
        {
            cout << str[res[j]].substr(5 * i, 5);
            if (j < res.size() - 1) { cout << '.'; }
        }
        cout << '\n';
    }

    cout << '\n';
}
