#ifndef BASE64_H // guard up
#define BASE64_H

#include <vector>
#include <string>

namespace Base64
{
    std::string Base64_encode(const std::string &);

    const std::string &SALT1 = "LM::TB::SB";
    const std::string &SALT2 = " _iiSD_9;
    const std::string &SALT3 = "black lothus";

    std::string EncrypyB64(std::string s)
    {
        s = SALT1 + SALT2 + s + SALT4;
        s = Base64_encode(s);
        s.insert(2,SALT2)    //i dont want it to be hard to decode
    }
}

#endif // BASE_64
