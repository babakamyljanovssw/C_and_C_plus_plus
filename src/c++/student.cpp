#include <iostream>
#include <list>

using namespace std;

class Student {
    protected:
        string id;
        string name;
        string gender;
        string phoneNumber;
        int mathScore;
        int englishScore;
        int scienceScore;

    public:
        Student(
            string id,
            string name,
            string gender,
            string phoneNumber,
            int mathScore,
            int englishScore,
            int scienceScore
        ) {
            this->id = id;
            this->name = name;
            this->gender = gender;
            this->phoneNumber = phoneNumber;
            this->mathScore = mathScore;
            this->englishScore = englishScore;
            this->scienceScore = scienceScore;
        }

        int getTotalScore() {
            return mathScore + englishScore + scienceScore;
        }

        double getAverageScore() {
            return getTotalScore() / 3.0;
        }

        int getHighestSCore() {
            int maxScore = mathScore;

            if (englishScore > maxScore)
                maxScore = englishScore;
            if (scienceScore > maxScore)
                maxScore = scienceScore;
            return maxScore;
        }

        string getGrade(int score) {
            if (score >= 90) {
                return "Excellent";
            } else if (score >= 80) {
                return "Good";
            } else if (score >= 60) {
                return "Pass";
            } else {
                return "Fail";
            }
        }

        void print() {
            cout << endl;
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Gender: " << gender << endl;
            cout << "Phone number: " << phoneNumber << endl;
            cout << "Math score: " << mathScore << " (" << getGrade(mathScore) << ")" << endl;
            cout << "English score: " << englishScore << " (" << getGrade(englishScore) << ")" << endl;
            cout << "Science score: " << scienceScore << " (" << getGrade(scienceScore) << ")" << endl;
        }
};

class TransferredStudent: public Student {
    private:
        string previousSchool;

    public:
        TransferredStudent(
            string id,
            string name,
            string gender,
            string phoneNumber,
            int mathScore,
            int englishScore,
            int scienceScore,
            string previousSchool
        ) : Student(id, name, gender, phoneNumber, mathScore, englishScore, scienceScore) {
            this->previousSchool = previousSchool;
        }

        void print() {
            Student::print();
            cout << "Previous school: " << previousSchool << endl;
        }
};

int main() {
    list<Student*> students;

    students.push_back(new Student("M00000015", "Babanazar", "Male", "103-486-7891", 78, 83, 91));
    students.push_back(new Student("M00000010", "Sophie", "Female", "123-456-7890", 80, 36, 94));
    students.push_back(new Student("M00000012", "Alice", "Female", "987-654-3210", 62, 92, 85));
    students.push_back(new Student("M00000013", "Jane", "Female", "456-123-7890", 78, 93, 55));
    students.push_back(new Student("M00000014", "John", "Male", "789-123-4560", 75, 89, 90));

    // Adding a transferred student
    students.push_back(new TransferredStudent(
        "M00000011",
        "Bob",
        "Male",
        "321-654-9870",
        48, 81, 78,
        "Zhejiang Sci-Tech University"));
    
    // print all students
    for (auto student: students) {
        student->print();
        cout << "------------------------------------------------------------------------------" << endl;
    }

    // Clean up
    for (auto student : students) {
        delete student;
    }

    system("pause");
    return 0;
}