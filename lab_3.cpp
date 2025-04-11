#include<iostream>
using namespace std;
class Course{
private:
  string course_code;
  string course_name;
  int duration;
  int credits_points;
  string coordinator;
  int Enrolled_students;

public:

void set(string course_c ,string course_nam, int dur, int cred_p, string coord,int enroll_st){
   course_code=course_c;
   course_name=course_nam;
   duration=dur;
   credits_points=cred_p;
   coordinator=coord;
   Enrolled_students=enroll_st;
}
void get(){
cout<<course_code<<endl;
cout<<course_name<<endl;
cout<<duration<<endl;
cout<<credits_points<<endl;
cout<<coordinator<<endl;
cout<<Enrolled_students<<endl;
}
};

class Btech : public Course{
   float fee;
public:
   Btech()
{
  fee=65000;
}
};

int main(){
Btech B1;
B1.set("CSE_22_26","CSE",4,20,"XYZ",60);
B1.get();
}