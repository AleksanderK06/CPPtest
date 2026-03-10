
#include <vector>
#include <iostream>
#include <numeric>

struct Student {
    std::string name;
    std::string surname;
    std::vector<float> grades;

    float calculate_grade() {
        float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
        return sum / grades.size();
    }
    void print() {
        std::cout<<name<<" "<<surname<<": ";
        for(int i=0;i<grades.size();i++){
            std::cout<<grades[i]<<" ";
        }
        std::cout << std::endl;
    }
};

int main(){
    Student student{"Some", "Student", {2, 3, 4, 5, 3}};
    std::cout << student.calculate_grade() << std::endl;
    student.print();
}