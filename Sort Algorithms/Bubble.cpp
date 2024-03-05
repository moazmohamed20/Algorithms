#include <iostream>

using namespace std;

void printArray();
void swap(int a, int b);
void bubbleSort();

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
  bubbleSort();

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

void bubbleSort()
{
  /**
   * The lastIndex represents: the LAST UNSORTED ELEMENT in the array.
   */
  int lastIndex = arrSize - 1;

  /**
   * This while loop continues as long as lastIndex is greater than 0.
   * (If the lastIndex equals to 0, it means that the array is sorted.)
   */
  while (lastIndex > 0)
  {
    /**
     * This for loop iterates over the array from the first element to the lastIndex element.
     */
    for (int i = 0; i < lastIndex; i++)
    {
      /**
       * If the current element is greater than the next one,
       * swap their positions to move the greater one to the right "bubble up".
       */
      if (arr[i] > arr[i + 1])
        swap(i, i + 1);
    }

    /**
     * This line decreases the value of lastIndex by 1 after each pass through the array.
     * This is because after each pass, the largest element is "bubbled" to the end of the array,
     * so there's no need to consider it in the next pass.
     */
    lastIndex--;
  }
}
