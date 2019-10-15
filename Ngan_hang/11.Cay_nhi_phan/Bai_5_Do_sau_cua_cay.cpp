// Source: Nguyễn Hữu Long - D17CN11
#include<iostream>
using namespace std;

struct node{
	int info;
	node *left, *right;
};

node *createnode(int a){
	node *p = new node;
	p->info = a;
	p->left = p->right = NULL;
}

node *insert(node *root, int a){
	if(root == NULL) return createnode(a);
	if(a < root->info) root->left = insert(root->left, a);
	else root->right = insert(root->right, a);
	return root;
}


int maxDepth(node *root){
	if(root == NULL) return 0;
	else{
		int lDepth = maxDepth(root->left) + 1;
		int rDepth = maxDepth(root->right) + 1;
		if(lDepth < rDepth) return rDepth;
		else return lDepth;
	}
}

main(){
	ios::sync_with_stdio(false);
	cin.tie();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		node *root = NULL;
		for(int i = 0;i < n; i++){
			int x;
			cin>>x;
			root = insert(root, x);
		}
		cout<<maxDepth(root)-1<<endl;
	}
}