#include"iostream"

using namespace std;

class CustomArray {
private:
	int size;
	int *mArray;

public:
	CustomArray(int initialSize = 100) {
		size = 0;
		mArray = new int[initialSize];
	}

	void insert(int value) { mArray[size++] = value; }

	int get(int index) { return mArray[index]; }

	int getSize() { return size; }

};

int main() {


	getchar();
	return 0;
}