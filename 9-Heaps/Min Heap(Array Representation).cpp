#include<iostream>
using namespace std;

void swap(int *a, int *b);

class MinHeap {
private:
	int *harr; //pointer to array of elements in heap
	int capacity; //maximum size of min heap
	int heap_size;//current number of elements in min heap
public:
	//constructor
	MinHeap(int cap); 

	//returns the parent node
	int parent(int i) {
		return (i - 1) / 2;
	}
	//returns the left child of parent node
	int left(int i) {
		return (2 * i) + 1;
	}
	//returns the right child of parent node
	int right(int i) {
		return (2 * i) + 2;
	}
	//returns the minimum value
	int getMin() {
		return harr[0];
	}
	void minHeapify(int i);

	void insertKey(int k);
	void display();
};

//Constructor
MinHeap::MinHeap(int cap) {
	harr = new int[cap];
	capacity = cap;
	heap_size = 0;
}

void MinHeap::minHeapify(int i) {
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		minHeapify(smallest);
	}
}
//Function to insert a node in min heap
void MinHeap::insertKey(int k) {
	if (heap_size == capacity) {
		cout << "Overflow: couldn't insert" << endl;
		return;
	}
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;
	while (i != 0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}

}


//display values
void MinHeap::display() {
	cout << "Min Heap is : ";
	for (int i = 0; i < capacity; i++) {
		cout << harr[i] << "  ";
	}
	cout << endl;
}

int main() {

	MinHeap m(5);
	m.insertKey(5);
	m.insertKey(13);
	m.insertKey(2);
	m.insertKey(0);
	m.insertKey(55);
	m.display();
	cout << m.parent(0) << endl;
	cout << m.left(0) << endl;
	cout << m.right(0) << endl;
	cout << m.getMin() << endl;
	
	
	system("pause");
	return 0;
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}