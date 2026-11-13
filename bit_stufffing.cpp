string bit_stuff_sender(string data)
{
    string stuffed;
    int ones = 0;

    for (int i = 0; i < data.size(); i++)
    {
        stuffed.push_back(data[i]);

        if (data[i] == '1')
        {
            ones++;

            if (ones == 5)
            {
                stuffed.push_back('0');
                ones = 0;
            }
        }
        else
        {
            ones = 0;
        }
    }

    return stuffed;
}
