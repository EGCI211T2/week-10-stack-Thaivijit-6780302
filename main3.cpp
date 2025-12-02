#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "Queue.h"

int main(int argc, char** argv) {
    Queue q;
    int count = 1;

    for(int i = 1; i < argc; i++) {
        if(strcmp(argv[i], "x") == 0) {
            if(!q.is_empty()) {
                cout << "Customer no: " << count << endl;
                if(q.dequeue() != -1) count++;
            }
        } else {
            int menu = atoi(argv[i]);
            if(menu < 1 || menu > N) {
                cout << "No Food" << endl;
                continue;
            }
            if(i + 1 >= argc) {
                cout << "Invalid food amount" << endl;
                break;
            }
            int amount = atoi(argv[i+1]);
            if(amount < 1) {
                cout << "Invalid food amount" << endl;
            } else {
                q.enqueue(menu, amount);
            }
            i++; // skip next argument since it's amount
        }
    }

    cout << "==============================================" << endl;
    cout << "There are " << q.get_size() << " ppl left in the queue" << endl;

    return 0;
}
