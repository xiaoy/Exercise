#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    typedef map<string, vector<string> > chordMap;
    chordMap jazz_chord;
    vector<string> cmajor;
    cmajor.push_back("C");
    cmajor.push_back("E");
    cmajor.push_back("D");
    pair<chordMap::iterator, bool> ret = jazz_chord.insert(make_pair(string("C major"), cmajor));
    if(ret.second) {
        cout<<ret.first->first<<"insert success\n";
    }else {
        cout<<ret.first->first<<"insert failed\n";
    }
    chordMap::const_iterator iter = jazz_chord.find("C major");
    if(iter != jazz_chord.end()) {
        cout<<"find"<<iter->first<<endl;
    }
    return 0;
}
