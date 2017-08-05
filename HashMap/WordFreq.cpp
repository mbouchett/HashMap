#include "WordFreq.h"

WordFreq::WordFreq(){
    uniqueWords = 0;
}

int WordFreq::addWord(std::string w){
    if(freq.find(w) != freq.end()){
        ++freq[w];
    }else{
        freq.insert(std::pair<std::string, int>(w,1));
        uniqueWords++;
    }
    return freq[w];
}