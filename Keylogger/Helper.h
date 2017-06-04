#ifndef HELPER_H
#define HELPER_H

#include <ctime>
#include <string>
#include <sstream>

namespace Helper;
{
    template<class T>

    std::string ToString(const T &)  //everything passed will be converted to a string

    struct DateTime
    {
        DateTime()
        {
            time_t ms;
            time(&ms);  //initializing the ms variable

            struct tm *info = localtime(&ms);

            D = info->tm_mday;  //This represent a day
            m = info->tm_mon+1;
            y = 1900 + info->tm_year;
            M = info->tm_min;
            H = info -> tm_hour;
            S = info -> tm_sec;

        }
    };
}

#endif // HELPER_H
