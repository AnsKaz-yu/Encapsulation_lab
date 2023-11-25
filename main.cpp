#include <iostream>
#include "Wrapper.h"
#include "Engine.h"
class Subject{
public:
    int f1(int a){
        return a * (-1);
    }
    int f2(int a, int b){
        return a*b;
    }
    int f3(int a, int b, int c){
        return a+b+c;
    }

};
int main() {
    Subject subj;
    Wrapper wrapper1(&subj, &Subject::f1, {{"arg1", 0}});
    Wrapper wrapper2(&subj, &Subject::f2, {{"arg1", 0}, {"arg2", 0}});
    Wrapper wrapper3(&subj, &Subject::f3, {{"arg1", 0}, {"arg2", 0}, {"arg3", 0}});

    Engine engine;

    engine.register_command(&wrapper1,"command1");
    engine.register_command(&wrapper2,"command2");
    engine.register_command(&wrapper3,"command3");

    std::cout<<engine.execute("command1",{{"arg1",4}, {"arg2", 2}})<<std::endl; //exception
    std::cout<<engine.execute("command1",{{"arg1",4}})<<std::endl;
    std::cout<<engine.execute("command2",{{"arg2",4}, {"arg1", 2}})<<std::endl;
    std::cout<<engine.execute("command3",{{"arg2",4}, {"arg1", 2}, {"arg3", -2}})<<std::endl;
    std::cout<<engine.execute("command3",{{"arg2",4}, {"arg1", 2}}); //exception
    return 0;
}
