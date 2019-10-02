#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Following is the given TreeNode structure.

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};


void printNodesAtDepthK(TreeNode<int>* root, int k) {
    
  if(k==0)
  { cout<<root->data<<" ";
   return;
  }
  for(int i=0;i<root->children.size();i++)
  {     
   TreeNode<int>* t=root->children[i];
      printNodesAtDepthK(t,k-1);
}
}


TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    int k;
    cin >> k;
    printNodesAtDepthK(root, k);
}