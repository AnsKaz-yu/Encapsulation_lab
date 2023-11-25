#pragma once
#include <map>
#include <functional>
#include <string>
#include <utility>
#include <vector>
#include <iostream>

using arg_list = std::map<std::string, int>;
using arg_vector = std::vector<int>;
using m_func = std::function<int(arg_vector& args)>;


class Wrapper {
    m_func func;
    arg_list list;
public:
    Wrapper() = default;
    ~Wrapper() = default;

    template <typename m_class, typename...Args>
    Wrapper(m_class* Class, int(m_class::*Func)(Args...), arg_list list){
        if (!Class || !Func){
            throw std::exception(); //pointer to an empty object
        }
        if (list.size() != sizeof...(Args)){
            throw std::exception(); //invalid number of arguments in arg_list
        }

        this->list = std::move(list);

        func = [Class, Func, this](const arg_vector& args){
            if (sizeof...(Args) != args.size()){
                throw std::exception(); //invalid number of arguments
            }
            return callfunc(Class, Func, args, std::make_index_sequence<sizeof...(Args)>{});
        };

    }
    template <typename m_class, typename m_func, size_t...index>
    int callfunc(m_class Class, m_func Func, std::vector<int>const& args, std::index_sequence<index...>){
        return (Class->*Func)(args[index]...);
    }
    int execute(const arg_list& new_list);
};


