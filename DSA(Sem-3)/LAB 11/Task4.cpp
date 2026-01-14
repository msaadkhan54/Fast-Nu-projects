#include<iostream>
using namespace std;

class Node {
public:
    int key, freq;
    Node* next;
    Node(int k){
        key = k;
        freq = 1;
        next = 0;
    }
};

class HashTable {
public:
    int size;
    Node** table;

    HashTable(int s){
        size = s;
        table = new Node*[size];
        for(int i=0;i<size;i++) table[i] = 0;
    }

    int hashFunc(int x){
        if(x < 0) x = -x;
        return x % size;
    }

    void insertKey(int x){
        int idx = hashFunc(x);
        Node* t = table[idx];
        while(t){
            if(t->key == x){
                t->freq++;
                return;
            }
            t = t->next;
        }
        Node* n = new Node(x);
        n->next = table[idx];
        table[idx] = n;
    }

    int mostFrequent(){
        int bestFreq = 0, ans = -1;
        for(int i=0;i<size;i++){
            Node* t = table[i];
            while(t){
                if(t->freq > bestFreq){
                    bestFreq = t->freq;
                    ans = t->key;
                }
                else if(t->freq == bestFreq && t->key > ans){
                    ans = t->key;
                }
                t = t->next;
            }
        }
        return ans;
    }
};

int main(){

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[1000];
    cout << "Enter array elements:\n";
    for(int i=0;i<n;i++) cin >> arr[i];

    HashTable h(1009);
    for(int i=0;i<n;i++) h.insertKey(arr[i]);

    int ans = h.mostFrequent();
    cout << "RESULT\n";
    cout << "Most Frequent Element: " << ans << "\n";
}

