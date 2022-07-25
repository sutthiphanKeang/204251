#include <iostream>
#include <string>
#include "station.cpp"
using namespace std;

class Trip
{

public:
    Station* header;
    Station* trailer;
    Trip()
    {
        header = new Station;
        trailer = new Station;
        header->prev = NULL;
        header->next = trailer;
        trailer->prev = header;
        trailer->next = NULL;

    }
    void remove(Station* cur)
    {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
        cur = NULL;
    }
    void printList()
    {
        cout << "[ ";
        Station* ptr = header->next;
        while (ptr != trailer)
        {
            cout << ptr->name << " ";
            ptr = ptr->next;
        }
        cout << "]\n";
    }


    void insert_front(string newItem)
    {
        Station* newStation = new Station;
        newStation->name = newItem;
        newStation->prev = header;
        newStation->next = header->next;
        header->next->prev = newStation;
        header->next = newStation;

    }
    void insert_back(string newItem)
    {
        Station* newStation = new Station;
        newStation->name = newItem;
        newStation->prev = trailer->prev;
        newStation->next = trailer;
        trailer->prev->next = newStation;
        trailer->prev = newStation;
    }

    void remove_front()
    {
        if (header->next != trailer)
        {
            remove(header->next);
        }
    }
    void remove_back()
    {
        if (header->next != trailer)
        {
            remove(trailer->prev);
        }
    }

    Station* visit(int nStep, string stepText)
    {
        Station* cur = header->next;
        for(int i = 0; i < nStep; i++)
        {
            if(stepText[i] == 'R')
            {
                if (cur->next != trailer)
                    cur = cur->next;
            }
            if(stepText[i] == 'L')
            {
                if (cur->prev != header)
                    cur = cur->prev;
            }
        }
        return cur;

    }
};
