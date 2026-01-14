#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
using namespace std;

class HashNode {
public:
    string key;
    string value;
    HashNode* next;

    HashNode(string k, string v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class HashTable {
private:
    static const int SIZE = 101;
    HashNode* table[SIZE];

    int hashFunc(const string& key) {
        int h = 0;
        for (char c : key)
            h = (h * 31 + c) % SIZE;
        return h;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = nullptr;
    }

    bool contains(const string& key) {
        int idx = hashFunc(key);
        HashNode* curr = table[idx];
        while (curr) {
            if (curr->key == key) return true;
            curr = curr->next;
        }
        return false;
    }

    string get(const string& key) {
        int idx = hashFunc(key);
        HashNode* curr = table[idx];
        while (curr) {
            if (curr->key == key) return curr->value;
            curr = curr->next;
        }
        return "";
    }

    void insert(const string& key, const string& value) {
        int idx = hashFunc(key);
        HashNode* node = new HashNode(key, value);
        node->next = table[idx];
        table[idx] = node;
    }
};

#endif
