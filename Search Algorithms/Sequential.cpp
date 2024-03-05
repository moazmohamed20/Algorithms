#include <iostream>

using namespace std;

void printArray();
int sequentialSearch(int value);

const int arrSize = 10;
int arr[arrSize];

int main()
{
  // Filling the array with random numbers...
  for (int i = 0; i < arrSize; i++)
    arr[i] = rand() % 100;

  cout << "Random Array:\n";
  printArray();

  cout << "\nEnter A Number To Search For: ";
  int x;
  cin >> x;
  cout << "The Number At Index: " << sequentialSearch(x);

  return 0;
}

void printArray()
{
  for (int i = 0; i < arrSize; i++)
    cout << arr[i] << "\t";
  cout << "\n";
}

int sequentialSearch(int value)
{
  /**
   * This for loop iterates over the entire array form the first to the last element.
   */
  for (int i = 0; i < arrSize; i++)
  {
    /**
     * If the i-th element of the array is equal to the value, immediately returns the current index i.
     */
    if (arr[i] == value)
      return i;
  }

  /**
   * If the previous loop iterates over the entire array and does not find the value, return -1.
   * (This is a common convention to indicate that the searched value was not found.)
   */
  return -1;
}