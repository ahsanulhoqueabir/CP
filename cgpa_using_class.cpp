#include<bits/stdc++.h>
using namespace std;
int mx=0;
class Student 
{
    private:
        string name;
        double gpa[5];
        double cgpa;

    public:

    float gp(int a)
    {
        float x=0;
        if(a>=80) x=4;
        else if(a>=75 and a<80) x=3.75;
        else if(a>=70 and a<75) x=3.5;
        else if(a>=65 and a<70) x=3.25;
        else if(a>=60 and a<65) x=3;
        else if(a>=55 and a<60) x=2.75;
        else if(a>=50 and a<55) x=2.5;
        else if(a>=45 and a<50) x=2.25;
        else if(a>=40 and a<45) x=2.0;
        return x;
    }

    void input() 
    {
        cout << "Enter student name: ";
        // cin >> name;
        getchar();
        getline(cin,name);
        int sz= name.size();
        mx=max(mx,sz);
        cout << "Enter Number for 5 subjects:\n";
        for (int i = 0; i < 5; ++i) 
        {   
            cout << "Subject " << i + 1 << ": ";
            int x; cin >> x;
            float y = gp(x);
            gpa[i] =y;
        }
    }
        

    void calculateCGPA() 
    {
        double totalGPA = 0.0;
        for (int i = 0; i < 5; ++i) 
        {
            totalGPA += gpa[i];
        }
        cgpa = totalGPA / 5.0;
    }

    void display() 
    {
        // cout << "Student Name: " << name << endl;
        // cout << "CGPA: " << fixed << setprecision(2) << cgpa << endl;
        int x=name.size();
        cout << "| " << name << setw(mx-x+10) << fixed << setprecision(2) << "| " << cgpa << " |" << endl;
    }
};

int main() {
    Student students[10];
    
    for (int i = 0; i < 10; ++i) {
        cout << "Enter details for Student " << i + 1 << ":\n";
        students[i].input();
        students[i].calculateCGPA();
    }

    cout << "\nStudent Details:\n \n";
    cout<< "Student Name" << setw(mx+1) << "CGPA\n\n";
    for (int i = 0; i < 10; ++i) {
        students[i].display();
        cout << endl;
    }
    return 0;
}
