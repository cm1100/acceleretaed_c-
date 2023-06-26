

// also finding where the word occurs
#include<iostream>
#include<vector>
#include<map>

using namespace std;

bool space(char c){
    return isspace(c);
}

bool not_space(char c){
    return !isspace(c);
}

vector<string>split(const string& str){
    typedef string::const_iterator iter;

    vector<string> ret;

    iter i = str.begin();
    while(i!= str.end()){
         i = find_if(i,str.end(),not_space);
         iter j = find_if(i,str.end(),space);

         if(i!=str.end()){
            ret.push_back(string(i,j));
         }
         i=j;
    }
    return ret;
}

map<string,vector<int> > xref(istream& in , vector<string> find_words(const string&)=split){


    string line;
    int line_number =0;
    map<string,vector<int> > ret;


    while(getline(in,line)){
        ++line_number;

        vector<string>words = find_words(line);

        for (vector<string>::const_iterator it = words.begin();it!=words.end();++it){
            ret[*it].push_back(line_number);
        }
    }
    return ret;
}


int main(){

    return 0;
}
