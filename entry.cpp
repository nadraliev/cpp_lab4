#include "entry.h"

Entry::Entry(int line, int indexInLine)
{
    this->line = line;
    this->indexInLine = indexInLine;
}

int Entry::getIndexInLine() {
    return indexInLine;
}

int Entry::getLine() {
    return line;
}

string Entry::toString() {
    return Utils::format("Line %d, indexInLine %d", line, indexInLine);
}
