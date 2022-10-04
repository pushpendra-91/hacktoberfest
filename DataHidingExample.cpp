//WAP to find area of rectangle

#include <iostream>

using namespace std;

class Rectangle{
	
	private:
	int length;
	int breadth;
	
	public:
	void setLength(int l){
		
		if(l<1){
		cout<<"Negative Number";
		exit(0);
		}
		
		else{
			this->length = l;

		}
	}
	
	void setBreadth(int b){
		this->breadth = b;
	}
	
	void getArea() {
		cout<<"The area is "<<this->length*this->breadth;
			}
};



int main() {
	
	Rectangle rect;
	
	
	rect.setLength(20);
	rect.setBreadth(10);
	
	rect.getArea();
	
	
	return 0;
}