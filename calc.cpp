#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <cstring>
#include <iostream>
#include <string>
#include "stack.h"

using namespace std;


int main(int argc, char *argv[]){

	Fl_Window *window = new Fl_Window(200, 250);
	window->color(FL_DARK_BLUE);
	Fl_Box *display = new Fl_Box(25,40,150,30, "0");
	display->box(FL_DOWN_BOX);
	display->color(FL_WHITE);
	//Fl_Box *numbers = new Fl_Box(15, 85, 110, 135, " ");
	//numbers->box(FL_BORDER_BOX);

	//Fl_Box *operators = new Fl_Box(135, 85, 60, 135, " ");
	//operators->box(FL_BORDER_BOX);

	Fl_Box *border = new Fl_Box(128, 85, 2, 135, " ");
	border->box(FL_EMBOSSED_FRAME);
	//border->color(FL_WHITE);

	//number buttons
	Fl_Button *one = new Fl_Button(20,90,20,20, "&1");
	Fl_Button *two = new Fl_Button(60,90,20,20, "&2");
	Fl_Button *three = new Fl_Button(100,90,20,20, "&3");
	Fl_Button *four = new Fl_Button(20,125,20,20, "&4");
	Fl_Button *five = new Fl_Button(60,125,20,20, "&5");
	Fl_Button *six = new Fl_Button(100,125,20,20, "&6");
	Fl_Button *seven = new Fl_Button(20,160,20,20, "&7");
	Fl_Button *eight = new Fl_Button(60,160,20,20, "&8");
	Fl_Button *nine = new Fl_Button(100,160,20,20, "&9");
	Fl_Button *zero = new Fl_Button(60,195,20,20, "&0");
	
	//operatorbuttons
	Fl_Button *enter = new Fl_Button(30,225,50,20, "&Enter");
	Fl_Button *drop = new Fl_Button(110,225,50,20, "&Drop");
	Fl_Button *plus = new Fl_Button(140,90,20,20, "&+");
	Fl_Button *minus = new Fl_Button(170,90,20,20, "&-");
	Fl_Button *multiply = new Fl_Button(140,125,20,20, "&*");
	Fl_Button *divide = new Fl_Button(170,125,20,20, "&/");
	Fl_Button *exponent = new Fl_Button(140,160,20,20, "&^");
	Fl_Button *root = new Fl_Button(163,160,30,20, "&sqrt");
	Fl_Button *negative = new Fl_Button(140,195,30,20, "+/-");




	window->end();
	window->show(argc,argv);
	return Fl::run();

}