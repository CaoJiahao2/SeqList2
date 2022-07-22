#include <iostream>
#define initSize 20
typedef int elemType;

class SeqStack{
private:
    elemType *elem;
    int top,maxSize;
public:
    explicit SeqStack(int size);
    ~SeqStack();
    bool isEmpty() const;
    bool isFull() const;
    bool getTop(elemType &x);
    bool push(elemType x);
    bool pop(elemType &x);
    void disPlayStack();
};
SeqStack::SeqStack(int size) {
    maxSize=size;
    top=-1;
    elem=new elemType [size];
}
SeqStack::~SeqStack() {delete elem;}

bool SeqStack::isEmpty() const {
    if (top==-1)return true;
    return false;
}

bool SeqStack::isFull() const {
    if(top==maxSize-1)return true;
    return false;
}

bool SeqStack::getTop(elemType &x) {
    if(isEmpty())return false;
    x=elem[top];
    return true;
}

bool SeqStack::push(elemType x) {
    if(isFull())return false;
    elem[++top]=x;
    return true;
}

bool SeqStack::pop(elemType &x) {
    if(isEmpty())return false;
    x=elem[top--];
    return true;
}
void SeqStack::disPlayStack() {
    for(int i=top;i>=0;i--)
        printf("%d\t",elem[i]);
}


int main() {
    SeqStack seqStack(initSize);
    for(int i=0;i<initSize;i++)
        seqStack.push(i);
    elemType x;
    for(int i=0;i<4;i++){
        seqStack.pop(x);
    }
    seqStack.disPlayStack();
    seqStack.getTop(x);
    std::cout<<"\ntop is "<<x<<std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}