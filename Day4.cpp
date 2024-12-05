#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;


int main(){
    int part1_result;
    int part2_result;
    ifstream inputFile("Day4.txt");
    string inputVal;

    vector<vector<char>> grid;;
   
    vector<string> strings;
    char current;

    while(getline(inputFile, inputVal)){
        
        strings.push_back(inputVal);
        
    }
    
    for(int i = 0; i < 140; i++){ // Loop through entire grid
    vector<char> storage;
    string tempString = strings.at(i); //set tempString to current line
        for(int j = 0; j < 140; j++){ //Increment through entire tempstring
            current = tempString[j]; //set current char to tempString at j
            storage.push_back(current); //add char to storage
        }
        grid.push_back(storage);
    }
//Part 1 Code
    // row search
   for(int i = 0; i < grid.size(); i++){
    for(int j = 0; j < grid.size(); j++){
        if(grid[i][j] == 'X' && grid[i][j+1] == 'M' && grid[i][j+2] == 'A' && grid[i][j+3] == 'S' || 
        grid[i][j] == 'S' && grid[i][j+1] == 'A' && grid[i][j+2] == 'M' && grid[i][j+3] == 'X' ){
            ++part1_result;
        }
    }
   }
   
  
    // col search
    for(int i = 0; i < grid.size()-3; i++){
        for(int j = 0; j < grid.size(); j++){
        if(grid[i][j] == 'X' && grid[i+1][j] == 'M' && grid[i+2][j] == 'A' && grid[i+3][j] == 'S' || 
        grid[i][j] == 'S' && grid[i+1][j] == 'A' && grid[i+2][j] == 'M' && grid[i+3][j] == 'X' ){
            ++part1_result;
        }
    }
}


 //Diagonal left search
for(int i = 0; i < grid.size()-3; i++){
    for(int j = 0; j < grid.size(); j++){
        if(grid[i][j] == 'X' && grid[i+1][j+1] == 'M' && grid[i+2][j+2] == 'A' && grid[i+3][j+3] == 'S' || 
        grid[i][j] == 'S' && grid[i+1][j+1] == 'A' && grid[i+2][j+2] == 'M' && grid[i+3][j+3] == 'X' ){
            ++part1_result;
        }   
    }
}

for(int i = 0; i < grid.size()-3; i++){
    for(int j = 3; j < grid.size(); j++){
        if(grid[i][j] == 'X' && grid[i+1][j-1] == 'M' && grid[i+2][j-2] == 'A' && grid[i+3][j-3] == 'S' || 
        grid[i][j] == 'S' && grid[i+1][j-1] == 'A' && grid[i+2][j-2] == 'M' && grid[i+3][j-3] == 'X' ){
            ++part1_result;
        }
    }
}


//part 2 Code

for(int i = 1; i < grid.size()-1; ++i){
    for(int j = 1; j < grid.size()-1; ++j){
        if(grid[i][j] == 'A'){
            if(grid[i-1][j-1] == 'M' && grid[i-1][j+1] == 'M' && grid[i+1][j-1] == 'S' && grid[i+1][j+1] == 'S'){
                part2_result++;              
            }else if(grid[i-1][j-1] == 'S' && grid[i-1][j+1] == 'S' && grid[i+1][j-1] == 'M' && grid[i+1][j+1] == 'M'){
                part2_result++;
            }else if(grid[i-1][j-1] == 'M' && grid[i-1][j+1] == 'S' && grid[i+1][j-1] == 'M' && grid[i+1][j+1] == 'S'){
                 part2_result++;
            }else if(grid[i-1][j-1] == 'S' && grid[i-1][j+1] == 'M' && grid[i+1][j-1] == 'S' && grid[i+1][j+1] == 'M')
            {            
                 part2_result++;   
            }
        }
       
        
    }
}


cout << "p1: " << part1_result << endl;
cout << "p2: " << part2_result << endl;




return 0;
}

/*
  if(grid[i-1][j-1] == 'M' && grid[i+1][j+1] == 'M' && grid[i+1][j+1] == 'S' && grid[i-1][j+1] == 'S'){
                part2_result++;
            }else if(grid[i-1][j-1] == 'M' && grid[i+1][j+1] == 'S' && grid[i+1][j+1] == 'M' && grid[i-1][j+1] == 'S'){
                part2_result++;
            }else if(grid[i-1][j-1] == 'S' && grid[i+1][j+1] == 'M' && grid[i+1][j+1] == 'S' && grid[i-1][j+1] == 'M'){
                 part2_result++;
            }else if(grid[i-1][j-1] == 'M' && grid[i+1][j+1] == 'M' && grid[i+1][j+1] == 'S' && grid[i-1][j+1] == 'S')
            {            
                 part2_result++;
            }
            */
