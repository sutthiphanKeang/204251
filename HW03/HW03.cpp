#include <iostream>
#include "term.cpp"
using namespace std;
class Polynomial
{
public:
    int i;
    Poly_node* head;
    Polynomial()
    {
        i = 0;
        head = NULL;
    }
    void addTerm(int coef, int exponent)
    {
        Poly_node* newPtr = new Poly_node;
        newPtr->coef = coef;
        newPtr->exponent = exponent;
        newPtr->next = NULL;
        if (head == NULL)
        {
            head = newPtr;
            i++;
        }
        else if (head != NULL && i == 1)
        {
            if (exponent > head->exponent)
            {
                newPtr->next = head;
                head = newPtr;
            }
            else if (exponent < head->exponent)
            {
                head->next = newPtr;
            }
            else if (exponent == head->exponent)
            {
                head->coef = head->coef + coef;
            }
            i++;
        }
        else if (head != NULL && i != 1)
        {
            Poly_node* cur = head;
            if(head->exponent < newPtr->exponent)
            {
                newPtr->next = head;
                head = newPtr;
            }
            else if (head->exponent == newPtr->exponent)
            {
                head->coef = head->coef + coef;
            }
            else
            {
                while(cur->next != NULL && cur->next->exponent > exponent)
                {
                    cur = cur->next;
                }
                if (cur->next == NULL)
                {
                    cur->next = newPtr;
                }
                else
                {
                    if(cur->next->exponent == exponent)
                        cur->next->coef = cur->next->coef + coef;
                    else if (cur->next->exponent != exponent)
                    {
                        newPtr->next = cur->next;
                        cur->next = newPtr;
                    }
                }
            }
        }
    }
    void printPolynomial()
    {
        cout<<"[ ";
        Poly_node* ptr = head;
        while(ptr!=NULL)
        {
            if(ptr->coef==0)
            {

            }
            else
            {
                cout<< ptr->coef<<"X^{"<<ptr->exponent<<"} ";
            }
            ptr = ptr->next;
        }
        cout<<"]\n";
    }
    void plus(Polynomial f2)
    {
        Poly_node* cur = f2.head;
        while(cur != NULL)
        {
            addTerm(cur->coef, cur->exponent);
            cur = cur->next;
        }
    }
    void minus(Polynomial f2)
    {
        Poly_node* cur = f2.head;
        while(cur != NULL)
        {
            addTerm((cur->coef * -1), cur->exponent);
            cur = cur->next;
        }
    }
};



