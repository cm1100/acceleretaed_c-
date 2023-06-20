#include <iostream>
#include<vector>


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

