#ifndef _CHANGEODDLOCNUMSORDER_HPP
#define _CHANGEODDLOCNUMSORDER_HPP

#include "SingleLinkedList.hpp"

#define DEBUG_STM(fmt) \
        std::cout<<__FILE__<<":"<<__FUNCTION__<<":"<<__LINE__<<": "<<fmt<<std::endl
#define ERROR_STM(fmt) \
        std::cerr<<__FILE__<<":"<<__FUNCTION__<<":"<<__LINE__<<": "<<fmt<<std::endl

#if DEBUG
  #define FUNC_ENTRY DEBUG_STM("Function Entry")
#else
  #define FUNC_ENTRY ;
#endif

#endif //#ifndef _CHANGEODDLOCNUMSORDER_HPP

