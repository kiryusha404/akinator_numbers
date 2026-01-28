#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib> 
#include <ctime> 

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
    70, 80, 81, 82, 83, 84, 
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

//проверка на четность
set<int> even_set(set<int> number, int number_question) {
    bool answer = 0;
    cout << endl;
    cout << number_question << ". Ваше число четное?: ";
    cin >> answer;
    cout << endl << endl;
    
    //вывод на ответ
    set<int> answer_set;

    if (answer) {
        //пересечение множеств
        set_intersection(
            number.begin(), number.end(),
            even_numbers.begin(), even_numbers.end(),
            inserter(answer_set, answer_set.begin()));
    }
    else {
        //разность множеств
        set_difference(
            number.begin(), number.end(),
            even_numbers.begin(), even_numbers.end(),
            inserter(answer_set, answer_set.begin()));
    }
    
    return answer_set;
}

//проверка на равенство 2х цифр
set<int> equality_set(set<int> number, int number_question) {
    bool answer = 0;
    cout << endl;
    cout << number_question << ". В вашем числе две одинаковые цифры?: ";
    cin >> answer;
    cout << endl << endl;

    //вывод на ответ
    set<int> answer_set;

    if (answer) {
        //пересечение множеств
        set_intersection(
            number.begin(), number.end(),
            equality_numbers.begin(), equality_numbers.end(),
            inserter(answer_set, answer_set.begin()));
    }
    else {
        //разность множеств
        set_difference(
            number.begin(), number.end(),
            equality_numbers.begin(), equality_numbers.end(),
            inserter(answer_set, answer_set.begin()));
    }

    return answer_set;
}

//проверка на наличие в числе цифры
set<int> number_set(set<int> number, int number_question, int num, set<int> n_number) {
    bool answer = 0;
    cout << endl;
    cout << number_question << ". В вашем числе есть цифра " << num << "?: ";
    cin >> answer;
    cout << endl << endl;

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
        vector<int> num_question = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

        //номер вопроса
        int number_question = 1;

        cout << "Зраствуйте, я попытаюсь угадать ваще число!!" << endl;
        cout << "Загадайте число в диапозонге от 10 до 99" << endl;
        cout << "Я буду задавать вопросы, отвечайте на них - 1(да) или 0(нет)" << endl;
        cout << "Начнём!" << endl;

        //масимальное количество вопросов
        int i = num_question.size();
        while (number.size() > 1 && i != 0)
        {
            //определяем номер вопроса
            int question = rand() % i;

            switch (num_question[question])
            {
            case 1://проверка на четность
                number = even_set(number, number_question);
                break;
            case 2://проверка на равенство двух цифр
                number = equality_set(number, number_question);
                break;
            case 3://проверка есть ли число 1
                number = number_set(number, number_question, 1, one_numbers);
                break;
            case 4://проверка есть ли число 2
                number = number_set(number, number_question, 2, two_numbers);
                break;
            case 5://проверка есть ли число 3
                number = number_set(number, number_question, 3, three_numbers);
                break;
            case 6://проверка есть ли число 4
                number = number_set(number, number_question, 4, four_numbers);
                break;
            case 7://проверка есть ли число 5
                number = number_set(number, number_question, 5, five_numbers);
                break;
            case 8://проверка есть ли число 6
                number = number_set(number, number_question, 6, six_numbers);
                break;
            case 9://проверка есть ли число 7
                number = number_set(number, number_question, 7, seven_numbers);
                break;
            case 10://проверка есть ли число 8
                number = number_set(number, number_question, 8, eight_numbers);
                break;
            case 11://проверка есть ли число 9
                number = number_set(number, number_question, 9, nine_numbers);
                break;
            case 12://проверка есть ли число 0
                number = number_set(number, number_question, 0, zero_numbers);
                break;
            default:
                
                break;
            }

            //удаляем отработаный вопрос по индексу
            num_question.erase(num_question.begin() + question);
            //уменьшаем количетво незаданых вопросов
            i--;
            //увеличиваем номер вопроса
            number_question++;
        }

        cout << "Ваше число: " << *number.begin() << "?: ";
        bool answer;
        cin >> answer;
        cout << endl << endl;
        if (answer) {
            cout << "Ура, я угадал ваше число. Это было просто!" << endl;
        }
        else {
            cout << "К сожелению я не смог угадать ваше число" << endl;
        }
        cout << "Сыграем ещё раз?: ";
        cin >> game;

    }
}