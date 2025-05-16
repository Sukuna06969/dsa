#include<iostream>

template<typename T>
class node{
    private:
        node *m_next;
        T m_data;
    public:
        node *next(){
            return m_next;
        }
};

template<typename T>
class l_list{
    private:
        node<T> head;
        
};
