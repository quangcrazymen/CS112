#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

// WAY TO USE MAP
// https://www.stdio.vn/modern-cpp/stl-map-trong-c-v12lmL
// find keys
// https://stackoverflow.com/questions/4263640/find-mapped-value-of-map
int main()
{
	int v, e, n; // v: số đỉnh, e: số cạnh, n: số thao tác
	// cin >> v >> e >> n;
	map<string, int> a;
	a["A"] = 1;
	a["B"] = 4;

	cout << a["A"];
	for (auto it = a.begin(); it != a.end() ; it++)
	{
		cout << it->first;
		cout << it->second;
	}
	string b;
	cin>>b;
	cout<<b;
}

// for (auto it = someMap.begin(); it != someMap.end(); ++it)
//     if (it->second == someValue)
//         return it->first;