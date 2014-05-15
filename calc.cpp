#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <cstring>
#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

Fl_Box *display;
Stack<float > numbers;

class NumButton : public Fl_Button{

private: 
	const char* value;

public:
	NumButton(int x, int y, int w, int h, char *label, const char* val) 
	 : Fl_Button(x,y,w,h,label){
	 	this->value = val;
	 }
 
 	const char* getValue() {return value;}

 	static void numcb(Fl_Widget* w, void *){
 		NumButton *myButton = (NumButton *)w;

 		const char* text = display->label();
		char finalText[100];
		strcpy(finalText, text);
		strcat(finalText, myButton->getValue());
		display->copy_label(finalText);

 	}

};

void entercb(Fl_Widget* me, void * something){
	const char* val = display->label();
	int num = atoi(val);
	float fnum = (float)num;
	numbers.push(fnum);
	display->copy_label("");
}

void dropcb(Fl_Widget* me, void * something){
	float temp = numbers.pop();
}

void pluscb(Fl_Widget* me, void * something){
	const char* val = display->label();
	int num = atoi(val);
	float fnum = (float)num;
	numbers.push(fnum);

	float left = 0;
	float right = 0;
	float result = 0;
	right = numbers.pop();
	left = numbers.pop();

	result = left + right;

	numbers.push(result);

	display->copy_label(to_string(result).c_str());

}

int main(int argc, char *argv[]){

	Fl_Window *window = new Fl_Window(200, 250);
	window->color(FL_DARK_BLUE);
	
	display = new Fl_Box(25,40,150,30, "");
	display->box(FL_DOWN_BOX);
	display->color(FL_WHITE);

	Fl_Box *border = new Fl_Box(128, 85, 2, 135, " ");
	border->box(FL_EMBOSSED_FRAME);

	//number buttons
	NumButton *one = new NumButton(20,90,20,20, "&1", "1");
	NumButton *two = new NumButton(60,90,20,20, "&2", "2");
	NumButton *three = new NumButton(100,90,20,20, "&3", "3");
	NumButton *four = new NumButton(20,125,20,20, "&4", "4");
	NumButton *five = new NumButton(60,125,20,20, "&5", "5");
	NumButton *six = new NumButton(100,125,20,20, "&6", "6");
	NumButton *seven = new NumButton(20,160,20,20, "&7", "7");
	NumButton *eight = new NumButton(60,160,20,20, "&8", "8");
	NumButton *nine = new NumButton(100,160,20,20, "&9", "9");
	NumButton *zero = new NumButton(60,195,20,20, "&0", "0");
	
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

	one->callback(NumButton::numcb, 0);
	two->callback(NumButton::numcb, 0);
	three->callback(NumButton::numcb, 0);
	four->callback(NumButton::numcb, 0);
	five->callback(NumButton::numcb, 0);
	six->callback(NumButton::numcb, 0);
	seven->callback(NumButton::numcb, 0);
	eight->callback(NumButton::numcb, 0);
	nine->callback(NumButton::numcb, 0);
	zero->callback(NumButton::numcb, 0);

	enter->callback(entercb, 0);
	drop->callback(dropcb, 0);
	plus->callback(pluscb, 0);




	window->end();
	window->show(argc,argv);
	return Fl::run();

}