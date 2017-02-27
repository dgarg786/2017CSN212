#include <bits/stdc++.h>
using namespace std;



long long int numWays(int width, int height, string bad [],int bl)
{   map<string,int> m;
for(int i=0;i<bl;i++){m[bad[i]]=1;}
	long long int arr[width+1][height+1];
	
	for(int i=0;i<=width;i++){
		
		for(int j=0;j<=height;j++){
			string st,st2;arr[i][j]=0;
			if(i>=1){
			st=to_string(i)+" "+to_string(j)+" "+to_string(i-1)+" "+to_string(j);
			st2=to_string(i-1)+" "+to_string(j)+" "+to_string(i)+" "+to_string(j);
				if(m[st]!=1 && m[st2]!=1)arr[i][j]+=arr[i-1][j];
				
				
			}
			if(j>=1){
			st=to_string(i)+" "+to_string(j-1)+" "+to_string(i)+" "+to_string(j);
			st2=to_string(i)+" "+to_string(j)+" "+to_string(i)+" "+to_string(j-1);
				
				if(m[st]!=1 && m[st2]!=1)arr[i][j]+=arr[i][j-1];
			}
		
		if(i==0 && j==0 )arr[0][0]=1;
		}
	}
	
	return arr[width][height];
}


