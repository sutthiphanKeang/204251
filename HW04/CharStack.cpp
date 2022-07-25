class Stack_node
{
public:
    char input;
    Stack_node* next;

    Stack_node() {}
    Stack_node(const Stack_node &i)
    {
        input = i.input;
    }
};
class CharStack
{
public:
    Stack_node* head;
    CharStack()   // constructor
    {
        head = nullptr;
    }

    void push(char new_item)
    {
        Stack_node * new_head = new Stack_node();
        new_head->input = new_item;
        new_head -> next = head;
        head = new_head;
    }

    char pop()
    {
        if(!isEmpty())
        {
            Stack_node * ret = head;
            head = head->next;
            char ans = ret->input;
            delete ret;
            ret = nullptr;
            return ans;
        }
    }

    char top()
    {
        return head->input;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }
};
