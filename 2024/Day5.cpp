#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

bool contains(vector<int> update, int page){
   for(int i = 0; i < update.size(); i++){
      if(update[i] == page){
         return true;
      }
   }
   return false;
}

bool inOrder(map <int, int> instructions, vector<int> page1, vector<int> page2, vector<int> update){
   int invalid = 0;
   for(int i = 0; i < page1.size(); i++){
      int rule1 = page1.at(i);
      int rule2 = page2.at(i);
      if(contains(update, rule1) && contains(update, rule2)){
         if(instructions[rule1] > instructions[rule2]){
            invalid++;
         }
      }
   }
   if(invalid == 0){ 
      return true;
   }
   return false;
}

int fixOrder(map<int, int> instructions, vector<int> page1, vector<int> page2, vector<int> update){
   bool didSwap;
   do{
      didSwap = false;
      for(int i = 0; i < page1.size(); i++){
         int rule1 = page1.at(i);
         int rule2 = page2.at(i);
         if(contains(update, rule1) && contains(update, rule2) && instructions[rule1] > instructions[rule2]){ 
            didSwap = true;
            int temp = instructions[rule1];
            instructions[rule1] = instructions[rule2];
            instructions[rule2] = temp;
         }
      }
   }
   while(didSwap);
      int res = 0;
      double middle = (instructions.size()/2);
      for(auto j : instructions){
         if(j.second == middle){
            res = j.first;
         }
      }
      cout << endl;
   return res;
}
      



using namespace std;

int main(){
   int part1_result = 0;
   int part2_result = 0;
   ifstream inputFile("Day5.txt");
   string inputVal;
   vector<string> orders;
   vector<int> page1;
   vector<int> page2;
      while(getline(inputFile, inputVal)){
         if(inputVal.empty()){
            break;
         }
         orders.push_back(inputVal);
      }
            
      for(int i = 0; i < orders.size(); i++){
         string temp = orders.at(i);
         string order1 = temp.substr(0, 2);
         string order2 = temp.substr(3, 2);
         page1.push_back(stoi(order1));
         page2.push_back(stoi(order2));
      }
      while(getline(inputFile, inputVal)){
         istringstream iss(inputVal);
         int n;
         int key = 0;
         map<int, int> instructions;
         vector<int> tempUpdates;
         while(iss >> n)
      {
            instructions.insert(pair<int, int>(n,  key));
            tempUpdates.push_back(n);
             if(iss.peek() == ','){
               iss.ignore();
         }
            key++;
      }

         if(inOrder(instructions, page1, page2, tempUpdates)){
            double middle = (instructions.size()/2);
            for(auto j : instructions){
               if(j.second == middle){
                  part1_result += j.first;               
            }    
         }
      }
      if(!inOrder(instructions, page1, page2, tempUpdates)){
            part2_result += fixOrder(instructions, page1, page2, tempUpdates);
   }
}

        
   cout << "Part1: " << part1_result << endl;
   cout << "Part2: " << part2_result << endl;
    
}
   


   