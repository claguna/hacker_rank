#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <utility> 
#include <limits>

#define  ALPHABET_SIZE 30

using namespace std;

struct Node{
	bool isleaf;
	struct Node* child[ALPHABET_SIZE];
};

struct Node head;

void init(){	
	head.isleaf = false;
}
	
void insert(string word){
	
	Node *current = &head;
    
	for(unsigned int i = 0; i < word.size(); i++){
		int letter = (int)word[i] - (int)'a';
		if(!current->child[letter]){
			current->child[letter] = (Node *)malloc(sizeof(Node));			
		}
		current->child[letter]-> isleaf = false;
		current = current->child[letter];
	}
	current->isleaf = true;
}

bool isprefix(string word){
	
	Node * current = &head;
	
	for(unsigned int i = 0; i < word.size(); i++){
		int letter = (int)word[i] - (int)'a';		
		current = current->child[letter];
		
		if(!current)
			return false;
		if(current && current->isleaf){
		   return true;
	    }
	}
		
	return false;
}

int main()
{
	int n;
	cin >> n;
	init();
	 
	for(int i = 0; i < n; i++){
		string ss;		
		cin >> ss; 
		if(isprefix(ss)){
			cout << "BAD SET" << endl << ss ;
			return 0 ;
		}
		
		insert(ss);
			
	}
	cout << "GOOD SET";
	return 0;
}