#include<bits/stdc++.h>

using namespace std;

#define Fast1 ios_base::sync_with_stdio(0)
#define Fast2 cin.tie(0)
#define Fast3 cout.tie(0)
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef short int SI;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

// Binary Search Tree

class binarySearchTree
{
public:
	int data;
	binarySearchTree* left;
	binarySearchTree* right;
	binarySearchTree(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
	~binarySearchTree(){
		delete left;
		delete right;
	}
	
};

void LevelOrderTraversal(binarySearchTree* root){

	if(!root) return;

	queue<binarySearchTree*> node;
	node.push(root);

	while(!node.empty()){

		int count = node.size();
		while(count--){

			binarySearchTree* ptr = node.front();
			cout<<ptr->data<<" ";
			node.pop();

			if(ptr->left) node.push(ptr->left);

			if(ptr->right) node.push(ptr->right);
		}
		cout<<"\n";

	}
}

binarySearchTree* builtBinaryTree(binarySearchTree* root,int key){

	if(!root) return new binarySearchTree(key);

	if( root->data > key){
		root->left = builtBinaryTree(root->left,key);
	}
	else{
		root->right = builtBinaryTree(root->right,key);
	}
	return root;
}

bool findElement(binarySearchTree* root,int key){

	if(!root) return false;

	if(root->data == key) return true;

	bool res;
	if(root->data < key) res =  findElement(root->right,key);

	else{
		res = findElement(root->left,key); 
	} 
	return res;
}

void printWithinRange(binarySearchTree* root, int k1,int k2){

	if(!root) return;
	
	if(root->data >= k1) printWithinRange(root->left,k1,k2);

	if(root->data >= k1 && root->data <= k2){
		cout<<root->data<<" ";
	}

	if(root->data <= k2) printWithinRange(root->right,k1,k2);
}

binarySearchTree* LCABinarySearchTree( binarySearchTree* root,int k1, int k2){

	if(!root ) return NULL;

	if( root->data == k1 || root->data == k2){
		return root;
	}

	binarySearchTree* ld = LCABinarySearchTree(root->left, k1,k2);
	binarySearchTree* rd = LCABinarySearchTree(root->right,k1,k2);

	if( ld && rd) return root;

	return (ld?ld : rd);
}

int main()
{
	int n;
	cin>>n;
	binarySearchTree* root = NULL;
	FOR(i,n){
		int x;
		cin>>x;
		root = builtBinaryTree(root , x);
	}

	cout<<"\n Level Order Traversal : \n";
	LevelOrderTraversal(root);

	cout<<"\n Lowest Common Ancestor :";
	binarySearchTree*temp =  LCABinarySearchTree(root,1,14);
	cout<<temp->data;


	delete root;
	return 0;
}

/*
Input :-
9
8 3 10 1 6 14 4 7 13


output:-


 Level Order Traversal : 
8 
3 10 
1 6 14 
4 7 13 

 Lowest Common Ancestor :8
*/
