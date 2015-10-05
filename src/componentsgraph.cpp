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
	if(m[data])
		return;
	
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
    sm.erase(na);
	sm.erase(nb);
	sm.erase(pa);
	sm.erase(pb);
	
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

void printmaxmin(){	
	std::map<Node*,int>::iterator it;
	int max=0;int min=0;
	it = sm.begin();
	min = it->second;
	max = min;
	for (it = sm.begin(); it != sm.end(); it++){
		int dat=  it->second;
		//cout << it->first->data << " "<<dat << endl;
		if(max <= dat){
			max = dat;
		}
		if(min >= dat){
			min = dat;
		}
	}
	cout << min << " "<<max;
}

int main()
{
	int nodes;
	cin >> nodes;
	
	for(int i = 0; i < nodes; i++){
		int g,b;
		cin >> g >> b;
		makeset(g);
		makeset(b);
		//cout<< g<< " "<<b << endl;
		unionset(g, b);
	}
	printmaxmin();
}
