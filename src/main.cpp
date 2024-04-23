//
// Created by Christian Betancourt and Alexander Osterude on 4/20/24.
//
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <chrono>
#include "sorting.h"
#include "data_extraction.h"
using namespace std;

int main(){
    auto start = chrono::high_resolution_clock::now();
    //Preparing the vectors that will contain the counter pairs from the unordered_map process.
    vector<pair<string,int>> companies;
    vector<pair<string,int>> categories;
    vector<pair<string,int>> chemicals;
    counter_list(companies, categories, chemicals);
    auto end = chrono::high_resolution_clock::now();
    auto duration = end - start;

    cout << "Execution time for counter_list() from data_extraction.h: " << duration.count() << endl;
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
    //Comparer for the stl sort. Declared early to be able to be used in at every scope.
    auto comparer = [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b){
        return a.second > b.second;
    };

    //Repeating loop to access all the information.
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
            //Top or bottom list
            cout << "Would you like to list the ones with the highest or lowest count?" << endl;
            cout << "Press H for highest, press anything else for lowest." << endl;
            string high_or_low;
            string temp;
            getline(cin, high_or_low);
            for (auto c: high_or_low){
                temp += toupper(c);
            }
            high_or_low = temp;
            //Number of entries
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
            //Results vector used to display sorted info
            vector<pair<string,int>> res;
            if (choice == "1"){
                //companies
                if(sort_choice == "H") { //Heap Sort
                    auto start = chrono::high_resolution_clock::now();
                    companies = heapSort(companies);
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = end - start;
                    cout << "Execution time for HeapSort(): " << duration.count() << endl;

                }else{ //STL Sort
                    auto start = chrono::high_resolution_clock::now();
                    sort(companies.begin(), companies.end(), comparer);
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = end - start;
                    cout << "Execution time for sort() from STL: " << duration.count() << endl;



                }
                res = companies;
            }
            else if(choice == "2"){
                if(sort_choice == "H") { //Heap sort
                    auto start = chrono::high_resolution_clock::now();
                    categories = heapSort(categories);
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = end - start;
                    cout << "Execution time for HeapSort(): " << duration.count() << endl;

                }else{ //STL Sort
                    auto start = chrono::high_resolution_clock::now();
                    std::sort(categories.begin(), categories.end(), comparer);
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = end - start;
                    cout << "Execution time for sort() from STL: " << duration.count() << endl;
                }
                res = categories;
            }
            else if (choice == "3"){
                if(sort_choice == "H") { //Heap sort
                    auto start = chrono::high_resolution_clock::now();
                    chemicals = heapSort(chemicals);
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = end - start;
                    cout << "Execution time for HeapSort(): " << duration.count() << endl;


                }else{//Stl Sort
                    auto start = chrono::high_resolution_clock::now();
                    std::sort(chemicals.begin(), chemicals.end(), comparer);
                    auto end = chrono::high_resolution_clock::now();
                    auto duration = end - start;
                    cout << "Execution time for sort() from STL: " << duration.count() << endl;

                }
                res = chemicals;
            }
            if(entries > res.size()){
                cout << "Sorry, number of entries out of range. Please try again and pick a number less than: " << res.size() + 1 << endl;
            }
            else if(high_or_low == "H"){
                //Top count
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
}
