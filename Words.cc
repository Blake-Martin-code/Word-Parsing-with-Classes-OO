#include "Words.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <ostream>
using namespace std;

ostream & operator<<(ostream &os, const Words &words){
    // print all the words of the given Words object
    // separated by only commas
    for (long unsigned int i = 0; i < words.size(); i++){
        if (i == words.size()-1) {
            os<< words.getWord(i);
        }
        else{
            os<<words.getWord(i)<<",";
        }
    }
    return os;
}

Wordsy::Wordsy(const string &winput, const bool &wescaped){
    theword = winput;
    isescaped = wescaped;
}
bool Wordsy::getescaped() const{
    return Wordsy::isescaped;
}
string Wordsy::getWordsy() const{
    return Wordsy::theword;
}

void lineParse(string line, vector<Wordsy> &v){
    // parse the line for words, given the definition of a word
    // in the directions. put each of these words into the vector.
    string temp;
    bool escapeTemp;
    while(line.size() > 0){ // there are still contents in the string that need to be parsed
        int firstChar = line.find_first_of(" \f\n\r\t\v \\ ()");  // these are the key characters that we are looking to parse by
        // there are special cases for if the key character is at the beginning of the string or not
        if (firstChar == 0){
            // a back slash escapes the next character so add the character to the temp string
            // and erase both from the line, set escape to true so we know it has been escaped
            if (line[firstChar] == '\\'){
                temp.push_back(line[firstChar+1]);
                line.erase(0,2);
                escapeTemp = true;
            }
            // a ) is its own word so you need to create a wordsy object of the temp variable if it isnt empty
            // push it onto the vecotr, create a wordsy object of the ), push it onto the stack and erase the ) from line
            else if (line[firstChar] == ')'){
                if(!temp.empty()){
                    Wordsy newword(temp, escapeTemp);
                    v.push_back(newword);
                    temp.clear();
                    escapeTemp = false;
                }
                Wordsy newword1(")", false);
                v.push_back(newword1);
                line.erase(0,1);
            }
            // a ( is its own word so you need to create a wordsy object of the temp variable if it isnt empty
            // push it onto the vecotr, create a wordsy object of the (, push it onto the stack and erase the ( from line
            // reset escape bool
            else if (line[firstChar] == '('){
                if(!temp.empty()){
                    Wordsy newword(temp, escapeTemp);
                    v.push_back(newword);
                    temp.clear();
                    escapeTemp = false;
                }
                Wordsy newword1("(", false);
                v.push_back(newword1);
                line.erase(0,1);
            }
            // if the key character is not a '\' or ( or ) then it is another word delimiting character
            // if the temp variable is empty then you can just simply delete the key char from line
            // if temp is not empty then create a wordsy object out of it and push onto vector
            // clear the temp, erase from line and reset escape bool
            else{
                if(temp.empty()){
                    line.erase(0,1);
                }
                else{
                    Wordsy newword(temp, escapeTemp);
                    v.push_back(newword);
                    temp.clear();
                    line.erase(0,1);
                    escapeTemp = false;
                }
            }
        }
        // the key char is not at the beginning of the line
        else{
            // if the key char is a '\' then you can add the previous chars to temp including the char after the '\' 
            // erase from line, set escape to true so we know word has been escaped
            if (line[firstChar] == '\\'){
                temp.append(line.substr(0,firstChar));
                temp.push_back(line[firstChar+1]);
                line.erase(0,firstChar+2);
                escapeTemp = true;
            }
            // if key char is a ) then we can append the previous chars to temp and create a new wordsy object to push onto
            // the vector, clear temp, create a wordsy object with ) push onto stack, erase from line and reset escape.
            else if (line[firstChar] == ')'){
                temp.append(line.substr(0,firstChar));
                Wordsy newword(temp, escapeTemp);
                v.push_back(newword);
                temp.clear();
                Wordsy newword1(")", false);
                v.push_back(newword1);
                line.erase(0,firstChar+1);
                escapeTemp = false;
            }
            // if key char is a ( then we can append the previous chars to temp and create a new wordsy object to push onto
            // the vector, clear temp, create a wordsy object with ( push onto stack, erase from line and reset escape.
            else if (line[firstChar] == '('){
                temp.append(line.substr(0,firstChar));
                Wordsy newword(temp, escapeTemp);
                v.push_back(newword);
                temp.clear();
                Wordsy newword1("(", false);
                v.push_back(newword1);
                line.erase(0,firstChar+1);
                escapeTemp = false;
            }
            // if the key char is not '\' or ( or ) then it is another word delimiter. append the previous chars to the temp
            // create a new wordsy object with temp and push onto vector. clear temp, erase from line and reset escapetemp
            else{
                temp.append(line.substr(0,firstChar));
                Wordsy newword(temp, escapeTemp);
                v.push_back(newword);
                temp.clear();
                line.erase(0,firstChar+1);
                escapeTemp = false;
            }
        }
    }
 
}

Words::Words(const string &input){
    // given a string input, parse the input for words.
    // Put each word into a vector so you can access this
    // vectors size and get words from the vector.
    // parse the input using lineParse();
    string newstringy = input;
    newstringy.append("\n");        // this ensures there is always a newline character at end of the input 
	lineParse(newstringy, v);       // so that the parse function will always get the last character
	vsize = v.size();               // incase of a syntactical mishap.
} 

// this method is not needed because the copy constructor was assigned to default
/*Words::Words(const Words &w){
     copy all information from another object of the
     same class but do not replace the previous information
}*/

const Words &Words::operator=(const Words &w){
    // copy all information from another object of the same
    // class, replacing any previous information
    this->v = w.v;
    this->vsize = w.v.size();
    return *this;
}

Words::Words(const Words &w){
//    copy all information from another object of the
//     same class but do not replace the previous information
    this->v = w.v;
    this->vsize = w.vsize;
}

int Words::analyze(string input){
    // perform lexical analysis on the given multi-line input
    // calling this method more than once will "start from scratch" 
    // and ignore any previous input
    input.append("\n");
    v.clear();
    lineParse(input, v);
    vsize = v.size();
    return 1;
}             

string Words::getWord(int index)const{
	return this->v[index].getWordsy();
}
bool Words::getescapeB(int index) const{
    return this->v[index].getescaped();
}

[[nodiscard]]size_t Words::size()const{
    // return how many words there are. This is done
    // by return the size of the vector member field
    return vsize;
}

[[nodiscard]]bool Words::empty()const{
    // return true iff there are no words in this object. 
    // Ignoring the result of this method must generate a 
    // compile-time warning?
    if(this->v.size() == 0) return true;
    else return false;
}

bool Words::get(size_t n, string &line, bool &escaped)const{
    // the first argument "n" is an index into the words, where 
    // 0 represents the first word. if n is out of range, return false 
    // to indicate failure. Otherwise, set the string argument to the 
    // corresponding word, set the bool argument to true if that word
    // was escaoed in the input and false if not, and return true to
    // indicate success. "escaped" means any character of that word was 
    // escaped by a backslash
    if (n > v.size()-1){
        escaped = false;
        line = "";
        return false;
    }
    else{
        line = v[n].getWordsy();
        // if that word was escaped in input set bool argument
        // equal to true, if not set it equal to false and 
        // return true either way
        if(v[n].getescaped() == true){
            escaped = true;
            return true;
        }
        else{
            escaped = false;
            return true;
        }
    }
}
