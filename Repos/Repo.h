#pragma once
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
class Repo {
private:
    vector<T> entities;
public:
    Repo();
    Repo(T& r);
    void add(T& e);
    bool find(T& e);
    void update(int index, T& nou);
    void remove(int index);
    T get(int index);
    vector<T> get_all();
    unsigned int size();
    Repo& operator=(const Repo& r);
    ~Repo();
};

template<class T>
inline Repo<T>::Repo(){
    entities.reserve(3);
}

template<class T>
inline Repo<T>::Repo(T& r) {
    this->entities = r.entities;
}

template<class T>
inline bool Repo<T>::find(T& e) {
    typename std::vector<T>::iterator it = std::find(entities.begin(), entities.end(), e);
    if (it != entities.end()) return true;
    return false;
}

template<class T>
inline void Repo<T>::add(T& e) {
    entities.push_back(e);
}


template<class T>
inline void Repo<T>::update(int index, T& nou) {
    this->entities[index] = nou;
}

template<class T>
inline void Repo<T>::remove(int index) {
    T e = entities[index];
    typename vector<T>::iterator it = std::find(entities.begin(), entities.end(), e);
    if (it != entities.end()) entities.erase(it);
}

template<class T>
inline T Repo<T>::get(int index) {
    return this->entities[index];
}

template<class T>
inline vector<T> Repo<T>::get_all() {
    return entities;
}

template<class T>
inline unsigned int Repo<T>::size() {
    return entities.size();
}

template<class T>
inline Repo<T>& Repo<T>::operator=(const Repo<T>& r) {
    if (this != &r) {
        this->entities = r.entities;
    }
    return *this;
}

template<class T>
inline Repo<T>::~Repo() {}
