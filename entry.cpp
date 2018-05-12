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
