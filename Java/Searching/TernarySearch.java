// Java program to illustrate
// recursive approach to ternary search

// Steps to perform Ternary Search: 

// First, we compare the key with the element at mid1. If found equal, we return mid1.
// If not, then we compare the key with the element at mid2. If found equal, we return mid2.
// If not, then we check whether the key is less than the element at mid1. If yes, then recur to the first part.
// If not, then we check whether the key is greater than the element at mid2. If yes, then recur to the third part.
// If not, then we recur to the second (middle) part.

// Time Complexity: O(log3n)
// Auxiliary Space: O(log3n)

class TernarySearch {

	// Function to perform Ternary Search
	static int ternarySearch(int l, int r, int key, int ar[])
	{
		if (r >= l) {

			// Find the mid1 and mid2
			int mid1 = l + (r - l) / 3;
			int mid2 = r - (r - l) / 3;

			// Check if key is present at any mid
			if (ar[mid1] == key) {
				return mid1;
			}
			if (ar[mid2] == key) {
				return mid2;
			}

			// Since key is not present at mid,
			// check in which region it is present
			// then repeat the Search operation
			// in that region

			if (key < ar[mid1]) {

				// The key lies in between l and mid1
				return ternarySearch(l, mid1 - 1, key, ar);
			}
			else if (key > ar[mid2]) {

				// The key lies in between mid2 and r
				return ternarySearch(mid2 + 1, r, key, ar);
			}
			else {

				// The key lies in between mid1 and mid2
				return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
			}
		}

		// Key not found
		return -1;
	}

	// Driver code
	public static void main(String args[])
	{
		int l, r, p, key;

		// Get the array
		// Sort the array if not sorted
		int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		// Starting index
		l = 0;

		// end element index
		r = 9;

		// Checking for 5

		// Key to be searched in the array
		key = 5;

		// Search the key using ternarySearch
		p = ternarySearch(l, r, key, ar);

		// Print the result
		System.out.println("Index of " + key + " is " + p);

		// Checking for 50

		// Key to be searched in the array
		key = 50;

		// Search the key using ternarySearch
		p = ternarySearch(l, r, key, ar);

		// Print the result
		System.out.println("Index of " + key + " is " + p);
	}
}
