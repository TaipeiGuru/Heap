// This is Heap, which is a max heap of 100 integers. Last modified by Jason Randolph on 3-3-23.

// Imports
#include <iostream>
#include <cstring>
#include <fstream>

// Help with floor() and the associated import from https://www.scaler.com/topics/floor-in-cpp/
#include <cmath>

using namespace std;

// Function prototypes
void insertNum(int* maxHeap, int num, int counter);
void displayHeap(int* maxHeap, int index, int tabCounter);
void heapify(int* maxHeap, int index);
void reverseHeapify(int* maxHeap, int index);
int removeLargest(int* maxHeap);
void removeAll(int* maxHeap);
void fileAdd(int* maxHeap);

int main() {
	// Creating the array, setting the 0 index to an arbitrary number, and setting the rest of the values to 0.
  int maxHeap[101];
  maxHeap[0] = -2;
  for(int i = 1; i < 101; i++) {
    maxHeap[i] = 0; 
  }
  char input[20];

  cout << "Welcome to Heap!" << endl;
  
  // Standard repeating message sequence using bool and while loop.
  bool active = true;
  while(active == true) {
    cout << "\nYour commands are \"INSERT,\" \"REMOVE_LARGEST,\" \"REMOVE_ALL,\" \"DISPLAY,\" and \"QUIT.\"" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(10000, '\n');
    
    /* If the user wants to input something, ask them if they want to input a number or file. If number, ask for the number and then 
     * pass it into the insertNum function. If file, run the fileAdd function. */
    if(strcmp(input, "INSERT") == 0) {
      cout << "Choose your insert method: \"INPUT\" \"FILE\"" << endl;
      cin >> input;
      cin.clear();
      cin.ignore(10000, '\n');
      if(strcmp(input, "INPUT") == 0) {
        int num;
        cout << "What number would you like to add? It must be between 1-1000. Only one number can be added at a time." << endl;
        cin >> num;
        cin.clear();
        cin.ignore(10000, '\n');
        insertNum(maxHeap, num, 1);
      } else if(strcmp(input, "FILE") == 0) {
	      fileAdd(maxHeap);
      } else {
        cout << "Sorry, invalid input." << endl; 
      }
      
    // If the user wants to remove the largest number, call the function and set its return value to the largest number. Then, print it to the console.
    } else if(strcmp(input, "REMOVE_LARGEST") == 0) {
      int removedNum = removeLargest(maxHeap);
      cout << "The largest number (" << removedNum << ") was removed." << endl;
      
    // If the user wants to remove all numbers, call that function.
    } else if(strcmp(input, "REMOVE_ALL") == 0) {
      removeAll(maxHeap);
      
    // If the user wants to display the heap, check to see if it's empty. If not, run the display function.
    } else if(strcmp(input, "DISPLAY") == 0) {
      int index = 1;
      if(maxHeap[index] == 0) {
        cout << "No numbers to display in this heap." << endl;
      } else {
        displayHeap(maxHeap, index, 0);
      }
    } else if(strcmp(input, "QUIT") == 0) {
      active = false; 
    } else {
      cout << "Sorry, invalid input." << endl; 
    }
  }
  return 0;
}

/* insertNum function. If the array value is 0 (meaning no input at that index), a number is added and the heap function
 * is called. Otherwise, increment the index. Repeat this until the array bounds have been exceeded. If this is the case, 
 * warn the user that the heap can't take any more numbers. */ 
void insertNum(int* maxHeap, int num, int counter) {
  int index = 1;
  while(index < 101) {
    if(maxHeap[index] == 0) {
      maxHeap[index] = num;
      heapify(maxHeap, index);
      return;
    } else {
      index++;
    }
  }
  cout << "You have reached the limit of 100 numbers. The number " << num << " could not be added." << endl;
}

/* displayHeap function, with help from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/. 
 * The recursive nature of the function, as well as the fact that it evaluates left and right child,
 * allows the program to print all levels of the heap by going from parent to child in each branch. */
void displayHeap(int* maxHeap, int index, int tabCounter) {
  // If there isn't any data in the heap or the array bounds are exceeded, end the function.
  if (maxHeap[index] == 0 || index > 100) {
    return;
  }
    // Otherwise, increase the horizontal distance using a tab counter.
  tabCounter++;
 
  // Display the right child first using index*2+1
  displayHeap(maxHeap, (index*2+1), tabCounter);
 
  // Add a new line and then the appropriate number of spaces depending on which generation it is (hence the use of the tab counter).
  cout << endl;
  for (int i = 1; i < tabCounter; i++) {
    cout << "\t";
  }
  
  // Enter the value at that index.
  cout << maxHeap[index] << "\n";
 
  // Then, display the left child using index*2.
  displayHeap(maxHeap, (index*2), tabCounter);
}

// Heapify function. 
void heapify(int* maxHeap, int index) {
  
  // Set the parent to the floor of the index / 2. 
  int parent = floor(index / 2);
  
  /* If the child is smaller than its parent and the parent's index is greater than 0 and the child index is within the array bounds,
   * swap the child and parent. Then, set the parent to the new child and call the function again. This recursion will allow for 
   * continued swapping until the parent is larger than the child. */
  if(maxHeap[index] > maxHeap[parent] && parent > 0 && index < 101) {
    int temp = maxHeap[index];
    maxHeap[index] = maxHeap[parent];
    maxHeap[parent] = temp;
    index = parent;
    heapify(maxHeap, index);
  }
}

// reverseHeapify function, used for data removal. Similar process as heapify.
void reverseHeapify(int* maxHeap, int index) {
  
  /* If the parent is less than the left child, the left child is greater than the right child, and the left child is not empty 
   * and within array bounds, the parent and left child get swapped. The parent is then set to the child and recursion is used to
   * progress through that branch. */
  if(maxHeap[index] < maxHeap[index*2] && maxHeap[index*2] > maxHeap[index*2+1] && index*2 < 101 && maxHeap[index*2] != 0) {
    int temp = maxHeap[index];
    maxHeap[index] = maxHeap[index*2];
    maxHeap[index*2] = temp;
    index = index*2;
    reverseHeapify(maxHeap, index);
    
  // Same logic as above but for right child.
  } else if(maxHeap[index] < maxHeap[index*2+1] && maxHeap[index*2+1] > maxHeap[index*2] && index*2+1 < 102 && maxHeap[index*2+1] != 0) {
    int temp2 = maxHeap[index];
    maxHeap[index] = maxHeap[index*2+1];
    maxHeap[index*2+1] = temp2;
    index = index*2+1;
    reverseHeapify(maxHeap, index);
	
  // Accounts for possibility that both children are the same (in which case it swaps with the left child)
  } else if(maxHeap[index] < maxHeap[index*2+1] && maxHeap[index*2+1] == maxHeap[index*2] && index*2+1 < 102 && maxHeap[index*2+1] != 0) {
    int temp2 = maxHeap[index];
    maxHeap[index] = maxHeap[index*2+1];
    maxHeap[index*2+1] = temp2;
    index = index*2+1;
    reverseHeapify(maxHeap, index);
  }
}

// removeLargest function. 
int removeLargest(int* maxHeap) {
  int index = 1;
  
  // Declare index 1 as the largest number (which it should be if I programmed it correctly)
  int largestNum = maxHeap[index];
  int temp;
  
  // Set the first index to -1. This is just an arbitrary value for reverseHeapify
  maxHeap[index] = -1;
  
  // Reverse heapify to put -1 at the bottom of the heap
  reverseHeapify(maxHeap, index);
  
  // For any index with a value of -1, that value is set to 0.
  for(int i = 0; i<101; i++) {
    if(maxHeap[i] == -1) {
      maxHeap[i] = 0;
    }
  }
  
  // Return the removed number for printing to console
  return largestNum;
}

/* removeAll function. In the spirit of "work smarter, not harder," I just repeated the removeLargest function
 * until the first index slot is 0 (indicating an empty array). */
void removeAll(int* maxHeap) {
  if(maxHeap[1] != 0) {
    while(maxHeap[1] != 0) {
      int num = removeLargest(maxHeap);
      cout << "Removed number: " << num << endl;
    }
  }
}

// fileAdd function with help from Galbraith and https://stackoverflow.com/questions/2287121/how-to-read-groups-of-integers-from-a-file-line-by-line-in-c. 
void fileAdd(int* maxHeap) {
  
  // The file name is entered and then a file with that name is opened.
  cout << "Please enter the name of your file:" << endl;
  char input[20];
  cin >> input;
 
  ifstream numFile;    

  numFile.open(input);
 
  int num;
  
  // While the file is open, take in the first number. Cin separates by whitespace so no additional work needed. 
  if(numFile.is_open() == true) {
    
    // Repeat while numbers are left in the file (help with this from Galbraith).
    while(numFile >> num) {   
      
      // Insert that number into the heap.
      insertNum(maxHeap, num, 1);
    }
  }
  
  // Close file.
  numFile.close();
} 
