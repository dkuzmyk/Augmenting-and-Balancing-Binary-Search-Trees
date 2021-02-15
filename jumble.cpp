//
// Created by Dmytro Kuzmyk on 4/17/2019.
//


#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void ssort(string &s){
    sort(s.begin(), s.end());
}

int main(int argc, char *argv[]){

    std::unordered_map<std::string, vector<string>> word2freq;
    std::ifstream file;
    std::string word;

    string str_input;       // added a variable to store the user input

    if(argc != 2) {
        std::cout << "usage:  ./freq <filename>\n";
        std::cout << "goodbye\n";
        return 1;
    }

    file.open(argv[1], std::ios::in);

    if(!file.is_open()){
        std::cout << "Error: could not open file '" <<
                  argv[1] << "'\n";
        std::cout << "goodbye\n";
        return 1;
    }

    std::cout << "reading input file...\n";

    string key;                     // store new word
    int words;                      // store num of words
    int classes;                    // store num of classes
    string biggest_class;           // store the largest class string
    int big_class;                  // store the largest class size

// storing the file's words into the container
    while(file >> word) {
        // file >> word;
        key = word;                 // get the word
        ssort(key);                // sort the word
        // check of the class exists
        if(word2freq.count(key) == 0){              // if it doesnt exist
            word2freq[key] = vector<string>();      // create a class
            word2freq[key].push_back(word);         // insert the word into the vector class
            words++; classes++;                     // update the counts
        }
        // the class exists
        else {
            word2freq[key].push_back(word);         // store the word into the appropriate class
            words++;                                // update the word count
        }
        if(word2freq[key].size() > big_class){      // check if the biggest class is still same
            big_class = word2freq[key].size();      // update to new biggest class
            biggest_class = key;                    // update the word of the biggest class
        }
    }

file.close();                                       // not sure if the toy program forgot this
                                                    // or it's useless. But I'll put it to close the file
    std::cout <<
              "enter a word and I will tell you what I know about it\n";
    std::cout <<
              "when you are done, type ctrl-d (ctrl-z on windows)\n\n";
    std::cout << "> ";


    while(std::cin >> str_input) {
        ssort(str_input);               // get its class
        //cout << "> ";
        if(word2freq.count(str_input)==0) {
            std::cout << "sorry, '" << str_input <<
                      "' doesn't appear to have anagrams. '" << "'\n";
            cout << "> \n";

        }
        else {
            cout << "Found the following word combinations: " << endl;
            for(int i = 0; i < word2freq[str_input].size(); i++)
                cout << word2freq[str_input][i] << endl;
        }
	cout << "> ";
    }
    // user has quit.  Let's dump the map contents

    //std::cout << "word2freq contents:\n\n";

    printf("REPORT:\n");
    //printf("------------------------------------------\n\n");

    cout << "num_words: " << words << endl;
    cout << "num_classes: " << classes << endl;
    cout << "size-of-largest-class: " << big_class << endl;
    cout << "largest-class key: '" << biggest_class << "'" << endl;
    cout << "members of largest class: " << endl << endl;

    for(int j = 0; j < big_class; j++)
        cout << word2freq[biggest_class][j] << endl;

    return 0;
}
