#include "appcoord.h"
#include "controller.h"
#include "repo.h"
#include "ui.h"

using namespace std;

void maain()
{
	repo rep;
	contr con(rep);
	ui userinterface(con);
	userinterface.run();
}

int main()
{
	maain();
	return 0;
}