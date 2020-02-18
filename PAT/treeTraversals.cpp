// A1020
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *lchild;
    node *rchild;
};

void printLayorOrder(node *root, int treeSize)
{
    if (root == NULL)
        return;
    queue<node *> q;
    int count = 0;
    q.push(root);
    while (not q.empty())
    {
        node *next = q.front();
        q.pop();
        cout << next->data;

        count++;
        if (count < treeSize)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }

        if (next->lchild != NULL)
        {
            q.push(next->lchild);
        }
        if (next->rchild != NULL)
        {
            q.push(next->rchild);
        }
    }
    cout << endl;
}

vector<int> subArray(vector<int> v, int start, int end)
{
    if (start > end)
        return vector<int>();
    return vector<int>(v.begin() + start, v.begin() + end + 1);
}

node *buildTree(vector<int> postOrder, vector<int> inOrder)
{
    if (postOrder.size() == 0 or inOrder.size() == 0)
        return NULL;

    int rootVal = postOrder[postOrder.size() - 1], rootIndex;
    node *root = new node;
    root->data = rootVal;
    for (int i = 0; i < inOrder.size(); i++)
    {
        if (inOrder[i] == rootVal)
        {
            rootIndex = i;
            break;
        }
    }
    
    root->lchild = buildTree(subArray(postOrder, 0, rootIndex - 1), subArray(inOrder, 0, rootIndex - 1));
    root->rchild = buildTree(subArray(postOrder, rootIndex, postOrder.size() - 2), subArray(inOrder, rootIndex + 1, inOrder.size() - 1));

    return root;
}

int main()
{
    int treeSize;
    vector<int> postOrder, inOrder;
    cin >> treeSize;
    for (int i = 0; i < treeSize; i++)
    {
        int data;
        cin >> data;
        postOrder.push_back(data);
    }

    for (int i = 0; i < treeSize; i++)
    {
        int data;
        cin >> data;
        inOrder.push_back(data);
    }

    node *tree = buildTree(postOrder, inOrder);

    printLayorOrder(tree, treeSize);

    return 0;
}