#include "entry.h"

Entry::Entry(int line, int indexInLine, string text)
{
    this->line = line;
    this->indexInLine = indexInLine;
    this->text = text;
}

int Entry::getIndexInLine() {
    return indexInLine;
}

int Entry::getLine() {
    return line;
}

string Entry::toString() {
    return Utils::format("Line %d, indexInLine %d, text %s", line + 1, indexInLine + 1, text.c_str());
}

string Entry::getText() {
    return text;
}
