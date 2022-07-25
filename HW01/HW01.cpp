#include <iostream>
#include <string>
#include "card.cpp"

using namespace std;

class CardList{

public:
    int i;
	Card* head;
    CardList(){
        i = 0;
        head = NULL;
    }

    Card* find(int index){
        if((index < 1) || index > i)
            return NULL;
        else{
            Card* cur = head;
            for(int skip = 1;skip<index;skip++){
                cur = cur->next;
            }
            return cur;
        }
    }
	void pop_back(){
        if (head != NULL){
            i--;
            Card* cur;
            if ( i == 0){
                cur = head;
                head = NULL;

            }else{
                Card*last = find(i);
                cur = last->next;
                last->next = NULL;
            }
            delete cur;
            cur = NULL;
        }
	}


    void insert_back(string newItem){
        Card *newCard = new Card;
        newCard->name = newItem;
        newCard->next = NULL;
        if (head == NULL || i == 0){
            head = newCard;
            i++;
        }
        else{
            Card* last = find(i);
            last->next = newCard;
            i++;
        }

    }

    void shuffle(int pos){ //1<=pos<=size-1
        if (head != NULL && i >= 2 && pos < i){
            Card* cur = find(pos);
            Card* cur_n = cur->next;
            Card* last = find(i);
            last->next = head;
            head = cur_n;
            cur->next = NULL;
        }

    }

    void printCardList(){
        /*
         DO NOT DELETE OR EDIT
         */
        cout << "[ ";
        Card* ptr = head;
        while(ptr!=NULL){
            cout << ptr->name << " ";
            ptr = ptr->next;
        }
        cout << "]\n";
    }
};
