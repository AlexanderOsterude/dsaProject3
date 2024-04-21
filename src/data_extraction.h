#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <regex>

using namespace std;


void increase_counter(unordered_map<string, int> &column, string name){
    if(!column.count(name)){
        column[name] = 1;
    }
    else{
        column[name] += 1;
    }
}

vector<unordered_map<string, int>> extract_columns(){
    vector<unordered_map<string,int>> data = {{},{},{}};
    ifstream file("../data/chemicals.csv");
    if(!file.is_open()){
        cout << "Failed to Open File" << endl;
        return data;
    }

    string line;
    int row = 0;
    while(getline(file,line)){
        istringstream stream(line);
        string value;
        regex removal("[\"\\\\]");
        int current = 0;
        while (getline(stream,value,',')){
            value = regex_replace(value,removal,"");
            if (current == 5 && row > 0) {
                increase_counter(data[0], string(value));
            } else if (current == 8 && row > 0) {
                increase_counter(data[1], string(value));;
            } else if (current == 10 && row > 0) {
                increase_counter(data[2], string(value));
            }
            current++;
        }
        row++;
    }
}

void counter_list(vector<pair<string, int>> &company, vector<pair<string, int>> &category, vector<pair<string, int>> &subcategory){
    auto data = extract_columns();
    for(int i = 0; i < 3; i++){
        for(auto column: data[i]){
            if(i == 0){
                company.emplace_back(column.first,column.second);
            }
            else if(i == 1){
                category.emplace_back(column.first,column.second);
            }
            else if(i == 2){
                subcategory.emplace_back(column.first,column.second);
            }

        }
    }
}
