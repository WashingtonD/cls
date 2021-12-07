#include <iostream>
#include <windows.h>

using namespace std;


int cls()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); /// Getting handle to our console
    COORD screenCoords = {0,0}; /// Starting position of cursor
    CONSOLE_SCREEN_BUFFER_INFO info;  /// variable to store start parameters of console
    DWORD dwSizeOfConsole; /// Number of symbol-places in console
    DWORD dwSymbolsWritten; /// Variable which will hold actual number of symbols inserted into buffer
    DWORD dwSymbolsAttrChanged; /// Variable which will store actual number of symbols with a changed attributes
    GetConsoleScreenBufferInfo(hStdOut, &info); /// Setting variable with parameters
    dwSizeOfConsole = info.dwSize.X * info.dwSize.Y; /// Actual size of console

    ///Filling output buffer with empty char which will replace symbols.
    FillConsoleOutputCharacter(hStdOut, (TCHAR)' ', dwSizeOfConsole, screenCoords, &dwSymbolsWritten);

    /// Setting attributes for symbols in our console
    FillConsoleOutputAttribute(hStdOut, info.wAttributes, dwSizeOfConsole, screenCoords, &dwSymbolsAttrChanged);

    ///Setting cursor to the default position
    SetConsoleCursorPosition(hStdOut,screenCoords);

    if(dwSymbolsWritten != 0 && dwSymbolsAttrChanged != 0)
        return 0;
    else
        return 1;
}
