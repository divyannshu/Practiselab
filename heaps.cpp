#include <iostream>
using namespace std;
class heap
{
    int capacity = 100;
    int *arr = new int[capacity];
    int heapsize = 0;

public:
    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    int Parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    void insert(int key)
    {
        if (heapsize == capacity)
        {
            cout << "Heap full" << endl;
            return;
        }
        heapsize++;
        int i = heapsize - 1;
        arr[i] = key;
        while (i >= 0 && arr[i] < arr[Parent(i)])
        {
            swap(&arr[i], &arr[Parent(i)]);
            i = Parent(i);
        }
    }
    void decreaseKey(int i, int new_value)
    {
        if (new_value > arr[i])
        {
            cout << "The new key is larger" << endl;
            return;
        }
        arr[i] = new_value;
        while (i >= 0 && arr[i] < arr[Parent(i)])
        {
            swap(&arr[i], &arr[Parent(i)]);
            i = Parent(i);
        }
    }
    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest;
        if (l <= heapsize && arr[l] < arr[i])
            smallest = l;
        else
            smallest = i;
        if (r <= heapsize && arr[r] < arr[smallest])
            smallest = r;
        if (smallest != i)
            swap(&arr[i], &arr[smallest]);
        MinHeapify(smallest);
    }
    int getMin()
    {
        if (heapsize <= 0)
            return 0;
        return arr[0];
    }
    int extractmin()
    {
        if (heapsize <= 0)
            return 0;
        if (heapsize == 1)
        {
            return arr[0];
            heapsize--;
        }
        int root = arr[0];
        arr[0] = arr[heapsize - 1];
        heapsize--;
        MinHeapify(0);
        return root;
    }
};
int main()
{
    heap h;
    h.insert(10);
    h.insert(18);
    h.insert(5);
    h.insert(8);
    h.insert(2);
    h.insert(20);
    h.insert(11);
    // cout << "Extract MIN" << h.extractmin() << endl;
    cout << "MIN" << h.getMin() << endl;
    return 0;
}