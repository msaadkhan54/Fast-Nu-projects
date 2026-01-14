
#ifndef SIMILARITY_H
#define SIMILARITY_H

#include<iostream>
#include "normalizer.h"
#include<vector>
#include<set>
#include<unordered_set>
#include<stack>
#include<string>
using namespace std;

int LCS(vector<string>& A, vector<string>& B) {
    int a= A.size();
	int b= B.size();
	int** LCS=new int*[a+1];
	for(int i=0;i<a+1;i++){
		LCS[i]=new int[b+1];
	}
	for(int k=0;k<=b;k++){
		LCS[0][k]=0;
	}
	for(int k=0;k<=a;k++){
		LCS[k][0]=0;
	}

	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			if(A[i-1]==B[j-1]){
				LCS[i][j]=1+LCS[i-1][j-1];
			}
			else{
				LCS[i][j] = max( LCS[i-1][j], LCS[i][j-1] );
			}
		}
	}
	int ans = LCS[a][b];

    for (int i = 0; i <= a; i++) delete[] LCS[i];
    delete[] LCS;
	return ans;
}
void merge(vector<string>& tokens, int st, int mid, int end) {
    vector<string> temp;
    int i = st, j = mid + 1;
    while (i <= mid && j <= end) {
        if (tokens[i] <= tokens[j]) temp.push_back(tokens[i++]);
        else temp.push_back(tokens[j++]);
    }
    while (i <= mid) temp.push_back(tokens[i++]);
    while (j <= end) temp.push_back(tokens[j++]);
    for (int idx = 0; idx < temp.size(); idx++) tokens[st + idx] = temp[idx];
}

void mergeSort(vector<string>& tokens, int st, int end) {
    if (st < end) {
        int mid = st + (end - st) / 2;
        mergeSort(tokens, st, mid);
        mergeSort(tokens, mid + 1, end);
        merge(tokens, st, mid, end);
    }
}
int hashToken(const string &token, int tableSize) {
    int hash = 0;
    for(char c : token)
    hash = (hash * 31 + c) % tableSize; // polynomial rolling hash
    return hash;
}
vector<vector<string>> buildHashTable(const vector<string>& tokens, int tableSize) {
    vector<vector<string>> hashTable(tableSize);
    for(string token : tokens) {
        int idx = hashToken(token, tableSize);
        hashTable[idx].push_back(token); // collision handled by chaining
    }
    return hashTable;
}
int countCommonTokens(const vector<vector<string>>& table1, const vector<vector<string>>& table2) {
    int common = 0;
    int tableSize = table1.size();
    for(int i = 0; i < tableSize; i++) {
        for(string tok1 : table1[i]) {
            for(string tok2 : table2[i]) {
                if(tok1 == tok2) common++;
            }
        }
    }
    return common;
}
int rabinKarpMatch(const vector<string>& tokens1, const vector<string>& tokens2, int patternLen) {
    if (tokens1.size() < patternLen || tokens2.size() < patternLen) 
        return 0;

    const  long d = 256;
    const long long q = 1000000007;

    unordered_set<long long> hashes1;
    long long hash = 0, power = 1;

    for (int i = 0; i < patternLen; i++) {
        hash = (hash * d + std::hash<string>{}(tokens1[i])) % q;
        if (i < patternLen - 1)
            power = (power * d) % q;
    }
    hashes1.insert(hash);

    for (int i = patternLen; i < tokens1.size(); i++) {
        hash = (hash - (std::hash<string>{}(tokens1[i - patternLen]) * power) % q + q) % q;
        hash = (hash * d + std::hash<string>{}(tokens1[i])) % q;
        hashes1.insert(hash);
    }

    int matches = 0;
    hash = 0;
    power = 1;

    for (int i = 0; i < patternLen; i++) {
        hash = (hash * d + std::hash<string>{}(tokens2[i])) % q;
        if (i < patternLen - 1)
            power = (power * d) % q;
    }
    if (hashes1.count(hash)) matches++;

    for (int i = patternLen; i < tokens2.size(); i++) {
        hash = (hash - (std::hash<string>{}(tokens2[i - patternLen]) * power) % q + q) % q;
        hash = (hash * d + std::hash<string>{}(tokens2[i])) % q;
        if (hashes1.count(hash)) matches++;
    }

    return matches;
}

struct Block {
    // string type;    
    int startIndex; 
    int depth;      
};

int nestedStructures(const vector<string>& tokens) {
    stack<Block> st;
    int maxDepth = 0;
    int currentDepth = 0;

    for (int i = 0; i < tokens.size(); i++) {
        string tok = tokens[i];

        // Start of a block
        if (tok == "if" || tok == "for" || tok == "while") {
            Block b;
            // b.type = tok;
            b.startIndex = i;
            b.depth = currentDepth + 1;
            st.push(b);
            currentDepth++;
            if (currentDepth > maxDepth) maxDepth = currentDepth;
        }

        // End of a block
        else if (tok == "}") {
            if (!st.empty()) {
                Block finished = st.top();
                st.pop();
                currentDepth--;
            }
        }
    }

    return maxDepth;
}

double computeTokenSimilarity(vector<string>& tokens1, vector<string>& tokens2){
    vector<string> normalFile1=normalizeTokens(tokens1);
    vector<string> normalFile2=normalizeTokens(tokens2);

    int lcsLen = LCS(normalFile1, normalFile2);
    double lcsSimilarity = (lcsLen * 100.0) / max(normalFile1.size(), normalFile2.size());

    int tableSize = 100;
    vector<vector<string>> table1 = buildHashTable(tokens1, tableSize);
    vector<vector<string>> table2 = buildHashTable(tokens2, tableSize);

    int commonTokens=countCommonTokens(table1,table2);

    double hashSimilarity = (commonTokens * 100.0) / max(normalFile1.size(), normalFile2.size());

    int patternLen = 5;
    int commonSegments = rabinKarpMatch(normalFile1, normalFile2, patternLen);
    double substringSimilarity =
        (commonSegments * 100.0) /
        (max(normalFile1.size(), normalFile2.size()) - patternLen + 1);

    int maxDepthFile1 = nestedStructures(normalFile1);
    int maxDepthFile2 = nestedStructures(normalFile2);

    double depthSimilarity = 100.0 - abs(maxDepthFile1 - maxDepthFile2) * 10;
    if (depthSimilarity < 0) depthSimilarity = 0;

    // prevent overflow
    if (lcsSimilarity > 100) lcsSimilarity = 100;
    if (hashSimilarity > 100) hashSimilarity = 100;
    if (substringSimilarity > 100) substringSimilarity = 100;
    if (depthSimilarity > 100) depthSimilarity = 100;
    if (lcsSimilarity < 0) lcsSimilarity = 0;
    if (hashSimilarity < 0) hashSimilarity = 0;
    if (substringSimilarity < 0) substringSimilarity = 0;
    if (depthSimilarity < 0) depthSimilarity = 0;

    double finalSimilarity =
          0.55 * lcsSimilarity
        + 0.20 * hashSimilarity
        + 0.15 * substringSimilarity
        + 0.10 * depthSimilarity;

    return finalSimilarity;

}

double computeFinalSimilarity(
    const vector<vector<string>>& table1,
    const vector<vector<string>>& table2
) {
    int tableSize = table1.size();

    int intersection = 0;
    int unionCount = 0;

    for (int i = 0; i < tableSize; i++) {

        for (int a = 0; a < table1[i].size(); a++) {
            for (int b = 0; b < table2[i].size(); b++) {

                if (table1[i][a] == table2[i][b]) {
                    intersection++;
                }

            }
        }

    }

    for (int i = 0; i < tableSize; i++) {

        unordered_set<string> bucketSet;

        for (int a = 0; a < table1[i].size(); a++) {
            bucketSet.insert(table1[i][a]);
        }

        for (int b = 0; b < table2[i].size(); b++) {
            bucketSet.insert(table2[i][b]);
        }

        unionCount += bucketSet.size();
    }

    if (unionCount == 0) return 0.0;

    double similarity = (double(intersection) / unionCount) * 100.0;

    return similarity;
}

#endif