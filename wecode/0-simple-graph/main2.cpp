/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
#include<vector>
using namespace std;

//###INSERT CODE HERE -
void inputGraph(vector<vector<int>> &G,int v,int e){
	//initialized all array to 0
	for(auto i=0;i<v;i++){
		G.push_back(vector<int>{v,0});
	}
	for(auto i=0;i<e;i++){
		int u=v=0;
		cin>>u>>v;
		G[u-1][v-1]=1;
	}
}

void process(vector<vector<int>> &G,int v,int n){
	for(auto i=0;i<n;i++){
		int option,u,v;
		cin>>option;
		if(option==1){
			cin>>u>>v;
			if(G[u-1][v-1]==1){
				cout<<"TRUE"<<endl;
			}
			else{
				cout<<"FALSE"<<endl;
			}
		}
		else if(option==2){
			cin>>u;
			// int it = find (G[u-1].begin(), G[u-1].end(), 1);
			for(auto &i:G[u-1]){
				if(i==1){
					cout<<i;
				}
			}
		}
	}
}

int main()
{

	int v, e, n;
	cin >> v >> e >> n; //v: số đỉnh, e: số cạnh, n: số thao tác
	vector<vector<int> > G;

	inputGraph(G,v,e);
    process(G,v,n);

	return 0;
}

//allocate 
// vector<vector<int>>a(v,vector<int>(v,0))