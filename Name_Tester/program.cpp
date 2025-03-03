#include "splashkit.h"


//Reads string from the user
string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}


//Checks the name inputted and displays a custom message
void name_tester()
{
    string name;

    name = read_string("What is your name: ");

    write_line("Hello " + name);

    if (to_uppercase(name) == "JOHANZ")
    {
    write("Hello cutie <3");
    }
    else if (to_uppercase(name) == "JOSH")
    {
    write("How are you?");
    }
    else if (to_uppercase(name) == "PETER")
    {
    write("What are you doing?");
    }
    else if (to_uppercase(name) == "GLORY")
    {
    write("Please give me an extension");
    }
    else if (to_uppercase(name) == "BEN")
    {
    write("Hi sir");
    }
    else
    {
    write("Do I know you?");
    }
}


void guessing_game()
{
    string line;
    int guess;
    int target;

    target = rnd(100) + 1;

    write_line("Guess a number between 1 and 100");

while (guess != target)
{
    write("Enter guess: ");
    line = read_line();

    guess = convert_to_integer(line);


    if (guess < target)
    {
        write_line("Guess higher");
    }
    else if (guess > target)
    {
        write_line("Guess lower");
    }

}

  write_line("You guessed correct :)");

}


int main()
{
string line;
int option;

write_line("Choose from the menu: ");
write_line("1: Custom messages ");
write_line("2: Guessing game ");

write("Choose option: ");
line = read_line();
option = convert_to_integer(line);


switch(option)
{
    case 1:
        name_tester();
        break;
    case 2:
        guessing_game();
        break;
    default:
        write_line("Choose the numbers from the menu");
}

    return 0;
}