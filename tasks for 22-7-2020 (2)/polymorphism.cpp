#include<iostream>
using namespace std; 

//RUNTIME POLYMORPHISM

class quadilateral
{
        public:
        void area()
        {
            cout<<"gonna show this one";
        }
};

class square:public quadilateral
{
    public:
    int side = 5;
    void area()
    {
        cout<<"area square =="<<side*side;
    }
};

int main()
{
    quadilateral *pointer;
    square sq_1;
    pointer = &sq_1;
    pointer->area();
return 0;    
}
