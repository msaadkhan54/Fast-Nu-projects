#include<iostream>
#include<string>
using namespace std;

class Node {
public:
    char ch;
    Node* next;
    Node(char c){
        ch = c;
        next = 0;
    }
};

class HashSet {
public:
    int size;
    Node** table;

    HashSet(int s){
        size = s;
        table = new Node*[size];
        for(int i=0;i<size;i++) table[i] = 0;
    }

    int hashFunc(char c){
        return (int)c % size;
    }

    void insertChar(char c){
        int idx = hashFunc(c);
        Node* t = table[idx];
        while(t){
            if(t->ch == c) return;
            t = t->next;
        }
        Node* n = new Node(c);
        n->next = table[idx];
        table[idx] = n;
    }

    bool exists(char c){
        int idx = hashFunc(c);
        Node* t = table[idx];
        while(t){
            if(t->ch == c) return true;
            t = t->next;
        }
        return false;
    }
};

int bruteForceSearch(string text, string pattern){
    int n = text.length(), m = pattern.length();

    HashSet hs(257);
    for(int i=0;i<m;i++) hs.insertChar(pattern[i]);

    for(int i=0;i<=n-m;i++){
        if(!hs.exists(text[i])) continue;
        int j = 0;
        while(j<m && text[i+j] == pattern[j]) j++;
        if(j == m) return i;
    }
    return -1;
}

int main(){
    string text, pat;
    cout << "Enter log string:\n";
    getline(cin, text);
    cout << "Enter pattern:\n";
    getline(cin, pat);
    int pos = bruteForceSearch(text, pat);

    cout << "RESULT\n";
    cout << "Starting Index: " << pos << "\n";
}

