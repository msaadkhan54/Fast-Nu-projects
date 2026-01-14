#ifndef NORMALIZER_H
#define NORMALIZER_H

#include<iostream>
#include<vector>
#include<string>
#include "KeywordAVL.h"
#include "HashTable.h"
using namespace std;
vector<string> normalizeTokens(const vector<string>& tokens) {

    KeywordAVL keywords;
    keywords.insert("int");
    keywords.insert("float");
    keywords.insert("if");
    keywords.insert("else");
    keywords.insert("while");
    keywords.insert("for");
    keywords.insert("return");
    keywords.insert("void");
    keywords.insert("char");
    keywords.insert("double");
    keywords.insert("bool");

    HashTable idMap;
    vector<string> normalized;
    int idCount = 1;

    for (int i = 0; i < tokens.size(); i++) {
        string tok = tokens[i];

        if (keywords.contains(tok)) {
            normalized.push_back(tok);
        }
        else if (isalpha(tok[0]) && tok != "(" && tok != ")" && tok != "{" && tok != "}") {

            if (idMap.contains(tok)) {
                normalized.push_back(idMap.get(tok));
            } else {
                string id = "ID" + to_string(idCount++);
                idMap.insert(tok, id);
                normalized.push_back(id);
            }
        }
        else {
            normalized.push_back(tok);
        }
    }
    return normalized;
}

#endif