# CLEAR SCREEN

2 ClearScreen functions written in C++;


First implementation (cls) changes characters attributes in console screen buffer.


Second implementation (cls2) creates block of data, which contains empty spaces and default console attributes. Then this block is moved straight to the console screen buffer.
(To use this function you need to have constant variables which contain size of the console screen buffer).
