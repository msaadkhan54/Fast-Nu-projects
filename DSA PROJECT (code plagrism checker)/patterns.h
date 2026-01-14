#ifndef PATTERNS_H
#define PATTERNS_H

#include <iostream>
#include <string>
using namespace std;

// ======================== SINGLY LINKED LIST ========================
struct Node {
    string data;
    Node* next;
    Node(string val) : data(val), next(nullptr) {}
};

struct LinkedList {
    Node* head;
    LinkedList() : head(nullptr) {}

    void append(const string& val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    int size() const {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    string get(int index) const {
        Node* temp = head;
        int i = 0;
        while (temp) {
            if (i == index) return temp->data;
            temp = temp->next;
            i++;
        }
        return ""; // invalid index
    }
};

// ======================== COUNT LOOPS ==========================
int countLoops(const LinkedList& tokens) {
    int count = 0;
    Node* temp = tokens.head;
    while (temp) {
        if (temp->data == "for" || temp->data == "while") count++;
        temp = temp->next;
    }
    return count;
}

// ======================== COUNT IF / ELSE ========================
int countConditionals(const LinkedList& tokens) {
    int count = 0;
    Node* temp = tokens.head;
    while (temp) {
        if (temp->data == "if" || temp->data == "else") count++;
        temp = temp->next;
    }
    return count;
}

// ======================== FUNCTION COUNT =========================
int countFunctions(const LinkedList& tokens) {
    int count = 0;
    Node* prev = nullptr;
    Node* curr = tokens.head;
    Node* next = nullptr;

    if (curr) next = curr->next;
    while (next) {
        if (next->data == "(" && prev && prev->data != "if" && prev->data != "for" && prev->data != "while") {
            count++;
        }
        prev = curr;
        curr = next;
        next = next->next;
    }
    return count;
}

// ======================== NESTING DEPTH ==========================
struct StackNode {
    char data;
    StackNode* next;
    StackNode(char c) : data(c), next(nullptr) {}
};

class Stack {
private:
    StackNode* top;
public:
    Stack() : top(nullptr) {}
    void push(char c) {
        StackNode* newNode = new StackNode(c);
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (!top) return;
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
    bool empty() { return top == nullptr; }
};

int computeNestingDepth(const LinkedList& tokens) {
    Stack st;
    int depth = 0, maxDepth = 0;
    Node* temp = tokens.head;
    while (temp) {
        if (temp->data == "{") {
            st.push('{');
            depth++;
            if (depth > maxDepth) maxDepth = depth;
        } else if (temp->data == "}") {
            if (!st.empty()) {
                st.pop();
                depth--;
            }
        }
        temp = temp->next;
    }
    return maxDepth;
}

// ======================== OPERATOR FREQUENCY (DYNAMIC ARRAY) =====================
struct OpFreq {
    string op;
    int count;
};

int findOpIndex(OpFreq ops[], int size, const string& op) {
    for (int i = 0; i < size; i++) {
        if (ops[i].op == op) return i;
    }
    return -1;
}

OpFreq* operatorFrequency(const LinkedList& tokens, int& size) {
    string opsArr[] = { "+", "-", "*", "/", "%", "=", "+=", "-=", "==", "!=", "<", ">", "<=", ">=" };
    size = sizeof(opsArr) / sizeof(opsArr[0]);
    OpFreq* freq = new OpFreq[size];
    for (int i = 0; i < size; i++) {
        freq[i].op = opsArr[i];
        freq[i].count = 0;
    }

    Node* temp = tokens.head;
    while (temp) {
        int idx = findOpIndex(freq, size, temp->data);
        if (idx != -1) freq[idx].count++;
        temp = temp->next;
    }
    return freq;
}

// ======================== SEQUENCE PATTERNS =====================
struct SeqPattern {
    string pattern;
    int count;
};

void bubbleSort(SeqPattern arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].count < arr[j+1].count) {
                SeqPattern temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

SeqPattern* sequencePatterns(const LinkedList& tokens, int& size) {
    int maxPairs = tokens.size() - 1;
    if (maxPairs <= 0) {
        size = 0;
        return nullptr;
    }

    size = maxPairs;
    SeqPattern* patterns = new SeqPattern[size];

    Node* curr = tokens.head;
    for (int i = 0; i < maxPairs; i++) {
        patterns[i].pattern = curr->data + " -> " + curr->next->data;
        patterns[i].count = 1; // count is dummy, could be enhanced
        curr = curr->next;
    }

    bubbleSort(patterns, size);
    return patterns;
}

// ======================== PRINT REPORT ===========================
void printPatternReport(const LinkedList& tokens) {
    cout << "\n======== CODE PATTERN ANALYSIS ========\n";
    cout << "Loops Found: " << countLoops(tokens) << endl;
    cout << "If/Else Found: " << countConditionals(tokens) << endl;
    cout << "Functions Found: " << countFunctions(tokens) << endl;
    cout << "Max Nesting Depth: " << computeNestingDepth(tokens) << endl;

    cout << "\nOperator Usage:\n";
    int opSize;
    OpFreq* ops = operatorFrequency(tokens, opSize);
    for (int i = 0; i < opSize; i++) {
        if (ops[i].count > 0)
            cout << "  " << ops[i].op << " : " << ops[i].count << endl;
    }
    delete[] ops;

    cout << "\nSequence Patterns (top transitions):\n";
    int seqSize;
    SeqPattern* seq = sequencePatterns(tokens, seqSize);
    for (int i = 0; i < min(seqSize, 10); i++) {
        cout << "  " << seq[i].pattern << " : " << seq[i].count << endl;
    }
    delete[] seq;

    cout << "========================================\n";
}

#endif
