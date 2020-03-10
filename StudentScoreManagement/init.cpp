#include<stdlib.h>
#include<windows.h>
#include<string.h>

#include"init.h"
#include"node.h"
#include"tools.h"
#include"figures.h"
#include"process.h"
/*
This package include the init figures 
and theirs method.
(prestart,  loading ,  password,  welcome, predata import)
*/

void init(void)
{
	preStart();
	system("CLS");
	loadFigure();
	system("CLS");

	passwordFigure();
	//  µœ÷ ‰»Î√‹¬Î
	do
	{
		getPassword
	}

}