include <iostream>                              
#include <string>                                
#include <vector>
using namespace std;                             
int main()                                       
{
    string word;
    vector<string> word_vec;
    for(int i = 0; i < 4; ++i) {
        cin>>word;
        word_vec.push_back(word);
    }
    vector<string>::reverse_iterator iter;
    for(iter = word_vec.rbegin(); iter != word_vec.rend(); ++iter) {
        word = *iter;
        string word1 = word;
        for(int j = 0; j < word.length(); ++j) {
            word1[j-1] = word[word.length()-j];
        }
        if(!word.compare(word1)) {
            cout<<word<<endl;
        }
    }
}
