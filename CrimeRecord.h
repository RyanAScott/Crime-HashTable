//
//  CrimeRecord.h
//  Sequence Tester
//
//  Created by Ryan Scott on 10/20/21.
//
#pragma once
#ifndef CrimeRecord_h
#define CrimeRecord_h
struct CrimeRecord {
public:
    int key;
    string incident_number;
    string offense_code;
    string offense_code_group;
    string offense_description;
    string district;
    string reporting_area;
    string shooting;
    string occured_on_date;
    string year;
    string month;
    string day_of_week;
    string hour;
    string ucr_part;
    string street;
    string latitude;
    string longitude;
    string location;
    
    friend ostream &operator << (ostream &os, CrimeRecord &data){
        os
            << "(" << data.key << ",("
            << data.incident_number << ","
            << data.offense_code << ","
            << data.offense_code_group << ","
            << data.offense_description << ","
            << data.district << ","
            << data.reporting_area << ","
            << data.shooting << ","
            << data.occured_on_date << ","
            << data.year << ","
            << data.month << ","
            << data.day_of_week << ","
            << data.hour << ","
            << data.ucr_part << ","
            << data.street << ","
            << data.latitude << ","
            << data.longitude << ","
            << data.location << "))" << "\n";
        return os;
    }// frined
};

#endif /* CrimeRecord_h */
