#include"iostream"

using namespace std;

class CustomArray {
private:
	int size;
	int *mArray;

	void swap(int a, int b) {
		int temp = mArray[a];
		mArray[a] = mArray[b];
		mArray[b] = temp;
	}

	int locatePivot(int first, int last) {
		int i = first;
		int j = last;

		while (i < j)
		{
			// Find Big Value From Left
			while (mArray[i] <= mArray[first])
				i++;
			// Find Small Value From Right
			while (mArray[j] > mArray[first])
				j--;
			// If The [Small Value In Left] And [Big Value In Righ] Swap Them
			if (i < j)
				swap(i, j);
		}
		// Move The Pivot From First To Center
		swap(first, j);

		// Return Pivot Position
		return j;
	}

	void merge(int leftFirst, int leftLast, int rightFirst, int rightLast) {
		int tempArraySize = rightLast - leftFirst + 1;
		int *tempArray = new int[tempArraySize];
		int saveFirst = leftFirst;
		int index = 0;
		// Comparing First Index Of Both Halfs Until One Of Them Finish
		while ((leftFirst <= leftLast) && (rightFirst <= rightLast)) {
			if (mArray[leftFirst] < mArray[rightFirst]) {
				tempArray[index] = mArray[leftFirst];
				leftFirst++;
			}
			else {
				tempArray[index] = mArray[rightFirst];
				rightFirst++;
			}
			index++;
		}
		// If Anything Remainig In Left Half Add It
		while (leftFirst <= leftLast) {
			tempArray[index] = mArray[leftFirst];
			leftFirst++;
			index++;
		}
		// If Anything Remainig In Right Half Add It
		while (rightFirst <= rightLast) {
			tempArray[index] = mArray[rightFirst];
			rightFirst++;
			index++;
		}
		// Move All Ordered Items To Main Array
		for (int i = 0; i < tempArraySize; i++)
			mArray[saveFirst + i] = tempArray[i];
	}

	void buildMaxHeap() {
		for (int i = (size / 2) - 1; i >= 0; i--)
			heapify(i, size - 1);
	}

	void heapify(int parent, int last) {
		int checkChild = 2 * parent + 1;

		while (checkChild <= last) {
			// Focus On The Bigger Child Of Two
			if (checkChild < last && mArray[checkChild] < mArray[checkChild + 1])
				checkChild++;

			// If Child Is Bigger Than Parent
			if (mArray[checkChild] > mArray[parent]) {
				// Make The Child The New Parent
				swap(parent, checkChild);
				parent = checkChild;
				checkChild = 2 * parent + 1;
			}
			else {
				break;
			}
		}
	}

public:
	CustomArray(int initialSize = 100) {
		size = 0;
		mArray = new int[initialSize];
	}

	void insert(int value) { mArray[size++] = value; }

	int get(int index) { return mArray[index]; }

	int getSize() { return size; }

	void selectionSort() {
		for (int i = 0; i < size; i++) {

			// Find Minimum Value After i
			int minPos = i;
			for (int j = i; j < size; j++)
				if (mArray[j] < mArray[minPos])
					minPos = j;

			// Swap Current Index With Minimum Value
			swap(i, minPos);
		}
	}

	void insertionSort() {
		for (int i = 1; i < size; i++) {
			// If Current Index Is Not In Right Position
			if (mArray[i] < mArray[i - 1]) {
				// Move It Back To Its Right Position
				for (int j = i; j > 0; j--)
					if (mArray[j] < mArray[j - 1])
						swap(j, j - 1);
			}
		}
	}

	void bubbleSort() {
		int lastIndex = size - 1;
		while (lastIndex > 0) {

			for (int i = 0; i < lastIndex; i++)
				if (mArray[i] > mArray[i + 1])
					swap(i, i + 1);

			lastIndex--;
		}
	}

	void quickSort(int first, int last) {
		if (first < last) {
			int pivot = locatePivot(first, last);
			quickSort(first, pivot);
			quickSort(pivot + 1, last);
		}
	}

	void mergeSort(int first, int last) {
		if (first < last) {
			int mid = (first + last) / 2;
			mergeSort(first, mid);
			mergeSort(mid + 1, last);
			merge(first, mid, mid + 1, last);
		}
	}

	void heapSort() {
		buildMaxHeap();
		for (int i = size - 1; i > 0; i--) {
			// Swap The Root With Last Leaf
			swap(0, i);
			// Heapify Without The Root
			heapify(0, i - 1);
		}
	}

};

int main() {
	CustomArray customArray;

	// Generating 10 Random Numbers
	for (int i = 0; i < 10; i++)
		customArray.insert(rand() % 100);

	cout << "Random Array Before Sorting:\n";
	for (int i = 0; i < 10; i++)
		cout << customArray.get(i) << "\t";

	customArray.heapSort();

	cout << "\n\nRandom Array After Sorting:\n";
	for (int i = 0; i < 10; i++)
		cout << customArray.get(i) << "\t";


	getchar();
	return 0;
}