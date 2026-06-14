/* Лекция №5
1) написать три функции swap которые принимают параметры по значению, по ссылке и по указателю
(пусть будет swapPtr, swapRef, swapVal)
в функции main создаем две переменные , вызываем функции (сопровождаем все выводом значений, адресов)
2)написать функцию void processArray(int* arr, int size) (стараемся избегать обращения по индексу (arr[i]) ) работаем с адресной арифметикой
указатель++ и т.д.
Вывести например сумму всех элементов массива
3) Посерьезнее. Вычисление среднего балла. Спрашиваем у пользователя количество оценок, в динамической памяти выделяем память под массив (оператор new)
Пользователь заполняет массив оценками, высчитываем средний балл, выводим его пользователю.
4) Посмотреть сколько на вашей машине с вашим компилятором весит указатель (сколько места занимает адрес ячейки памяти)

Можно попробовать (необязательно) создать репозиторий на гитхаб, запушить туда ДЗ через гит и скинуть в таком виде
*/


#include <iostream>
#include <utility> // для std::pair



// Cвап по значению
std::pair<int, int> swappedByValue(int value1, int value2){
    return std::make_pair(value2,value1);
}

// Cвап по указателю
int swappedByPtr (int* ptr1, int* ptr2){
    std::cout<<"----------------------------"<<std::endl;
    std::cout<<"Run swappedByPtr"<<std::endl;
    int tempValue1=0;
    int tempValue2=0;
    std::cout<<"Temp= "<<tempValue1+tempValue2<<" Adress X="<<ptr1<<" Adress Y="<<" "<< ptr2<<std::endl;
        tempValue1=*ptr1;
        tempValue2=*ptr2;
    std::cout<<"Temp1= "<<tempValue1<<std::endl;
    std::cout<<"Temp2= "<<tempValue2<<std::endl;
        *ptr1=tempValue2;
        *ptr2=tempValue1;
    std::cout<<"ptr1= "<<*ptr1<<std::endl;
    std::cout<<"ptr2= "<<*ptr2<<std::endl;
    std::cout<<"Function  swappedByPtr done."<<std::endl;
    std::cout<<"----------------------------"<<std::endl;
    return 0;
}

int swappedByRef(int& ref1, int& ref2){
    std::cout<<"----------------------------"<<std::endl;
    std::cout<<"Run swappedByRef"<<std::endl;
    std::cout<<ref1<<" "<<ref2<<std::endl;
    int tempValue1=ref1;
    int tempValue2=ref2;
    std::cout<<"tempValue1= "<<ref1<<std::endl;
    std::cout<<"tempValue2= "<<ref2<<std::endl;
    ref1=tempValue2;
    ref2=tempValue1;
    std::cout<<"ref1= "<<ref1<<std::endl;
    std::cout<<"ref2= "<<ref2<<std::endl;
    std::cout<<"Function  swappedByRef done."<<std::endl;
    std::cout<<"----------------------------"<<std::endl;
    return 0;
}
// Нерпавильное решение задачи, массив читается через [i]
void sumOfArr(int recivedArr[], int sizeOfRecivedArr){
    std::cout<<"----------------------------"<<std::endl;
    std::cout<<"Run summOfArr"<<std::endl;
    int i=0;
    int valueOfSumm=0;
    while (i<sizeOfRecivedArr){
        std::cout<<"arrValue="<<recivedArr[i]<<" "<<"arrAdress="<<&recivedArr[i]<<std::endl;
        valueOfSumm=valueOfSumm+recivedArr[i];
        i=i+1;
    }
    std::cout<<">valueOfSum= "<<valueOfSumm<<std::endl;
    std::cout<<">Finished summOfArr"<<std::endl;
    std::cout<<"----------------------------"<<std::endl;
}

int main(){
    std::cout<<">Start main"<<std::endl;
        int x=10;
        int y=20;
            std::cout<<">value1= "<<x<<"     "<<" value2= "<<y<<std::endl;
    // СВАП ПО ЗНАЧЕНИЮ 
    std::pair<int, int> swapped=swappedByValue(x, y);
        x=swapped.first;
        y=swapped.second;
            std::cout<<">Result (swapedByValue)  "<<x<<"...."<<y<<std::endl;
        x=10;
        y=20;
      // СВАП ПО УКАЗАТЕЛЮ 
    swappedByPtr(&x,&y) ;
    std::cout<<">x= "<<x<<" y= "<<y<<std::endl;
        x=10;
        y=20;
    std::cout<<">x= "<<x<<" y= "<<y<<std::endl;
    // СВАП ПО ССЫЛКЕ
    swappedByRef(x,y) ;
    std::cout<<">x= "<<x<<" y= "<<y<<std::endl;
        x=10;
        y=20;
    std::cout<<">x= "<<x<<" y= "<<y<<std::endl;
    //написать функцию void processArray(int* arr, int size) (стараемся избегать обращения по индексу (arr[i]) ) работаем с адресной арифметикой указатель++ и т.д. Вывести например сумму всех элементов массива
    int arr1[5]={1,2,3,4,5};
        int arr1Size=sizeof(arr1)/sizeof(arr1[0]);
            std::cout<<"Size of array= "<<arr1Size<<std::endl;
                int i=0;
                for (;i<arr1Size; i=i+1){
                    std::cout<<"Array position= "<<i<<" Array value= "<<arr1[i]<<" Cell aderss= "<<&arr1[i]<<std::endl;
                }
    sumOfArr(arr1,arr1Size);

    //Вычисление среднего балла. Спрашиваем у пользователя количество оценок, в динамической памяти выделяем память под массив (оператор new) Пользователь заполняет массив оценками, высчитываем средний балл, выводим его пользователю.

    std::cout<<">Please, enter quantity of student grades: "<<std::endl;
        int quantityOfStudentGrades = 0;
        std::cin>>quantityOfStudentGrades;
        std::cout<<quantityOfStudentGrades<<std::endl;
    
            int* arr2=new int[quantityOfStudentGrades]; // веделяю массив
                int* arr2Begin=arr2; // указатель на начало масиива
                std::cout<<"Array volume ="<<sizeof(arr2)<<std::endl;
                std::cout<<"Enter "<<quantityOfStudentGrades<<" greades one by one (obly digits pelease)"<<std::endl;
                int k=0;
                while (k<quantityOfStudentGrades){
                    std::cin>>*arr2Begin;
                    ++arr2Begin;
                    k=k+1;
                    }
                //обход массива
                std::cout<<"Array2 read: "<<std::endl;
                k=0;
                int averageGrade=0;
                while (k<quantityOfStudentGrades)
                {
                    std::cout<<*arr2<<" item "<<std::endl;
                    averageGrade=averageGrade+*arr2;
                    ++arr2;
                    ++k;
                    if (k>=quantityOfStudentGrades){
                        int ostatok=averageGrade%k;
                        averageGrade=averageGrade/k;
                        std::cout<<"Average Grade is "<<averageGrade<<"."<<ostatok<<std::endl;
                    }
                }
                

            delete[] arr2;
            
        




}