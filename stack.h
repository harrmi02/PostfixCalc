#ifndef STACK
#define STACK
#include <stdexcept>

using namespace std;

template <typename thisType> class Stack {
	private:
		int maxSize;
		thisType* storage;
		int sp;

	public:
		Stack(){
			maxSize = 15;
			sp = 0;
			storage = new thisType[maxSize];
		}

		void restack(){
			int oldMax = maxSize;
			maxSize = 1.5 * maxSize;
			thisType* oldStack = storage;
			storage = new thisType[maxSize];
			for(int cp = 0; cp < oldMax; cp++){
				storage[cp] = oldStack[cp];
			}		
			delete[] oldStack;
		}

		void push(thisType newValue){
			if(sp == maxSize){
				restack();
				storage[sp] = newValue;
				sp ++; 
			}else{
				storage[sp] = newValue;
				sp ++; 
			}
		}

		thisType pop(){
			sp--;
			if(sp < 0){
			throw out_of_range("The stack is empty!");

			}
			return storage[sp];
		}

		bool isEmpty(){
			if(sp <= 0){
				return 1;
			}else{
				return 0;
			}
		}

		int size(){
			return sp + 1;
		}

};

#endif