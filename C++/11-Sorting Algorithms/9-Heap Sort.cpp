//Heap Sort
//Time Complexity: Time complexity of heapify is O(Logn). 
//Time complexity of createAndBuildHeap() is O(n) and 
//overall time complexity of Heap Sort is O(nLogn).

//Space Complexity: O(1) auxiliary
//Stable: No
//In Place: Yes

//To understand heap sort watch the following videos:
// 1-    https://www.youtube.com/watch?v=zDlTxrEwxvg 
// 2-    https://www.youtube.com/watch?v=NEtwJASLU8Q&list=PLdo5W4Nhv31bEiyP4tclZMc5mP_X7OD7k&index=6
// 3-    https://www.youtube.com/watch?v=Q_eia3jC9Ts&list=PLdo5W4Nhv31bEiyP4tclZMc5mP_X7OD7k&index=7

#include<iostream>
using namespace std;

void HeapSort(int A[],int n);

void heapify(int A[], int n, int i);

void swap(int *a,int *b);

int main() {
    
    int size;
    cout<<"How many values you wanna enter:";
    cin>>size;
    
    int *A = new int[size];
    
    cout<<"Enter "<<size<<" values :"<<endl;
	for(int i=0;i<size;i++)
	cin>>A[i];
	
	HeapSort(A,size);
	    
	cout<<"Sorted Array is: ";
	for(int i=0; i<size; i++)
	cout<<A[i]<<"  ";
	cout<<endl;
	
	delete[] A;
	
	system("pause");
	return 0;
}

void HeapSort(int A[], int n){
	//as we know we start from last non-leaf element with largest index.
	for(int i=n/2 -1; i>=0; i--){
		heapify(A,n,i);                //Building of heap
	}
	
	//now picking each element one by one from last node and deletion
	for(int i=n-1; i>=0; i--){
		swap(&A[0],&A[i]); //it swap root node with last node.
		
		heapify(A,i,0);//here we pass 0 because deletion is always from root node.
	}
}


//function to swap two array values
void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void heapify(int A[],int n, int i){
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
    	heapify(A,n,largest);
	}
	
}
