#include "splashkit.h"
#include <string>


#define STROUHAL 3

//Calculate airspeed with frequency and amplitude
double calculate_air_speed(int freq, int amp)
{
    double result; 
    result = freq * amp * STROUHAL; 
    return result; 
}

//To output the air speed along with the bird name to the terminal
void output_air_speed(string bird_name, int freq, int amp)
{
    write(bird_name + ": ");
    write_line(calculate_air_speed(freq, amp));
}

//To read string from the user
string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

//To read integers from the user
int read_integer(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}


int main()
{
   string name;
   int age;
   string bird_name;
   int freq;
   int amp;


   name = read_string("What is your name: ");
   age = read_integer("What is your age: ");
   bird_name = read_string("Bird's name: ");
   freq = read_integer("Freq: ");
   amp = read_integer("Amp: ");



   write_line("");
   write("Hello, ");
   write_line(name + "!");
   write("Age: ");
   write_line(age);


   output_air_speed(bird_name, freq, amp);


   write_line("* End of Program *");

    return 0;
}

