#include <iostream>

using namespace std;

void printArray();
void swap(int a, int b);
void heapSort();
void buildMaxHeap();
void heapify(int parent, int last);

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
  heapSort();

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

void heapSort()
{
  /**
   * Build a max heap from the array.
   * The max heap is a binary tree where the value of each node
   * is greater than or equal to the values of its children.
   * (See the buildMaxHeap function for more details.)
   */
  buildMaxHeap();

  /**
   * Now, after building the max heap:
   *  - the root of the tree is the maximum value.
   *  - the last leaf of the tree is the minimum value.
   *
   * This for loop will (repeatedly):
   *  1) swap the root with the last leaf of the tree.
   *  2) heapify the entire tree without the last leaf.
   * (Heapify: rebuild the max heap with the new root.)
   */
  for (int last = arrSize - 1; last > 0; last--)
  {
    /**
     * 1) Swap the root with the last leaf.
     */
    swap(0, last);

    /**
     * 2) Heapify the entire tree without the last leaf.
     * (See the heapify function for more details.)
     */
    heapify(0, last - 1);
  }
}

void buildMaxHeap()
{
  /**
   * This for loop iterates over the array from the middle to the beginning.
   *
   * The reason it starts from the middle is that in a heap represented as an array,
   * the second half of the array is made up of leaf nodes (nodes without children).
   * (Look at this: https://i.stack.imgur.com/7MkVp.png)
   */
  for (int i = (arrSize / 2) - 1; i >= 0; i--)
    /**
     * For each iteration, we heapify the sub-tree which has the root at the current index i.
     * (Once the i index reaches 0, the entire array will be a max heap.)
     */
    heapify(i, arrSize - 1);
}

void heapify(int parent, int last)
{
  /**
   * Since the array is represented as a binary tree (max heap is a binary tree),
   * the parent has:
   *  - left child at:  2 * i + 1
   *  - right child at: 2 * i + 2
   * (Look again at this: https://i.stack.imgur.com/7MkVp.png)
   */

  /**
   * We start by assuming that the left child is the bigger child.
   */
  int biggerChild = 2 * parent + 1;

  while (biggerChild <= last)
  {
    /**
     * If the left child is not the last element in the array,
     * it means that the parent has also a right child.
     */
    if (biggerChild < last)
      /**
       * If the right child is bigger than the left child,
       * then we consider the right child as the bigger child.
       */
      if (arr[biggerChild + 1] > arr[biggerChild])
        biggerChild++;

    /**
     * If the parent is smaller than the bigger child,
     * then we should swap them.
     */
    if (arr[parent] < arr[biggerChild])
    {
      swap(parent, biggerChild);

      /**
       * After swapping, prepare the variables for the next iteration.
       */
      parent = biggerChild;
      biggerChild = 2 * parent + 1;
    }

    /**
     * But, if the parent is already bigger than the bigger child,
     * then the heap is already built.
     */
    else
      break;
  }
}
