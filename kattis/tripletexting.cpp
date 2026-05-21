#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    string text;

    getline(cin, text);

    string ans(text.size() / 3, '\0');
    
    for (size_t i = 0 ; i < text.size(); ++i)
    {
        size_t idx = i % ans.size();
        auto iter = i / ans.size();

        if (iter == 0) { ans[idx] = text[i]; continue; }
        if (iter == 1 && ans[idx] != text[i]) { ans[idx] = '\0'; }
        if (iter == 2 && ans[idx] == '\0') { ans[idx] = text[i]; }
    }

    cout << ans << '\n';
}
