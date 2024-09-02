// #include <iostream>
// #include <queue>
// using namespace std;

// class node
// {o
// public:
//     int data;
//     node *left;
//     node *right;

//     node(int d)
//     {
//         this->data = d;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// node *buildTree(node *root)
// {
//     cout << "Enter the data for the tree :" << endl;
//     int data;
//     cin >> data;
//     root = new node(data);

//     if (data == -1)
//     {
//         return NULL;
//     }

//     cout << "Enter the data for the left node of :" << data << endl;
//     root->left = buildTree(root->left);
//     cout << "Enter the data for the right node of : " << data << endl;
//     root->right = buildTree(root->right);
//     return root;
// }
// void preorder(node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     cout << root->data << " ";
//     preorder(root->left);
//     preorder(root->right);
// }

// int main()
// {
//     node *root = NULL;

//     root = buildTree(root);

//     cout << "Preorder Traversal is: ";
//     preorder(root);
//     cout << endl;

//     return 0;
// }
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> boxes;
    int ports, max_box, max_wt, n;
    vector<int> dp;
    
    int backtrack(int index) {
        if (index == n)
            return 0;
        if (dp[index] != 0)
            return dp[index];
        
        int start = index, end = index, currWt = boxes[index][1], boxCount = 1, lastPort = boxes[index][0], ports_visited = 0;
        
        while (end + 1 < n && currWt + boxes[end + 1][1] <= max_wt && boxCount + 1 <= max_box) {
            end++;
            currWt += boxes[end][1];
            boxCount++;
            if (lastPort != boxes[end][0]) {
                ports_visited++;
                lastPort = boxes[end][0];
            }
        }
        
        int trips = 2 + ports_visited + backtrack(end + 1);
        
        int x = -1;
        for (int i = end - 1; i >= index; i--) {
            if (boxes[i][0] != lastPort) {
                x = i;
                break;
            }
        }
        if (x != -1) {
            trips = min(trips, 2 + ports_visited - 1 + backtrack(x + 1));
        }

        dp[index] = trips;
        return trips;        
    }
    
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        this->boxes = boxes;
        n = boxes.size();
        dp.assign(n, 0);
        ports = portsCount;
        max_box = maxBoxes;
        max_wt = maxWeight;
        return backtrack(0);
    }
};

int main() {
    Solution solution;
    vector<vector<int>> boxes = {{1, 2}, {3,3 }, {3,1}, {3,1}, {2,4}};
    int portsCount = 3;
    int maxBoxes = 3;
    int maxWeight = 6;

    int result = solution.boxDelivering(boxes, portsCount, maxBoxes, maxWeight);
    cout << "Minimum number of trips: " << result << endl;

    return 0;
}