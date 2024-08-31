#include<iostream>
#include<string>

using namespace std;

class StudentGPA{
    private:
    float *array;
    int size;
    float TotalGPA = 0.0, TotalCGPA = 0.0;
    public:
    //constructor to initialize the array with a given size
    StudentGPA(int initialSize): size(initialSize)
    {
        array = new float[size];
        //initialize the array elements and store 0 in it
        for (int i = 0; i<size; i++)
        {
            array[i] = 0;
        }
    }
    //create a destructor to free the dynamixally allocated memory
    StudentGPA(){
        delete[]array;
    }
    //make a method to get data from user
    void GetCGPA(){
        cout<<"Enter the Previous GPA"<<endl;
        for(int i = 0; i<size; i++ )
        {
            cin>> array[i];
    
        }
    }
    //method to calculate cgpa
    void calculateCGPA(){
        string Grade;
        for(int i = 0; i<size; i++)
        {
            TotalGPA = array[i]+ TotalGPA;
        }
        TotalCGPA = TotalGPA / size;
        cout<<"Your current CGPA is : "<<TotalCGPA<<endl;
        //now check the grade
        if (static_cast<int>(TotalCGPA) == 4.0)
        {
            Grade = "A";
        }
        else if ((static_cast<int>(TotalCGPA)>= 3.0)&&(static_cast<int>(TotalCGPA)< 4.0)){
            Grade = "B";
        }
        else if ((static_cast<int>(TotalCGPA)>= 2.0)&&(static_cast<int>(TotalCGPA)< 3.0)){
            Grade = "C";
        }
        else if ((static_cast<int>(TotalCGPA)>= 1.0)&&(static_cast<int>(TotalCGPA)< 2.0)){
            Grade = "D";
        }
        else if ((static_cast<int>(TotalCGPA)>= 0.0)&&(static_cast<int>(TotalCGPA)< 1.0)){
            Grade = "F";
        }
        cout<<"Your current Grade is : "<<Grade;



    }

};

int main()
{
// create a dynamic array to stor the total semester grades you have clear
int TotalSemester;
cout<<"How many semesters have you completed"<<endl;
cin>>TotalSemester;
//object class for StudentGPA

StudentGPA Student(TotalSemester);
//call get methods
Student.GetCGPA();
//calculate methods
Student.calculateCGPA();
return 0;
}