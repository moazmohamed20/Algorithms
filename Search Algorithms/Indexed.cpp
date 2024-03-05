#include <iostream>
// Unnecessary, but it's used to format the output of printIndex().
#include <iomanip>

using namespace std;

void printArray();
void sortArray();
void printIndex();
void createIndex(int sectionSize);
int indexedSearch(int value);

const int arrSize = 11;
int arr[arrSize] = {1, 15, 54, 92, 165, 296, 462, 512, 654, 789, 888};

int main()
{
  // Filling the array with random numbers...
  for (int i = 0; i < arrSize; i++)
    arr[i] = rand() % 100;

  cout << "Array:\n";
  sortArray();
  printArray();

  cout << "Index:\n";
  createIndex(3);
  printIndex();

  cout << "Enter A Number To Search For: ";
  int x;
  cin >> x;
  cout << "\nThe Number At Index: " << indexedSearch(x);

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

/**
 * This structure is used to represent a section in the index.
 * Each section has a `start` value and an `index` value.
 * The `start` value is the first value of the corresponding section in the original array.
 * The `index` value is the index of that value in the original array.

*/
struct Section
{
  int start;
  int index;
};

Section *sections;
int sectionsCount;

/**
 * This function is used to create an index for an array, to speed up search operations.
 * The index is divided into sections, where each section represents a segment of the original array.
 * The size of these sections is determined by the `sectionSize` argument.
 */
void createIndex(int sectionSize)
{
  /**********************************************************
   * Example:
   * ﹉﹉﹉﹉﹉
   * arr = {1, 15, 54, 92, 165, 296, 462, 512, 654, 789, 888}
   *        ‾          ‾‾            ‾‾‾            ‾‾‾
   * arrSize       = 11
   * sectionSize   = 3
   * sectionsCount = 11 / 3 = 3.6666 ≈ 4 Sections
   *
   * Index:
   * ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
   * ┣━ START                        INDEX ┃
   * ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
   * ┣━   1 ............................ 0 ┃
   * ┣━  92 ............................ 3 ┃
   * ┣━ 462 ............................ 6 ┃
   * ┣━ 789 ............................ 9 ┃
   * ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
   **********************************************************/

  /**
   * This line calculates the number of sections
   */
  sectionsCount = arrSize / sectionSize;

  /**
   * If the size of the original array is not a multiple of the section size,
   * it means there are some elements at the end of the array that don't make up a full section.
   * So we add one more section to group these elements.
   */
  if (arrSize % sectionSize != 0)
    sectionsCount++;

  /**
   * This line allocates memory for an array of `Section` structures.
   * Each structure represents a section.
   */
  sections = new Section[sectionsCount];

  /**
   * The for loop iterates over each section.
   * For each section:
   *  - it sets the `start` to the first value of the corresponding segment in the original array.
   *  - it sets the `index` to the index of that value in the original array. (i * sectionSize)
   */
  for (int i = 0; i < sectionsCount; i++)
  {
    sections[i].start = arr[i * sectionSize];
    sections[i].index = i * sectionSize;
  }
}

void printIndex()
{
  cout << "+-----------+\n";
  for (int i = 0; i < sectionsCount; i++)
    cout << "| " << setw(2) << sections[i].start << " ... " << setw(2) << sections[i].index << " |\n";
  cout << "+-----------+\n";
}

int indexedSearch(int value)
{
  /**
   * This variable will be used to iterate over the sections in the index.
   */
  int sectionNo = 0;

  /**
   * This while loop continues to increment sectionNo as long as:
   *  - the sectionNo is less than sectionsCount. (to avoid going out of bounds)
   *  - the search value is greater than the `start` value of the current section.
   *    (because we aim to land on a section that starts with a `value` greater than the search value,
   *     then we search at the section before it)
   */
  while (sectionNo < sectionsCount && value > sections[sectionNo].start)
    sectionNo++;

  /**
   * This variable will be used to store the last index of the current section.
   */
  int lastIndex;

  /**
   * Special Case:
   *
   * If the sectionNo is equal to sectionsCount, it means that the search value may be in the last section.
   * So we set lastIndex to the size of the original array.
   */
  if (sectionNo == sectionsCount)
  {
    lastIndex = arrSize;
  }

  /**
   * Special Case:
   *
   * If (luckily) the search value is equal to the `start` value of the current section,
   * we just return the `index` value of the current section.
   */
  else if (value == sections[sectionNo].start)
  {
    return sections[sectionNo].index;
  }

  /**
   * Otherwise, we set lastIndex to the `index` value of the current section.
   * (Because the search will start from the beginning of the previous section.)
   */
  else
  {
    lastIndex = sections[sectionNo].index;
  }

  /**
   * Sequential Search (any search algorithm can be used here).
   *
   * Notice that the search starts from the beginning of the previous section:
   *  - i =sections[sectionNo - 1].index
   */
  for (int i = sections[sectionNo - 1].index; i < lastIndex; i++)
    if (arr[i] == value)
      return i;

  /**
   * If the value is not found after all these steps, return -1.
   * (This is a common convention to indicate that the searched value was not found.)
   */
  return -1;
}
