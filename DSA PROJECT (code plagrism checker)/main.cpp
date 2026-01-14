// main.cpp
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>      // for setprecision
#include "normalizer.h"
#include "similarity.h"
#include "tokenizer.h"
#include "utlis.h"
#include "patterns.h"
using namespace std;

// small helper: convert vector<string> -> LinkedList (patterns.h)
LinkedList vectorToLinkedList(const vector<string>& tokens) {
    LinkedList list;
    for (const string &t : tokens) list.append(t);
    return list;
}

int main() {
    // --- 1) Read files (hardcoded names used in your original main) ---
    string file1 = readFile("file1.cpp");
    string file2 = readFile("file2.cpp");

    if (file1 == "error" || file2 == "error") {
        cout << "Error reading files. Exiting..." << endl;
        return 0;
    }

    // --- 2) Clean files ---
    file1 = cleaning(file1);
    file2 = cleaning(file2);

    // --- 3) Tokenize ---
    vector<string> tokens1 = tokenize(file1);
    vector<string> tokens2 = tokenize(file2);

    // --- 4) Normalize tokens ---
    vector<string> normalTokens1 = normalizeTokens(tokens1);
    vector<string> normalTokens2 = normalizeTokens(tokens2);

    // --- 4b) Optional safe sort (guard against empty vectors) ---
    if (normalTokens1.size() > 1) mergeSort(normalTokens1, 0, (int)normalTokens1.size() - 1);
    if (normalTokens2.size() > 1) mergeSort(normalTokens2, 0, (int)normalTokens2.size() - 1);

    // --- 5) Compute similarity (your engine) ---
    double similarity = computeTokenSimilarity(tokens1, tokens2);

    // --- 6) Print similarity nicely ---
    cout << fixed << setprecision(2);
    cout << "\n====================================\n";
    cout << "Plagiarism Similarity: " << similarity << " %\n";
    cout << "====================================\n";

    // --- 7) Convert normalized tokens to LinkedList and print pattern reports ---
    LinkedList list1 = vectorToLinkedList(normalTokens1);
    LinkedList list2 = vectorToLinkedList(normalTokens2);

    cout << "\n===== Pattern Report for File 1 =====\n";
    printPatternReport(list1);

    cout << "\n===== Pattern Report for File 2 =====\n";
    printPatternReport(list2);

    cout << "\nDone.\n";
    return 0;
}

