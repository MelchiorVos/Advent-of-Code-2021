#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::ifstream;
using std::cout;
using std::string;

void importAndOrganizeInput(int& forward, int& depth1, int& depth2){
    ifstream inFS;
    inFS.open("DiveInput.txt");

    string course;
    unsigned short int steps;
    while (inFS >> course >> steps){
      if (course == "forward"){
        forward += steps;
        depth2 += depth1 * steps;
      }
      else if (course == "down"){
        depth1 += steps;
      }
      else{
        depth1 -= steps;
      }
    }
    inFS.close();
}

int main(){
  int forward = 0; 
  int depth1 = 0;
  int depth2 = 0;

  importAndOrganizeInput(forward,depth1,depth2);

  int productOfCoordinates1 = forward * depth1;
  int productOfCoordinates2 = forward * depth2;

  cout << "Part 1: The product of the coordinates is " << productOfCoordinates1 << "\n";
  cout << "Part 2: The product of the coordinates is " << productOfCoordinates2;
  return 0;  
}