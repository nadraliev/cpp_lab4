#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <utils.h>

using namespace std;

class Entry
{
public:
    Entry(int line, int indexInLine);
    int getLine();
    int getIndexInLine();
    string toString();

private:
    int line;
    int indexInLine;
};

#endif // ENTRY_H
