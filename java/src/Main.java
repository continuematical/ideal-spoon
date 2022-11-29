import javax.imageio.IIOException;
import java.io.*;
import java.nio.charset.Charset;

class NodeManager {
    private Node root;
    private int size = 1;

    //外部类：添加结点
    public void add(int data) {
        if (root == null) {
            Node newNode = new Node(data);
            root = newNode;
        } else {
            root.addNode(data);
        }
    }

    public void delete(int data) {
        if (root == null) {
            return;
        }
        if (root.getData() == data) {
            root = root.next;
        } else {
            root.deleteNode(data);
        }
    }

    //打印全部结点
    public void print() {
        if (root != null) {
            System.out.print(root.getData());
            System.out.println();
            root.printNode();
        } else {
            return;
        }
    }

    //查找
    public boolean find(int data) {
        if (root == null) {
            return false;
        }
        ;
        if (root.getData() == data) {
            return true;
        } else {
            return root.findNode(data);
        }
    }

    public boolean update(int oldData, int newData) {
        if (root == null) {
            return false;
        }
        ;
        if (root.getData() == oldData) {
            root.setData(newData);
        } else {
            return root.updateNode(oldData, newData);
        }
        return false;
    }

    public void insert(int index, int newData) {
        if (index < 0) {
            return;
        }
        if (index == size) {
            Node newNode = new Node(newData);
            newNode.next = root;
            root = newNode;
        } else {
            root.insertNode(index, newData);
        }
    }

    class Node {
        private int data;
        private Node next;

        //修改节点的值
        public void setData(int data) {
            this.data = data;
        }

        public int getData() {
            return data;
        }

        //构造方法
        public Node(int data) {
            this.data = data;
        }

        //增加节点
        public void addNode(int data) {
            if (this.next == null) {
                Node newNode = new Node(data);
                this.next = newNode;
            } else {
                this.next.addNode(data);
            }
        }

        //删除某个结点
        public void deleteNode(int data) {
            if (this.next != null) {
                if (this.next.getData() == data) {
                    this.next = this.next.next;
                } else {
                    this.next.deleteNode(data);
                }
            }
        }

        //输出所有结点
        public void printNode() {
            if (this.next != null) {
                System.out.println(this.next.getData());
                this.next.printNode();
            }
        }

        //寻找某个结点
        public boolean findNode(int data) {
            if (this.next != null) {
                if (this.next.getData() == data) {
                    return true;
                } else {
                    this.next.findNode(data);
                }
            }
            return false;
        }

        //更新结点的值
        public boolean updateNode(int oldData, int newData) {
            if (this.next != null) {
                if (this.next.getData() == oldData) {
                    this.next.setData(newData);
                    return true;
                } else {
                    return this.next.updateNode(oldData, newData);
                }
            }
            return false;
        }

        public void insertNode(int index, int newData) {
            size++;
            if (index == size) {
                Node newNode = new Node(newData);
                newNode.next = this.next;
                this.next = newNode;
            } else {
                this.next.insertNode(index, newData);
            }
        }
    }
}



