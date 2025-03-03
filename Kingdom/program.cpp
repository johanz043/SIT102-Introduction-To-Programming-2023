#include "splashkit.h"
#include <string>
#include <vector>

using std::vector;
using namespace std;


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


struct knight_data
{
    string name;
    int age;
};


struct kingdom_data
{
    string name;
    vector<knight_data> knights;
};





knight_data read_knight()
{
    knight_data result;
    
    result.name = read_string("Enter name: ");
    result.age = read_integer("Enter age: ");

    return result;
}


void write_knight(const knight_data &knight)
{
    write_line(knight.name + " aged " + to_string(knight.age));
}

enum knight_update_option
{
    UPDATE_NAME,
    UPDATE_AGE,
    FINISH_UPDATE
};

knight_update_option read_knight_update_option()
{
    int result;

    write_line("1: Update name");
    write_line("2: Update age");
    write_line("3: Finish update");

    result = read_integer("Select option: ");

    return static_cast<knight_update_option>(result - 1);
}


void update_knight(knight_data &knight)
{
    knight_update_option option;

    do
    {
        write_line();
        write_line("==Update Knight==");
        write_knight(knight);
        write_line();
        option = read_knight_update_option();

        switch(option)
        {
            case UPDATE_NAME:
                knight.name = read_string("Enter new name: ");
                break;
            case UPDATE_AGE:
                knight.age = read_integer("Enter new age: ");
                break;
            case FINISH_UPDATE:
                break;
            default:
                write_line("Please select a valid option");    
        }
    } while(option != FINISH_UPDATE);
} 



enum kingdom_update_option
{
    ADD_KNIGHT,
    QUERY_KNIGHT,
    UPDATE_KNIGHT,
    DELETE_KNIGHT,
    DISPLAY_KINGDOM
};

kingdom_update_option read_kingdom_update_option()
{
    int result;

    write_line("1: Add knight");
    write_line("2: Query knight");
    write_line("3: Update knight");
    write_line("4: Delete knight");
    write_line("5: Display kingdom");

    result = read_integer("Select option: ");

    return static_cast<kingdom_update_option>(result - 1);
}


void update_kingdom()
{
    kingdom_update_option option;

    do
    {
        option = read_kingdom_update_option();

        switch(option)
        {
            case ADD_KNIGHT:
                add_knight;
                break;
            case QUERY_KNIGHT:
                
                break;
            case DISPLAY_KINGDOM:
                write_kingdom;
                break;
            default:
                write_line("Please select a valid option");    
        }
    } while(option != FINISH_UPDATE);
} 





void add_knight(kingdom_data &kingdom)
{
knight_data new_knight;
new_knight = read_knight();

kingdom.knights.push_back(new_knight);
}



void delete_knight(kingdom_data &kingdom, int index)
{
    if (index <= 0 and index < kingdom.knights.size())
    {
        int last_idx;
        last_idx = kingdom.knights.size() - 1;
        kingdom.knights[index] = kingdom.knights[last_idx];
        kingdom.knights.pop_back();
    }
}



void write_kingdom(const kingdom_data &kingdom)
{
    write_line("==============");
    write_line(kingdom.name);
    write_line("==== Knights ====");
    for(int i = 0; i < kingdom.knights.size(); i++)
    {
        write_knight(kingdom.knights[i]);
    }
    write_line("==============");
}

kingdom_data read_kingdom()
{
    kingdom_data result;
    result.name = read_string("Enter kingdom name: ");
    return result;
}


int main()
{

    update_kingdom();

    return 0;
}