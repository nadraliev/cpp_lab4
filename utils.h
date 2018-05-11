#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

using namespace std;

class Utils
{
public:
    Utils();
    static void stringTokenizer(string* line, char delimiter, vector<string> *tokens);
};

#endif // UTILS_H
