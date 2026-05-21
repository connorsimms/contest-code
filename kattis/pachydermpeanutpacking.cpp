#include <iostream>
#include <vector>
using namespace std;

struct Box
{
    float x1, y1, x2, y2;
    string type;
}

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        vector<Box> boxes(n);

        for (int i = 0 ; i < n ; ++i)
        {
            float x1, y1, x2, y2; 
            cin >> x1 >> y1 >> x2 >> y2;
            string type; cin >> type;
    
            boxes.emplace_back(x1, y2, x2, y2, type);
        }

        int m; cin >> m;
        for (int = 0 ; i < m ; ++i)
        {
            float x, y; cin >> x >> y;
            string type; cin >> type;

            auto it = std::find_if(boxes.begin(), boxes.end(), 
                                   [=](const auto& box)
                                   {
                                        if (x >= box.x1 && x <= box.x2 && y >= box.y1 && y <= box.y2)
                                        {
                                            return box.type == type;
                                        }
                                        return false;
                                   });
        }
    }
}
