#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <cstring>
#include <iostream>
#include <string>
#include <math.h>
#include "stack.h"

using namespace std;

Fl_Box *display;
Fl_Box *lowest;
Fl_Box *middle1;
Fl_Box *middle2;
Fl_Box *highest;
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

void updateBoxes(){
	lowest->copy_label(to_string(numbers.peek(4)).c_str());
	middle1->copy_label(to_string(numbers.peek(2)).c_str());
	middle2->copy_label(to_string(numbers.peek(3)).c_str());
	highest->copy_label(to_string(numbers.peek(1)).c_str());
}

void entercb(Fl_Widget* me, void * something){
	const char* val = display->label();
	int num = atoi(val);
	float fnum = (float)num;
	numbers.push(fnum);
	display->copy_label("");

	updateBoxes();
}

void dropcb(Fl_Widget* me, void * something){
	float temp = numbers.pop();
	display->copy_label("");
	updateBoxes();	
}

void clearcb(Fl_Widget* me, void * something){
	display->label("");
}

void pluscb(Fl_Widget* me, void * something){
	const char* val = display->label();
	if(val != ""){
		int num = atoi(val);
		float fnum = (float)num;
		numbers.push(fnum);
	}
	float left = 0;
	float right = 0;
	float result = 0;
	right = numbers.pop();
	left = numbers.pop();

	result = left + right;

	numbers.push(result);
	display->copy_label(to_string(result).c_str());

	updateBoxes();
}

void minuscb(Fl_Widget* me, void * something){
	const char* val = display->label();
	if(val != ""){
		int num = atoi(val);
		float fnum = (float)num;
		numbers.push(fnum);
	}

	float left = 0;
	float right = 0;
	float result = 0;
	right = numbers.pop();
	left = numbers.pop();

	result = left - right;

	numbers.push(result);

	display->copy_label(to_string(result).c_str());
	updateBoxes();

}

void multcb(Fl_Widget* me, void * something){
	const char* val = display->label();
	if(val != ""){
		int num = atoi(val);
		float fnum = (float)num;
		numbers.push(fnum);
	}
	float left = 0;
	float right = 0;
	float result = 0;
	right = numbers.pop();
	left = numbers.pop();

	result = left * right;

	numbers.push(result);

	display->copy_label(to_string(result).c_str());
	updateBoxes();

}

void dividecb(Fl_Widget* me, void * something){
	const char* val = display->label();
	if(val != ""){
		int num = atoi(val);
		float fnum = (float)num;
		numbers.push(fnum);
	}
	float left = 0;
	float right = 0;
	float result = 0;
	right = numbers.pop();
	left = numbers.pop();

	result = left / right;

	numbers.push(result);

	display->copy_label(to_string(result).c_str());
	updateBoxes();

}

void expocb(Fl_Widget* me, void * something){
	const char* val = display->label();
	if(val != ""){
		int num = atoi(val);
		float fnum = (float)num;
		numbers.push(fnum);
	}

	float left = 0;
	float right = 0;
	float result = 0;
	right = numbers.pop();
	left = numbers.pop();

	numbers.push(result);

	display->copy_label(to_string(result).c_str());
	updateBoxes();

}

void rootcb(Fl_Widget* me, void * something){
	const char* val = display->label();
	if(val != ""){
		int num = atoi(val);
		float fnum = (float)num;
		numbers.push(fnum);
	}
	float operand = 0;
	float result = 0;
	operand = numbers.pop();

	result = sqrt(operand);

	numbers.push(result);

	display->copy_label(to_string(result).c_str());
	updateBoxes();

}

void negcb(Fl_Widget* me, void * something){
	const char* val = display->label();
	if(val != ""){
		int num = atoi(val);
		float fnum = (float)num;
		numbers.push(fnum);
	}

	float operand = 0;
	float result = 0;

	operand = numbers.pop();
	result = -operand;

	numbers.push(result);

	display->copy_label(to_string(result).c_str());
	updateBoxes();
}

int main(int argc, char *argv[]){

	Fl_Window *window = new Fl_Window(200, 340);
	window->color(FL_DARK_BLUE);
	
	display = new Fl_Box(25,20,150,30, "");
	display->box(FL_DOWN_BOX);
	display->color(FL_WHITE);

	lowest = new Fl_Box(50,120,100,15, "");
	lowest->box(FL_DOWN_BOX);
	lowest->color(FL_WHITE);

	middle1 = new Fl_Box(50,80,100,15, "");
	middle1->box(FL_DOWN_BOX);
	middle1->color(FL_WHITE);

	middle2 = new Fl_Box(50,100,100,15, "");
	middle2->box(FL_DOWN_BOX);
	middle2->color(FL_WHITE);

	highest = new Fl_Box(50,60,100,15, "");
	highest->box(FL_DOWN_BOX);
	highest->color(FL_WHITE);

	Fl_Box *border = new Fl_Box(128, 175, 2, 135, " ");
	border->box(FL_EMBOSSED_FRAME);

	//number buttons
	NumButton *one = new NumButton(20,180,20,20, "&1", "1");
	NumButton *two = new NumButton(60,180,20,20, "&2", "2");
	NumButton *three = new NumButton(100,180,20,20, "&3", "3");
	NumButton *four = new NumButton(20,215,20,20, "&4", "4");
	NumButton *five = new NumButton(60,215,20,20, "&5", "5");
	NumButton *six = new NumButton(100,215,20,20, "&6", "6");
	NumButton *seven = new NumButton(20,250,20,20, "&7", "7");
	NumButton *eight = new NumButton(60,250,20,20, "&8", "8");
	NumButton *nine = new NumButton(100,250,20,20, "&9", "9");
	NumButton *zero = new NumButton(60,285,20,20, "&0", "0");
	
	//operatorbuttons
	Fl_Button *enter = new Fl_Button(30,315,50,20, "&Enter");
	Fl_Button *drop = new Fl_Button(110,315,50,20, "&Drop");
	Fl_Button *plus = new Fl_Button(140,180,20,20, "&+");
	Fl_Button *minus = new Fl_Button(170,180,20,20, "&-");
	Fl_Button *multiply = new Fl_Button(140,215,20,20, "&*");
	Fl_Button *divide = new Fl_Button(170,215,20,20, "&/");
	Fl_Button *exponent = new Fl_Button(140,250,20,20, "&^");
	Fl_Button *root = new Fl_Button(163,250,30,20, "&sqrt");
	Fl_Button *negative = new Fl_Button(140,285,30,20, "+/-");

	Fl_Button *clear = new Fl_Button(75, 150, 50, 20, "&Clear");

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

	clear->callback(clearcb, 0);
	enter->callback(entercb, 0);
	drop->callback(dropcb, 0);
	plus->callback(pluscb, 0);
	minus->callback(minuscb, 0);
	multiply->callback(multcb, 0);
	divide->callback(dividecb, 0);
	exponent->callback(expocb, 0);
	root->callback(rootcb, 0);
	negative->callback(negcb, 0);


	window->end();
	window->show(argc,argv);
	return Fl::run();

}