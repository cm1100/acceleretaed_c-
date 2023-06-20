#include <iostream>
#include<vector>
#include<algorithm>


using namespace std;


string::size_type width(const vector<string>& v){

    string::size_type maxlen =0;
    for (vector<string>::size_type i =0;i!=v.size();i++){

        maxlen = max(maxlen,v[i].size());

    }
    return maxlen;
}


vector<string> vcat(const vector<string>& top,const vector<string>& bottom){

    vector<string>ret=top;

    ret.insert(ret.end(),bottom.begin(),bottom.end());

    return ret;
}

vector<string> hcat(const vector<string>& left,const vector<string>& right){
    vector<string> ret;

    string::size_type widthl = width(left)+1;

    vector<string>::size_type i=0,j=0;

    while(i!=left.size()||j!=right.size()){
        string s;

        if (i!=left.size()){
            s=left[i++];
        }

        s+=string(widthl-s.size(),' ');

        if(j!=right.size()){
            s+=right[j++];
        }

        ret.push_back(s);
    }


    return ret;
}


void adapter_example(const vector<string>& bottom){
    vector<string>ret;
    copy(bottom.begin(),bottom.end(),back_inserter(ret));
}


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

bool is_palindrome(const string & s){
    return equal(s.begin(),s.end(),s.rbegin());
}


bool not_url_char(char c){
    static const string url_ch = "~;?:@=&$-_.+!*'(),";

    return !(isalnum(c)||find(url_ch.begin(),url_ch.end(),c)!=url_ch.end());
}


string::const_iterator url_end(string::const_iterator b , string::const_iterator e){
    
}

vector<string> find_urls(const string s){

    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(),e=s.end();

    while(b!=e){
        b = url_beg(b,e);

        if(b!=e){
        iter after = url_end(b,e);
        ret.push_back(string(b,after));
        b=after;
    }
    }

   
    return ret;
}


