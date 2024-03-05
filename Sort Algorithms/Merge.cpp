#include <iostream>

using namespace std;

void printArray();
void swap(int a, int b);
void mergeSort(int first, int last);
void merge(int leftFirst, int leftLast, int rightFirst, int rightLast);

const int arrSize = 10;
int arr[arrSize];

int main()
{
  // Filling the array with random numbers...
  for (int i = 0; i < arrSize; i++)
    arr[i] = rand() % 100;

  cout << "Array Before Sorting:\n";
  printArray();

  cout << "\nSorting...\n";
  mergeSort(0, arrSize - 1);

  cout << "\nArray After Sorting:\n";
  printArray();

  return 0;
}

void printArray()
{
  for (int i = 0; i < arrSize; i++)
    cout << arr[i] << "\t";
  cout << "\n";
}

void swap(int a, int b)
{
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

/**
 * Look at this: https://miro.medium.com/v2/1*KKOLPjSopMYlHi0dvwb-3Q.png
 */
void mergeSort(int first, int last)
{
  /**
   * This if condition checks if the current segment has more than one element.
   * Initially, we will consider the entire array as a big segment to sort.
   * (If first == last, then the segment has only one element.)
   */
  if (first < last)
  {
    /**
     * Calculate the middle index of the segment.
     */
    int mid = (first + last) / 2;

    /**
     * Here where the segment is recursively split into halves:
     *   - The left half:  [fist   ->  mid].
     *   - The right half: [mid+1  ->  last].
     *
     * These calls will continue to split the segment until they are of size = 1.
     */
    mergeSort(first, mid);
    mergeSort(mid + 1, last);

    /**
     * Finally, merge the two halves together in a single sorted array.
     * (See the merge function for more details.)
     */
    merge(first, mid, mid + 1, last);
  }
}

/**
 * This function is responsible for merging two unsorted sub arrays into a single sorted array.
 */
void merge(int leftFirst, int leftLast, int rightFirst, int rightLast)
{
  /**
   * leftFirst and leftLast represent the starting and ending indices of the left half.
   * rightFirst and rightLast represent the starting and ending indices of the right half.
   */

  /**
   * Calculates the size of a tempArray, which is used to hold the merged halves.
   * The size is calculated as the sum of the sizes of the two halves.
   */
  int tempArraySize = (leftLast - leftFirst + 1) + (rightLast - rightFirst + 1);
  // or:            = rightLast - leftFirst + 1;
  int *tempArray = new int[tempArraySize];

  /**
   * saveFirst is used to remember the starting index of the left half in the original array.
   * (This is used to copy the sorted elements back to the original array, used later in the last loop.)
   */
  int saveFirst = leftFirst;

  /**
   * index is used to keep track of the current position in tempArray.
   */
  int index = 0;

  /**
   * This while loop compares the elements at the beginning of both halfs.
   */
  while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
  {
    /**
     * If the element in the beginning of the left half is smaller,
     * it is copied to tempArray and the leftFirst index is incremented.
     */
    if (arr[leftFirst] < arr[rightFirst])
    {
      tempArray[index] = arr[leftFirst];
      leftFirst++;
    }
    /**
     * If the element in the beginning of the right half is smaller,
     * it is copied to tempArray and the rightFirst index is incremented.
     */
    else
    {
      tempArray[index] = arr[rightFirst];
      rightFirst++;
    }

    /**
     * index is incremented to point to the next position in tempArray.
     */
    index++;
  }

  /**
   * The next two while loops handle the situation where
   * one of the halves half has been completely copied to tempArray,
   * while the other half still has elements.
   */
  /**
   * Copy the remaining elements of the left half to tempArray.
   */
  while (leftFirst <= leftLast)
  {
    tempArray[index] = arr[leftFirst];
    leftFirst++;
    index++;
  }
  /**
   * Copy the remaining elements of the right half to tempArray.
   */
  while (rightFirst <= rightLast)
  {
    tempArray[index] = arr[rightFirst];
    rightFirst++;
    index++;
  }

  /**
   * This for loop iterates over the tempArray and copies its elements back to the original array.
   * (Remember the saveFirst index!, it is used to copy the elements back to the correct positions.)
   */
  for (int i = 0; i < tempArraySize; i++)
    arr[saveFirst + i] = tempArray[i];
}
