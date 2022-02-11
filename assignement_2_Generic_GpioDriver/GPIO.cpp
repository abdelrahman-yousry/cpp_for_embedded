#include "ARM.hpp"
#include "AVR.hpp"
#include "GPIO.hpp"


GPIO::GPIO_Set_Pin_Dir(mcu_type)
{
    switch (mcu_type)
    {
        case 0:
            AVR_Set_Pin_Dir();
        break;

        case 1:
            ARM_Set_Pin_Dir();
        break;
    }
}

GPIO::GPIO_Set_Pin_Val(mcu_type)
{
    switch (mcu_type)
    {
        case 0:
            AVR_Set_Pin_Val();
        break;

        case 1:
            ARM_Set_Pin_Val();
        break;
    }
}

GPIO::GPIO_Get_Pin_Val(mcu_type)
{
    switch (mcu_type)
    {
        case 0:
            AVR_Get_Pin_Val();
        break;

        case 1:
            ARM_Get_Pin_Val();
        break;
    }
}