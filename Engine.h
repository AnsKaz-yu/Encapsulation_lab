#pragma once
#include <map>
#include <string>
#include "Wrapper.h"

class Engine {
public:
    void register_command(Wrapper* wrapper, const std::string& name);
    int execute(const std::string& name, const arg_list& m_arg_list);
private:
    std::map<std::string, Wrapper*> MyCommands;
};



