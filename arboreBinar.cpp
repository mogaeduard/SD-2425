#include <iostream>

using namespace std;
struct Nod {
  int val;
  Nod *left;
  Nod *right;
};
void inserare(Nod *&root, int val) {
  if (!root) {
    root = new Nod{val, nullptr, nullptr};
    return;
  }
  if (val < root->val)
    inserare(root->left, val);
  else
    inserare(root->right, val);
}
Nod *find(Nod *root, int val) {
  if (!root)
    return nullptr;
  if (root->val == val)
    return root;
  if (val < root->val)
    return find(root->left, val);
  return find(root->right, val);
}
void inorder(Nod *root) {
  if (!root)
    return;
  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}
void preorder(Nod *root) {
  if (!root)
    return;
  cout << root->val << " ";
  preorder(root->left);
  preorder(root->right);
}
void postorder(Nod *root) {
  if (!root)
    return;
  postorder(root->left);
  postorder(root->right);
  cout << root->val << " ";
}
int main() {
  int n, x;
  cin >> n;
  Nod *root = nullptr;
  for (int i = 0; i < n; i++) {
    cin >> x;
    inserare(root, x);
  }
  inorder(root);
  cout << endl;
  preorder(root);
  cout << endl;
  postorder(root);
  cout << endl;
  return 0;
}