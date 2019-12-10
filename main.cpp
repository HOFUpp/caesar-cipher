//Caesar-cipher.cpp
#include <iostream>
#include <string>
using namespace std;

//this is the message struct
struct message
{
    private:
        string input;
        int key;
    public:
        void enter();
        void encrypt();
        void decrypt();
        void show();
};

void message::enter()
{
    cout << "Enter the message that you wish to encrypt: ";
    //getline is used to recive more than a word from the user
    cin.ignore();
    getline(cin, input);
    do {
        cout << "Enter the encrypting key(1-25): ";
        cin >> key;
    } while(key < 0 || key > 25);
}

//the folowing code is used to encrypt the message
void message::encrypt()
{
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z' - key || input[i] >= 'A' && input[i] <= 'Z' - key) input[i] = input[i] + key;
        else if (input[i] >= 'z' - (key - 1) && input[i] <= 'z' || input[i] >= 'Z' - (key - 1) && input[i] <= 'Z') input[i] = input[i] - (26 - key);
    }
}

void message::decrypt()
{
    string doutput;

    cout << "Enter the message that you wish to decrypt: ";
    cin.ignore();
    getline(cin, input);

    doutput = input;

    for (int dkey = 1; dkey <= 25; dkey++)
    {
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] >= 'a' + dkey && input[i] <= 'z' || input[i] >= 'A' + dkey && input[i] <= 'Z') doutput[i] = input[i] - dkey;
            else if (input[i] >= 'a' && input[i] <= 'a' +(dkey -1) || input[i] >= 'A' && input[i] <= 'A' +(dkey -1)) doutput[i] = input[i] + (26 - dkey);
        }
        cout << dkey << "\t:" << doutput << endl;
    }
}

void message::show()
{
    cout << "The encrypted message: " << input << endl;
}

int main()
{
    message m1;
    char ext;
    int resp;

    while(true)
    {
        do {
            cout << "do you wish to decrypt(0) or to encrypt(1) a message? ";
            cin >> resp;
        } while(resp != 0 && resp != 1);
        
        if (resp == 0) {
            m1.decrypt();
        } else {
            m1.enter();
            m1.encrypt();
            m1.show();
        }

        do {
            cout << endl << "Do You wish to decrypt/encrypt another message(Y/N)? ";
            cin >> ext;
        } while(ext != 'y' && ext != 'Y' && ext != 'n' && ext != 'N');
        if (ext == 'n' || ext == 'N') return 0;
        cout << endl;
    }

    return 0;
}