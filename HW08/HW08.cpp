#include "BSTNode.cpp"

class BST
{

public:
    BSTNode* root;

    BST()
    {
        root = nullptr;
    }

    BSTNode *createNode(int value)
    {
        BSTNode *newNode = new BSTNode;
        newNode -> value = value;
        newNode -> left = nullptr;
        newNode -> right = nullptr;
        return newNode;
    }

    void insert(int value)
    {
        BSTNode *p, *previous;
        BSTNode *newNode = createNode(value);
        if(root == nullptr)
        {
            root = newNode;
        }
        else
        {
            p = root;
            while(p!=nullptr)
            {
                previous = p;
                if(p -> value > newNode -> value)
                {
                    p = p -> left;
                }
                else
                {
                    p = p -> right;
                }
            }
            if(previous -> value > newNode -> value)
            {
                previous -> left = newNode;
            }
            else
            {
                previous -> right = newNode;
            }
        }
    }


    void remove(int value)
    {
        root = deleteNode(root,value);
    }

    BSTNode * deleteNode(BSTNode *p, int value)
    {
        if(p == nullptr)
        {
            return p;
        }
        if(p->value > value)
        {
            p -> left = deleteNode(p->left, value);
            return p;
        }
        else if (p->value < value)
        {
            p->right = deleteNode(p->right, value);
            return p;
        }


        if(p->left == nullptr)
        {
            BSTNode *temp = p->right;
            delete p;
            return temp;
        }
        else if(p->right == nullptr)
        {
            BSTNode *temp = p->left;
            delete p;
            return temp;
        }
        else
        {
            BSTNode* twochild = p;
            BSTNode* child = p->right;
            while(child -> left != nullptr)
            {
                twochild = child;
                child = child -> left;
            }

            if(twochild != p)
                twochild -> left = child -> right;
            else
                twochild -> right = child -> right;

            p -> value = child -> value;
            delete child;
            return p;
        }
    }

    int get_depth(int value)
    {
        BSTNode *p;
        int depth = 0;
        p = root;
        while(p != nullptr && p->value != value)
        {
            if(value > p->value)
            {
                p = p -> right;
            }
            else
            {
                p = p -> left;
            }
            depth++;
        }
        if(p == nullptr)
            return -1;
        else
            return depth;
    }

};
