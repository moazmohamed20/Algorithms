#include <iostream>

using namespace std;

void printArray();
void swap(int a, int b);
void quickSort(int first, int last);
int locatePivot(int first, int last);

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
  quickSort(0, arrSize - 1);

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

void quickSort(int first, int last)
{
  /**
   * This if condition checks if the current segment has more than one element.
   * Initially, we will consider the entire array as a big segment to sort.
   * (If first == last, then the segment has only one element.)
   */
  if (first < last)
  {
    /**
     * Calculate the pivot index of the current segment.
     * (pivot: المحور الذي يفصل بين الأرقام الأصغر والأكبر منه.)
     */
    int pivot = locatePivot(first, last);

    /**
     * Sort the elements before the pivot (recursively).
     */
    quickSort(first, pivot);
    /**
     * Sort the elements after the pivot (recursively).
     */
    quickSort(pivot + 1, last);
  }
}

/**
 * This function rearranges the elements of the segment so that:
 *  - all elements less than the pivot come before it.
 *  - all elements greater than the pivot come after it.
 */
int locatePivot(int first, int last)
{
  /**
   * The i pointer starts from the first element of the segment.
   * The j pointer starts from the last element of the segment.
   */
  int i = first;
  int j = last;

  /**
   * This outer loop continues until i and j cross each other.
   */
  while (i < j)
  {
    /**
     * (The pivot assumed to be the first element of the segment.)
     */

    /**
     * This inner loop moves the i pointer to the right until it finds an element > the pivot.
     * (Now, the i pointer is pointing to an element > the pivot in the left side of the segment.)
     */
    while (arr[i] <= arr[first])
      i++;

    /**
     * This inner loop moves the j pointer to the left until it finds an element < than the pivot.
     * (Now, the j pointer is pointing to an element <= than the pivot in the right side of the segment.)
     */
    while (arr[j] > arr[first])
      j--;

    /**
     * If i and j have not crossed each other, then swap the elements at i and j.
     */
    if (i < j)
      swap(i, j);
  }

  /**
   * When the previous loop finishes, all elements less than or equal to the pivot are to its left,
   * and all elements greater than the pivot are to its right.
   *
   * However, the pivot is still at the first element of the segment,
   * so we swap it with the element at the j position.
   *
   * Now, the pivot is in its final sorted position.
   */
  swap(first, j);

  /**
   * Finally, return the new position of the pivot (which is now the j position).
   * (This is used in the quickSort function to sort the elements before and after the pivot.)
   */
  return j;
}
