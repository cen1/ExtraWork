/*
*	ExtraWork Client - Loads an ExtraWork DLL for information
*	Copyright (C) 2014  xboi209 (xboi209@gmail.com)
*
*	This program is free software: you can redistribute it and/or modify
*	it under the terms of the GNU General Public License as published by
*	the Free Software Foundation, either version 3 of the License, or
*	(at your option) any later version.
*
*	This program is distributed in the hope that it will be useful,
*	but WITHOUT ANY WARRANTY; without even the implied warranty of
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*	GNU General Public License for more details.
*
*	You should have received a copy of the GNU General Public License
*	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include "Main.h"

using namespace std;

int main(int argc, char ** argv)
{
	HINSTANCE		hLib;
	ExtraWorkProc	lpfnExtraWork;
	BOOL			bReturn = NULL;
	EXTRAWORK		ew;
	char			*dllname = "IX86ExtraWork.dll";

	ew.GameType = 0x3;
	ew.Length = 4;
	strcpy_s(ew.OutBuffer, sizeof(ew.OutBuffer), "\0");
	
	hLib = LoadLibrary(dllname)
	bReturn = (*lpfnExtraWork)(&ew, 0);

	cout << "ExtraWork returned " << (bReturn ? "TRUE" : "FALSE") << endl;
	cout << "GameType: " << ew.GameType << "\t\t" << "Length: " << ew.Length << endl;
	cout << "Message: " << ew.OutBuffer << endl;

	FreeLibrary(hLib);

	return 0;
}
