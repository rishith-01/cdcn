#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Sender: Character Stuffing
string character_stuff(string data)
{
    stringstream ss(data);
    string word;
    vector<string> out;

    while (ss >> word)
    {
        if (word == "FLAG" || word == "ESC")
        {
            out.push_back("ESC");
        }

        out.push_back(word);
    }

    string frame = "FLAG";

    for (int i = 0; i < out.size(); i++)
    {
        frame += " " + out[i];
    }

    frame += " FLAG";

    return frame;
}

// Receiver: Character De-stuffing
string character_destuff(string frame)
{
    stringstream ss(frame);
    string word;

    vector<string> words;

    // Read all words
    while (ss >> word)
    {
        words.push_back(word);
    }

    vector<string> out;

    // Skip starting and ending flags
    for (int i = 1; i < words.size() - 1; i++)
    {
        if (words[i] == "ESC")
        {
            i++;
        }

        out.push_back(words[i]);
    }

    string result = "";

    for (int i = 0; i < out.size(); i++)
    {
        if (i > 0)
            result += " ";

        result += out[i];
    }

    return result;
}

int main()
{
    string data;

    cout << "Enter data (words separated by space): ";
    getline(cin, data);

    // Sender
    string frame = character_stuff(data);

    cout << "\nStuffed Frame: " << frame << endl;

    // Receiver
    string received = character_destuff(frame);

    cout << "After De-stuffing: " << received << endl;

    return 0;
}
