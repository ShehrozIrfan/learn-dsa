/*
DSA Lab
Date: 12-04-19
Task 1:
Write a program implementing inheritance in which there is a base class shape.Base class should have methods to set
width and height of shape.A derived class should have methods to get area.Area is obtained by multiplying 
Height*Width.
note:
Base class should have data members declared in protected access specifiers.
*/
#include<iostream>
using  namespace std;

class Base{
	protected:
		float height;
		float width;
		public:
			void set_height(int h){
				height=h;
			}
			void set_width(int w){
				width=w;
			}
};
class Derived:public Base{
	public:
		int get_area(){
			return (width*height);
		}
};
int main(){
	
	Derived d;
	d.set_height(10);
	d.set_width(50);
	cout<<"Area=";
	cout<<d.get_area();
	return 0;
}
