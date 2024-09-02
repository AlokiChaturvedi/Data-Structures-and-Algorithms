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

node *buildTree(node *root)
{

    cout << "Enter the data for the tree :" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for the left node of :" << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for the right node of : " << data << endl;
    root->right = buildTree(root->right);
    return root;
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

int count(node *root)
{

    if (root)
    {
        return count(root->left) + count(root->right) + 1;
    }
    return 0;
}

int countleaf(node *root)
{

    if (root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return countleaf(root->left) + countleaf(root->right) + 1;
        }
        else
        {
            return countleaf(root->left) + countleaf(root->right);
        }
    }

    return 0;
}

int degree2leaf(node *root)
{

    if (root)
    {
        if (root->left != NULL && root->right != NULL)
        {
            return degree2leaf(root->left) + degree2leaf(root->right) + 1;
        }
        else
        {
            return degree2leaf(root->left) + degree2leaf(root->right);
        }
    }

    return 0;
}

int degree1leaf(node *root)
{

    if (root)
    {
        if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
        {
            return degree1leaf(root->left) + degree1leaf(root->right) + 1;
        }
        else
        {
            return degree1leaf(root->left) + degree1leaf(root->right);
        }
    }

    return 0;
}

int Internalleaf(node *root)
{

    if (root)
    {
        if (root->left != NULL || root->right != NULL)
        {
            return Internalleaf(root->left) + Internalleaf(root->right) + 1;
        }
        else
        {
            return Internalleaf(root->left) + Internalleaf(root->right);
        }
    }

    return 0;
}

int height(node *root)
{
    int x = 0, y = 0;
    if (root == 0)
    {
        return 0;
    }
    x = height(root->left);
    y = height(root->right);

    if (x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
}

int main()
{
    node *root = NULL;

    root = buildTree(root);
    // 5 1 4 -1 -1 3 -1 -1 2 7 -1 -1 6 -1 9 -1 -1

    cout << "Print the level order traversal of the tree: " << endl;
    levelordertaverasal(root);

    cout << "The height of the tree is : " << height(root) << endl;
    cout << "The count of the nodes of the tree is : " << count(root) << endl;
    cout << "The count of the leafnodes of the tree is : " << countleaf(root) << endl;
    cout << "The count of the nodes of the tree with degree 2 is : " << degree2leaf(root) << endl;
    cout << "The count of the nodes of the tree with degree 1 is : " << degree1leaf(root) << endl;
    cout << "The count of all the internal nodes of the tree is : " << Internalleaf(root) << endl;

    return 0;
}
