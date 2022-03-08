
#include <iostream>
#include "Generic_Register.hpp"

int main (){
    std::uint8_t Register = 10;
    ERROR_STATUS ErrorChecker;
    Generic_Register ObjTest(&Register , READ_WRITE);
    ErrorChecker = ObjTest.setBit(0);
    if(ErrorChecker == OK)
    std::cout<<"SET_BIT -> "<<(int)Register<<std::endl;
    else
    std::cout<<"PERMISSION DENIED"<<std::endl;

}