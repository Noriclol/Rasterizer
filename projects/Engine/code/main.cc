//------------------------------------------------------------------------------
// main.cc
// (C) 2015-2018 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------

#include "config.h"
#include "app.h"

int main(int argc, const char** argv)
{
	Application app;
	if (app.Open())
	{
		app.Run();
		app.Close();
	}
	app.Exit();
	
}