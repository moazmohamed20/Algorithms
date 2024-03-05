#include <iostream>

using namespace std;

void printArray();
void swap(int a, int b);
void insertionSort();

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
  insertionSort();

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

void insertionSort()
{
  /**
   * This outer for loop starts from the second element (index 1) and iterates through the entire array.
   * This loop represents the card you are currently trying to place in the sorted portion of the array.
   */
  for (int i = 1; i < arrSize; i++)
  {
    /**
     * This if statement that checks if the current element is smaller than the previous one.
     * If it is, it means that this element is not in its correct position
     * and needs to be moved back to the correct place in the sorted part of the array.
     */
    if (arr[i] < arr[i - 1])
    {
      /**
       * To find the correct position, this for loop starts from the current element
       * and goes backwards to the start of the array.
       */
      for (int j = i; j > 0; j--)
      {
        /**
         * This if statement that checks if the current element is smaller than the previous one.
         * If it is, the swap function is called to swap these two elements.
         * (This process continues until the element is in its correct position.)
         */
        if (arr[j] < arr[j - 1])
          swap(j, j - 1);
      }
    }
  }
}
