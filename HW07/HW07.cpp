#include<iostream>
using namespace std;
class Router
{

	int capacity; // maximum possible size of min heap
	int heap_size; // Current number of elements in min heap
public:
    int *data; // pointer to array of elements in heap
	Router(int cap){
        capacity = cap;
        heap_size = -1;
        data = new int[cap];
    }
	int parent(int i) { return (i-1)/2; }
	int left(int i) { return (2*i + 1); }
	int right(int i) { return (2*i + 2); }
	int removeMin(){
        if(heap_size <= 0)
            return NULL;
        if(heap_size == 1){
            heap_size--;
            return data[0];
        }
        int root = data[0];
        data[0] = data[heap_size - 1];
        heap_size--;
        downHeap(0);
        return root;
    }
	int min() {
        return data[0];
	}
	void insert(int k){
        if(heap_size == capacity){
            return;
        }
        heap_size++;
        int i = heap_size;
        data[i] = k;
        while(i != 0 && data[parent(i)] > data[i]){
            swap(data[i], data[parent(i)]);
            i = parent(i);
        }
    }
	void downHeap(int i){
        int l = left(i);
        int r = right(i);
        int small = i;
        if(l <= heap_size && data[l]< data[i])
            small = l;
        if(r <= heap_size && data[r] < data[small])
            small =r;
        if(small != i){
            swap(data[i],data[small]);
            downHeap(small);
        }
    }

	void reset(int k){
        swap(data[0],k);
        downHeap(0);
    }
};

