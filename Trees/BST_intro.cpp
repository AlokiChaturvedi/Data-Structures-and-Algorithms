#include <iostream>
#include <queue>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *insertIntoBST(node *root, int d)
{
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelordertaverasal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

bool searchinBST(node *root, int x)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }

    if (root->data > x)
    {
        return searchinBST(root->left, x);
    }

    else
    {
        return searchinBST(root->right, x);
    }
}

node *minVal(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node *maxVal(node *root)
{
    node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

node *Successor(node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {
        // 0 child

        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child

        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child

        if (root->left != NULL && root->right != NULL)
        {
            int min = minVal(root->right)->data;
            root->data = min;
            root->right = Successor(root->right, min);
            return root;
        }
    }

    else if (root->data > val)
    {
        root->left = Successor(root->left, val);
        return root;
    }

    else
    {
        root->right = Successor(root->right, val);
        return root;
    }
}

node *Predecessor(node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {
        // 0 child

        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child

        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child

        if (root->left != NULL && root->right != NULL)
        {
            int max = maxVal(root->left)->data;
            root->data = max;
            root->left = Predecessor(root->left, max);
            return root;
        }
    }

    else if (root->data > val)
    {
        root->left = Predecessor(root->left, val);
        return root;
    }

    else
    {
        root->right = Predecessor(root->right, val);
        return root;
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    // 5 4 7 8 9 6 3 2 -1
    node *root = NULL;
    cout << "Enter the data to fill into your BST: " << endl;
    takeInput(root);

    cout << "Print the level order traversal of the tree: " << endl;
    levelordertaverasal(root);

    int x;
    cout << "Enter the value to search in the BST: ";
    cin >> x;
    cout << searchinBST(root, x) << endl;

    cout << "minimum value in the BST is: " << minVal(root)->data << endl;
    cout << "Maximum value in the BST is : " << maxVal(root)->data << endl;

    cout << "Inorder Traversal is: ";
    inorder(root);
    cout << endl;

    int n;
    cout << "Enter the node to be deeted:  ";
    cin >> n;
    Predecessor(root, n);

    cout << "Inorder Traversal is: ";
    inorder(root);
    cout << endl;

    cout << "Tree after deletion: " << endl;
    levelordertaverasal(root);

    return 0;
}