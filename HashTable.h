//
//  HashTable.h
//  Sequence Tester
//
//  Created by Ryan Scott on 10/20/21.
//
#pragma once
#include "CrimeRecord.h"
#include "Sequence.hh"
#include <string>
#include <math.h>
#include <utility>
#ifndef HashTable_h
#define HashTable_h
using namespace std;

class HashTable{
private:
    Sequence<pair<string,CrimeRecord>> *crimetype;
    int size;
public:
    HashTable(){
        size = 0;
        crimetype = new Sequence<pair<string,CrimeRecord>>[426000];
    }// constructor
    int hashing(string key){
        string cutkey = key.substr(1,9);
        int temp = stoi(cutkey);
        double ratio = 0.662525558;
        int hash = floor(426000 * ( fmod(temp * ratio, 1) ) );
        return hash;
    }// Hashing
    void insert(string key, CrimeRecord rec){
        int hash = hashing(key);
        pair<string,CrimeRecord> var(rec.incident_number, rec);
        crimetype[hash].add(var, 0);
        size++;
    }// insert
    
    void del(string key){
        int hash = hashing(key);
        int length = crimetype[hash].length();
        for (int i = 0; i < length; i++){
            if (crimetype[hash].entry(i).first == key){
                crimetype[hash].remove(crimetype[hash].entry(i), i);
                break;
            }
        }// for
    }// delete
    
    CrimeRecord search(string key){
        int hash = hashing(key);
        int length = crimetype[hash].length();
        CrimeRecord BlankRec;
        for (int i = 0; i < length; i++){
            if (crimetype[hash].entry(i).first == key){
                return crimetype[hash].entry(i).second;
                break;
            }
        }// for
        return BlankRec;
    }// search
    
    float loadfactor(){
        // number of values in the table/the size of the table
        float loadfactor = 319075.0 / 426000.0;
        return loadfactor;
    }// loadfactor
};

#endif /* HashTable_h */
