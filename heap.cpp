#include <iostream>

using namespace std;

void insertNum(int* maxHeap, int num);

int main() {
  int maxHeap[101];
  maxHeap[0] = -1;
  char input[20];
  
  bool active = true;
  while(active == true) {
    cout << "Welcome to Heap!" << endl;
    cout << "Your commands are \"INSERT,\" \"REMOVE LARGEST,\" \"REMOVE ALL,\" \"DISPLAY,\" and \"QUIT.\"" << endl;
    cin.getline(input, 20);
    cin.clear();
    cin.ignore(10000, '\n');
    if(strcmp(input, "INSERT") == 0) {
               
    } else if(strcmp(input, "REMOVE LARGEST") == 0) {
               
    } else if(strcmp(input, "REMOVE ALL") == 0) {
      active = false;
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
  
}
