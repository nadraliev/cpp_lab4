#include "fileentries.h"

FileEntries::FileEntries()
{
    entries = new vector<Entry>();
}

FileEntries::~FileEntries() {
    delete entries;
}

vector<Entry> *FileEntries::getEntries() {
    return entries;
}

void FileEntries::addEntry(int line, int indexInLine) {
    entries->push_back(Entry(line, indexInLine));
}
