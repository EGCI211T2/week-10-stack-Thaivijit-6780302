
#ifndef stack_h
#define stack_h
#include "node.h"
class Stack {
	NodePtr top;
	int size =0 ;
public:
    void push(int);
    int pop();
    Stack();
    ~Stack();
};


void Stack::push(int x){
  NodePtr new_node=new NODE(x);
  if(new_node){
    if (size == 0){
    top = new_node;
    size++;
    } else {
        new_node->set_next(top);
        top = new_node;
        size++;    
    }
   }
 
         // Left missing for exercises…
    
}

int Stack::pop(){
        NodePtr t;
        t=top;
        int value = t->get_value();
        top = t->get_next();
        t->set_next(nullptr);
    // Left missing part for exercises
        delete t;
        size --;
        return value;
	//be careful of the empty stack!!!
    }

Stack::Stack(){
    //initialize stack
    top = nullptr;
    size = 0;
}

Stack::~Stack(){
    //delete all remaning stack (i.e. pop all) 
    while (size != 0){
        pop();
    }
}


#endif
