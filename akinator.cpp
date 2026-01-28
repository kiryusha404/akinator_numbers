#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib> 
#include <ctime> 
#include <string> 

using namespace std;



//множество всех чисел
set<int> numbers{
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
    20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
    60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
    90, 91, 92, 93, 94, 95, 96, 97, 98, 99
};

//подмножество четный чисел
set<int> even_numbers{
    10, 12, 14, 16, 18,
    20, 22, 24, 26, 28,
    30, 32, 34, 36, 38,
    40, 42, 44, 46, 48,
    50, 52, 54, 56, 58,
    60, 62, 64, 66, 68,
    70, 72, 74, 76, 78,
    80, 82, 84, 86, 88,
    90, 92, 94, 96, 98
};

// подмножество чисел, первая цифра больше второй
set<int> greater_first_digit{
    10,
    20, 21,
    30, 31, 32,
    40, 41, 42, 43,
    50, 51, 52, 53, 54,
    60, 61, 62, 63, 64, 65,
    70, 71, 72, 73, 74, 75, 76,
    80, 81, 82, 83, 84, 85, 86, 87,
    90, 91, 92, 93, 94, 95, 96, 97, 98
};


// подмножество чисел, которые являются полиномами
set<int> equality_numbers{
    11, 22, 33, 
    44, 55, 66, 
    77, 88, 99
};

// подмножество чисел, которые содержат цифру 1
set<int> one_numbers{
    10, 11, 12, 13, 14, 15, 
    16, 17, 18, 19, 21, 31, 
    41, 51, 61, 71, 81, 91
};

// подмножество чисел, которые содержат цифру 2
set<int> two_numbers{
    12, 20, 21, 22, 23, 24, 
    25, 26, 27, 28, 29, 32, 
    42, 52, 62, 72, 82, 92
};

// подмножество чисел, которые содержат цифру 3
set<int> three_numbers{
    13, 23, 30, 31, 32, 33, 
    34, 35, 36, 37, 38, 39, 
    43, 53, 63, 73, 83, 93
};

// подмножество чисел, которые содержат цифру 4
set<int> four_numbers{
    14, 24, 34, 40, 41, 42, 
    43, 44, 45, 46, 47, 48, 
    49, 54, 64, 74, 84, 94
};

// подмножество чисел, которые содержат цифру 5
set<int> five_numbers{
    15, 25, 35, 45, 50, 51, 
    52, 53, 54, 55, 56, 57, 
    58, 59, 65, 75, 85, 95
};

// подмножество чисел, которые содержат цифру 6
set<int> six_numbers{
    16, 26, 36, 46, 56, 60, 
    61, 62, 63, 64, 65, 66, 
    67, 68, 69, 76, 86, 96
};

// подмножество чисел, которые содержат цифру 7
set<int> seven_numbers{
    17, 27, 37, 47, 57, 67, 
    70, 71, 72, 73, 74, 75, 
    76, 77, 78, 79, 87, 97
};

// подмножество чисел, которые содержат цифру 8
set<int> eight_numbers{
    18, 28, 38, 48, 58, 68, 
    78, 80, 81, 82, 83, 84, 
    85, 86, 87, 88, 89, 98
};

// подмножество чисел, которые содержат цифру 9
set<int> nine_numbers{
    19, 29, 39, 49, 59, 69, 
    79, 89, 90, 91, 92, 93, 
    94, 95, 96, 97, 98, 99
};

// подмножество чисел, которые содержат цифру 0
set<int> zero_numbers{
    10, 20, 30,
    40, 50, 60, 
    70, 80, 90
};

//защита ввода
bool answ() {
    string str;
    while (1) {
        cin >> str;
        if (str == "1") {
            return 1;
        }
        else if (str == "0") {
            return 0;
        }
        else {
            cout << endl << "Введите корректное значение (1 или 0): ";
        }
    }
}

//проверка на условие
set<int> get_set(set<int> number, int number_question, string str, set<int> n_condition) {

    set<int> condition_set;

    set_intersection(
        number.begin(), number.end(),
        n_condition.begin(), n_condition.end(),
        inserter(condition_set, condition_set.begin()));

    if (condition_set.empty() || number == condition_set) {
        return number;
    }

    bool answer = 0;
    cout << number_question << str;
    answer = answ();
    cout << endl;
    
    //вывод на ответ
    set<int> answer_set;

    if (answer) {
        //пересечение множеств
        set_intersection(
            number.begin(), number.end(),
            n_condition.begin(), n_condition.end(),
            inserter(answer_set, answer_set.begin()));
    }
    else {
        //разность множеств
        set_difference(
            number.begin(), number.end(),
            n_condition.begin(), n_condition.end(),
            inserter(answer_set, answer_set.begin()));
    }
    
    return answer_set;
}


//проверка на наличие в числе цифры
set<int> number_set(set<int> number, int number_question, int num, set<int> n_number) {

    set<int> condition_set;

    set_intersection(
        number.begin(), number.end(),
        n_number.begin(), n_number.end(),
        inserter(condition_set, condition_set.begin()));

    if (condition_set.empty() || number == condition_set) {
        return number;
    }

    bool answer = 0;
    cout << number_question << ". В вашем числе есть цифра " << num << "?: ";
    answer = answ();
    cout << endl;

    //вывод на ответ
    set<int> answer_set;

    if (answer) {
        //пересечение множеств
        set_intersection(
            number.begin(), number.end(),
            n_number.begin(), n_number.end(),
            inserter(answer_set, answer_set.begin()));
    }
    else {
        //разность множеств
        set_difference(
            number.begin(), number.end(),
            n_number.begin(), n_number.end(),
            inserter(answer_set, answer_set.begin()));
    }

    return answer_set;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    bool game = 1;
    
    while (game) {

        system("cls");

        //задаём множество для поиска числа 
        set<int> number = numbers;

        //задаём максимальное количество попросов
        vector<int> num_question = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

        //номер вопроса
        int number_question = 1;

        cout << "Зраствуйте, я попытаюсь угадать ваще число!!" << endl;
        cout << "Загадайте число в диапозонге от 10 до 99" << endl;
        cout << "Я буду задавать вопросы, отвечайте на них - 1(да) или 0(нет)" << endl;
        cout << "Начнём!" << endl << endl;

        //масимальное количество вопросов
        int i = num_question.size();
        while (number.size() > 1 && i != 0)
        {
            //определяем номер вопроса
            int question = rand() % i;

            set<int> new_number;

            switch (num_question[question])
            {
            case 1://проверка на четность
                new_number = get_set(number, number_question, ". Ваше число четное?: ", even_numbers);
                if (number != new_number) {
                    number_question++;
                }
                number = new_number;
                break;
            case 2://проверка на равенство двух цифр
                new_number = get_set(number, number_question, ". В вашем числе две одинаковые цифры?: ", equality_numbers);
                if (number != new_number) {
                    number_question++;
                }
                number = new_number;
                break;
            case 3://проверка есть ли число 1
                new_number = number_set(number, number_question, 1, one_numbers);
                if (number != new_number) {
                    number_question++;
                }
                number = new_number;
                break;
            case 4://проверка есть ли число 2
                new_number = number_set(number, number_question, 2, two_numbers);
                if (number != new_number) {
                    number_question++;
                }
                number = new_number;
                break;
            case 5://проверка есть ли число 3
                new_number = number_set(number, number_question, 3, three_numbers);
                if (number != new_number) {
                    number_question++;
                }
                number = new_number;
                break;
            case 6://проверка есть ли число 4
                new_number = number_set(number, number_question, 4, four_numbers);
                if (number != new_number) {
                    number_question++;
                }
                number = new_number;
                break;
            case 7://проверка есть ли число 5
                new_number = number_set(number, number_question, 5, five_numbers);
                if (number != new_number) {
                    number_question++;
                }
                number = new_number;
                break;
            case 8://проверка есть ли число 6
                new_number = number_set(number, number_question, 6, six_numbers);
                if (number != new_number) {
                    number_question++;
                }
                number = new_number;
                break;
            case 9://проверка есть ли число 7
                new_number = number_set(number, number_question, 7, seven_numbers);
                if (number != new_number) {
                    number_question++;
                }
                number = new_number;
                break;
            case 10://проверка есть ли число 8
                new_number = number_set(number, number_question, 8, eight_numbers);
                if (number != new_number) {
                    number_question++;
                }
                number = new_number;
                break;
            case 11://проверка есть ли число 9
                new_number = number_set(number, number_question, 9, nine_numbers);
                if (number != new_number) {
                    number_question++;
                }
                number = new_number;
                break;
            case 12://проверка есть ли число 0
                new_number = number_set(number, number_question, 0, zero_numbers);
                if (number != new_number) {
                    number_question++;
                }
                number = new_number;
                break;
            case 13://проверка больше ли первая цифра чем вторая
                new_number = get_set(number, number_question, ". В вашем числе первая цифра больше второй?: ", greater_first_digit);
                if (number != new_number) {
                    number_question++;
                }
                number = new_number;
                break;
            default:
                cout << "Произогла ошибка, мы обязательно её исправим." << endl;
                break;
            }

            //удаляем отработаный вопрос по индексу
            num_question.erase(num_question.begin() + question);
            //уменьшаем количетво незаданых вопросов
            i--;
            
        }

        if (number.empty()) {
            cout << "Вы отвечали не честно!!!" << endl << endl;
        }
        else {
            cout << "Ваше число " << *number.begin() << "?: ";
            bool answer;
            answer = answ();
            cout << endl << endl;

            if (answer) {
                cout << "Ура, я угадал ваше число. Это было просто!" << endl;
            }
            else {
                cout << "К сожелению я не смог угадать ваше число" << endl;
            }
        }
        cout << "Сыграем ещё раз?: ";
        game = answ();

    }
}