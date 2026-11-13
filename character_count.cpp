#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Sender: Character Count
string character_count(vector<string> frames)
{
    string stream = "";

    for (int i = 0; i < frames.size(); i++)
    {
        stream += to_string(frames[i].length() + 1);
        stream += frames[i];
    }

    return stream;
}

// Receiver: Decode Character Count
vector<string> decode_character_count(string stream)
{
    vector<string> frames;
    int i = 0;

    while (i < stream.length())
    {
        int n = stream[i] - '0';

        frames.push_back(stream.substr(i + 1, n - 1));

        i += n;
    }

    return frames;
}

int main()
{
    vector<string> frames;
    string word;

    cout << "Enter number of frames: ";
    int n;
    cin >> n;

    cout << "Enter frames:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> word;
        frames.push_back(word);
    }

    // Sender
    string stream = character_count(frames);

    cout << "\nTransmitted Stream: " << stream << endl;

    // Receiver
    vector<string> received = decode_character_count(stream);

    cout << "Received Frames: ";

    for (int i = 0; i < received.size(); i++)
    {
        cout << received[i] << " ";
    }

    cout << endl;

    return 0;
}
