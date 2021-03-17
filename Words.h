#ifndef Words_H
#define Words_H
#include <iostream>
#include <ostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ostream>

class Wordsy{
    public:
        Wordsy(const std::string &winput, const bool &wescaped);
        ~Wordsy() = default;
        bool getescaped() const;
        std::string getWordsy() const;
    private:
        std::string theword;
        bool isescaped;
};



class Words{
    public:
        Words(const std::string &input);
        Words(const Words &w);        // copy constructor
        ~Words() = default;                     // deconstructor
        const Words &operator=(const Words &w); // assignment operator
        int analyze(std::string input);
	    std::string getWord(int index)const; 
        bool getescapeB(int index) const;            
        [[nodiscard]]size_t size()const;
        [[nodiscard]]bool empty()const;
        bool get(size_t n, std::string &line, bool &escaped)const;

    private:
        std::vector<Wordsy> v;
	    int vsize;

};

std::ostream & operator<<(std::ostream &os, const Words &words);

#endif /* Words_H */
