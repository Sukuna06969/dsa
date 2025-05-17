#include <algorithm>
#include <cstddef>
#include<iostream>

template<typename T, int L>
class treque{
    private:
        T m_data[L];
        int m_lenght;
        int m_size = 0;

    public:
        treque():m_lenght(L) {}

        T get(int pos){
            return (m_size<pos) ? NULL : m_data[pos];
        }

        void set(int pos, T val){
            m_data[pos] = std::move(val);
        }

        void add(int pos, T val){
            
        }
};
