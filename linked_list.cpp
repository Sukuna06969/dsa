#include<iostream>
#include <optional>

template<typename _type>
class node{
    private:
        node<_type> *m_next;
        _type m_data;
    public:
        node(): m_next(nullptr),m_data(_type{}){}
        node(const _type& data) : m_next(nullptr), m_data(data) {}   // Copy constructor
        node(_type&& data) : m_next(nullptr), m_data(std::move(data)) {}  // Move constructor

        node(const node<_type>& other):m_next(other.m_next()),m_data(other.getData()){}

        ~node(){
            m_next = nullptr;
        }
        
    public:

        _type getData() const{
            return m_data;
        }
        node *next() const{
            return m_next;
        }

        void setData(_type& data){
            this->m_data = data;      //copying data here
        }

        void setData(_type&& data){
            this->m_data = std::move(data);
        }

        void setNext(node<_type>* new_next){
            this->m_next = new_next;
        }
};

template<typename _type>
class l_list{
    private:
        node<_type>* m_head;
        node<_type>* m_tail;
        int m_size;

    public:
        l_list(): m_size{0},m_head(nullptr),m_tail(nullptr) {}
        
        l_list(l_list<_type>& other):
            m_head(nullptr),m_tail(nullptr),m_size(other.m_size){
                node<_type>* current = other.m_head;
                while(current){
                    this->add(current->getData());
                    current = current->next();
                }
            }
        ~l_list(){
            while(m_head){
                auto temp = m_head;
                m_head = m_head->next();
                delete temp;
            }
            m_tail = nullptr;
            m_size = 0;
        }

    public:
        node<_type> getHead(){return m_head;}
        node<_type> getTail(){return m_tail;}
        int size() const {return m_size;}

        bool push(_type data){
            if(!m_size){
                m_head = new node<_type>(data);
                m_tail = m_head;
                m_size++;
                return true;
            }
            auto temp = m_head;
            m_head = new node<_type>();
            m_head->setData(data);
            m_head->setNext(temp);
            m_size++;
            return true;
        }

        _type pop(){
            if(!m_size) return std::nullopt;
            _type data = m_head->getData();
            auto nxt = m_head->next();
            delete m_head;
            m_head = nxt;
            m_size--;
            return data;
        }

        _type remove(){
            return this->pop();
        }

        bool add(_type data){
            if(!m_size){
                m_head = new node<_type>();
                m_tail = m_head;
                m_head->setData(data);
                m_size++;
                return true;
            }
            node<_type>* nxt = new node<_type>(data);
            nxt->setNext(nullptr);
            m_tail->setNext(nxt);
            m_tail = nxt;
            m_size++;
            return true;
        }

};

int main(){
    l_list<int> llist;
}
