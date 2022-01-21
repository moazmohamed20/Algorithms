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

};

int main() {
	CustomArray customArray;

	// Generating 10 Random Numbers
	for (int i = 0; i < 10; i++)
		customArray.insert(rand() % 100);

	cout << "Random Array Before Sorting:\n";
	for (int i = 0; i < 10; i++)
		cout << customArray.get(i) << "\t";

	customArray.quickSort(0, 9);

	cout << "\n\nRandom Array After Sorting:\n";
	for (int i = 0; i < 10; i++)
		cout << customArray.get(i) << "\t";


	getchar();
	return 0;
}