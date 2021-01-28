#include <iostream>
#include <string>
#include <iomanip>

using namespace std; 
class MyTime
{   
  public:

    // CONVERT THESE CONSTRUCTORS INTO A SINGLE CONSTRUCTOR THAT USES 
    // DEFAULT ARGUMENTS
    MyTime(int h = 0, int m = 0);
   
    void Reset(int h, int m);    
   
    MyTime operator + (const MyTime& t2) const;


 
    MyTime operator - (const MyTime& t2) const;
 
    MyTime operator * (int num) const;

    MyTime operator / (int num) const;

    bool operator == (const MyTime& t2) const;

    bool operator < (const MyTime& t2) const;

    bool operator <= (const MyTime& t2) const;

    void input(std::istream& ins);            

    void output(std::ostream& outs);

    int get_hours() const{return hours;}
    int get_minutes() const{return minutes;}
   
  private:
      void simplify();
      int hours;      // hours can be > 24
      int minutes;   // 0 <= minutes <= 59
 };
 std::ostream& operator <<(ostream& outs, const MyTime& t1);
 std::istream& operator >> (istream& ins, MyTime& t1); 

 int main(int argc, char* argv[]) {
    MyTime t1;
    MyTime t2(15, 30);

    //outputs the T1 and T2 to the user
    cout << "T1 is " << t1 << endl;

    cout << "T2 is " << t2 << endl;

    //allows the user to enter the data for t3 and t4
    //use .input(cin) for t4
    MyTime t3, t4;
    cout << "Enter the time for t3" << endl;
    cin >> t3;

    cout << "Enter the time for t4" << endl;
    t4.input(cin);
    cout << endl;

    //allow user to input scalars for multiplication
    float scalar;
    float scalar2;

    //output t3 and t4
    cout << "t3 is " << t3 << endl;
    cout << "t4 is ";
    t4.output(cout);
    cout << endl;

    //get scalar values
    cout << "Enter a scalar value to multiply for t3" << endl;
    cin >> scalar;

    cout << "Choose a scalar value to divide t4" << endl;

    cout << "t3 * " << scalar << " = " << t3 * scalar << endl;
    cout << "t4 / " << scalar2 << " = " << t4 / scalar2 << endl;

    if (t3 == t4)
    {
        cout << t3 << " is equal to " << t4 << endl;

    }
    else
    {
        cout << t3 << " is not equal to " << t4 << endl;
    }
    

    if (t3 < t4)
    {
        cout << t3 << " is less than " << t4 << endl;

    }
    else
    {
        cout << t3 << " is NOT less than " << t4 << endl;
    }

    if (t3 <= t4)
    {
        cout << t3 << " is less than/equal to " << t4 << endl;
    }

    else
    {
        cout << t3 << " is NOT less than/equal to " << t4 << endl;


    }
    
    
    
    
    
















    return 0;}
    //main

    MyTime::MyTime(int h, int m){
	Reset(h,m);
}



void MyTime::Reset(int h, int m){
	hours = h;
	minutes = m;
    simplify();
}

void MyTime::simplify(){
    hours += minutes/60;
	minutes = minutes%60;
}

MyTime MyTime::operator + (const MyTime& t2) const{
	MyTime tmp;
    tmp.hours = hours + t2.hours;
	tmp.minutes = minutes + t2.minutes;
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator - (const MyTime& t2)const{
	MyTime tmp;
	tmp.minutes = abs((hours * 60 + minutes) - (t2.hours * 60 + t2.minutes));
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator / (int num) const{
	MyTime tmp;
	tmp.minutes = (hours * 60 + minutes) / num;
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator * (int num) const{
	MyTime tmp;
	tmp.minutes = (hours * 60 + minutes) * num;
	tmp.simplify();
	return tmp;
}

bool MyTime::operator == (const MyTime& t2) const {
	return hours == t2.hours && minutes == t2.minutes;
}

bool MyTime::operator < (const MyTime& t2) const{
	return (hours * 60 + minutes) < (t2.hours*60 + t2.minutes);
}

bool MyTime::operator <=(const MyTime& t2) const{
	return (hours*60 + minutes) <= (t2.hours*60 + t2.minutes);
}

void MyTime::input(istream&ins){
       // Here you are to copy the implementation code from the >> operator shown below
	// remember to that variables will be local here - so no referene to t1
       //Then you can have the >> operator call this function.
      // In the .h file remove the word friend for the operator and move its prototype to a spot
      // under the class declaration

      char junk;
      ins >> hours;
      ins.get(junk);
      ins >> minutes;
      simplify();
}

void MyTime::output(ostream& outs){
	// Do the same thing a you did for the function above except using the code for the << 
	//operator
    outs << hours << minutes;

    
}


ostream& operator <<(ostream& outs, const MyTime& t1){
    outs << t1.get_hours() << ':' << setw(2) << setfill('0') << t1.get_minutes();
    return outs;
}

istream& operator >> (istream& ins, MyTime& t1){
	char junk;
	int h;
    int m;
    ins >> h;
    ins.get(junk);
    ins >> m;
    t1.Reset(h, m);
    return ins;
}
