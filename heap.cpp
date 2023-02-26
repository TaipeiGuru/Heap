#include <iostream>
#include <cstring>

using namespace std;

void insertNum(int* maxHeap, int num, int counter);
void displayHeap(int* maxHeap, int index, int tabCounter);
void heapify(int* maxHeap);
void removeLargest(int* maxHeap);

int main() {
  int maxHeap[101];
  maxHeap[0] = -1;
  for(int i = 1; i < 101; i++) {
    maxHeap[i] = 0; 
  }
  char input[20];

  cout << "Welcome to Heap!" << endl;
  
  bool active = true;
  while(active == true) {
    cout << "\nYour commands are \"INSERT,\" \"REMOVE_LARGEST,\" \"REMOVE_ALL,\" \"DISPLAY,\" and \"QUIT.\"" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(10000, '\n');
    if(strcmp(input, "INSERT") == 0) {
      cout << "Choose your insert method: \"INPUT\" \"FILE\"" << endl;
      cin >> input;
      cin.clear();
      cin.ignore(10000, '\n');
      if(strcmp(input, "INPUT") == 0) {
        int num;
        cout << "What number would you like to add? It must be between 1-1000. You may insert one number or a sequence of numbers separated by spaces." << endl;
        cin >> num;
        cin.clear();
        cin.ignore(10000, '\n');
        insertNum(maxHeap, num, 1);
      } else if(strcmp(input, "FILE") == 0) {
               
      } else {
        cout << "Sorry, invalid input." << endl; 
      }
    } else if(strcmp(input, "REMOVE_LARGEST") == 0) {
      removeLargest(maxHeap);
    } else if(strcmp(input, "REMOVE_ALL") == 0) {
      
    } else if(strcmp(input, "DISPLAY") == 0) {
      int index = 1;
      displayHeap(maxHeap, index, 0);
    } else if(strcmp(input, "QUIT") == 0) {
      active = false; 
    } else {
      cout << "Sorry, invalid input." << endl; 
    }
  }
  return 0;
}

void insertNum(int* maxHeap, int num, int counter) {
  if(maxHeap[counter] == 0){
    maxHeap[counter] = num;
  } else if(maxHeap[counter*2+1] == 0) {
    cout << maxHeap[counter*2+1] << endl;
    maxHeap[counter*2+1] = num;
  } else if(maxHeap[counter*2] == 0) {
    maxHeap[counter*2] = num;
  } else {
    if(maxHeap[counter*4+2] !=0 && maxHeap[counter*4] == 0) {
      counter = counter*2;
      insertNum(maxHeap, num, counter);
    } else {
      counter = counter*2+1;
      insertNum(maxHeap, num, counter);
    }
  }
  heapify(maxHeap);
}

// https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void displayHeap(int* maxHeap, int index, int tabCounter) {
  // Base case
  if (maxHeap[index] == 0) {
    return;
  }
    // Increase distance between levels
  tabCounter += 1;
 
  // Process right child first
  displayHeap(maxHeap, (index*2+1), tabCounter);
 
  // Print current node after space
  // count
  cout << endl;
  for (int i = 1; i < tabCounter; i++) {
    cout << "\t";
  }
  cout << maxHeap[index] << "\n";
 
  // Process left child
  displayHeap(maxHeap, (index*2), tabCounter);
}

void heapify(int* maxHeap) {
  for(int i = 1; i < 101; i++) {
    if(maxHeap[i] != 0 && maxHeap[i*2] != 0 && maxHeap[i] < maxHeap[i*2]) {
      int temp = maxHeap[i];
      maxHeap[i] = maxHeap[i*2];
      maxHeap[i*2] = temp;
    }
    if(maxHeap[i] != 0 && maxHeap[i*2+1] != 0 && maxHeap[i] < maxHeap[i*2+1]) {
      int temp2 = maxHeap[i];
      maxHeap[i] = maxHeap[i*2+1];
      maxHeap[i*2+1] = temp2;
    }
  }
}

void removeLargest(int* maxHeap) {
  int index = 1;
  int largestNum = maxHeap[index];
  int temp;
  maxHeap[index] = 0;
  while(maxHeap[index*2] != 0) {
    temp = maxHeap[index];
    maxHeap[index] = maxHeap[index*2];
    maxHeap[index*2] = temp;
    index = index*2;
  }
  cout << "The largest number (" << largestNum << ") was removed." << endl;
}
