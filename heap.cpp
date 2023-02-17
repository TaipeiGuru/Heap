#include <iostream>
#include <cstring>

using namespace std;

void insertNum(int* maxHeap, int num);
void displayHeap(int* maxHeap);

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
        cout << "What number would you like to add? It must be between 1-1000." << endl;
        cin >> num;
	cin.clear();
	cin.ignore(10000, '\n');
        insertNum(maxHeap, num);
      } else if(strcmp(input, "FILE") == 0) {
               
      } else {
        cout << "Sorry, invalid input." << endl; 
      }
    } else if(strcmp(input, "REMOVE LARGEST") == 0) {
               
    } else if(strcmp(input, "REMOVE ALL") == 0) {
      
    } else if(strcmp(input, "DISPLAY") == 0) {
      displayHeap(maxHeap);
    } else if(strcmp(input, "QUIT") == 0) {
      active = false; 
    } else {
      cout << "Sorry, invalid input." << endl; 
    }
  }
  return 0;
}

void insertNum(int* maxHeap, int num) {
  int counter = 1;
  while(maxHeap[counter] != 0) {
    counter++;
  }
  maxHeap[counter] = num;
}

void displayHeap(int* maxHeap) {
  for(int i = 1; i < 101; i++) {
    if(maxHeap[i] != 0){
      cout << maxHeap[i] << endl;
    }
  }
}
