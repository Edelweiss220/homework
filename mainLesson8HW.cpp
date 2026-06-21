#include <iostream>
#include <string>
#include <cmath>
/*
II. Небольшие практические задачи по структурам в духе "пока пью чай"

1)
Создайте структуру Student, содержащую поля:
• name
• age,
• average.
Необходимо самим попределить тип данных полей.
Напишите программу, которая запрашивает у пользователя данные об одном студенте (ввод с клавиатуры), затем выводит их в удобном формате.

2)
Объявите структуру Point с координатами x и y (целые или вещественные).
Запросите координаты двух точек, вычислите и выведите расстояние между ними по формуле:
√((x₂−x₁)² + (y₂−y₁)²).

*/
struct user{
    std::string userName;
    int age;
    double grade;
};

struct Point{
    int x;
    int y;
};

void fillStruct(user& x){
    std::cout<<"Enter userName:"<<std::endl;
    std::cin>>x.userName;
    std::cout<<"Enter age:"<<std::endl;
    std::cin>>x.age;
    std::cout<<"Enter grade:"<<std::endl;
    std::cin>>x.grade;
}
void printInfo(user name){
    std::cout<<"UserName:="<<name.userName<<" "<<"User age:"<<name.age<<" "<<"User grade:"<<name.grade<<std::endl;
}

void inputPoint (Point& pointStruct){
    std::cout<<"Enter X and Y";
    std::cin>>pointStruct.x>>pointStruct.y;
}

double distance (Point& a, Point& b){
    double xDistance=a.x-b.x;
    double yDistance=a.y-b.y;
    return std::sqrt(xDistance*xDistance+yDistance*yDistance);
}

int main(){
    int menu;
    Point p1,p2;

    while(true)
    {
        std::cout << "\nMAIN MENU:\n";
        std::cout << "Operation #1 - FILL STRUCR (UserName, age, grade)\n";
        std::cout << "Operation #2 - ESTIMATE DISTANCE\n";
        std::cout << "Operation #3 - END RUN\n";
        std::cout << "Start operation №: ";
            while (!(std::cin >> menu)) {
            std::cout << "Wrong operation #";
            std::cin.clear();               
            std::cin.ignore(100000, '\n');
            std::cout << "Start operation №: ";
            }
        if (menu==1){
            user u1;
            fillStruct(u1);
            std::cout<<"Operation finished"<<std::endl;
            printInfo(u1);
        }
        else if (menu==2){
            std::cout << "Enter coordinates of first point (x y): ";
            inputPoint(p1);
            std::cout << "Enter coordinates of second point (x y): ";
            inputPoint(p2);
            double dist = distance(p1, p2);
            std::cout << "Distance between points: " << dist << std::endl;
            break;
        }
        else if (menu==3){
            std::cout<<"Terminated";
            break;
        }
        else{
            std::cout<<"Wrong operation #";
        }
    }
    return 0;
}