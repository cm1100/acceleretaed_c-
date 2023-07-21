#include<iostream>



template<class T> class Vec{
    public:

        typedef T* iterator;
        typedef const T* const_iterator;
        typedef size_t size_type;
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T& reference;
        typedef const T& const_reference;


        Vec() {create();}
        explicit Vec(size_type n, const T& val=T()){
            create(n,val);
        }

        Vec(const Vec& v){
            create(v.begin(),v.end());
        }

        Vec& operator=(const Vec&);

        size_type size const(return limit-data;)

        T& operator[](size_type i){
            return data[i];
        }
        const T& operator[](size_type i)const {
            return data[i];
        }

        iterator begin(){return data;}
        const_iterator begin const (){
            return data;
        }

        iterator end(){
            return limit;
        }
        const_iterator end const(){
            return limit;
        }
    private:
        iterator data; // first element in the vec
        iterator limit; // past one last element
};