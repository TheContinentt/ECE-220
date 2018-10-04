#include "shape.hpp"

//Introduction: In this program, I first introduce the base class Shape and several derived class based
// on the base class. In each derived class, I set getArea, getVolume and operator functions since they are virtual
// function in the base clss. Then in the createShape function, I read the input file and store the graph names and their lengths and widths
// into the vector and then return the vector. Inthe last two functions, I compare eevery volume and area and return the maximums of them.

//Base class
//Please implement Shape's member functions
//constructor, getName()
//

Shape::Shape(string name){
  name_=name;//set Shape(string name) in Shape class
}
string Shape::getName(){return name_;}//function in Shape class
//Base class' constructor should be called in derived classes'
//constructor to initizlize Shape's private variable



//Rectangle
//Please implement the member functions of Rectangle:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here


Rectangle::Rectangle(double a, double b):Shape("Rectangle"){
  width_=a;// set width and length in Rectangle class
  length_=b;// set width and length in Rectangle class
}
double Rectangle::getWidth(){return width_;}
double Rectangle::getLength(){return length_;}// set getLength and getArea in Rectangle since they are virtual in Shape class.
double Rectangle::getArea(){ return width_*length_;}// set getLength and getArea in Rectangle since they are virtual in Shape class.
double Rectangle::getVolume(){
  return 0.0;
}
Rectangle Rectangle:: operator + (const Rectangle& R2){
  Rectangle R3(0,0);
  R3.length_=length_+R2.length_;//set new plus operator of two rectangles
  R3.width_=width_+R2.width_;//set new plus operator of two rectangles

  return R3;
}
Rectangle Rectangle:: operator - (const Rectangle& R2){
  Rectangle R3(0,0);
  R3.length_=length_-R2.length_;//set new minus operator of two rectangles
  R3.width_=width_-R2.width_;//set new minus operator of two rectangles
  if (R3.length_<0){R3.length_=0;}//compare result to 0 and return the maximum
  if (R3.width_<0) {R3.width_=0;}//compare result to 0 and return the maximum
  return R3;
}


//Circle
//Please implement the member functions of Circle:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here
Circle::Circle(double r):Shape("Circle"){
  radius_=r;//set radius in circle class
}
double Circle::getRadius(){return radius_;}
double Circle::getArea(){return radius_*radius_*M_PI;}//set getArea function in Circle
double Circle::getVolume(){return 0.0;}//set getVolume function in Circle
Circle Circle::operator + (const Circle& R2){
  Circle R3(0);
  R3.radius_=radius_+R2.radius_;//set new plus operator
  return R3;//return result
}
Circle Circle::operator - (const Circle& R2){
  Circle R3(0);
    R3.radius_=radius_-R2.radius_;//set new minus operator
    if(R3.radius_<0){R3.radius_=0;}//compare the result to 0 and take the maximum
    return R3;// return result
}
//Sphere
//Please implement the member functions of Sphere:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here


Sphere::Sphere(double r):Shape("Sphere"){
  radius_=r;
}
double Sphere::getRadius(){return radius_;}
double Sphere::getArea(){return 4*M_PI*radius_*radius_;}//set getArea function in Sphere
double Sphere::getVolume(){return (4.0/3.0)*radius_*radius_*radius_*M_PI;}//set getVolume function in Sphere
Sphere Sphere:: operator + (const Sphere& S2){
  Sphere S3(0);
  S3.radius_=radius_+S2.radius_;//set new plus operator
  return S3;//return result
}
Sphere Sphere:: operator - (const Sphere& S2){
  Sphere S3(0);
  S3.radius_=radius_-S2.radius_;//set new minus operator
  if(S3.radius_<0){S3.radius_=0;}//compare the result to 0 and take the maximum
  return S3;// return result
}
//Rectprism
//Please implement the member functions of RectPrism:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

RectPrism::RectPrism(double a, double b,double c):Shape("RectPrism"){
  width_=a;
  height_=b;
  length_=c;
}
double RectPrism::getWidth(){return width_;}
double RectPrism::getHeight(){return height_;}
double RectPrism::getLength(){return length_;}//set getArea function in RectPrism
double RectPrism::getArea(){return 2*(length_*width_+length_*height_+width_*height_);}//set getVolume function in RectPrism
double RectPrism::getVolume(){return length_*width_*height_;}
RectPrism RectPrism::operator + (const RectPrism& RP2){
  RectPrism RP3(0,0,0);
  RP3.length_=length_+RP2.length_;//set new plus operator
  RP3.width_ =width_+RP2.width_;//set new plus operator
  RP3.height_=height_+RP2.height_;//set new plus operator
  return RP3;//return result
}
RectPrism RectPrism::operator - (const RectPrism& RP2){
  RectPrism RP3(0,0,0);
  RP3.length_=length_-RP2.length_;//set new minus operator
  RP3.width_=width_-RP2.width_;//set new minus operator
  RP3.height_=height_-RP2.height_;//set new minus operator
  if(RP3.length_<0.0){RP3.length_=0.0;}//compare the result to 0 and take the maximum
  if(RP3.width_<0.0){RP3.width_=0.0;}//compare the result to 0 and take the maximum
  if(RP3.height_<0.0){RP3.height_=0.0;}//compare the result to 0 and take the maximum
  return RP3;// return result
}


// Read shapes from test.txt and initialize the objects
// Return a vector of pointers that points to the objects
vector<Shape*> CreateShapes(char* file_name){
	int number;
  double a,b,c;
  string name;
	//string Rectangle = "Rectangle";
	//string Circle = "Circle";
	ifstream ifs (file_name, std::ifstream::in);//open the file
	ifs >> number;//get the number of different inputs
  vector<Shape*> vect(number);
  int i=0;
  while(i<number){//set a while loop
    ifs >> name;//scan the next name
      if (name=="Rectangle"){//check whether it is rectangle
        ifs >> a >> b;//scan the next two inputs
        vect[i]=new Rectangle(a,b);//set all the inputs to the initializtion of the rectangle
      }
      if(name=="Circle"){//check whether it is circle
        ifs>>a;//scan the next two inputs
        vect[i]=new Circle(a);//set all the inputs to the initializtion of the circle
      }
      if(name=="Sphere"){//check whether it is sphere
        ifs>>a;//scan the next two inputs
        vect[i]=new Sphere(a);//set all the inputs to the initializtion of the sphere
      }
      if(name=="RectPrism"){//check whether it is rectprism
        ifs>>a>>b>>c;//scan the next two inputs
        vect[i]=new RectPrism(a,b,c);//set all the inputs to the initializtion of the RectPrism
      }
    i=i+1;//increment the counter
  }
    ifs.close();//close the file
    return vect;//return the vector

  }
	
// call getArea() of each object
// return the max area
double MaxArea(vector<Shape*> shapes){
	double max_area = 0;
  double temp=0;//set the temporary value
  max_area=shapes[0]->getArea();//set the initial max value
  double i=0;
	int size = shapes.size();
  while(i < size){
    temp=shapes[i]->getArea();//set the next area value to the temp
    if(temp>max_area){
      max_area=temp;//set the temp as the new max value if it's greater than the current max value.
    }
    i++;//increment the counter
  }
	return max_area;//return the max value
}


// call getVolume() of each object
// return the max volume
double MaxVolume(vector<Shape*> shapes){
	double max_volume = 0;
  double temp=0;//set the temporary value
  max_volume=shapes[0]->getVolume();//set the initial max value
  double i=0;
	int size = shapes.size();
  while(i < size){
    temp=shapes[i]->getVolume();//set the next Volume value to the temp
    if(temp>max_volume){
      max_volume=temp;//set the temp as the new max value if it's greater than the current max value.
    }
    i++;//increment the counter
  }
	return max_volume;//return the max value
}
