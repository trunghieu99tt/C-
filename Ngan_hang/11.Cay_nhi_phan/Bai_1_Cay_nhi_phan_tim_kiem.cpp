#include<bits/stdc++.h>

using namespace std;


typedef struct node{
	int key;
	struct node *left, *right;
	node(int data)
	{
		this->key = key;
		left = right = NULL;
	}
} node;

struct node *newNode(int item)
{
	node *temp = (node *) malloc(sizeof(node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp; 
}

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}


void Postorder(node *root)
{
	if(root!=NULL)
	{
		Postorder(root->left);
		Postorder(root->right);
		cout<<root->key<<" ";
	}
}


void Preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<root->key<<" ";
		Preorder(root->left);
		Preorder(root->right);
	}
}

node* insert(node* node, int key)
{
	if(node == NULL)
		return newNode(key);
	if(key < node -> key)
		node->left = insert(node->left, key);
	else if(key > node -> key)
		node->right = insert(node->right, key);
	return node;
}

node * minV(node* node)
{
	struct node* current = node;
	while(current -> left != NULL)
		current = current->left;
	return current;
}

node* delNode(node* root, int key)
{
	if(root == NULL)
		return root;
	if(key < root->key)
		root->left = delNode(root->left,key);
	else if(key  > root -> key)
		root->right = delNode(root->right,key);
	else
	{
		if(root->left == NULL)
		{
			node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			node *temp = root->left;
			free(root);
			return temp;
		}

		node* temp = minV(root->right);

		root->key = temp->key;

		root->right = delNode(root->right, temp->key);
	}
	return root;
}

void solve()
{
	struct node *root = NULL;
	int q;
	while(cin>>q)
	{
		int key;
		switch(q)
		{
			case 1:
			{
				cin>>key;
				root = insert(root,key);
			};break;
			case 2:{
				cin>>key;
				root = delNode(root,key);
			};break;
			case 3: {
				Preorder(root);
				cout<<endl;
			};break;
			case 4: {
				inorder(root);
				cout<<endl;
			};break;
			case 5: {
				Postorder(root);
				cout<<endl;
			};break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	solve();
	return 0;
}