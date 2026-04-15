#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <cctype>

using namespace std;


struct Compare {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second == b.second)
            return a.first > b.first; 
        return a.second < b.second;   
    }
};

int main() {

    ifstream fin("input.txt");
    if (!fin) {
        cout << "File error\n";
        return 0;
    }

    string text, line;

   
    while (getline(fin, line)) {
        text += line + " ";
    }

   
    for (char& c : text)
        c = (char)tolower(c);

    map<string, int> freq;

    string separators = " ,?.!";

    
    size_t start = 0;
    while (start < text.size()) {

       
        while (start < text.size() && separators.find(text[start]) != string::npos)
            start++;

        if (start >= text.size()) break;

        size_t end = start;

       
        while (end < text.size() && separators.find(text[end]) == string::npos)
            end++;

        string word = text.substr(start, end - start);

        freq[word]++;

        start = end;
    }

   
    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;

    for (auto& it : freq)
        pq.push(it);

    
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        cout << top.first << " => " << top.second << endl;
    }

    return 0;
}