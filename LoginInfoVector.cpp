#include "LoginInfoVector.hpp"

std::vector<LoginInfo *> LoginInfoVector::GetVectorPointers(std::vector<LoginInfo> &v)
{
    std::vector<LoginInfo *> vp;

    for (std::vector<LoginInfo>::iterator it = v.begin(); it != v.end(); std::advance(it, 1))
        vp.push_back(&(*it));

    return vp;
}