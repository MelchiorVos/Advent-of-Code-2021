#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
using std::ifstream;
using std::cout;

vector<int> importTxtFile(){
    ifstream inFS;
    inFS.open("SonarSweepInput.txt");

    vector<int> input;
    int currentNumber;
    while (inFS >> currentNumber){
        input.push_back(currentNumber);
    }
    inFS.close();
    return input;
}

int increasingWindows(vector<int> sonarSweepinput){

    vector<int> input = sonarSweepinput;
    int count = 0;
    for (unsigned int i = 0; i < input.size(); i++){
        bool isNotOutOfBounds = i + 1 < input.size() && i + 2 < input.size() && i + 3 < input.size();
        if (isNotOutOfBounds && input.at(i) + input.at(i + 1) + input.at(i + 2) < 
                                input.at(i + 1) + input.at(i + 2) + input.at(i + 3)){
            count += 1;
        }
    }
    return count;
}

int increasingIndexes(vector<int> sonarSweepinput){

  vector<int> input = sonarSweepinput;
  int count = 0;
  for (unsigned int i = 1; i < input.size(); i++){
    if(input.at(i) > input.at(i - 1)){
        count += 1;
    }
  }
    return count;
}

int main(){

    cout << "Part 1: The amount of increasing indexes is " << increasingIndexes(importTxtFile()) << "\n";
    cout << "Part 2: The amount of increasing windows is " << increasingWindows(importTxtFile());

    return 0;  
}