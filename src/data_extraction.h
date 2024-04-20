#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <unordered_set>

using namespace std;
vector<vector<string>> extract_columns(unordered_set<int> columns){
    vector<vector<string>> data = {{},{},{}};
    ifstream file("../data/chemicals.csv");
    if(!file.is_open()){
        cout << "Failed to Open File" << endl;
        return data;
    }

    string line;
    while(getline(file,line)){
        istringstream stream(line);
        string value;
        int current = 0;
        while (getline(stream,value,',')){
            if(columns.find(current) != columns.end()){
                if (current == 5) {
                    data[0].push_back(value);
                } else if (current == 8) {
                    data[1].push_back(value);
                } else if (current == 10) {
                    data[2].push_back(value);
                }
            }
        current++;
        }
    }
}


