#include<iostream>
#include "HW01.cpp"
using namespace std;

int main()
{
  CardList L;
  L.insert_back("Pokemon");
  L.insert_back("Natu");
  L.insert_back("Steelix");

  Card * curr = L.head;
  while(curr!=NULL) {
    cout << curr->name << endl;
    curr = curr->next;
  }

  L.shuffle(1);
  curr = L.head;
  while(curr!=NULL) {
    cout << curr->name << endl;
    curr = curr->next;
  }

  return 0;
}
