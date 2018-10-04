#include "shape.hpp"



//Base class
//Please implement Shape's member functions
//constructor, getName()
//
Shape::Shape(string name){
  name_=name;
}
string Shape::getName(){return name_;}
//Base class' constructor should be called in derived classes'
//constructor to initizlize Shape's private variable



//Rectangle
//Please implement the member functions of Rectangle:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here

Rectangle::Rectangle(double a, double b):Shape("Rectangle"){
  width_=a;
  length_=b;
}
double Rectangle::getWidth(){return width_;}
double Rectangle::getLength(){return length_;}
double Rectangle::getArea(){ return width_*length_;}
double Rectangle::getVolume(){
  return 0.0;
}
Rectangle Rectangle:: operator + (const Rectangle& R2){
  Rectangle R3(0,0);
  R3.length_=length_+R2.length_;
  R3.width_=width_+R2.width_;

  return R3;
}
Rectangle Rectangle:: operator - (const Rectangle& R2){
  Rectangle R3(0,0);
  R3.length_=length_-R2.length_;
  R3.width_=width_-R2.width_;
  if (R3.length_<0){R3.length_=0;}
  if(R3.width_<0){R3.width_=0;}

  return R3;
}


//Circle
//Please implement the member functions of Circle:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here
Circle::Circle(double r):Shape("Circle"){
  radius_=r;
}
double Circle::getRadius(){return radius_;}
double Circle::getArea(){return radius_*radius_*M_PI;}
double Circle::getVolume(){return 0.0;}
Circle Circle::operator + (const Circle& R2){
  Circle R3(0);
  R3.radius_=radius_+R2.radius_;
  return R3;
}
Circle Circle::operator - (const Circle& R2){
  Circle R3(0);
    R3.radius_=radius_-R2.radius_;
    if(R3.radius_<0){R3.radius_=0;}
    return R3;
}
//Sphere
//Please implement the member functions of Sphere:
//constructor, getArea(), getVolume(), operator+, operator-
//@@Insert your code here


Sphere::Sphere(double r):Shape("Sphere"){
  radius_=r;
}
double Sphere::getRadius(){return radius_;}
double Sphere::getArea(){return 4*M_PI*radius_*radius_;}
double Sphere::getVolume(){return (4.0/3.0)*radius_*radius_*radius_*M_PI;}
Sphere Sphere:: operator + (const Sphere& S2){
  Sphere S3(0);
  S3.radius_=radius_+S2.radius_;
  return S3;
}
Sphere Sphere:: operator - (const Sphere& S2){
  Sphere S3(0);
  S3.radius_=radius_-S2.radius_;
  if(S3.radius_<0){S3.radius_=0;}
  return S3;
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
double RectPrism::getLength(){return length_;}
double RectPrism::getArea(){return 2*(length_*width_+length_*height_+width_*height_);}
double RectPrism::getVolume(){return length_*width_*height_;}
RectPrism RectPrism::operator + (const RectPrism& RP2){
  RectPrism RP3(0,0,0);
  RP3.length_=length_+RP2.length_;
  RP3.width_=width_+RP2.width_;
  RP3.height_=height_+RP2.height_;
  return RP3;`
}
RectPrism RectPrism::operator - (const RectPrism& RP2){
  RectPrism RP3(0,0,0);
  RP3.length_=length_-RP2.length_;
  RP3.width_=width_-RP2.width_;
  RP3.height_=height_-RP2.height_;
  if(RP3.length_<0){RP3.length_=0;}
  if(RP3.width_<0){RP3.width_=0;}
  if(RP3.height_<0){RP3.height_=0;}
  return RP3;
}



// Read shapes from test.txt and initialize the objects
// Return a vector of pointers that points to the objects
vector<Shape*> CreateShapes(char* file_name){
	int number;
  double a,b,c;
  string name;
	//string Rectangle = "Rectangle";
	//string Circle = "Circle";
	ifstream ifs (file_name, std::ifstream::in);
	ifs >> number;
	//cout << number;
	//cout << "\n";
  vector<Shape*> vect(number);
  int i=0;
  while(i<number){
    ifs >> name;
      if (name=="Rectangle"){
        ifs >> a >> b;
        vect[i]=new Rectangle(a,b);
      }
      if(name=="Circle"){
        ifs>>a;
        vect[i]=new Circle(a);
      }
      if(name=="Sphere"){
        ifs>>a;
        vect[i]=new Sphere(a);
      }
      if(name=="RectPrism"){
        ifs>>a>>b>>c;
        vect[i]=new RectPrism(a,b,c);
      }
    i=i+1;
  }
    ifs.close();
    return vect;

  }
	//while (number > 0)
	//{

		/*int pa, paa, paaa;
		paa = 0;
		paaa = 0;
		ifs >> name >> pa;
		if (name == "Circle")
		{
			//ifs >> pa;
			//cout << name << pa;
		//ifs >> name >> pa >> paa;
		cout << name << pa << paa;
		}
		cout << name << "";
		cout << pa;
		cout << "\n";
		if (paa == 0)
		{
			Shape* shape_ptr = new name(pa);
		}
		else
		{
			if (paaa == 0)
			{
				Shape* shape_ptr = new name(pa, paa);
			}
			else
			{
				Shape* shape_ptr = new name(pa, paa, paaa);
			}
		}
		if (name == 'Rectangle')
		{
			ifs >> pa >> paa;
			cout << name << pa << paa;
		}
		else if (name == 'Circle')
		{
			ifs >> pa;
			cout << name << pa;
		}
		//cout << name << pa << paa << paaa;
	//number--;
	//shape_ptr = shape_ptr + 1;
	//}
	ifs.close();

	//@@Insert your code here
	return vector<Shape*>(0, NULL); // please remeber to modify this line to return the correct value
}
*/
// call getArea() of each object
// return the max area
double MaxArea(vector<Shape*> shapes){
	double max_area = 0;
  	double temp=0;
	int i = 0;
	int counter = 0;
	while (vector[i] != NULL)
	{
		counter++;
		i++;
	}
	for (i = 0; i < counter; i++)
	{
		getArea
	return max_area;
}


// call getVolume() of each object
// return the max volume
double MaxVolume(vector<Shape*> shapes){
	double max_volume = 0;
	//@@Insert your code here
	return max_volume;
}
