#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

string itoa(int input);
float RandomFloat(float a, float b);

int main()
{
    int coffee_genre = 0;


    cout << "How many coffee genre would you like to test?" << endl;
    cin >> coffee_genre;

    srand(time(NULL));

    int sugar_start = 0;
    int sugar_end = 0;
    int milk_start = 0;
    int milk_end = 0;

    for (int i = 0; i < coffee_genre; i++)
    {
        cout << "Please enter the sugar start range (0 to 10) for Genre " << i + 1 << ":" << endl;
        cin >> sugar_start;
        cout << "Please enter the sugar end range (0 to 10) for Genre " << i + 1 << ":" << endl;
        cin >> sugar_end;
        cout << "Please enter the milk start range (0 to 10) for Genre " << i + 1 << ":" << endl;
        cin >> milk_start;
        cout << "Please enter the milk end range (0 to 10) for Genre " << i + 1 << ":" << endl;
        cin >> milk_end;
        string genre_name = "coffee_genre_" + itoa(i + 1) + ".svm";
        ofstream genre_output(genre_name.c_str());
        for (int j = 0; j < 1000; j++)
        {
            float sugar = RandomFloat((float)sugar_start, (float)sugar_end) / 10;
            float milk = RandomFloat((float)milk_start, (float)milk_end) / 10;
            genre_output << "+" << itoa(i + 1) << " " << "1:" << sugar << " 2:" << milk << endl;
        }
    }

}

string itoa(int input)
{
    stringstream ss;
    ss << input;
    string str = ss.str();
    return str;
}

float RandomFloat(float a, float b)
{
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}
