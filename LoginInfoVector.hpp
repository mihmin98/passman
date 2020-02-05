#ifndef _LOGIN_INFO_VECTOR_HPP_
#define _LOGIN_INFO_VECTOR_HPP_

#pragma once
#include <vector>
#include "LoginInfo.hpp"

//TODO: See if this class should even exist
class LoginInfoVector
{
public:
    static std::vector<LoginInfo *> GetVectorPointers(std::vector<LoginInfo> &v);
};

#endif