#include "Engine.h"

int Engine::execute(const std::string& name, const arg_list& m_arg_list) {
    if (MyCommands.find(name) == MyCommands.end()){
        throw std::exception(); //there are no commands with this name
    }
    auto it = MyCommands[name];
    int result = INT_MIN;
    try{
        result = it->execute(m_arg_list);
    }
    catch(...){
        std::cout<<"Error: wrong args" <<std::endl;
    }

    return result;
}

void Engine::register_command(Wrapper* wrapper, const std::string& name) {
    if (MyCommands.find(name) != MyCommands.end()){
        throw std::exception(); //the command with this name already exist
    }
    if (!wrapper){
        throw std::exception(); //pointer to an empty object
    }
    MyCommands[name] = wrapper;
}
