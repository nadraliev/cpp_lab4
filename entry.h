#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <utils.h>

using namespace std;

class Entry
{
public:
    Entry(int line, int indexInLine, string text);
    int getLine();
    int getIndexInLine();
    string getText();
    string toString();

private:
    int line;
    int indexInLine;
    string text;
};

#endif // ENTRY_H
