#include <iostream>
#include <windows.h>

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
