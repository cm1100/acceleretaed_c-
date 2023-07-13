#include<iostream>

using namespace std;

char* duplicate_chars(const char * p){
    size_t length = strlen(p)+1;
    cout<<length<<endl;
    char * result = new char[length];
    copy(p,p+length,result);
    copy(result,result+length,ostream_iterator<char>(cout,""));
    return result;
}

int main(){

    char arr[ ]={'h','k','l','\0'};
    duplicate_chars(arr);
    return 0;
}