#include <iostream>
#include <cstring>

using namespace std;

void insertNum(int* maxHeap, int num);

int main() {
  int maxHeap[101];
  maxHeap[0] = -1;
  for(int i = 1, i < 101; i++) {
    maxHeap[i] = NULL; 
  }
  char input[20];
  
  bool active = true;
  while(active == true) {
    cout << "Welcome to Heap!" << endl;
    cout << "\nYour commands are \"INSERT,\" \"REMOVE LARGEST,\" \"REMOVE ALL,\" \"DISPLAY,\" and \"QUIT.\"" << endl;
    cin.getline(input, 20);
    if(strcmp(input, "INSERT") == 0) {
      cout << "Choose your insert method: \"INPUT\" \"FILE\"" << endl;
      cin >> input;
      cin.clear();
      cin.ignore(10000, '\n');
      if((strcmp(input, "INPUT") == 0) {
        int num;
        cout << "What number would you like to add? It must be between 1-1000." << endl;
        cin >> num;
        insertNum(maxHeap, num);
      } else if((strcmp(input, "FILE") == 0) {
               
      } else {
        cout << "Sorry, invalid input." << endl; 
      }
    } else if(strcmp(input, "REMOVE LARGEST") == 0) {
               
    } else if(strcmp(input, "REMOVE ALL") == 0) {
      
    } else if(strcmp(input, "DISPLAY") == 0) {
               
    } else if(strcmp(input, "QUIT") == 0) {
      active = false; 
    } else {
      cout << "Sorry, invalid input." << endl; 
    }
  }
  return 0;
}

void insertNum(int* maxHeap, int num) {
  for(int i = 1; i < 101; i++) {
    if(maxHeap[i] == NULL) {
      maxHeap[i] = num;
    }
  }
}
