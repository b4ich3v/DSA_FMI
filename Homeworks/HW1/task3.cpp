#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Student 
{

    std::string name;
    int score;

    bool operator < (const Student& other) const 
    {
        
        if (score != other.score) return score > other.score;
        return name < other.name; 

    }

};

int main() 
{

    int N;
    std::cin >> N;

    std::vector<Student> students(N);

    for (int i = 0; i < N; i++) 
    {

        std::cin >> students[i].name;

    }

    for (int i = 0; i < N; i++) 
    {

        std::cin >> students[i].score;

    }

    std::sort(students.begin(), students.end());

    for (const auto& student : students) 
    {

        std::cout << student.name << " " << student.score << std::endl;

    }

    return 0;

}

