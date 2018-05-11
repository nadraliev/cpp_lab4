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
