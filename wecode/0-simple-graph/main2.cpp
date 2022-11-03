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
	G=vector<vector<int>>(v, vector<int>(v, 0));
	int a,b;
	for(auto i=0;i<e;i++){
		cin>>a>>b;
		G[a-1][b-1]=1;
	}
}

void process(vector<vector<int>> &G,int v,int n){
	for(auto i=0;i<n;i++){
		int option,a,b;
		cin>>option;
		if(option==1){
			cin>>a>>b;
			if(G[a-1][b-1]==1){
				cout<<"TRUE"<<endl;
			}
			else{
				cout<<"FALSE"<<endl;
			}
		}
		else if(option==2){
			bool hvAdjVer=false;
			cin>>a;
			int index=0;
			for(auto &j:G[a-1]){
				if(j==1){
					hvAdjVer=1;
					cout<<index+1<<" ";
				}
				index++;
			}
			if(!hvAdjVer){
				cout<<"NONE\n";
			}
		}
		cout<<"\n";
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