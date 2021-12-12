#include <iostream>
#include <windows.h>

using namespace std;

const int col = 80; /// Constant variables which are used for the cls2 function
const int row = 50;




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


void cls2(HANDLE wHnd) /// Getting console Handle as an argument of cls2 function
{
	CHAR_INFO consBuffer[col * row]; /// Creating character information buffer; (Containing symbols and other info about characters)

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(wHnd, &csbi); /// Getting standart console parameters into csbi variable

	for (int i = 0; i < col * row; i++) /// Col & row here - are constant representation of console buffer size
	{
		consBuffer[i].Char.UnicodeChar = ' ';			/// setting every character in the buffer as an empty UNICODE symbol (space)
		consBuffer[i].Attributes = csbi.wAttributes;   ///  setting all the other attributes of this symbol as the console default one
	}

	COORD charPosition = { 0,0 }; /// Setting starting point of the console
	SMALL_RECT writeArea = { 0,0,col - 1,row - 1 };	/// Setting which area is going to be changed in the clearence proccess
	COORD bufferSize = { col,row }; /// getting out buffer size as a COORD;
	WriteConsoleOutput(wHnd, /// Console Handle
						consBuffer, ///  Buffer with the data to be written
						bufferSize,  /// Size of the consBuffer  
						charPosition, /// Coordinate of the left-upper point of the buffer
						&writeArea);  /// Left-upper and right-lower points of the console screen buffer rect to witrren to
}
