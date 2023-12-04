#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct WordSturct {
    int size;
    char word[51];
};

bool cmp(const WordSturct& a, const WordSturct& b){
    if(a.size == b.size) {
        for(int i = 0; i < a.size; i++){
            if(a.word[i] == b.word[i]) continue;
            return a.word[i] < b.word[i];
        }
    }
    return a.size < b.size;
}

void sort(WordSturct& s) {
    
}

int main(void){
    WordSturct word[20001];
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> word[i].word;
        word[i].size = strlen(word[i].word);
    }
    stable_sort(word, word + n, cmp);

    cout << word[0].word << endl;
    for(int i = 1; i < n; i++) {
        if(strcmp(word[i - 1].word, word[i].word) == 0) continue;
        cout << word[i].word << endl;
    }
}