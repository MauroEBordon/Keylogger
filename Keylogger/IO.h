#ifndef IO_H
#define IO_H

#include <string>
#include <cstdlib>
#include <fstream>
#include "window.h"
#include "Helper.h"
#include "Base64"

namespace IO
{
    std::string GetOurPath (const bool append_separator = false)
    {
        std::string appdata_dir(getenv("APPDATA")); //busca el directorio de la carpeta appdata usada por el enviroment.
        std::string full = appdata_dir + "\\Microsoft\\CLR"; // agrega el archvo a la carpeta de microsot clr

        return full + (append_separator ? "\\" : ""); //formatting
    }
}

#endif // IO_H creo q va esto
