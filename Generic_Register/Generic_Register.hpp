
#define GET_BIT(REG,BIT)        ((REG>>BIT) & 0x01)

typedef enum{
    OK=0,
    NOK
}ERROR_STATUS;
typedef enum{
READ=0,
WRITE,
READ_WRITE,
RESERVED
}REG_PERMISSION;

template <class T>
class Generic_Register{
private:
    T* RegAdd ;
    T Write_Only;
    T Read_Only;

public:
    Generic_Register(T * Reg,REG_PERMISSION permission=READ_WRITE);
    ERROR_STATUS setRegVal(T copy_value);
    ERROR_STATUS getRegVal (T &Ref_tValue);
    ERROR_STATUS setBit(std::uint8_t copy_BitNum);
    ERROR_STATUS clearBit(std::uint8_t copy_BitNum);
    ERROR_STATUS getBit(std::uint8_t copy_BitNum,bool &Ref_BitValue);
    ERROR_STATUS setPermission(REG_PERMISSION permission);
    ERROR_STATUS setBitPermission(std::uint8_t Copy_BitNum , REG_PERMISSION Permission);
};
template <class T>
Generic_Register<T>::Generic_Register(T * Register,REG_PERMISSION Permission)
{
    RegAdd = Register;
    switch(Permission)
    {
        case READ:
            Read_Only = ~((T) 0);
            Write_Only = 0;
            break;
        case WRITE:
            Write_Only = ~((T) 0);
            Read_Only = 0;
            break;        
        case READ_WRITE:
            Write_Only = ~((T) 0);
            Read_Only = ~((T) 0);
            break;
        case RESERVED:
            Read_Only = 0;
            Write_Only = 0;
            break;            
    }
}
template<class T>
ERROR_STATUS Generic_Register <T>::setRegVal(T copy_value)
{
    ERROR_STATUS LOC_retErrorStatus = NOK;
    if(Write_Only == ~((T) 0))
    {
        *RegAdd = copy_value;
        LOC_retErrorStatus= OK;
    }

    return LOC_retErrorStatus;
}
template <class T>
ERROR_STATUS Generic_Register <T>::getRegVal(T &Ref_tValue)
{
    ERROR_STATUS LOC_retErrorStatus= NOK;
    if(Read_Only == ~((T) 0))
    {
        Ref_tValue = *RegAdd;
        LOC_retErrorStatus= OK;
    }
    return LOC_retErrorStatus;    
}
template<class T>
ERROR_STATUS Generic_Register <T>::setBit(std::uint8_t copy_BitNum)
{
    ERROR_STATUS LOC_retErrorStatus= NOK;
    if(GET_BIT(Write_Only , copy_BitNum) == 1)
    {
        *RegAdd |= (1<<copy_BitNum);
        LOC_retErrorStatus = OK;
    }
    return LOC_retErrorStatus;
}
template<class T>
ERROR_STATUS Generic_Register <T>::clearBit(std::uint8_t copy_BitNum)
{
    ERROR_STATUS LOC_retErrorStatus= NOK;
    if(GET_BIT(Write_Only , copy_BitNum) == 1)
    {
        *RegAdd &= ~(1<<copy_BitNum);
        LOC_retErrorStatus= OK;
    }
    return LOC_retErrorStatus;
}
template<class T>
ERROR_STATUS Generic_Register <T>::getBit(std::uint8_t copy_BitNum,bool &Ref_BitValue)
{
    ERROR_STATUS LOC_retErrorStatus= NOK;
    if(GET_BIT(Read_Only , copy_BitNum) == 1)
    {
        Ref_BitValue = (*RegAdd >> copy_BitNum)  & 1;
        LOC_retErrorStatus= OK;
    }
    return LOC_retErrorStatus;    
}

template <class T>
ERROR_STATUS Generic_Register<T>::setPermission(REG_PERMISSION Permission)
{
    ERROR_STATUS LOC_retErrorStatus= NOK;
    if(Permission==READ)
    {
            Read_Only = ~((T) 0);
            Write_Only = 0;     
            LOC_retErrorStatus = OK;
    }
    else if(Permission==WRITE)
    {
            Write_Only = ~((T) 0);
            Read_Only = 0;
            LOC_retErrorStatus = OK;
    }
    else if(Permission==READ_WRITE)
    {             
            Write_Only = ~((T) 0);
            Read_Only = ~((T) 0);
            LOC_retErrorStatus = OK;
    }
    else if(Permission==RESERVED)
    {
            Read_Only = 0;
            Write_Only = 0;         
            LOC_retErrorStatus = OK;   
    }
    return LOC_retErrorStatus;
}

template <class T>
ERROR_STATUS Generic_Register<T>::setBitPermission(std::uint8_t Copy_BitNum , REG_PERMISSION Permission)
{
    ERROR_STATUS LOC_retErrorStatus= NOK;
    if(Permission==READ)
    {
            Read_Only |= (1<<Copy_BitNum);
            Write_Only &= ~(1<<Copy_BitNum);
            LOC_retErrorStatus = OK;
    }
    else if(Permission==WRITE) 
    {
            Write_Only |= (1<<Copy_BitNum);
            Read_Only &= ~(1<<Copy_BitNum);
            LOC_retErrorStatus = OK;
    }    
    else if(Permission==READ_WRITE)
        {
            Write_Only |= (1<<Copy_BitNum);
            Read_Only |= (1<<Copy_BitNum);
            LOC_retErrorStatus = OK;
        }
    else if(Permission==RESERVED)
    {
            Read_Only &= ~(1<<Copy_BitNum);
            Write_Only &= ~(1<<Copy_BitNum);
            LOC_retErrorStatus = OK;
    } 
    return LOC_retErrorStatus;
}