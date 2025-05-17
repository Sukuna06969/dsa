#include <cstddef>
#include<iostream>

template<typename _type>
class node{
    private:
        node *m_next;
        _type m_data;
    public:
        node(): m_next(nullptr),m_data(){}
        node(node<_type>& other){
            other.m_data = m_data;
            other.m_next = m_next;
        }
        _type getData(){
            return m_data;
        }
        node *next(){
            return m_next;
        }
};

template<typename _type>
class l_list{
    private:
        node<_type> head;
        node<_type> tail;
        int m_size;

    public:
        l_list(): m_size{0} {}
        
        l_list(l_list<_type>& other){
            other.tail = this->tail;
            other.head = this->head;
            other.m_size = this->m_size;
        }

    public:

        _type show_data(){
            return head.getData();
        }
};

int main(){
    l_list<int> llist;
}
