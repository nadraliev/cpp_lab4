#include "utils.h"
#include <bits/stdc++.h>

Utils::Utils()
{

}

void Utils::stringTokenizer(string *line, char delimiter, vector<string> *tokens) {
    stringstream stream(*line);
    string temp;
    while (getline(stream, temp, delimiter)) {
        tokens->push_back(temp);
    }
}

string Utils::readFile(const string &path) {
    ifstream file(path);
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void Utils::replaceAll(string &str, const string &from, const string &to) {
    size_t index = 0;
    while (true) {
        index = str.find(from, index);
        if (index == string::npos) break;

        str.replace(index, from.size(), to);

        index += to.size();
    }
}
