#ifndef HELPER_H // guard up
#define HELPER_H

#include <ctime>
#include <string>
#include <sstream>

namespace Helper
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

        DateTime(int D, int m, int y, int M, int H, int S): D(D), m(m), y(y), M(M), H(H), S(S){}
        //This is sure going to e needed in the future
        DateTime(int D, int m, int y):D(D), m(m), y(y), M(0), H(0), S(0){}

        DateTime Now() const
        //this returns the Date at the time its called. if you are reading this please stop, this are for myself, go away. jajja.
        {
            return DateTime();
        }

        int D, m, y, H, M, S;

        std::string GetDateString() const
        {
            return  std::string(D < 10 ? "0" : "") + ToString(D) + std::string(m < 10 ? "0" : ".") + ToString(m) +
                    std::string(y < 10 ? ".0" : ".") + ToString(y);
        }
        std::string GetTimeString(const std::string &sep = ":") const   // formatting
        {
            return  std::string(H < 10 ? ".0" : "") + ToString(H) + sep +
                    std::string(M < 10 ? ".0" : "") + ToString(M) + sep +
                    std::string(S < 10 ? ".0" : "") + ToString(S);
        }

        std::string GetDateTimeString(const std::string &sep = ":") const
        {
            return GetDateString() + " " + GetTimeString(sep);
        }
    };

    template<class T>
    std::string ToString(const T &e)
    {
        std::ostringstream s;  //its a variable
        s << e; //insertion
        return s.str();


    }//this is not needed really
    void WriteAppLog(const std::string &s)
    {
        std::ofstream file("AppLog.txt", std::ios::app); //ios input output stream, app append(modify, change).
        file << "[" << Helper::DateTime.GetDateTimeString() << "]" << "\n" << s << std::endl << "\n";
        file.close();
    }
}

#endif // HELPER_H
