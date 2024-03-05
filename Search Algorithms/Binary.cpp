#include <iostream>

using namespace std;

void printArray();
void sortArray();
int binarySearch(int value);

const int arrSize = 10;
int arr[arrSize];

int main()
{
  // Filling the array with random numbers...
  for (int i = 0; i < arrSize; i++)
    arr[i] = rand() % 100;

  cout << "Array:\n";
  sortArray();
  printArray();

  cout << "\nEnter A Number To Search For: ";
  int x;
  cin >> x;
  cout << "The Number At Index: " << binarySearch(x);

  return 0;
}

void printArray()
{
  for (int i = 0; i < arrSize; i++)
    cout << arr[i] << "\t";
  cout << "\n";
}

void sortArray()
{
  /**
   * Selection Sort (any sorting algorithm can be used here).
   */
  for (int i = 0; i < arrSize; i++)
  {
    int minPos = i;
    for (int j = i; j < arrSize; j++)
      if (arr[j] < arr[minPos])
        minPos = j;

    /**
     * Swapping
     */
    int temp = arr[i];
    arr[i] = arr[minPos];
    arr[minPos] = temp;
  }
}

int binarySearch(int value)
{
  /**
   * Initially, we will consider the entire array as a segment to search in.
   */
  int first = 0;
  int last = arrSize - 1;

  /**
   * The while loop continues as long as the first index <= to the last index.
   * (Which means that the segment is not empty.)
   */
  while (first <= last)
  {

    /**
     * mid is calculated as the index of the middle element in the current segment.
     */
    int mid = (first + last) / 2;

    /**
     * If (luckily) the value is equal to arr[mid],
     * return mid (which is now the index of the found element).
     */
    if (value == arr[mid])
      return mid;

    /**
     * If the value is grater than arr[mid], it means that
     * the value may be in the second half of the current segment.
     * Therefore, first moved forward to (mid + 1).
     */
    else if (value > arr[mid])
      first = mid + 1;

    /**
     * If the value is less than arr[mid], it means that
     * the value may be in the first half of the current segment.
     * Therefore, last moved backward to (mid - 1).
     */
    else if (value < arr[mid])
      last = mid - 1;
  }

  /**
   * If the while loop exits, it means that value was not found in the array.
   * In this case, the function returns -1.
   * (This is a common convention to indicate that the searched value was not found.)
   */
  return -1;
}
