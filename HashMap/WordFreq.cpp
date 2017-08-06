#include "WordFreq.h"

/*
 * no-param constructor
 * sets the word count to zero
 */
WordFreq::WordFreq(){
    uniqueWords = 0;
}

/**
 * add a word to the map. If the word is there increments the counter
 * @param w the word to add
 * @return returns this word's frequency
 */
int WordFreq::addWord(std::string w){
    if(freq.find(w) != freq.end()){
        ++freq[w];
    }else{
        freq.insert(std::pair<std::string, int>(w,1));
        uniqueWords++;
    }
    return freq[w];
}

/**
 * returns the number of unique words
 * (the size of the map)
 * @return 
 */
int WordFreq::getUniqueWords(){
    return uniqueWords;
}

/**
 * lists the words alphabetically with their frequency
 */
void WordFreq::printFrequencyCount(){
    int ctr = 0;
    for (std::map<std::string,int>::iterator it=freq.begin(); it!=freq.end(); ++it){
        std::cout << std::setw(15) << it->first << " => "
                << std::setw(3) <<  it->second << "   |";
        ctr++;
        if (ctr % 6 == 0)
            std::cout << std::endl;
    }    
    std::cout << std::endl << std::endl;
}

/**
 * lists the words by frequency
 */
void WordFreq::displayInOrder(){
    int ctr = 0;
    wds *dWords;
    dWords = new wds[uniqueWords];
    for (std::map<std::string,int>::iterator it=freq.begin(); it!=freq.end(); ++it){
        dWords[ctr].w = it->first;
        dWords[ctr].f = it->second;
        ctr++;
    }
    
    std::sort(dWords, dWords+uniqueWords);
    
    for(int i = 0; i < uniqueWords; i++){
        std::cout << std::setw(15) << dWords[i].w << " => " 
                << std::setw(3) << dWords[i].f << "   |";
        if ((i+1) % 6 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}