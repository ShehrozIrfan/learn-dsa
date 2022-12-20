#include<iostream>
using namespace std;

//Maximum size of Heap.
#define MAX 100    

void insertHeap(int A[], int n, int key);
void insertHeapify(int A[], int n, int i);

void deleteRoot(int A[], int n);
void deleteHeapify(int A[], int n, int i);

void swap(int *a,int *b);
int main() {
    
    int arr[MAX]={10, 5, 3, 2, 4, 0};
    
	//key is the value that we wanna insert in heap.
    int key=25;
    
	//Total no. of elements in an array
    int n=6;
    
	//insertion
    insertHeap(arr, n, key);
	
	//to display
	cout<<"Max Heap is(After insertion) is: ";
	for(int i=0; i<n+1; i++)
	cout<<arr[i]<<"  ";
	cout<<endl;
	
	//deletion of root node
	deleteRoot(arr,n);
	
	cout<<"Max Heap(After Deletion) is: ";
	for(int i=0; i<n+1; i++)
	cout<<arr[i]<<"  ";
	cout<<endl;
	
	
	system("pause");
	return 0;
}
//function to swap two array values
void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
//Function to insert a node in Max heap
void insertHeap(int A[], int n, int key) {
    //first of all we increment the size of array
    //to add that node on last
    //because in heap insertion is at last index
    n=n+1;
    //now we put the value in last index
    //as we have start index=0 so last index will be n-1
    A[n-1]=key;
    //it will call the insertHeapify method that will build
    //a max heap
    insertHeapify(A,n,n-1);

}
//function that build a max heap
void insertHeapify(int A[], int n, int i){
	//As the inserted node is at last index 
	//so we first find its parent and compare that node
	//with its parent. if inserted node is greater than 
	//its parent then we will swap inserted node and parent.
	int parent=(i-1)/2;
	
	if(A[parent]>0){
		
		if(A[i]>A[parent]){
			
			swap(&A[i],&A[parent]);
			
			//recursive call
			insertHeapify(A,n,parent);
		}
	}
}

//Function to delete the root node
void deleteRoot(int A[],int n){
	//As we know for deletion in max heap 
	//first we place the last node
	//at the place of root node and then build the max heap
	int lastElement=A[n-1];
	//placing the last element at root 
	A[0]=lastElement;
	//decrementing the size becuase last element is placed
	//at the root node and root node is deleted
	n=n-1;
	
	deleteHeapify(A,n,0);
}

void deleteHeapify(int A[],int n, int i){
	//setting the largest value = root node
	int largest=i;
	//finding the left child of root node
	int l= (2 * i) + 1;
	//finding the right child of root node
	int r= (2 * i) + 2;
	//if left child is < size and left child is greater than
	//largest then largest = left child.
	if(l<n && A[l]>A[largest]){
		largest=l;
	}
	//if right child is < size and right child is greater than
	//largest then largest = right child
	if(r<n && A[r]>A[largest]){
	largest=r;
    }
    //now as we have updated the largest 
    //so we check if largest != i then we will swap
    if(largest!=i){
    	swap(&A[i],&A[largest]);
    	
    	//recursive call
    	deleteHeapify(A,n,largest);
	}
	
}
