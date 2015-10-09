#include <map>
#include <set>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>

#define  ALPHABET_SIZE 32

using namespace std;

typedef struct Node{
	bool isleaf;   /*mark the end of a word*/
	Node * child[ALPHABET_SIZE];
}Node;

struct Node head;

void insert(string word){	
	Node *current = &head;
    Node * child;
	for(unsigned int i = 0; i < word.size(); i++){
		int letter = (int)word[i] - (int)'a';
		child = current->child[letter];
		if(!child){
			child = (Node *)malloc(sizeof(Node));
			child -> isleaf = false;
		}
		current = child;
	}
	current->isleaf = true;
}

/*true if there is a prefix of "word" in the trie*/
bool find_prefix_in_trie(string word){	
	Node * current = &head;
	
	for(unsigned int i = 0; i < word.size(); i++){
		int letter = (int)word[i] - (int)'a';		
		current = current->child[letter];
		
		if(!current) /*The word is not in the trie*/
			return false;
		if(current->isleaf){ 
           /*we reached the end of a word in the trie,
			 then "word" has a prefix in the trie
			*/
		   return true;
	    }
	}		
	return false;
}

int main()
{
	int n;
	cin >> n;
	head.isleaf = false;
	
	for(int i = 0; i < n; i++){
		string ss;		
		cin >> ss; 
		if(find_prefix_in_trie(ss)){
			cout << "BAD SET" << endl;
			cout << ss ;
			return 0 ;
		}		
		insert(ss);			
	}
	cout << "GOOD SET";
	return 0;
}
