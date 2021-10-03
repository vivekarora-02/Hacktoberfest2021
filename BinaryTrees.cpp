//Made by Vivek Arora

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class binaryTreeNode
{
public:
    T data;
    binaryTreeNode *left;
    binaryTreeNode *right;

    binaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~binaryTreeNode()
    {
        delete left;
        delete right;
    }
};
binaryTreeNode<int> *takeInputLevelWise()
{

    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    binaryTreeNode<int> *root = new binaryTreeNode<int>(rootData);

    queue<binaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        binaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            binaryTreeNode<int> *child = new binaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            binaryTreeNode<int> *child = new binaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
//Preorder Traversal
void printBinaryTree(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";

    if (root->left != NULL)
    {
        cout << " Left " << root->left->data << " ";
    }
    if (root->right != NULL)
    {
        cout << " Right " << root->right->data << " ";
    }
    cout << "\n";
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

binaryTreeNode<int> *takeInput()
{

    cout << "Enter data: "
         << "\n";
    int data;
    cin >> data;

    if (data == '$')
    {
        return NULL;
    }

    binaryTreeNode<int> *root = new binaryTreeNode<int>(data);
    binaryTreeNode<int> *leftChild = takeInput();
    binaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

int numberOfNodes(binaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return 0;
    }

    return 1 + numberOfNodes(root->left) + numberOfNodes(root->right);
}

bool searchNode(binaryTreeNode<int> *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    cout << root->data << " : ";

    if (root->left != NULL)
    {
        if (root->left->data == key)
        {
            return true;
        }
    }
    if (root->right != NULL)
    {
        if (root->right->data == key)
        {
            return true;
        }
    }
    cout << "\n";
    searchNode(root->left, key);
    searchNode(root->right, key);
}

int heightOfBinaryTree(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int height = max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right)) + 1;
    return height;
}

void mirrorBinaryTree(binaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return;
    }

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

    binaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void inorderTreeTraversal(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderTreeTraversal(root->left);
    cout << root->data << " ";
    inorderTreeTraversal(root->right);
}

void postOrderTraversal(binaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);

    cout << root->data << " ";
}

void printLevelWise(binaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return;
    }

    queue<binaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {

        binaryTreeNode<int> *front = pendingNodes.front();

        cout << front->data << " ";
        pendingNodes.pop();

        if (front->left != NULL)
        {
            pendingNodes.push(front->left);
        }

        if (front->right != NULL)
        {
            pendingNodes.push(front->right);
        }
    }
}

int diameterOfBinaryTree(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int option1 = heightOfBinaryTree(root->left) + heightOfBinaryTree(root->right);
    int option2 = diameterOfBinaryTree(root->left);
    int option3 = diameterOfBinaryTree(root->right);

    return max(option1, max(option2, option3));
}

pair<int, int> optimizedDiameter(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
    }

    pair<int, int> leftAns = optimizedDiameter<root->left>;
    pair<int, int> rightAns = optimizedDiameter<root->right>;

    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max((lh + rh), ld, rd);

    pair<int, int> p;

    p.first = height;
    p.second.= diameter;

    return p;
}

//Binary Search Tree

bool searchInBST(binaryTreeNode<int> *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root == key)
    {
        return true;
    }

    if (key > root)
    {
        searchInBST(root->right, key);
    }
    else
    {
        searchInBST(root->left, key);
    }

    return false;
}

int main()
{

    // binaryTreeNode<int> *root = new binaryTreeNode<int>(1);
    // binaryTreeNode<int> *node1 = new binaryTreeNode<int>(2);
    // binaryTreeNode<int> *node2 = new binaryTreeNode<int>(3);

    // root->left = node1;
    // root->right = node2;

    binaryTreeNode<int> *root = takeInputLevelWise();
    cout << "Number of nodes of binary tree: " << numberOfNodes(root) << "\n";
    int value;
    cout << "Enter value to be searched: "
         << "\n";
    cin >> value;
    cout << "Value present or not: " << searchNode(root, value) << "\n";
    cout << "Height of binary tree: " << heightOfBinaryTree(root) << "\n";
    printBinaryTree(root);
    cout << "Binary Tree after mirroring: "
         << "\n";
    mirrorBinaryTree(root);
    printBinaryTree(root);
    cout << "Inorder Binary Tree Traversal: "
         << "\n";
    inorderTreeTraversal(root);
    cout << "\nPost-Order Binary Tree Traversal: "
         << "\n";
    postOrderTraversal(root);

    cout << "\nLevel Wise Tree Traversal: "
         << "\n";
    printLevelWise(root);
    cout << "Diameter of binary tree: \n"
         << diameterOfBinaryTree(root) << "\n";
    cout << "Optimized Diameter of binary tree: \n"
         << optimizedDiameter(root) << "\n";

    cout << "Enter key that you want to search in BST: "
         << "\n";
    int key;
    cin >> key;
    cout << "Searching in BSt: " << searchInBST(root, key) << "\n";
    delete root;
    return 0;
}
