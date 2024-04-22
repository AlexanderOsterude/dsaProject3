//
// Created by Christian Betancourt on 4/20/24.
//
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include "sorting.h"
#include "data_extraction.h"
using namespace std;

int main(){
    vector<pair<string,int>> companies;
    vector<pair<string,int>> categories;
    vector<pair<string,int>> chemicals;
    counter_list(companies, categories, chemicals);
    cout << "||^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^||" << endl;
    cout << "||        WELCOME TO CHEMPURGE!         ||" << endl;
    cout << "||______________________________________||" << endl;

    cout << "Our program helps determine what companies, product categories, and chemicals are \n"
            "the worst for our health.\n"
            "We collected data on dangerous chemicals and the companies and product categories that "
            "use them the most."  << endl;
    cout << "What type of sort would you like to use?\nType H for heap sort, anything else for stl sort" << endl;
    string sort_choice;
    getline(cin, sort_choice);
    for(int i = 0; i < sort_choice.length(); i++) {
        sort_choice[i] = toupper(sort_choice[i]);
    }
    auto comparer = [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b){
        return a.second > b.second;
    };
    while (true){
        cout << "What category would you like to review?" << endl;
        cout << "1. Companies\n2. Product Categories\n3. Chemicals" << endl;
        cout << "Choose a number. Press anything else to quit." << endl;
        string choice;
        getline(cin, choice);
        if (choice != "1" && choice != "2" && choice != "3"){
            cout << "Thanks for using ChemPurge. Goodbye!" << endl;
            break;
        }
        else{
            cout << "Would you like to list the ones with the highest or lowest count?" << endl;
            cout << "Press H for highest, press anything else for lowest." << endl;
            string high_or_low;
            string temp;
            getline(cin, high_or_low);
            for (auto c: high_or_low){
                temp += toupper(c);
            }
            high_or_low = temp;
            cout << "How many entries would you like to display. Please enter a positive integer." << endl;
            string num_entries;
            int entries;
            getline(cin, num_entries);
            if (!isInteger(num_entries)){
                cout << "Well, you did not enter a positive integer. Now you are going to have to restart.\n"
                        "You see what you did to yourself? >:(" << endl;
                continue;
            }
            else{
                entries = stoi(num_entries);
            }
            if (choice == "1"){
                //companies
                if(sort_choice == "H") {
                    companies = heapSort(companies);
                }else{
                    sort(companies.begin(), companies.end(), comparer);
                }
                auto res = companies;
                if(entries > res.size()){
                    cout << "Sorry, number of entries out of range. Please try again and pick a number less than: " << res.size() + 1 << endl;
                }
                else if(high_or_low == "H"){
                    //highest count for Companies with chemicals
                    for(int i = 0; i < entries; i++){
                        cout << (i+1) << ". " <<res[i].first << ": " << res[i].second << endl;
                    }
                }
                else{
                    //lowest count
                    for(int i = res.size()-1; i >= (res.size()-entries); i--){
                        cout << (i+1) << ". " <<res[i].first << ": " << res[i].second << endl;
                    }
                }
            }
            else if(choice == "2"){
                if(sort_choice == "H") {
                    categories = heapSort(categories);
                }else{
                    std::sort(categories.begin(), categories.end(), comparer);
                }
                auto res = categories;
                if(entries > res.size()){
                    cout << "Sorry, number of entries out of range. Please try again and pick a number less than: " << res.size() + 1 << endl;
                }
                else if(high_or_low == "H"){
                    //highest count of bad chemicals
                    for(int i = 0; i < entries; i++){
                        cout << (i+1) << ". " <<res[i].first << ": " << res[i].second << endl;
                    }
                }
                else{
                    //lowest count
                    for(int i = res.size()-1; i >= (res.size()-entries); i--){
                        cout << (i+1) << ". " <<res[i].first << ": " << res[i].second << endl;
                    }
                }
            }
            else if (choice == "3"){
                if(sort_choice == "H") {
                    chemicals = heapSort(chemicals);
                }else{
                    std::sort(chemicals.begin(), chemicals.end(), comparer);
                }
                auto res = chemicals;
                if(entries > res.size()){
                    cout << "Sorry, number of entries out of range. Please try again and pick a number less than: " << res.size() + 1 << endl;
                }
                else if(high_or_low == "H"){
                    //highest count of bad chemicals
                    for(int i = 0; i < entries; i++){
                        cout << (i+1) << ". " <<res[i].first << ": " << res[i].second << endl;
                    }
                }
                else{
                    //lowest count
                    for(int i = res.size()-1; i >= (res.size()-entries); i--){
                        cout << (i+1) << ". " <<res[i].first << ": " << res[i].second << endl;
                    }
                }
            }
        }
        cout << "Would you like to search another category? Press Y if yes, press anything "
                "else to end." << endl;
        string repeat_process;
        char answer;
        getline(cin, repeat_process);
        answer = repeat_process[0];
        if (toupper(answer) != 'Y'){
            cout << "Thanks for using ChemPurge. Goodbye!" << endl;
            break;
        }
    }

    return 0;
    //TODO:
    // pass in info from csv file (Alex)
    // create hash map to keep count of companies and number of their occurrences (Alex)
    // create sorting algorithm (Chris) DONE
    // create heapsort or mergesort (Chris) DONE
    // once this is done, we should create a more intricate main file for user to make decisions
    //  -Number of companies to display
    //  -Whether they want to display top or bottom companies
    //  -Loop to beginning if they want to do it again or if they want to exit
    //  -
}
