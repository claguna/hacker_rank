#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int moves = 0;

vector<pair<int,int>> getn(vector < vector <char> > M, ){
	
}

bool dfs(vector < vector <char> > M, pair <int,int> p){
	int i, j;
	i = p.first;
	j = p.second;
	
	if(M[i][j] == '*')
		return true;
	
	M[i][j] = 'v';
	

	return false;
}


int main()
{
	int testcases;
	int n, m, k;
	cin >> testcases;

	for(int t = 0; t < testcases; t++){
		pair<int, int> start;
		pair<int, int> end;
		cin >> n >> m;		
		vector < vector <char> > M (n, vector<char>(m));
		for(int i = 0; i < n; i++){
			string s;
			cin >> s;
			for(int j = 0; j < m; j++){ 
				M[i][j] = s[j];
				if(s[j]=='M')
					start = make_pair(i,j);
				if(s[j]=='*')
					end = make_pair(i,j);
		   }
		}
		cin >> k;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << M[i][j];
			}
			cout << endl;
		}
	}
}
