#include "Wrapper.h"

int Wrapper::execute(const arg_list &new_list) {
    //setting the values of the arguments according to the name
    for (const auto& arg : new_list){
        if (list.find(arg.first) == list.end()){
            throw std::exception(); //invalid name of argument
        }
        list[arg.first]=arg.second;
    }

    //we form the vector of arguments in the order of the declared names
    arg_vector args;
    for (const auto& arg: list){
        args.push_back(arg.second);
    }

    //passing the vector to the function and try run it
    int result;
    try{
        result = func(args);
    }
    catch(...){
        std::cout<<"ERROR: can't run function"<<std::endl;
    }

    return result;
}
