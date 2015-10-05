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

using namespace std;

struct Node{
	int data;
	struct Node * parent;
	int rank;
};
map<int, Node*> m;
map<Node *, int> sm;

void makeset(int data){
	Node * node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->parent = node;
	node->rank = 0;
	m[data] = node;
	sm[node] = 1;
}

Node* findset(int data){
	Node *n = m[data];
	Node *np = n->parent;
	if(np == n){
		return n;
	}	
	np->parent = findset(np->data);
	return np->parent;
}

int comsize(int p){
	Node *pn = findset(p);
	return sm[pn];
}

void unionset(int a, int b){
	int sizeA = comsize(a);
	int sizeB = comsize(b);
	Node *na = findset(a);
	Node *nb = findset(b);
	Node *pa = na->parent;
	Node *pb = nb->parent;
	
	
	if(pa->data == pb->data){
		return;
	}
	
	if(pa->rank >= pb->rank){
		pb->parent = pa;
		nb-> rank = 0;
		na-> rank++;
	}else{
		pa->parent = pb;
	}

	Node *np = findset(a);
	sm[np]=sizeA+sizeB;
}


int main(){
	int n, q;

    cin >> n >> q;
	for(int i = 1; i <= n; i++){
		makeset(i);
	}
	for(int i = 0; i < q; i++){
		char op;
		int p1, p2;
		cin >> op;
		if(op=='Q'){
			cin >> p1;
			cout<< comsize(p1) << endl;
		}else{
			cin >>p1 >> p2;
			unionset(p1, p2);
		}		
	}
	return 0;
}