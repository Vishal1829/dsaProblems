#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

pair<int, bool> getCountOfUniValueSubTrees(TreeNode* root) {
  if(root==NULL) {
    return {0, true};
  }
  if(root->left==NULL and root->right==NULL) {
    return {1, true};
  }

  auto [leftCount, isLeftUniValue] = getCountOfUniValueSubTrees(root->left);
  auto [rightCount, isRightUniValue] = getCountOfUniValueSubTrees(root->right);

  //inorder for a node to be univalue we need to first get its left and right univalues
  //then only we can check whats the status of this node so postorder traversal here.

  if(isLeftUniValue and isRightUniValue) {
    if(root->left and root->left->val!=root->val) {
      return {leftCount + rightCount, false};
    }
    if(root->right and root->right->val!=root->val) {
      return {leftCount + rightCount, false};
    }
    //left val , right val, this node val all are same and also subTrees of this node are univalues 
    //so this node also the part of univalue therefore we return leftCnt+rightCnt+1
    //1 here means that consider the subTree rooted at this node and this subTree is uniValueSubtree
    //so increase the count by 1.
    return {1 + leftCount + rightCount, true};
  }

  //this node is not univalueSubTree so return its subTree univalue counts with false as this node
  //is not uniValue.
  return {leftCount + rightCount, false};
}

//serialize & deserialize a binary tree.
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        vector<string> res;
    
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node) {
                res.push_back(to_string(node->val));
                q.push(node->left);
                q.push(node->right);
            } else {
                res.push_back("#");
            }
        }
    
        // Remove trailing "#"s
        while (!res.empty() && res.back() == "#") {
            res.pop_back();
        }
    
        // Join with commas
        string result;
        for (int i = 0; i < res.size(); ++i) {
            result += res[i];
            if (i != res.size() - 1) result += ',';
        }
        return result;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) 
          return nullptr;
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
    
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
    
            /*
                if (!...) break;
                This is checking whether getline failed (e.g., when there’s no more data to read).
                If getline fails (meaning val could not be filled), then the break statement stops 
                the while loop.
                
                In Simple English:
                “Try to read the next value from the stream. If there’s nothing left to read 
                (like we reached the end of the serialized string), then break out of the loop.”
            */
            if (!getline(ss, val, ',')) break;
            if (val != "#") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
    
            if (!getline(ss, val, ',')) break;
            if (val != "#") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
    
        return root;
    }

};

int main() {

  //"1,2,3,#,#,4,5", "1,1,1,1,1"
  string treeString = "1,1,1,2,1";
  Codec codec;
  TreeNode* root = codec.deserialize(treeString);
  auto ans = getCountOfUniValueSubTrees(root);
  cout<<"Count of univalueSubtrees are: "<<ans.first;
  return 0;
}


/*
Note: Every leaf node is a univalue subtree.
 1 
/ \
2 1
countOfUnivalueSubTrees=1

   0  
  / \ 
 1   0
/ \   
1 1   
countOfUnivalueSubTrees=4 ({1}, {1}, {1,1,1}, {0})

   1  
  / \ 
 1   1
/ \   
2 1   
countOfUnivalueSubTrees=3

   1  
  / \ 
 1   1
/ \   
1 1   
countOfUnivalueSubTrees=5

Base case for recursion is if node is leaf then return 1. But also a node should tell its parent
number of univalueSubtree under it and also whether it itself is part of univalueSubtree or not
so return type would be pair<int, bool>. 
*/
