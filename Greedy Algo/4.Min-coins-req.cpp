#include<iostream>
#include<vector>
using namespace std;

void MinCoins(vector<int>deno,int n, int V){
	vector<int>ans;
	for(int i=n-1;i>=0;i--){
		while(V>=deno[i]){
			V-=deno[i];
			ans.push_back(deno[i]);
		}
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<"+";
	}
	cout<<"\nMinimum coins required "<<ans.size();
}

int main(){
	int n;
	cout<<"Enter the number of coins:";
	cin>>n;
	vector<int>deno(n);//denominations array(coins value)
	cout<<"Enter the value of coins:";
	for(int i=0;i<n;i++){
		cin>>deno[i];
	}
	int V;
	cout<<"\nEnter the value:";
	cin>>V;
	MinCoins(deno,n,V);
}
/*
Enter the number of coins:4
Enter the value of coins:1 2 5 10

Enter the value:49
10+10+10+10+5+2+2+
Minimum coins required 7
*/