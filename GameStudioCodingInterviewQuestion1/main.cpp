// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;
//Shape's struct
    struct Rect {
        float minX;
        float minY;
        float maxX;
        float maxY;
    } Shape;
    float FinalValue;
    float Xcoordinate,Ycoordinate;
float DistanceToRect(float x, float y, Rect& rect);
int main()
{
    float value = 0,Xcoordinate,Ycoordinate;
    Rect Shape = Rect();
    try{
        cout << "Enter the low x value of the shape: ";
        cin >> value;
        Shape.minX = value;
        value = 0;
        cout << endl << "Enter the max x value of the shape: ";
        cin >> value;  
        Shape.maxX = value;
        value = 0; 
        cout << endl <<  "Enter the min y value of the shape: ";
        cin >> value; 
        Shape.minY = value;
        value = 0; 
        cout << endl <<  "Enter the max y value of the shape: ";
        cin >> value; 
        Shape.maxY = value;     
        //This just tells the user about the boundaries of the shape and relative location in (x,y) notation
        cout << "The coordinates of the shape is:" 
            << endl << "(" << Shape.minX << "," << Shape.minY << ")" << endl
            << endl << "(" << Shape.maxX << "," << Shape.minY << ")" << endl
            << endl << "(" << Shape.minX << "," << Shape.maxY << ")" << endl
            << endl << "(" << Shape.maxX << "," << Shape.maxY << ")" << endl;
        cout << "Enter the X coordinate of the point for finding the rect distance ";
        cin >> Xcoordinate;
        cout << "Enter the Y coordinate of the point for finding the rect distance ";
        cin >> Ycoordinate;
        FinalValue=DistanceToRect(Xcoordinate, Ycoordinate, Shape);
        cout << endl << "The distance to Rectangle is " << FinalValue; 
        return 0;
    }
    catch(exception){
        cout << "A failed attempt to input a number value. App has to be restarted";
    }
            return 0;
}



// The main function of the program that is to determine the distance of the individual point on a grid to 
float DistanceToRect(float x, float y, Rect& rect)
{
    float Distance;
    float xvalue=x,yvalue=y;
    
    //If x and y are within the min and maxes of the shape
    if (rect.minX <= xvalue && xvalue <= rect.maxX && rect.minY <= yvalue && yvalue <= rect.maxY){ 
        FinalValue=0.0f;
    return FinalValue;
    }
    //If y only is below or above the shape location
    else if (rect.minX >= xvalue && xvalue <= rect.maxX){
        if (rect.minY <= yvalue)
            FinalValue = abs(y) - abs(rect.maxY);
        else
            FinalValue = abs(y) - abs(rect.minY);
        return  FinalValue;
    }
    //If x only is away from the shape location
    else if (rect.minY >= yvalue && yvalue <= rect.maxY) {
        if (rect.minY <= yvalue)
            FinalValue = abs(x) - abs(rect.maxX);
        else
            FinalValue = abs(x) - abs(rect.minX);
        return  FinalValue;
    }
    //If both x and y are away from the min and maxes of x an y of shape
    else{
        xvalue = pow(x, 2);
        yvalue = pow(y, 2);
        Distance = xvalue + yvalue;
        FinalValue=sqrt(Distance);
        return FinalValue;
    }
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file