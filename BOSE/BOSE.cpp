#include <iostream>

using namespace std;
double calculate1(double x, int n) {
    double y = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            y += (x - i * i + j);
        }
    }
    return y;
}
double calculate2(double x, int n) {
    double y = 0;
    for (int i = 0; i < n; i++) {
        y += (x - 1) / (i + 1);
    }
    return y;
}
//перевірка параметру n винесена в окрему функцію
int checkValidParams(int n) {
    if (n <= 0) {
        throw invalid_argument("Incorrect input: n must be > 0");
    }
    return 1;
}
//функція що повертає true/false і вирішує чи буде продовжуватись програма
bool askIfContinueLoop() {
    string contLoop; //чи продовжити цикл (continue loop)
    cin >> contLoop;
    return (contLoop == "y" ||contLoop == "yes") ? true : false; //повернути true якщо текстова contLoop 
}
//визначення одного значення функції винесено в окремий метод
double singleValue(double x, int n) {
    //криптичний if який вирішує обраховувати просту чи подвійну суму
    double y = (x < 0) ? calculate1(x, n) : calculate2(x, n);
    return y;
}
//функція для визначення багатьох значень функції на введеному інтервалі
void intervalValues(int n) {
    double start, end, step;
    cout << "Enter the start of the Interval(inclusive) : ";
    cin >> start;
    cout << "Enter the end of the Interval(inclusive) : ";
    cin >> end;
    cout << "Enter the step for the Interval : ";
    cin >> step; 
    int i = 1;
    //цикл для обчислень значень у для кожного х
    for (double x = start; x <= end; x = x + step) {
        cout << i << ". x= " << x << "y = " << singleValue(x, n) << endl;
        i++;
    }
}
//функція для отримання значення n задля зручності та уникнення повторення коду
int entern() {
	int var;
	cout << "Enter the value of n: ";
	cin >> var;
	checkValidParams(var);
	return var;
}
//функція для отримання значення x задля зручності та уникнення повторення коду
double enterx() {
	double var;
	cout << "Enter the value of x: ";
	cin >> var;
	return var;
}
int main() {
    double x;
    int n; 
    int choice; //вибір програми або вихід
    // використання do/while взаміну звичному while задля використання безумовного першого виконання коду в блоці 
    // і продовженню циклу залежно від функції типу bool askIfContinueLoop
    do {
        //Первинний prompt щоб обрати складність обчислення або завершити програму 
        //Були використані Escape Codes для взаємодії з терміналом 
        // \033[2J - очищує консоль, \033[0H - повертає курсор на 0, 0 для подальшого виведення
        cout << "\033[2J\033[0HEnter \"1\" for single value, \"2\" for multiple value calculation or \"0\" to exit the program: ";
        cin >> choice;
        //використання конструкту switch задля ефективної заміни if/"else if"/else запитів
        switch (choice) {
        //якщо в choice введено 0 - програма закінчиться з кодом 2 
        case 0:
            return 2;
        //якщо в choice введено 1 - програма виконає вирахунок одного значення функції
        case 1:
            n = entern();
            x = enterx();
            cout << "The value of y is " << singleValue(x, n) << endl << "Try again? [y/n] : ";
            break;
        //якщо в choice введено 2 - програма виконає вирахунок інтервалу значень функції
        case 2:
            n = entern();
            intervalValues(n);
            cout << "Try again ? [y/n] : ";
            break;
        //якщо в choice введено будь який інший ввід буде виведено наступне в консоль
        default:
            cout << "Invalid Input. Try again? [y/n] : ";
            break;
        }
        // виконання функції що вирішує чи продовжуватиметься цикл
    } while (askIfContinueLoop());
}