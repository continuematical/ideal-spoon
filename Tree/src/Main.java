import java.sql.Connection;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        TreeNode root = new TreeNode("宋江", 1);
        TreeNode node1 = new TreeNode("林冲", 2);
        TreeNode node2 = new TreeNode("卢俊义", 3);
        TreeNode node3 = new TreeNode("江苏", 4);
        tree.setRoot(root);
        root.setLeft(node1);
        root.setRight(node2);
        node2.setLeft(node3);

        tree.delNode(3);
        tree.prevOrderSearch(3);
    }
}


class Person{
    private int age;
    private String name;

    public Person(int age, String name) {
        this.age = age;
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
//定义二叉树
class BinaryTree {
    //定义根节点
    private TreeNode root;

    public void setRoot(TreeNode root) {
        this.root = root;
    }

    public void preOrder() {
        if (this.root == null) {
            return;
        } else {
            this.root.preOrder();
        }
    }

    public void infixOrder() {
        if (this.root == null) {
            return;
        } else {
            this.root.infixOrder();
        }
    }

    public TreeNode prevOrderSearch(int data) {
        if (this.root != null) {
            return this.root.preOrderSearch(data);
        } else {
            return null;
        }
    }

    public void delNode(int data) {
        if (this.root == null) {
            return;
        } else {
            root.delNode(data);
        }
    }
}

//树节点
class TreeNode {
    private String name;
    private int data;
    private TreeNode left;
    private TreeNode right;

    public TreeNode(String name, int data) {
        this.name = name;
        this.data = data;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    public TreeNode getLeft() {
        return left;
    }

    public void setLeft(TreeNode left) {
        this.left = left;
    }

    public TreeNode getRight() {
        return right;
    }

    public void setRight(TreeNode right) {
        this.right = right;
    }

    //前序遍历
    public void preOrder() {
        System.out.println(this.getData());
        //左子树遍历
        if (left != null) {
            this.left.preOrder();
        }
        //右子树遍历
        if (right != null) {
            this.right.preOrder();
        }
    }

    //中序遍历
    public void infixOrder() {
        //左子树遍历
        if (left != null) {
            this.left.infixOrder();
        }
        System.out.println(this.getData());
        //右子树遍历
        if (right != null) {
            this.right.infixOrder();
        }
    }

    public void postOrder() {
        if (left != null) {
            this.left.postOrder();
        }
        if (this.right != null) {
            this.right.postOrder();
        }
        System.out.println(this.getData());
    }

    //前序遍历查找
    public TreeNode preOrderSearch(int data) {
        if (this.getData() == data) {
            return this;
        }
        TreeNode cur = null;
        if (this.getLeft() != null) {
            cur = this.getLeft().preOrderSearch(data);
        }
        if (cur != null && cur.getData() == data) {
            return cur;
        }
        if (this.getRight() != null) {
            cur = this.getRight().preOrderSearch(data);
        }
        return cur;
    }

    //中序遍历查找
    public TreeNode infixOrderSearch(int data) {
        TreeNode cur = null;
        if (this.getLeft() != null) {
            cur = this.getLeft().infixOrderSearch(data);
        }
        if (cur != null) {
            return cur;
        }
        if (this.data == data) {
            return this;
        }
        if (this.getRight() != null) {
            cur = this.getRight().infixOrderSearch(data);
        }
        return cur;
    }

    //后序遍历查找
    public TreeNode postOrderSearch(int data) {
        TreeNode cur = null;
        if (this.left != null) {
            cur = this.left.postOrderSearch(data);
        }
        if (cur != null) {
            return cur;
        }
        if (this.right != null) {
            cur = this.right.postOrderSearch(data);
        }
        if (cur != null) {
            return cur;
        }
        if (this.data == data) {
            return this;
        }
        return cur;
    }

    public void delNode(int data) {
        //空结点
        if (this == null) {
            return;
        }

        if (this.left != null) {
            if (this.left.data == data) {
                this.left = null;
                return;
            } else {
                this.left.delNode(data);
            }
        }

        if (this.right != null) {
            if (this.right.data == data) {
                this.right = null;
                return;
            } else {
                this.right.delNode(data);
            }
        }

    }
}