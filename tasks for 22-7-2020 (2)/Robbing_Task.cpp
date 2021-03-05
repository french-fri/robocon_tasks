#include<iostream>
using namespace std;

int sum(int* arr,int length,bool phase);
int optimize(int* arr,int length,int sum,bool phase);

int main()
{
    int length,input;               // user input
    cout<<"Number of houses >>>";
    cin>>length;
    
    int houses[length+2];           // array of houses
    
    for(int i{1};i <= length;i++)   // user input loop
    {
        cout<<"House no."<<i<<" >>>";
        cin>>input;
        houses[i] = input;
    }
    
    
    // phase = true means all odd numbers
    // phase = false means all even numbers
    int total = sum(houses,length,true);
    int total_temp = sum(houses,length,false);

    if (total < total_temp) // finding the greater alternate sum
    {
        total = total_temp;
        total = optimize(houses,length,total,true);
    }else
    {
        total = optimize(houses,length,total,false);
    }
    
    cout<<total;

}

int sum(int* arr,int length,bool phase) // Sum of alternate house values
{
    int sum_1 = 0;
    
    for(int i = int(phase)+1;i<=length;i = i + 2) // sum of odd index houses
    {
        sum_1 += arr[i];
    }
    
    return sum_1;
}


int optimize(int* arr,int length,int sum,bool phase) // highest value to steal
{
    // if house "i" has a value greater than the sum of the values in
    // neighbouring houses "(i+1)+(i-1)" then we will get a higher heist if
    // we steal from "i" instead of neighbours
    
    for(int i = int(phase)+1;i<=length;i += 2)  // checking all elements
    {
        if(arr[i-1]+arr[i+1] < arr[i]) // i > (i+1)+(i-1)
        {
            sum += arr[i] - arr[i-1] - arr[i+1];
            arr[i-1] = 0;
            arr[i+1] = 0; 
        }
    }
    
    for(int i{length};i<= int(phase)+1;i -= 2) // checking backwards for changes
    {
        if(arr[i-1]+arr[i+1] < arr[i]) // i > (i+1)+(i-1)
        {
            sum += arr[i] - arr[i-1] - arr[i+1];
            arr[i-1] = 0;
            arr[i+1] = 0; 
        }
    }
    
    return sum;
}
