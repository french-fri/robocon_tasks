#include<iostream>
using namespace std; 


class rectangle
{
    public:
    int length,breadth;
    void dimensions()
    {
            cout<<"dimenstions of square is "<<length<<" X "<<breadth<<" cm"<<endl;
    }
    rectangle operator +(rectangle const &rec)
    {
    rectangle result;
    result.length = rec.length + length;
    result.breadth = rec.breadth + breadth;
    return result;
    }
};


int main()
{
    rectangle quad_1,quad_2;
    quad_1.length =  12;
    quad_1.breadth = 10;
    
    quad_2.length =  6;
    quad_2.breadth = 9;
    rectangle quad_3 = quad_1+quad_2;
    quad_3.dimensions();
    
    
return 0;    
}
