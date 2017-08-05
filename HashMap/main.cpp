/* 
 * File:   main.cpp
 * Author: Mark Bouchett
 *
 * Created on August 5, 2017, 12:29 PM
 */

#include <iostream>  //console Input/Output
#include <string>    //string handler
#include <fstream>   //file stream handler
#include <map>
#include <vector>


using namespace std; //declares the name space
// declare function prototypes
void fileError();
string stripPunct(const string &);
/*
 * 
 */
int main() {
    ifstream inFile;
    string filename;
    string input;
    string word;
    map<string, int> freq;
    
    //open the text file
    cout << "Enter filename for word frequency analysis: ";
    cin >> filename;
    inFile.open(filename, ios::in);
    if(inFile.fail())   //test file exists?
        fileError();
    
    //process file
    while(inFile >> input){
        word = stripPunct(input);
        if(word.length() > 0)
            cout << stripPunct(input) << endl;
    }
    
    inFile.close();     //close file
    
    return 0;
}

/**
 * reports file error and terminates
 */
void fileError()
{
	cout << "Error opening file!" << endl << endl;
	system("pause");
	exit(1);
}

string stripPunct(const string &s){
    string cleanString = "";
    for(int i = 0; i < s.length(); i++){
        if(isalpha(s[i]))
            cleanString += s[i];
    }
        
    return cleanString;
}