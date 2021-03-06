#include "Words.h"
#include "Words.h"      // I meant to do that.
#include <iostream>
#include <cassert>
#include <ostream>
 
using namespace std;


int main() {
    string w;
    bool b;
    const auto prog = R"(
        n = \a +\=(b+14226034) # š
        )";
 
    Words words(prog);
    cout << "There are " << words.size() << " words.\n";
    for (size_t i=0; i<words.size(); i++) {
        words.get(i, w, b);
        cout << i << ": ā" << w << "ā";
        if (b)
            cout << " (escaped)";
        cout << '\n';
    }
    cout << words << '\n';
 
    words.analyze(")\tQ\nā \rFNORD\f\v ");
    assert(words.size() == 4);
 
    const auto w2(words);
    assert(w2.get(3, w, b) && w == "FNORD" && !b);
    assert(!w2.get(999, w, b));
 
    cout << w2 << "\nDone.\n";
 
    return 0;
}
