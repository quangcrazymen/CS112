/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
using namespace std;

void inputGraph(bool*[], int);
void process(bool*[], int, int);

void output(bool *G[],int e){
    for(auto i=0;i<e;i++){
        for(auto j=0;j<e;j++){
            cout<<G[i][j];
        }
        cout<<endl;
    }
}

int main()
{
	int v, e, n; //v: số đỉnh, e: số cạnh, n: số thao tác
	cin >> v >> e >> n;

	bool **G; // ma trận toàn số 0, 1 nên kiểu bool hay int đều được
    G =new bool*[v];
    for(auto i=0;i<v;i++){
        G[i] = new bool[v];
    }

    for(auto i=0;i<v;i++){
        for(auto j=0;j<v;j++){
            G[i][j]=0;
        }
    }
    inputGraph(G,e);
    process(G,v,n);
    //output(G,e);

//###INSERT CODE HERE -
}

void inputGraph(bool* G[],int e){
    int u,i;
    for(auto a=0;a<e;a++){
        cin>>u>>i;
        // Undirected graph
        G[u-1][i-1]=1;
        G[i-1][u-1]=1;
    }
}

void process(bool* G[],int v,int n){
    int x,y,op;
    for(auto i=0;i<n;i++){
        cin>>op;
        if(op==1){
            cin>>x>>y;
            if(G[x-1][y-1]==1){
                cout<<"TRUE"<<endl;
            }
            else{
                cout<<"FALSE"<<endl;
            }
        }
        else if(op==2){
            bool hvAdjVertex=false;
            cin>>x;
            for(auto j=0;j<v;j++){
                if(G[x-1][j]==1){
                    hvAdjVertex=true;
                    cout<<j+1<<" ";
                }
            }
            if(!hvAdjVertex){
                cout<<"NONE"<<endl;
            }
            cout<<endl;
        }
        cout<<endl;
    }

}
//map<string,int> mapping;
//mapping[x]
//for(int i=0;i<v;i++){
//     cin>>x;
//     mapping[x]=i;
// }
// G[mapping[x]][mapping[y]]
// last adjacency list unknown vertex