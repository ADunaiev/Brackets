#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

//Задание 1.
//Есть строка символов, признаком конца, которой является
//«; ».В строке могут быть фигурные, круглые, квадратные
//скобки.Скобки могут быть открывающими и закрывающими.
//Необходимо проверить корректность расстановки скобок.
//При этом необходимо, чтобы выполнились следующие
//правила :
//1. Каждая открывающая скобка должна иметь справа такую
//же закрывающую.Обратное также должно быть верно.
//2. Открывающие и закрывающие пары скобок разных
//типов должны быть правильно расположены по отношению друг к другу.
//■ Пример правильной строки : ({ x - y - z }*[x + 2y] - (z + 4x));
//■ Пример неправильной строки : ([x - y - z}*[x + 2y) - {z + 4x)].
//Если все правила соблюдены выведите информационное
//сообщение о корректности строки, иначе покажите строку
//до места возникновения первой ошибки.

class Stack
{
    //Нижняя и верхняя границы стека
    enum { END = ';'};
    string open_Bracket{ "({[" };
    string close_Bracket{ ")}]" };
    const int Max_Len = 256;
    //Массив для хранения данных
    string str;
    //Указатель на вершину стека
    int top;
public:
    //Конструктор
    Stack();
    Stack(string strP);
    //Добавление элемента
    void Push(char c);
    //Извлечение элемента
    void Pop();
    //Очистка стека
    void Clear();
    //Проверка существования элементов в стеке
    bool IsEmpty();
    //Проверка на переполнение стека
    bool IsFull();
    //Количество элементов в стеке
    int GetCount();
    void Check_String() const;
    void show() const;
};

Stack::Stack()
{
    //Изначально стек пуст
    str = nullptr;
    top = 0;
}

Stack::Stack(string strP)
{
    //Изначально стек пуст
    top = strP.length() + 1;
    str = strP;
 
}

void Stack::Clear()
{
    str = nullptr;
    top = 0;
}

bool Stack::IsEmpty()
{
    return top == 0;
}

bool Stack::IsFull()
{
    return top == Max_Len-1;
}
    
int Stack::GetCount()
{
     return top + 1;
}
    
void Stack::Push(char c)
{
    if (top < Max_Len -1)
        str[++top] = c;
}
    
void Stack::Pop()    
{ 
    //верхний и уменьшаем указатель на вершину стека 
    if (!IsEmpty())
    {
        str.pop_back();
        top--;
    }

}

void Stack::Check_String() const
{
    string temp, temp_brackets;

    for (size_t i = 0; i < top; i++)
    {
        if (str[i] == END)
        {

            if (temp_brackets.empty())
            {
                cout << str << endl;
                cout << "The stirg is correct!" << endl;
            }
            else
            {
                cout << temp << endl;
                cout << "The string is not correct!" << endl;
                exit(0);
            }
        }
        else
        {
            if (open_Bracket.find(str[i]) != string::npos)
                temp_brackets.push_back(str[i]);

            if (close_Bracket.find(str[i]) == string::npos)
                temp.push_back(str[i]);
            else
            {
                if (!temp_brackets.empty())
                {
                    int a = open_Bracket.find(temp_brackets[temp_brackets.length() - 1]);
                    int b = close_Bracket.find(str[i]);

                    if (a == b)
                    {
                        temp_brackets.pop_back();
                        temp.push_back(str[i]);
                    }
                    else
                    {
                        cout << temp << endl;
                        cout << "The string is not correct!" << endl;
                        exit(0);
                    }
                }
                else
                {
                    cout << temp << endl;
                    cout << "The string is not correct!" << endl;
                    exit(0);
                }

            }

        }
    }

    if (str.find(END) == string::npos)
        cout << str << endl <<
        "Error. There is no end of the string!" << endl;
}

void Stack::show() const
{
    cout << str << endl;
}
    
void main()
{
    
    Stack st1{ "({x - y - z}*[x + 2y] - (z + 4x));" };
    st1.show();
    Stack st2{ "([x - y - z }*[x + 2y) - {z + 4x)];" };
    st2.show();
    Stack st3{ "({x - y - z}*[x + 2y] - (z + 4x))" };
    st3.show();

    cout << endl;

    st1.Check_String();
    cout << endl;

    st2.Check_String();
    cout << endl;

    st3.Check_String();

    cout << "\n";
 
}