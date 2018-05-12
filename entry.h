#ifndef ENTRY_H
#define ENTRY_H


class Entry
{
public:
    Entry(int line, int indexInLine);
    int getLine();
    int getIndexInLine();

private:
    int line;
    int indexInLine;
};

#endif // ENTRY_H
