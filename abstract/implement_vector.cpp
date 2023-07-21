#include<iostream>
#include"implement_vector.h"



template<class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs){
    if(&rhs!=this){
        uncreate();
        create(rhs.begin(),rhs.end())
    }
    return *this;
}



