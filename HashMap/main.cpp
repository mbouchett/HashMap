/* 
 * File:   main.cpp
 * Author: Mark Bouchett
 *
 * Created on August 5, 2017, 12:29 PM
 * demonstrates a hash table
 */

#include <iostream>     //console Input/Output
#include <string>       //string handler
#include <fstream>      //file stream handler
#include "WordFreq.h"   //our hash table object
#include <ctype.h>      //for lowercase bit


using namespace std;    //declares the name space

// declare function prototypes
void fileError();
string stripPunct(const string &);
string lowercase(string);

int main() {
    ifstream inFile;
    string filename;
    string input;
    string word;
    int totalWords = 0;
    WordFreq wc;
    
    //open the text file
    cout << "Enter filename for word frequency analysis: ";
    cin >> filename;
    inFile.open(filename, ios::in);
    if(inFile.fail())               //test file exists?
        fileError();
    
    //process file
    while(inFile >> input){         //get a word from the file
        word = stripPunct(input);   //strip punctuation
        word = lowercase(word);     //convert the word to lower case
        if(word.length() > 0)       //if more than just punctuation
            wc.addWord(word);       //add the word to the hash table
        totalWords++;               //keep count of the words in the file 
    }
    
    // display the results
    cout << totalWords << " total words, ";
    cout << wc.getUniqueWords() << " unique words.";
    cout << endl;
    wc.printFrequencyCount();
    wc.displayInOrder();
    
    inFile.close();                 //close file
    cout << endl;
    
    return 0;
}

/**
 * reports file error and terminates
 */
void fileError()
{
	cout << "Error opening file!" << endl << endl;
	exit(1);
}

/**
 * strips punctuation
 * @param s string to strip
 * @return  stripped string
 */
string stripPunct(const string &s){
    string cleanString = "";
    for(int i = 0; i < s.length(); i++){
        if(isalpha(s[i]))
            cleanString += s[i];
    }
        
    return cleanString;
}

/**
 * converts string to lower case
 * @param s string to be converted
 * @return converted string
 */
string lowercase(string s){
    string lc = "";
    for(int i = 0; i < s.length(); i++){
        lc += tolower(s[i]);
    }
    
    return lc;
}