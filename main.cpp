//
//  main.cpp
//  Sequence Tester
//
//  Created by Ryan Scott on 10/18/21.
//

#include <iostream>
#include <string>
#include "Sequence.hh"
#include "CrimeRecord.h"
#include "HashTable.h"
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    
    fstream fin;
    // Open an existing file
    fin.open("crime.csv", ios::in);
    vector<string> row; // we can put the data into a vector first
    string line, word, temp;
    getline(fin, temp); // remove the title row
    
    // make hash table
    HashTable ht;
    
    while (getline(fin, temp)) {//read each remaining rows
        row.clear(); // clear the vector
        // used for breaking words
        stringstream s(temp);
        //std::getline(s, word, ',');
        // read every column data of a row and
        // store it in a string variable, 'word'
        for (int i=0; i<17; i++) {
            char c1 = s.peek();
            string tmp;
            if (c1 == '"') {
                char c2 = s.get();
                getline(s, tmp, '"');
                row.push_back(tmp);
                char c3 = s.get();
            }
            else {
                getline(s, tmp, ',');
                row.push_back(tmp);
            }
        }
        //cout << row[0] << "  size: " << row.size() << endl;
        // there are 18 different attributes, numbered 0 though 17
        //cout << "key : " << row[0].substr(1, 9) << endl;
        //create a CrimeRecord, assign the 18 values,
        CrimeRecord r;
        r.incident_number = row[0];
        r.offense_code = row[1];
        r.offense_code_group = row[2];
        r.offense_description = row[3];
        r.district = row[4];
        r.reporting_area = row[5];
        r.shooting = row[6];
        r.occured_on_date = row[7];
        r.year = row[8];
        r.month = row[9];
        r.day_of_week = row[10];
        r.hour = row[11];
        r.ucr_part = row[12];
        r.street = row[13];
        r.latitude = row[14];
        r.longitude = row[15];
        r.location = row[16];
        //cout << r << endl;
        
        ht.insert(r.incident_number, r);
    }
    cout << "Searching for key I100340225-00" << endl;
    CrimeRecord rec = ht.search("I100340225-00");
    cout <<rec << endl;
    
    cout << "\n" << endl;
    cout << "Deleting Key I100340225-00" << endl;
    ht.del("I100340225-00");
    cout << "\n" << endl;
    
    cout << "Chaining test: Searching for key I100340225-00"<< endl;
    rec = ht.search("I100340225-00");
    cout << rec << endl;
    cout << "Chaining successful" << endl;
    cout << "\n" << endl;
    
    cout << "Load Factor is ";
    float load = ht.loadfactor();
    cout << load << endl;
    
    return 0;
}
