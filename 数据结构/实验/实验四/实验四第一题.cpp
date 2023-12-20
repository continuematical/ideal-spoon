#include <bits/stdc++.h> 

typedef char TElemType;

typedef struct TreeNode {
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* build(TElemType* preorder, TElemType pre_left, TElemType pre_right, TElemType* inorder, TElemType in_left, TElemType in_right) {
    if (pre_left > pre_right || in_left > in_right) 	return NULL;
    int root_val = preorder[pre_left];//求出这棵树的根节点 
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = root_val;
    root->left = NULL;
    root->right = NULL;
    //在中序遍历中，求出根节点的位置 
    int root_index_inorder;
    for (int i = in_left; i <= in_right; ++i) 
        if (inorder[i] == root_val) {
            root_index_inorder = i;
            break;
        }
    
    //根节点前部分是左子树 
    int left_tree_size = root_index_inorder - in_left;
    root->left = build(preorder, pre_left + 1, pre_left + left_tree_size, inorder, in_left, root_index_inorder - 1);
    root->right = build(preorder, pre_left + left_tree_size + 1, pre_right, inorder, root_index_inorder + 1, in_right);
    return root;
}

void postorderTraversalHelper(TreeNode* root) {
    if (root) {
        postorderTraversalHelper(root->left);
        postorderTraversalHelper(root->right);
        printf("%c", root->val);
    }
}

int main() {
    char preorder[] = {"ABCDEFGH"};
    char inorder[] = {"CBEDFAGH"};
    int size = strlen(preorder);
    TreeNode* root=build(preorder, 0, size-1, inorder, 0, size-1); 
    printf("Postorder Traversal: ");
    postorderTraversalHelper(root);
    return 0;
}
