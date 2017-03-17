#include <bits/stdc++.h>
#define S second
#define F first 
using namespace std;

vector<pair<pair<int,int>,int> > e;
int v;

void bellmanford(int src){

	int dist[v+1];
	for(int i=1;i<=v;i++)dist[i]=INT_MAX;
	dist[src]=0;

	for(int i=1;i<=v;i++){
		for(int j=0;j<e.size();j++){
			int st = e[j].F.F;
            int en = e[j].F.S;
            int weight = e[j].S;
			if (dist[st] != INT_MAX && (dist[st] + weight < dist[en]))
                dist[en] = dist[st] + weight;
                     }

	}


	// for(int i=1;i<=v;i++)
 //        if(src!=i)
 //        if(dist[i]!=INT_MAX)cout<<dist[i]<<" ";
 //        else cout<<-1<<" ";
	// cout<<endl;

    
}

int main(){

	int t;
	cin>>t;

	while(t--){
		int m;
		cin>>v>>m;e.clear();
		for(int i=0;i<m;i++){
			int st,en,d;
			cin>>st>>en>>d;
			e.push_back({{st,en},d});
            e.push_back({{en,st},d});

		}
		int src;cin>>src;
        clock_t tStart = clock();
		bellmanford(src);
       double tt= ((double)(clock() - tStart)/CLOCKS_PER_SEC)*1000;
        long long int ve=v*m;
        cout<<fixed<<setprecision(6)<<tt<<" "<<ve<<" "<<v<<" "<<m<<endl;
	}

	
}