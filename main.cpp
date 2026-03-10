
#include <vector>
#include <iostream>
#include <numeric>

class Student {
    std::string name;
    std::string surname;
    std::vector<float> grades;
    int album;
public:
    Student(std::string n, std::string s, int a){
        name = n; surname = s;
        if(a<1000000&&a>=10000) album = a;
        else std::cout << "Provided album number is invalid";
    }

    float calculate_grade() {
        float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
        return sum / grades.size();
    }

    bool add_grade(float grade) {
        if (grade >= 2.0 && grade <= 5.0) {
            grades.push_back(grade);
            return true;
        }
    return false;
    }

    void set_name(std::string n, std::string s){
        name = n; surname = s;
    }

    bool set_album(int a){
        if(a<1000000&&a>=10000) {
            album = a;
            return true;
        }
        std::cout << "Provided album number is invalid";
        return false;
    }

    void summary() {
        std::cout<<album<<" - "<<name<<" "<<surname<<": ";
        for(int i=0;i<grades.size();i++){
            std::cout<<grades[i]<<" ";
        }
        std::cout << std::endl;
    }
    bool passed() {
        int fail=0;
        for(int i=0;i<grades.size();i++){
            if(grades[i]==2.0)fail++;
        }
        if(fail<=1)return true;
        return false;
    }
};

class Complex {
    float real;
    float im;
public:
    Complex(float a, float b){
        real = a; im = b;
    }
    Complex(float a){
        real = a;
    }

    void set_real(float a){
        real = a;
    }
    void set_im(float b){
        im = b;
    }
    Complex add(const Complex b){
        Complex c(real + b.real,im + b.im);
        return c;
    }

    void print(){
        if(im<0){
            std::cout << real<<im<<"i\n";
        }
        else std::cout <<real<<"+"<<im<<"i\n";
    }

}

int main(){
    Student student("Some","Student",192467);
    for(float f=2.0;f<=5.0;f+=0.5){
        student.add_grade(f);
    }
    student.summary();
    std::cout << "Mean grade: " << student.calculate_grade() << std::endl;
    student.set_album(342216);
    student.set_name("John","Doe");
    student.add_grade(4.0);
    student.summary();
    std::cout << "Mean grade: " << student.calculate_grade() << std::endl;
    if(student.passed())std::cout<<"This student has passed\n";
    else std::cout<<"This student has not passed\n";
}