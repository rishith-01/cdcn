#include <iostream>
#include <string>
using namespace std;

// Sender: Bit Stuffing
string bit_stuff(string bits)
{
    string out = "";
    int count = 0;

    for (int i = 0; i < bits.length(); i++)
    {
        out += bits[i];

        if (bits[i] == '1')
        {
            count++;

            if (count == 5)
            {
                out += '0';
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    return "01111110" + out + "01111110";
}

// Receiver: Bit De-stuffing
string bit_destuff(string frame)
{
    string data = frame.substr(8, frame.length() - 16);

    string out = "";
    int count = 0;

    for (int i = 0; i < data.length(); i++)
    {
        out += data[i];

        if (data[i] == '1')
        {
            count++;

            if (count == 5)
            {
                i++; // Skip stuffed 0
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    return out;
}

int main()
{
    string bits;

    cout << "Enter bit string: ";
    cin >> bits;

    // Sender
    string frame = bit_stuff(bits);

    cout << "\nStuffed Frame: " << frame << endl;

    // Receiver
    string received = bit_destuff(frame);

    cout << "After De-stuffing: " << received << endl;

    return 0;
}
