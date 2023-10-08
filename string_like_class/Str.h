#include<iostream>
#include<vector>

class Str{


    public:

    typedef std::vector<char>::size_type size_type;

    // default constructor contains an empty str
    Str(){

    }

    // create a string containing empty copies of c
    Str(size_type n ,char c):data(n,c){

    }

    // create a Str from a null terminated array
    Str(const char* cp){
        std::copy(cp,cp+std::strlen(cp),std::back_inserter(data));
    }


    friend std::istream& operator>>(std::istream &, Str&);


    // create a Str from the range denoted by iterators b and e
    template<class In> Str(In b,In e){
        std::copy(b,e,std::back_inserter(data));
    }



    char& operator[](size_type i){
        return data[i];
    }


    const char& operator[](size_type i) const{
        return data[i];
    }


    Str& operator+=(const Str& s){
        std::copy(s.data.begin(),s.data.end(),std::back_inserter(data));
        return *this;
    }


    size_type size() const{
        return data.size();
    }

   


    private:
    std::vector<char> data;

};



//std::istream& operator>>(std::istream &, Str&);
std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&,const Str&);

