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
        return s;
    }
    const std::string &BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

    std::string base64_encode(const std::string &s)
    {
        std::string ret;
        int val = 0;
        int bits = -6;
        const unsigned int b63 = 0x3F;

        for(const auto &c : s)
        {
            val = (val << 8) + c; //val = val * 2^8;
            bits += 8;
            while(bits >= 0)
            {
                ret.push_back(BASE64_CODES[(val >> bits) & b63]);
                bits -= 6;

            }

        }
        if(bits > -6)
            ret.push_back(BASE64_CODES[((val << 8) >> (bits + 8)) & b63]);

        while(ret.size() %4)
			ret.push_back('=');

		return ret;

    }
}

#endif // BASE_64
