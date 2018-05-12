#ifndef FILEENTRIES_H
#define FILEENTRIES_H

#include <vector>
#include <entry.h>

using namespace std;

class FileEntries
{
public:
    FileEntries();
    ~FileEntries();
    vector<Entry> *getEntries();
    void addEntry(int line, int indexInLine);


private:
    vector<Entry> *entries;
};

#endif // FILEENTRIES_H
