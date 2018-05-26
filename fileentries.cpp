#include "fileentries.h"

FileEntries::FileEntries(string path)
{
    entries = new vector<Entry>();
    this->path = path;
}

FileEntries::~FileEntries() {
    delete entries;
}

vector<Entry> *FileEntries::getEntries() {
    return entries;
}

void FileEntries::addEntry(int line, int indexInLine, string &text) {
    entries->push_back(Entry(line, indexInLine, text));
}

string FileEntries::toString() {
    string result = Utils::format("|-Entries in file %s\n", path.c_str());
    for (Entry entry: *entries) {
        result += Utils::format("|---- %s\n", entry.toString().c_str());
    }
    return result;
}
