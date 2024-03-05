#include <iostream>

using namespace std;

void printArray();
void swap(int a, int b);
void selectionSort();

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
  selectionSort();

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

void selectionSort()
{
  /**
   * This outer for loop iterates over the entire array.
   * For each iteration, it assumes the first element of the unsorted part is the smallest.
   * (Initially, the unsorted part is the whole array, but after each iteration the size of the unsorted part decreases by one)
   */
  for (int i = 0; i < arrSize; i++)
  {
    /**
     * The minPos variable is initialized to hold the position of the minimum element.
     */
    int minPos = i;

    /**
     * This inner for loop starts from the current position i and iterates until the end of the array.
     * This loop is used to find the actual minimum element in the unsorted part of the array.
     * If a smaller element than the current minimum is found, minPos is updated to the index of this new minimum.
     */
    for (int j = i; j < arrSize; j++)
    {
      if (arr[j] < arr[minPos])
        minPos = j;
    }

    /**
     * The swap function is called to swap the found minimum element with the first element of the unsorted part.
     */
    swap(minPos, i);
  }
}
