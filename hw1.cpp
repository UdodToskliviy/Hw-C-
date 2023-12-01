#include <iostream>
#include<cmath>

void task1(){
    std::cout << "input base 1, after baze 2 and height of your figure \n";
    double baze1;
    double baze2;
    double height;
    std::cin >> baze1;
    std::cin >> baze2;
    std::cin >> height;
    std::cout << "Area of your figure equals " << (baze1 + baze2) / 2 * height;
}

double circleLenght(double radius){
    const double pi = 3.14;
    return 2 * pi * radius;
}
double circleArea(double radius){
    const double pi = 3.14;
    return pi * radius * radius;
}
void task2(){
    std::cout << "input radius of your circle \n";
    double radius;
    std::cin >> radius;
    std::cout << "lenght of your circle equals " << circleLenght(radius) << " and area of your circle equals " << circleArea(radius);
}

double rightTriangleArea(double cathethus1, double cathethus2){
    return cathethus1 * cathethus2 / 2;
}
double getHypotenuse(double cathethus1, double cathethus2){
    return sqrt(cathethus2 * cathethus2 + cathethus1 * cathethus1);
}
void task3(){
    std::cout << "input cathethus 1, after cathethus 2 of your right triangle \n";
    double cathethus1;
    double cathethus2;
    std::cin >> cathethus1;
    std::cin >> cathethus2;
    std::cout << "area of your triangle equals " << rightTriangleArea(cathethus1, cathethus2) << " and hypotenuse equals " << getHypotenuse(cathethus1, cathethus2);
}

void task4(){
    std::cout << "input four-digit number \n";
    int number;
    std::cin >> number;
    std::cout << "sum of digits equals " << number % 10 + (number / 10) % 10 + (number / 100) % 10 + (number / 1000) % 10;
}

void task5(){
    std::cout << "input x-coordinate and after y-coordinate of your point \n";
    double x;
    double y;
    std::cin >> x;
    std::cin >> y;
    std::cout << "in polar coordinates your point has " << sqrt(x * x + y * y) << " radius and " << atan2(y, x) << " angle";
}

void task6(){
    std::cout << "input radius and after angle of your point in polar coordinates \n";
    double radius;
    double angle;
    std::cin >> radius;
    std::cin >> angle;
    double x = radius * cos(angle);
    double y = radius * sin(angle);
    std::cout << "your point has coordinates (" << x << ", " << y <<")";
}

void task7(){
    std::cout << "input quotient a, after quotient b and afer quotient c \n";
    double a;
    double b;
    double c;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    double d = b * b - 4 * a * c;
    if(d >= 0){
        std::cout << "roots are " << (-1 * b + sqrt(d)) / (2 * a) << " and " << (-1 * b - sqrt(d)) / (2 * a);
    }
    else{
        std::cout << "There are no real roots";
    }
}

void task8(){
    std::cout << "input sides of your triangle \n";
    double a;
    double b;
    double c;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    //Медиана треугольника со сторонами a, b и c, проведённая к стороне c, по формуле 
    //равна sqrt(2 * (a * a + b * b) - c * c) / 2 из чего получаем:
    double m1 = sqrt(2 * (a * a + b * b) - c * c) / 2;
    double m2 = sqrt(2 * (a * a + c * c) - b * b) / 2;
    double m3 = sqrt(2 * (c * c + b * b) - a * a) / 2;
    std::cout << "медианы финального треугольника рaвны " << sqrt(2 * (m1 * m1 + m2 * m2) - m3 * m3) / 2 << ", " << sqrt(2 * (m1 * m1 + m3 * m3) - m2 * m2) / 2 << " и " << sqrt(2 * (m3 * m3 + m2 * m2) - m1 * m1) / 2;
}

void task9(){
    std::cout << "input number of seconds passed \n";
    int seconds;
    std::cin >> seconds;
    std::cout << "from the beginning of the day " << seconds / 3600 << " hours " << (seconds / 60) % 60 << " minutes and " << seconds % 60 << " seconds passed";
}

void task10(){
    std::cout << "input sides of your triangle \n";
    double a;
    double b;
    double c;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    if(a == b || a == c || b == c){
        std::cout << "your triangle is isoscess";
    }
    else{
        std::cout << "your triangle is not isoscess";
    }
}

void task11(){
    std::cout << "input your price \n";
    double price;
    std::cin >> price;
    if(price < 1000){
        std::cout << "you must pay " << price;
    }
    else{
        std::cout << "you must pay " << 0.9 * price;
    }
}

void task12(){
    std::cout << "input your height and after your mass \n";
    double height;
    double mass;
    std::cin >> height;
    std::cin >> mass;
    double perfectMass = height - 100;
    if(perfectMass < mass){
        std::cout << "you need to lose weight";
    }
    else if(perfectMass > mass){
        std::cout << "you need to increase weight";
    }
    else{
        std::cout << "your body is perfect";
    }
}

void task13(){
    std::cout << "try to guess multiplication of two random numbers from 1 to 9 each \n";
    int guessedNumber;
    std::cin >> guessedNumber;
    int a = rand() % 9 + 1;
    int b = rand() % 9 + 1;
    if(guessedNumber == a * b){
        std::cout << "You guessed right";
    }
    else{
        std::cout << "You guessed not right";
    }
}

void task14(){
    std::cout << "input number of day (from 1 to 7) when the conversation goes and after time of talking \n";
    int weekDay;
    double talkingTime;
    std::cin >> weekDay;
    std::cin >> talkingTime;
    //i suppose that one unit of time consumes 1 unit of money on weekdays
    if(weekDay == 6 || weekDay == 7){
        std::cout << "you will spend " << talkingTime * 0.8 << " units of money";
    }
    else{
        std::cout << "you will spend " << talkingTime << " units of money";
    }
}

void task15(){
    std::cout << "input the number of your month \n";
    int monthNumber;
    std::cin >> monthNumber;
    std::cout << "your month is ";
    switch (monthNumber){
        case 1:
            std::cout << "january, winter";
            break;
        case 2:
            std::cout << "february, winter";
            break;
        case 3:
            std::cout << "march, spring";
            break;
        case 4:
            std::cout << "april, spring";
            break;
        case 5:
            std::cout << "may, spring";
            break;
        case 6:
            std::cout << "june, summer";
            break;
        case 7:
            std::cout << "july, summer";
            break;
        case 8:
            std::cout << "august, summer";
            break;
        case 9:
            std::cout << "september, autumn";
            break;
        case 10:
            std::cout << "october, autumn";
            break;
        case 11:
            std::cout << "november, autumn";
            break;
        case 12:
            std::cout << "december, winter";
            break;
        default:
            std::cout << "unknown month";
            break;
    }
}

void task16(){
    std::cout << "input the number of your ticket \n";
    int number;
    std::cin >> number;
    int secondHalf = number % 10 + (number / 10) % 10 + (number / 100) % 10;
    number = number / 1000;
    int firstHalf = number % 10 + (number / 10) % 10 + (number / 100) % 10;
    if(firstHalf == secondHalf){
        std::cout << "your ticket is happy";
    }
    else{
        std::cout << "your ticket is unhappy";
    }
}

void task17(){
    std::cout << "input amount of money, which you have \n";
    int amountofMoney;
    std::cin >> amountofMoney;
    std::cout << "u vas " << amountofMoney << " ";
    if(amountofMoney % 10 == 1){
        std::cout << "копейка";
    }
    else if(amountofMoney % 10 == 2 || amountofMoney % 10 == 3 || amountofMoney % 10 == 4){
        std::cout << "копейки";
    }
    else{
        std::cout << "копеек";
    }
}

void task18(){
    std::cout << "input your 4-digit number \n";
    int number;
    std::cin >> number;
    std::cout << "your number ";
    if((number % 10 == (number / 1000) % 10) && ((number / 100) % 10 == (number / 10) % 10)){
        std::cout << "is palindrom";
    }
    else{
        std::cout << "is not palindrom";
    }
}

void task19(){
    std::cout << "input your 3-digit number and after any number \n";
    int a;
    int b;
    std::cin >> a;
    std::cin >> b;
    int firstDigit = (a / 100) % 10;
    int secondDigit = (a / 10) % 10;
    int thirdDigit = a % 10;
    if(firstDigit * secondDigit * thirdDigit > b){
        if((firstDigit + secondDigit + thirdDigit) % 7 == 0){
            std::cout << "multiplication of digits of a > b, summ of digits of a is multiply of 7";
        }
        else{
            std::cout << "multiplication of digits of a > b, summ of digits of a is not multiply of 7";
        }
    }
    else{
        if((firstDigit + secondDigit + thirdDigit) % 7 == 0){
            std::cout << "multiplication of digits of a < b, summ of digits of a is multiply of 7";
        }
        else{
            std::cout << "multiplication of digits of a < b, summ of digits of a is not multiply of 7";
        }
    }
}

void task20(){
    std::cout << "input sides of your rectangles first with sides a, b and second with sides c, d \n";
    double a;
    double b;
    double c;
    double d;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    if((c < a && d < b) || (c < b && d < a)){
        std::cout << "it is possible";
    }
    else{
        std::cout << "it is impossible";
    }
    std::cout << " to fit the second one into first one, according to the given rule";
}




int main()
{
    task20();
    return 0;
}
