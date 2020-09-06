#include "anagram.h"
#include<algorithm>
using namespace std;

void removeSpace(std::string& w) {
    int count = 0;
    for (int i = 0; w[i]; i++) {
        if (w[i] != ' ') {
            w[count] = w[i];
            count++;
        }
    }
    w.erase(w.begin()+count,w.end());
    
}


void string_align(std::string& w) {
    transform(w.begin(), w.end(), w.begin(), ::tolower);
    
    removeSpace(w);

}


bool charWiseCompare(const std::string& w1, const std::string& w2) {
    int size = w1.size();
    for (int i = 0; i < size; i++) {
        if (w1[i] != w2[i]) {
            return false;
        }
    }
    return true;
}

bool Anagram::WordPairIsAnagram(const std::string& word1, const std::string& word2) {
    //Fill the correct implementation here
    
    std::string w1 = word1;
    std::string w2 = word2;
    
    string_align(w1);
    string_align(w2);

    sort(w1.begin(), w1.end());
    sort(w2.begin(), w2.end());
    
     return  (w1.size()==w2.size())&&charWiseCompare(w1,w2);
}

std::vector<std::string> Anagram::SelectAnagrams(
        const std::string& word,
        const std::vector<std::string>& candidates) {
    //Fill the correct implementation here

    std::vector<std::string> ans;
    for (unsigned int i = 0; i < candidates.size(); i++) {
        if (Anagram::WordPairIsAnagram(word, candidates[i])) {
            ans.push_back(candidates[i]);
        }
    }
    return ans;
}
