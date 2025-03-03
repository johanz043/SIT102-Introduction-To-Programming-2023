#include "splashkit.h"
#include <string>


#define STROUHAL 3

//Calculate airspeed with frequency and amplitude
double calculate_air_speed(double freq, double amp)
{
    double result; 
    result = freq * amp * STROUHAL; 
    return result; 
}

//To output the air speed along with the bird name to the terminal
void output_air_speed(string bird_name, double freq, double amp)
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

//Reads doubles from users
double read_double(string prompt)
{
    string decimal;
    decimal = read_string(prompt);
    return convert_to_double(decimal);
}

//Calculates total weight
double calculate_total_weight(double userweight, double exampleweight)
{
double result;
result = userweight + exampleweight;
return result;
}

//Displays total weight
void output_total_weight(double total_weight, double userweight, double exampleweight)
{
    write("Total weight: ");
    write_line(calculate_total_weight(userweight, exampleweight));
}




int main()
{
   string name;
   int age;
   string bird_name;
   double freq;
   double amp;
   double userweight;
   double exampleweight;
   double total_weight;


   name = read_string("What is your name: ");
   age = read_integer("What is your age: ");
   bird_name = read_string("Bird's name: ");
   freq = read_double("Freq: ");
   amp = read_double("Amp: ");
   userweight = read_double("How much do you weigh in Kilograms?: ");
   exampleweight = read_double("Enter the weight of someone you know: ");




   write_line("");
   write("Hello, ");
   write_line(name + "!");
   write("Age: ");
   write_line(age);
   write("");
   write("Total weight: ");
   
   
   output_air_speed(bird_name, freq, amp);

   output_total_weight(total_weight, userweight, exampleweight);


   write_line("* End of Program *");

    return 0;
}


