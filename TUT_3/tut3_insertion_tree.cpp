
/*
	Tutorial 3	
	
	Submitted by - 
		Deepanshu Garg (13116023)
		B.tech 4th year
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int val;
	int left_interval,right_interval;
	TreeNode(int a,int b,int c){
		left=NULL;right=NULL;
		val=c;left_interval=a;right_interval=b;	
	}
};


void insert(TreeNode* &root,int l,int r){
    
    if(root==NULL){
    	root=new TreeNode(l,r,r);
    	return;
    }
    if(root->left_interval>=l){
    	insert(root->left,l,r);
    }
    else insert(root->right,l,r);

    if(root->left!=NULL){
    	root->val=max(root->right_interval,root->left->val);
    }

    if(root->right!=NULL){
    	root->val=max(root->right_interval,root->right->val);
    }
    return;
}

void  eq_inorder_pred(TreeNode*root,int &l,int &r){
			if(root->left==NULL){
				l=root->left_interval;r=root->right_interval;

			}
			else{
				eq_inorder_pred(root->left,l,r); 
			}
}

void del(TreeNode* &root,int l,int r){
	if(root==NULL)return;
	if(root->left_interval==l && root->right_interval==r){
		if(root->left==NULL){root=root->right; return;}
		if(root->right==NULL){root=root->left;return;}
		eq_inorder_pred(root->right,root->left_interval,root->right_interval);
		del(root->right,root->left_interval,root->right_interval);
	}
	else if(root->left_interval>=l){
		del(root->left,l,r);
    }
    else{
    	del(root->right,l,r);
    }
    if(root->left!=NULL){
    	root->val=max(root->right_interval,root->left->val);
    }

    if(root->right!=NULL){
    	root->val=max(root->right_interval,root->right->val);
    }
    return;
}

pair<int,int> search(TreeNode*root,int l,int r){

	if(root==NULL)return {-1,-1};
	if((l>=root->left_interval && l<=root->right_interval)|| (r>=root->left_interval && r<=root->right_interval)){
		return {root->left_interval,root->right_interval};
	}
	if(root->left!=NULL){
		if(root->left->val>=l)return search(root->left,l,r);
		else return search(root->right,l,r);
	}
	return search(root->right,l,r);
}
int main(){

	// INSERT NO INPUT FROM USER
	int n,a,b;
	cin>>n;
	TreeNode*root=NULL;
	for(int i=0;i<n;i++){
		cin>>a>>b; // Insert intervals to add
		insert(root,a,b);
	}

	int t;cin>>t;// Insert no of intervals to check
	for(int i=0;i<t;i++){
		cin>>a>>b;// Insert intervals to check 
		pair<int,int> ans=search(root,a,b);
		cout<<ans.first<<" "<<ans.second<<endl;
	}

}

/*
Input for checking the required values 

6
15 20 
10 30 
17 19 
5 20
12 15 
30 40
2
14 16
21 23

Output by this program

15 20
10 30

*/


