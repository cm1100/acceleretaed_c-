#include<iostream>
#include<vector>
#include<cctype>


using namespace std;


string substring(const string &s,int start,int end){
    string sub;
    for (int i=start;i<=end;i++){
        sub.push_back(s[i]);
    }

    return sub;
}

vector<string> split(const string &s){
    vector<string> ret;

    typedef string::size_type string_size;

    string_size i=0;
    // invariant: we have processed characters 
    while(i!=s.size()){

        // ignorig blanks
        while(i!=s.size()&&isspace(s[i])){
            ++i;
        }

      

        string_size j =i;
        while(j!=s.size() && !isspace(s[j])){
            ++j;
        }


        if(i!=j){
            ret.push_back(substring(s,i,j-1));
            i=j;
        }
    }


    return ret;
}


int main()
{   
    string s;
    while(getline(cin,s)){
        vector<string>v =split(s);
        for(vector<string>::size_type i=0;i!=v.size();i++){
            cout<<v[i]<<endl;

        }
    }
}