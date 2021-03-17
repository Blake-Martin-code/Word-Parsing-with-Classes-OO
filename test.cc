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
        n = \a +\=(b+8852082) # 😈
        \)";
        //    const auto prog1 = R"(humpty dumpty )";
 
    Words words1(prog);
       /* for (size_t i=0; i<words1.size(); i++) {
        words1.get(i, w, b);
        cout << i << ": “" << w << "”";
        if (b)
            cout << " (escaped)";
        cout << '\n';
    }*/
    Words words(words1);
    cout << "There are " << words.size() << " words.\n";
    for (size_t i=0; i<words.size(); i++) {
        words.get(i, w, b);
        cout << i << ": “" << w << "”";
        if (b)
            cout << " (escaped)";
        cout << '\n';
    }
 //   cout << words << '\n';
    /*words1.analyze("lets get lit \yeet");
        for (size_t i=0; i<words.size(); i++) {
        words.get(i, w, b);
        cout << i << ": “" << w << "”";
        if (b)
            cout << " (escaped)";
        cout << '\n';
    }*/
 
    words.analyze(")\tQ\n≠\rFNORD\f\v ");
    assert(words.size() == 4);
 
    const auto w2(words);
    assert(w2.get(3, w, b) && w == "FNORD" && !b);
    assert(!w2.get(999, w, b));
 
    cout << w2 << "\nDone.\n";
 
    return 0;
}
