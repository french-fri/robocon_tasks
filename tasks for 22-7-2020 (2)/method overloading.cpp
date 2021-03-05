#include<iostream>
using namespace std; 


class rectangle
{
    public:
    void areaprint(int side)
    {
            cout<<"area of square is "<<side*side<<"cm"<<endl;
    }
    void areaprint(int length,int breadth)
    {
        cout<<"area of rectangle is "<<length*breadth<<"cm"<<endl;
    }
};


int main()
{
    rectangle shape;
    shape.areaprint(5);
    shape.areaprint(5,6);
    
    
return 0;    
}
