#include <iostream>
#include <algorithm>
using namespace std;
class Ranking
{
private:
    int data[1000];
    int size;
public:
    Ranking(int n)
    {
        size = n;
    }
    void inputData()
    {
        for(int i=0; i<size; i++)
        {
            cin>>data[i];
        }
    }
    int binarySearch(int key)
    {
        int low = 0;
        int hi = size -1;
        int mid;

        while(low <= hi)
        {
            mid = (low + hi + 1) /2;
            if(key == data[mid])
            {
                return (mid + 1);
            }
            else
            {
                if(key < data[mid])
                {
                    low = mid + 1;
                }
                else
                {
                    hi = mid -1;
                }
            }
        }
        return (NULL);
    }
    void merge(int left, int mid, int right)
    {
        int ans[right+1];
        int x = left;
        int y = mid + 1;
        int z = left;

        while(x <= mid && y <= right)
        {
            if(data[x] > data[y])
            {
                ans[z] = data[x];
                x++;
            }
            else
            {
                ans[z] = data[y];
                y++;
            }
            z++;
        }
        if(y <= right)
        {
            for(int i = y; i<=right; i++)
            {
                ans[z] = data[i];
                z++;
            }
        }
        if(x <= mid)
        {
            for(int i = x; i<=mid; i++)
            {
                ans[z] = data[i];
                z++;
            }
        }
        for(int i = left; i <= right; i++)
        {
            data[i] = ans[i];
        }


    }
    void mergeSort(int left, int right)
    {
        int mid;
        mid = (right + left) / 2;
        if(left < right)
        {
            mergeSort(left, mid);
            mergeSort(mid+1, right);
        }
        merge(left, mid, right);

    }
    int show(int index)
    {
        return data[index-1];
    }
};

