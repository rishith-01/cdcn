
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;

#define FLAG 0x7E
#define ESC 0x7D

// Sender: Character Stuffing
vector<unsigned char> char_stuff_sender(vector<unsigned char> data)
{
    vector<unsigned char> stuffed;

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == FLAG || data[i] == ESC)
        {
            stuffed.push_back(ESC);
            stuffed.push_back(data[i] ^ 0x20);
        }
        else
        {
            stuffed.push_back(data[i]);
        }
    }

    return stuffed;
}

// Receiver: Character De-stuffing
vector<unsigned char> char_stuff_receiver(vector<unsigned char> stuffed)
{
    vector<unsigned char> data;

    for (int i = 0; i < stuffed.size(); i++)
    {
        if (stuffed[i] == ESC)
        {
            i++;
            data.push_back(stuffed[i] ^ 0x20);
        }
        else
        {
            data.push_back(stuffed[i]);
        }
    }

    return data;
}

// Display data in hexadecimal
void print_bytes(vector<unsigned char> data, string label)
{
    cout << label;

    for (int i = 0; i < data.size(); i++)
    {
        cout << hex << uppercase << setw(2) << setfill('0')
             << (int)data[i] << " ";
    }

    cout << dec << endl;
}

int main()
{
    vector<unsigned char> original =
    {
        0x01, 0x7E, 0x02, 0x7D, 0x03, 0x7E, 0x04
    };

    print_bytes(original, "Original Data: ");

    vector<unsigned char> stuffed = char_stuff_sender(original);

    print_bytes(stuffed, "After Stuffing: ");

    vector<unsigned char> recovered = char_stuff_receiver(stuffed);

    print_bytes(recovered, "After Unstuffing: ");

    if (original == recovered)
    {
        cout << "SUCCESS: Original data recovered!" << endl;
    }
    else
    {
        cout << "ERROR: Data mismatch!" << endl;
    }

    return 0;
}
