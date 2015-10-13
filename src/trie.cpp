#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <utility> 

#define  ALPHABET_SIZE 30

using namespace std;

struct Node{
	bool isleaf;
	struct Node* child[ALPHABET_SIZE];
};

struct Node head;

void init()
{	
	head.isleaf = false;
}
	
void insert(string word)
{	
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

bool isprefix(string word)
{	
	Node * current = &head;
	
	for(unsigned int i = 0; i < word.size(); i++){
		int letter = (int)word[i] - (int)'a';		
		current = current->child[letter];
		
		/*Word is not in the trie. Then there is no prefix*/
		if(!current)
			return false;
		/*We hit the end of a word x, then x is prefix of word*/
		if(current && current->isleaf){
		   return true;
	    }
	}	
	/*We reached the end of word but the node is not leaf
      then word is prefix of a word in the trie*/
	if(!current->isleaf)
		return true;
		
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