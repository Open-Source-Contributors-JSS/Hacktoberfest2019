#include<iostream>
#include "create_tree.h"

void bfs_traversal(Node* root,int level);

int max(int a,int b){
  return a>b?a:b;
}

int height_calculate(Node* root){
  if (root==nullptr)
  return 0;
  else{
    height_calculate(root->left_child);
    height_calculate(root->right_child);
  }
  return max(height_calculate(root->left_child),height_calculate(root->right_child))+1;
}

void bfs_control_loop(Node* root){
  int height=height_calculate(root);
  for (int level=1;level<=height;level++){
    bfs_traversal(root,level);
  }
}

void bfs_traversal(Node* root,int level){
  if (root==nullptr)
  return;
  if (level==1)
  std::cout << root->data <<"->";
  bfs_traversal(root->left_child,level-1);
  bfs_traversal(root->right_child,level-1);
}

int main(){
  Node* root=new Node;
  create_tree tree;
  tree.add_root(&root,20);
  tree.add_node(root,4);
  tree.add_node(root,28);
  tree.add_node(root,3);
  tree.add_node(root,11);
  tree.add_node(root,27);
  tree.add_node(root,29);
  bfs_control_loop(root);
  std::cout << "NULL" << '\n';
  return 0;
}
