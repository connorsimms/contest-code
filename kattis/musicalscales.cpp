#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<string> notes = {"A","A#","B","C","C#","D","D#","E","F","F#","G","G#"};
    unordered_map<string, int> majors;

    vector<int> mdx = {2, 2, 1, 2, 2, 2, 1};

    int sz = (int)notes.size();

    for (int i = 0 ; i < sz; ++i)
    {
        majors[notes[i]] = 0;
    }

    for (int i = 0 ; i < sz; ++i)
    {
        majors[notes[i]] |= (1 << i);

        int dx = 0;
        for(int j = 0 ; j < mdx.size(); ++j)
        {
            dx += mdx[j];
            int nidx = (i + dx) % sz;
            majors[notes[nidx]] |= (1 << i);
        }
    }

    int allMajs = (1 << sz) - 1;
    for(int i = 0 ; i < n ; ++i)
    {
        string note; cin >> note;
        allMajs &= majors[note];
    }

    if (allMajs == 0) { cout << "none\n"; return 0; }

    for (int i = 0 ; i < sz ; ++i)
    {
        if ( ((1 << i) & allMajs) != 0) {
            cout << notes[i] << " ";
        }
    }

}
