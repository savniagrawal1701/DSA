#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Node {
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};

class Trie {
    Node* root;
public:
    Trie() { root = new Node(); }
    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) node->put(ch, new Node());
            node = node->get(ch);
        }
        node->setEnd();
    }
    bool checkIfAllPrefixesExist(string word) {
        Node* node = root;
        for (char ch : word) {
            if (node->containsKey(ch)) {
                node = node->get(ch);
                if (!node->isEnd()) return false;
            } else return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a) {
    Trie* trie = new Trie();
    for (auto &s : a) trie->insert(s);
    string longest = "";
    for (auto &s : a) {
        if (trie->checkIfAllPrefixesExist(s)) {
            if (s.length() > longest.length()) longest = s;
            else if (s.length() == longest.length() && s < longest) longest = s;
        }
    }
    return longest == "" ? "None" : longest;
}
int main() {
 
    vector<string> words = {"n", "ni", "nin", "ninj", "ninja", "ninga"};
    int n = words.size();

    string result = completeString(n, words);

    cout << "Longest Complete String: " << result << endl;

    return 0;
}