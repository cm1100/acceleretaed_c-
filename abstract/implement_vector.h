#include<iostream>
#include<memory>


/*
Invariants of the class

1. data points at our initial data element  , if we have any , and is zero otherwise
2. data<=avail<=limit
3. Elements have been constructed in range(data,avail)
4. Elements have not been constructed in range(avail,limit)

*/



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
        Vec(const_iterator a,const_iterator b){
            create(a,b);
        }

        ~Vec(){
            uncreate();
        }

        size_type size() const
        {return avail-data;}

        T& operator[](size_type i){
            return data[i];
        }
        const T& operator[](size_type i)const {
            return data[i];
        }

        iterator begin(){return data;}
        const_iterator begin() const {
            return data;
        }

        iterator end(){
            return avail;
        }
        const_iterator end() const{
            return limit;
        }

        void push_back(const T& val){
            if(avail==limit){
                grow();
            }
            unchecked_append(val);

        }
    private:
        iterator data; // as before , pointer to the first element in vec
        iterator avail;// pointer to (one past) the last constructed element
        iterator limit; // now points to(one past) the last availible element

        std::allocator<T> alloc;

        void create();
        void create(size_type,const T&);
        void create(const_iterator,const_iterator);

        void uncreate();
        void grow();
        void unchecked_append(const T&);
};