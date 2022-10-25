#pragma once
#include<cstddef>
#include<functional>

template<typename T>
inline void hash_combine(std::size_t& seed, const T& v)
{
    seed ^= std::hash<T> {}(v)+0x9e3779b9 + (seed << 6) + (seed >> 2);
    //0x9e3779b9==2654435769��2^32*(��5-1)/2 (2��32�η����Իƽ�ָ���)
    //�Ӹ�0x9e3779b9ֻ��Ϊ���õõ��Ĺ�ϣֵ�����ȵ�ɢ�е�[0,2^32]�ķ�Χ
    //(seed << 6) + (seed >> 2)ֻ����ϴ��,��С��ͻ����
}

template<typename T, typename... Ts>
inline void hash_combine(std::size_t& seed, const T& v, Ts... rest)
{
    hash_combine(seed, v);
    if constexpr (sizeof...(Ts) > 1)
    {
        hash_combine(seed, rest...);
    }
}
