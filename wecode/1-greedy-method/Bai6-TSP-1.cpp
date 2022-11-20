#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

bool has(vector<string> list, string vertex)
{
    for (auto &i : list)
    {
        if (i == vertex)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int e;
    cin >> e;
    string fVertex, adjVertex;
    // INITIALIZE ADJACENCY LIST
    map<string, vector<string>> adjVerList;
    for (auto i = 0; i < e; i++)
    {
        cin >> fVertex >> adjVertex;
        if (!has(adjVerList[fVertex], adjVertex))
        {
            adjVerList[fVertex].push_back(adjVertex);
        }
        // adjVerList[adjVertex].push_back(fVertex);
    }
    int vertex = adjVerList.size();
    int count = adjVerList.size();
    bool flag = true;
    int degree;
    for (auto &i : adjVerList)
    {
        degree = i.second.size();
        if (i.second.size() == vertex - 1)
        {
            count--;
        }
    }
    if (!count)
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
}
