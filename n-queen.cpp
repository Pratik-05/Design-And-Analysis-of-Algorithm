#include<iostream>
#include<vector>
using namespace std;
void printSolution(vector<vector<int> > &board,int n){
	for(int i=0;i<n;i++){
		for(int j =0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
bool isSafe(int row,int col,vector<vector<int> > &board,int n){
	//row-check
	int i=row;
	int j=col;
	while(j>=0){
		if(board[i][j]==1){
			return false;
		}
		j--;
	}
	//left-upper-diagonal-check
	i=row;
	j=col;
	while(i>=0 && j>=0){
		if(board[i][j]==1){
			return false;
		}
		i--;
		j--;
	}
	//left-lower diagonal-check
	i=row;
	j=col;
	while(i<n && j>=0){
		if(board[i][j]==1){
			return false;
		}
		i++;
		j--;
	}
	return true;
}
void solve(vector<vector<int> > &board,int col,int n){
	//base case
	if(col>=n){
		printSolution(board,n);
		return;
	}
	//1 case solve kro baaki recursion sambhal lega
	for(int row=0;row<n;row++){
		if(isSafe(row,col,board,n)){ //safe place hai toh queen ko rkh do
			board[row][col]=1;
			//baki recursion sambhal lega
			solve(board,col+1,n);//next col ke liye
			//backtrack
			board[row][col]=0; //agr glt ho gyi position fir vapas jake 0 kr do
		}
		
	}
	
}
int main(){
	int n;
	cout<<"Enter the value of n:";
	cin>>n;
	vector<vector<int> > board(n,vector<int>(n,0));
	int col=0;
	solve(board,col,n);
}