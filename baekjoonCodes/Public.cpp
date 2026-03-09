#include <iostream>

int count = 0;

int main()
{
    int Input;
    std::cin >> Input;

    int First = Input;
    while(true)
    {
        if(Input < 10)
        {
            Input = Input * 10 + Input;
        }

        else
        {
            Input = (Input % 10) * 10 + (Input / 10 + Input % 10) % 10;
        }
        count++;

        if(First == Input)
            break;
    }
    std::cout << count << '\n';
}

