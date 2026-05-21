#include <bits/stdc++.h>

using namespace std;

double cartDist(int x1, int y1, int x2, int y2)
{
    int dx = x1 - x2;
    int dy = y1 - y2;
    int prod = dx * dx + dy * dy;

    return sqrt(prod);
}

double ans = 1000000000;

void solve(const vector<int>& itemOrder, const vector<vector<int>>& itemStorePrice, const vector<vector<int>>& itemStores, const vector<pair<int,int>>& storePos, const vector<bool>& perish, 
	   pair<int,int> pos, int nextStore, int orderIdx, double cost, const int gas_price, bool havePerish) 
{
    if(pos != storePos[nextStore]) // drive to store if not there
    {
	auto goingTo = storePos[nextStore];
	cost += cartDist(pos.first, pos.second, goingTo.first, goingTo.second) * gas_price; 
	pos = storePos[nextStore];
    }

    cost += itemStorePrice[itemOrder[orderIdx]][nextStore]; 

    if(orderIdx == itemOrder.size() - 1) // finished shopping, return home
    {
	cost += cartDist(pos.first, pos.second, 0, 0) * gas_price;
	ans = min(ans, cost);
	return;
    }

    if(perish[itemOrder[orderIdx]]) { havePerish = true; }

    int nextItem = itemOrder[orderIdx + 1];
    for(auto store: itemStores[nextItem])
    {
	if((store == nextStore) || !havePerish) // no need to go home
	{
	    solve(itemOrder, itemStorePrice, itemStores, storePos, perish, storePos[nextStore], store, orderIdx + 1, cost, gas_price, havePerish);
	} else { // need to return perishable item
	    double newCost = cost;
	    newCost += cartDist(pos.first, pos.second, 0, 0) * gas_price;
	    solve(itemOrder, itemStorePrice, itemStores, storePos, perish, {0,0}, store, orderIdx + 1, newCost, gas_price, false);
	}
    }
}

int main()
{
    int T;
    cin >> T;
    for(int tcase = 0 ; tcase < T ; ++tcase)
    {
	ans = 1000000000;
	int num_items, num_stores, price_of_gas;
	cin >> num_items >> num_stores >> price_of_gas;

	vector<string> items(num_items);
	vector<vector<int>> itemStores(num_items);
	vector<pair<int,int>> storePos(num_stores);
	vector<vector<int>> itemStorePrice(num_items, vector<int>(num_stores));
	unordered_map<string, int> itemID;
	vector<bool> perish(num_items);

	for(int i = 0 ; i < num_items ; ++i)
	{
	    string item;
	    cin >> item;
	    if(item.back() == '!')
	    {
		perish[i] = true;
		item.pop_back();
	    }
	    items.push_back(item);
	    itemID[item] = i;
	}

	string junk;
	getline(cin, junk);

	for(int i = 0 ; i < num_stores ; ++i)
	{
	    string line;
	    getline(cin, line);
	    stringstream ss{ line };

	    int x_pos, y_pos;
	    ss >> x_pos >> y_pos;
	    storePos[i] = {x_pos,y_pos};

	    string item;
	    int price;
	    while(ss.ignore() && getline(ss, item, ':') && ss >> price)
	    {
		int id = itemID[item];
		itemStores[id].push_back(i);
		itemStorePrice[id][i] = price;
	    }
	}
	
	vector<int> itemOrder(num_items);
	for(int i = 0 ; i < num_items ; ++i)
	{
	    itemOrder[i] = i;
	}

	do {
	    for(auto store: itemStores[itemOrder[0]])
	    {
		solve(itemOrder, itemStorePrice, itemStores, storePos, perish, {0,0}, store, 0, 0, price_of_gas, false);
	    }
	} while(next_permutation(itemOrder.begin(), itemOrder.end()));

	cout << "Case #" << tcase + 1 << ": ";
	cout << fixed << setprecision(9) << ans << '\n';
    }
}

