#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return build(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}

TreeNode* build(int* preorder, int pre_left, int pre_right, int* inorder, int in_left, int in_right) {
    if (pre_left > pre_right || in_left > in_right) {
        return NULL;
    }

    int root_val = preorder[pre_left];
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = root_val;
    root->left = NULL;
    root->right = NULL;

    int root_index_inorder;
    for (int i = in_left; i <= in_right; ++i) {
        if (inorder[i] == root_val) {
            root_index_inorder = i;
            break;
        }
    }

    int left_tree_size = root_index_inorder - in_left;

    root->left = build(preorder, pre_left + 1, pre_left + left_tree_size, inorder, in_left, root_index_inorder - 1);
    root->right = build(preorder, pre_left + left_tree_size + 1, pre_right, inorder, root_index_inorder + 1, in_right);

    return root;
}

void postorderTraversal(TreeNode* root) {
    postorderTraversalHelper(root);
}

void postorderTraversalHelper(TreeNode* root) {
    if (root) {
        postorderTraversalHelper(root->left);
        postorderTraversalHelper(root->right);
        printf("%d ", root->val);
    }
}

int main() {
    int preorder[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[] = {4, 7, 2, 1, 5, 3, 8, 6};
    int size = sizeof(preorder) / sizeof(preorder[0]);

    TreeNode* root = buildTree(preorder, size, inorder, size);

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
