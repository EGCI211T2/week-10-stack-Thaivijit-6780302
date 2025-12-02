#ifndef NODE_H
#define NODE_H

class NODE {
    int menu;
    int amount;
    NODE *nextPtr;
public:
    NODE(int, int);
    ~NODE();
    void set_next(NODE*);
    NODE* get_next();
    int get_menu();
    int get_amount();
};

typedef NODE* NodePtr;

NODE::NODE(int x, int y) {
    menu = x;
    amount = y;
    nextPtr = nullptr;
}

NODE* NODE::get_next() {
    return nextPtr;
}

int NODE::get_menu() {
    return menu;
}

int NODE::get_amount() {
    return amount;
}

void NODE::set_next(NODE* t) {
    nextPtr = t;
}

NODE::~NODE() {

}

#endif
