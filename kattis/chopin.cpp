#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, string> m;
    m["A#"] = "Bb";
    m["Bb"] = "A#";
    m["C#"] = "Db";
    m["Db"] = "C#";
    m["D#"] = "Eb";
    m["Eb"] = "D#";
    m["F#"] = "Gb";
    m["Gb"] = "F#";
    m["G#"] = "Ab";
    m["Ab"] = "G#";
    string key, tone;
    int c = 0;
    while(cin >> key >> tone && !cin.eof())
    {
        ++c;
        cout << "Case " << c << ": ";  
        if (m.count(key)) { cout << m[key] << " " << tone << '\n';}
        else { cout  << "UNIQUE\n"; }
    }
}
