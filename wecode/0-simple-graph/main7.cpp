#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
    int e, n;
    cin >> e >> n;
    string fVertex, adjVertex;
    // INITIALIZE ADJACENCY LIST
    map<string, vector<string>> adjVerList;
    for (auto i = 0; i < e; i++)
    {
        cin >> fVertex >> adjVertex;
        adjVerList[fVertex].push_back(adjVertex);
    }
    for (int i = 0; i < n; i++)
    {
        int option;
        cin >> option;
        if (option == 1)
        {
            bool flip=false;
            cin >> fVertex >> adjVertex;
            for (auto &j : adjVerList[fVertex])
            {
                if (j == adjVertex)
                {
                    cout << "TRUE" << endl;
                    flip=1;
                    break;
                }
            }
            if(!flip){
                cout<<"FALSE"<<endl;
            }
        }
        if (option == 2)
        {
            cin >> fVertex;
            if (adjVerList[fVertex].size() != 0)
            {
                // for (auto &j : adjVerList[fVertex])
                // {
                //     cout << j << " ";
                // }
                cout<<adjVerList[fVertex].size();
                cout << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
}