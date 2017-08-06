/* 
 * File:   WordFreq.h
 * Author: mark
 *
 * Created on August 5, 2017, 5:11 PM
 */

#ifndef WORDFREQ_H
#define WORDFREQ_H
#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>

class WordFreq{
private:
    std::map<std::string, int> freq;
    int uniqueWords;
    
    //structure for the array
    struct wds{
        std::string w;      //the word
        int f;              //the frequency
        
        // built in compare for the sort algorithm
        bool operator < (const wds& w1) const {
            return (f > w1.f);
        }
    };

public:
    WordFreq();
    int addWord(std::string);
    int getUniqueWords();
    void printFrequencyCount();
    void displayInOrder();
};


#endif /* WORDFREQ_H */

