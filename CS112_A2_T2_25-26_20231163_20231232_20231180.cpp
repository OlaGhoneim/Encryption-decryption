// Purpose: The program is for encryption and decryption, it includes 3 types of Cipher
// Author1: ola Ghoneim Hammad Ahmed Salama – Atbash Cipher
// Email: olaghoneim38@gmail.com 
// Author2: Mariem Refaey Abd El-Manaf Ahmed 3 – Vignere Cipher
// Email: refaeymariem@gmail.com 
// Author3: Menna Mohamed Ashour 
// Email: mm1881569@gmail.com 

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cstdlib>
#include <stdexcept>
#include <limits>
using namespace std;

void Cipher_3(string msg,string keyword);
void Decipher_3(string encrypted_msg, string keyword);
void Vignere_Cipher();
void decipher_a();
void cipher_a();
void Atbash();
void test(int a, int b, int x,int e, int temp,const vector<char>& characters);
void cipher0 ( int a, int b, string word);
void EQUATION(int c, int b, int y,int d, int temp ,const vector<char>& characters);
void decipher(int c,int b ,string word);
void main0();

int main() 
{
    bool validInput = false;
    int choice;
    int close;

    while (true)
    {
        cout << "Welcome to Cipher programs" << endl;
        cout << "Please select an option" << endl;
        cout << "1 > Vignere Cipher" << endl;
        cout << "2 > Abtash Cipher" << endl;
        cout << "3 > Affine Cipher" << endl;
        cout << "4 > End" << endl;

        while (!validInput) 
        {
            try 
                {
                    cin >> choice;
                    if (cin.fail() || choice < 1 || choice > 4) 
                    {
                        throw invalid_argument("Invalid input: Please choose a valid option");
                    }          
                    validInput = true;
                } 
              
                catch (const invalid_argument& e) 
                {
                    cerr << e.what() << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            validInput = false;

            if (choice == 1)
            { 
                Vignere_Cipher();
            }
            else if (choice == 2)
            {
                Atbash();
            }
            else if (choice == 3)
            {
                main0();
            }
            else if ( choice == 4)    
            {
                cout << "----------END PROGRAM----------" << endl;
                break;
            }

            cout << "Do you want to end Cipher programs?" << endl;
            cout << "1 > End" << endl;
            cout << "2 > continue" << endl;

            while (!validInput) 
            {
                try 
                {
                    cin >> close;
                    if (cin.fail() || close < 1 || close > 2) 
                    {
                        throw invalid_argument("Invalid input: Please choose a valid option");
                    }          
                    validInput = true;
                } 
              
                catch (const invalid_argument& e) 
                {
                    cerr << e.what() << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            validInput = false;
          
            if (close == 1)
            {
                cout << "----------END PROGRAM----------" << endl;
                break;
            }
            else
            {
                cout << "-------------------------------------------------------------" << endl;
                cout << endl;
            }
        } 

    return 0;
}

void Cipher_3(string msg,string keyword)
{
    bool found = false;
    int change = 0;
    char s = ' '; 

    cout << "Welcome to Vignere Cipher program" << endl;
    cout << "This is the encryption version" << endl;
    cout << "Cipher algorithms are very important to encrypt private data and protect them from hackers" << endl;
    cout << "In this method, a keyword is repeatedly added character by character to each alphabetic letter in the original message" << endl;
    cout << "The addition is carried out using the ASCII codes for each of the characters, modulo 26 (the number of letters in the alphabet)" << endl;
    cout << "and the result is added to the code for the letter 'A' in the ASCII code sequence" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << "Please enter the message you want to encrypt" << endl;
    getline(cin, msg);
    getline(cin, msg);
  
    //This loop checks whether the message size is valid or not
    while (msg.size() > 80)
    {
        cout << "Message should be restricted to 80 characters, please enter another message" << endl;
        getline(cin, msg);
        getline(cin, msg);
    }

    cout << "Please enter a keyword" << endl;
    cin >> keyword;

    //This loop checks whether the keyword size is valid or not
    while (keyword.size() > 8)
    {
        cout << "keyword should be restricted to 8 characters, please enter another keyword" << endl;
        cin >> keyword;
    }

    //This loop checks whether the keyword characters are valid or not
    for (int i = 0; i < keyword.size(); i++)
    {
        if (isalpha(keyword[i]))
        {
            found = false;
        }
        else
        {
            found = true;
            cout << "keyword should be only alphabetic characters" << endl;
            break;
        }
    }     

    //This loop makes the user enter a valid keyword
    while (found)
    {
        cout << "Please enter another keyword" << endl;
        cin >> keyword;

        //This loop checks whether the keyword characters are valid or not
        for (int i = 0; i < keyword.size(); i++)
        {
            if (isalpha(keyword[i]))
            {
                found = false;
            }
            else
            {
                found = true;
                cout << "keyword should be only alphabetic characters" << endl;
                break;
            }
        }  

        //This loop checks whether the keyword size is valid or not
        while (keyword.size() > 8)
        {
            cout << "keyword should be restricted to 8 characters, please enter another keyword" << endl;
            cin >> keyword;
        }
    }

    //This loop makes the letters of the message uppercase
    for (int i = 0; i < msg.size(); i++)
    {
        msg[i] = toupper(msg[i]);
    }

    //This loop makes the letters of the keyword uppercase
    for (int i = 0; i < keyword.size(); i++)
    {
        keyword[i] = toupper(keyword[i]);
    }

    //If statement and loop to make the keyword size equal to the message size
    if (msg.size() > keyword.size())
    {
        for (int i = 0; i < msg.size(); i++)
        {
            if (msg.size() >= keyword.size())
            {
                keyword += keyword[i];
            }
                
            if (msg.size() == keyword.size())
            {
                break;
            }
        }
    }

    char encrypted_msg[msg.size()];

    //This loop is used to encrypt the message
    for (int i = 0; i < msg.size(); i++)
    {
        if (int(msg[i]) > 90 || int(msg[i]) < 65)
        {
            encrypted_msg[i] = msg[i];
        }
        else
        {
            change = ((int(msg[i]) + int(keyword[i])) % 26) + 65;
            s = change;
            encrypted_msg[i] = s;
        }
    }
    
    cout << "Encrypted Message: ";
    for (int i = 0; i < msg.size(); i++)
    {
        cout << encrypted_msg[i];
    }
    cout << endl;
    cout << "=============================================================" << endl;
    cout << endl;

}

void Decipher_3(string encrypted_msg, string keyword)
{
    bool found = false;
    int change = 0;
    char s = ' ';

    cout << "Welcome to Vignere Cipher program" << endl;
    cout << "This is the decryption version" << endl;
    cout << "Cipher algorithms are very important to protect them from hackers" << endl;
    cout << "In this method, an encrypted message is repeatedly subtracted character by character for each letter of the alphabet letter in the keyword" << endl;
    cout << "The Subtraction is carried out using the ASCII codes for each of the characters, and then we add to the result of the subtraction 26" << endl;
    cout << "then modulo 26, and the result is added to the code for the letter 'A' in the ASCII code sequence" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << "Please enter the encrypted message you want to decrypt" << endl;
    getline(cin, encrypted_msg);
    getline(cin, encrypted_msg);
  
    //This loop checks whether the encrypted message size is valid or not
    while (encrypted_msg.size() > 80)
    {
        cout << "Message should be restricted to 80 characters, please enter another encrypted message" << endl;
        getline(cin, encrypted_msg);
        getline(cin, encrypted_msg);
    }

    cout << "Please enter a keyword" << endl;
    cin >> keyword;

    //This loop checks whether the keyword size is valid or not
    while (keyword.size() > 8)
    {
        cout << "keyword should be restricted to 8 characters, please enter another keyword" << endl;
        cin >> keyword;
    }

    //This loop checks whether the keyword characters are valid or not
    for (int i = 0; i < keyword.size(); i++)
    {
        if (isalpha(keyword[i]))
        {
            found = false;
        }
        else
        {
            found = true;
            cout << "keyword should be only alphabetic characters" << endl;
            break;
        }
    }     

    //This loop makes the user enter a valid keyword
    while (found)
    {
        cout << "Please enter another keyword" << endl;
        cin >> keyword;

        //This loop checks whether the keyword characters are valid or not
        for (int i = 0; i < keyword.size(); i++)
        {
            if (isalpha(keyword[i]))
            {
                found = false;
            }
            else
            {
                found = true;
                cout << "keyword should be only alphabetic characters" << endl;
                break;
            }
        }  
        
        //This loop checks whether the keyword size is valid or not
        while (keyword.size() > 8)
        {
            cout << "keyword should be restricted to 8 characters, please enter another keyword" << endl;
            cin >> keyword;
        }
    }
 
    //This loop makes the letters of the encrypted message uppercase
    for (int i = 0; i < encrypted_msg.size(); i++)
    {
        encrypted_msg[i] = toupper(encrypted_msg[i]);
    }

    //This loop makes the letters of the keyword uppercase
    for (int i = 0; i < keyword.size(); i++)
    {
        keyword[i] = toupper(keyword[i]);
    }

    //If statement and loop to make the keyword size equal to the encrypted message size
    if (encrypted_msg.size() > keyword.size())
    {
        for (int i = 0; i < encrypted_msg.size(); i++)
        {
            if (encrypted_msg.size() >= keyword.size())
            {
                keyword += keyword[i];
            }
                
            if (encrypted_msg.size() == keyword.size())
            {
                break;
            }
        }
    }

    char msg[encrypted_msg.size()];
 
    //This loop is used to decrypt the encrypted message
    for (int i = 0; i < encrypted_msg.size(); i++)
    {
        if (int(encrypted_msg[i]) > 90 || int(encrypted_msg[i]) < 65)
        {
            msg[i] = encrypted_msg[i];
        }
        else
        {
            change = (((int(encrypted_msg[i]) - int(keyword[i])) + 26) % 26) + 65;
            s = change;
            msg[i] = s;
        }
    }
    
    cout << "Message: ";
    for (int i = 0; i < encrypted_msg.size(); i++)
    {
        cout << msg[i];
    }
    cout << endl;
    cout << "=============================================================" << endl;
    cout << endl;

}

void Vignere_Cipher()
{
    string msg;
    string keyword;
    string encrypted_msg;
    bool  validInput = false;
    int option;
    int end;

    while (true)
    {    
        cout << "Welcome to Vignere Cipher program" << endl;
        cout << "This program has two options for encryption and decryption" << endl;
        cout << "Please select an option" << endl;
        cout << "1 > Cipher a message" << endl;
        cout << "2 > Decipher a message" << endl;
        cout << "3 > End" << endl;

        while (!validInput) 
        {
            try 
            {
                cin >> option;
                if (cin.fail() || option < 1 || option > 3) 
                {
                    throw invalid_argument("Invalid input: Please choose a valid option");
                }          
                validInput = true;
            } 
            
            catch (const invalid_argument& e) 
            {
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        validInput = false;

        if (option == 1)
        { 
            Cipher_3(msg, keyword);
        }
        else if (option == 2)
        {
            Decipher_3(encrypted_msg, keyword);
        }
        else if ( option == 3)    
        {
            cout << "----------END PROGRAM----------" << endl;
            break;
        }

        cout << "Do you want to end Vignere Cipher program?" << endl;
        cout << "1 > End" << endl;
        cout << "2 > continue" << endl;

        while (!validInput) 
        {
            try 
            {
                cin >> end;
                if (cin.fail() || end < 1 || end > 2) 
                {
                    throw invalid_argument("Invalid input: Please choose a valid option");
                }          
                validInput = true;
            } 
            
            catch (const invalid_argument& e) 
            {
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        validInput = false;
        
        if (end == 1)
        {
            cout << "----------END PROGRAM----------" << endl;
            break;
        }
        else
        {
            cout << "-------------------------------------------------------------" << endl;
            cout << endl;
        }
    } 

}

//fn for program Atbash
void Atbash() 
{
    cout << "Welcome to Abtash Cipher" << "\n";

    while (true) {
        char s;

        cout << "A)decipher B)cipher " << "\n";
        cin >> s;
        s = toupper(s);
        cin.ignore();
        if (s == 'A') {
            decipher_a();

        } else if (s == 'B') {
            cipher_a();
        } else {
            cout << "invalid!";
            continue;
        }

        break;
    }
}

//fn for decryption in atbash cipher
void decipher_a() 
{
    cout << "Enter the message:";
    string txt;
    getline(cin, txt);

    transform(txt.begin(), txt.end(), txt.begin(),
              ::toupper);
    // Convert the input to uppercase
    char div;// Variable to store the version choice
    while (true) {
// Loop until a valid version is selected
        cout << "1)version(1)  2)version(2)" << "\n";
        cin >> div;
        if (div == '1') {
            string plain = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            string cipher = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

            for (int j = 0; j < txt.size(); j++) {
                for (int i = 0; i < plain.size(); i++) {
                    if (txt[j] == cipher[i]) {
                        cout << plain[i];
                        break;
                    } else
                        continue;
                }
            }
            cout << "\n";
        } else if (div == '2') {
            string a = "ABCDEFGHIJKLM";
            string b = "NOPQRSTUVWXYZ";
            for (int j = 0; j < txt.size(); j++) {
                for (int i = 0; i < a.size(); i++) {

                    if (txt[j] == b[i]) {
                        cout << b[(a.size() - 1) - i];
                        break;
                    }
                    if (txt[j] == a[i]) {
                        cout << a[(a.size() - 1) - i];
                        break;
                    } else
                        continue;

                }
            }
            cout << "\n";
        } else {
            cout << "invalid input" << "\n";
            continue;
        }
        break;
    }
}

//fn for encryption in atbash cipher
void cipher_a() 
{
    cout << "Enter the message:";
    string txt;
    getline(cin, txt);
    transform(txt.begin(), txt.end(), txt.begin(), ::toupper);

    char div;
    while (true) {

        cout << "1)version(1)  2)verision(2)" << "\n";
        cin >> div;
        if (div == '1') {
            string plain = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            string cipher = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

            for (int j = 0; j < txt.size(); j++) {
                for (int i = 0; i < plain.size(); i++) {

                    if (txt[j] == plain[i]) {
                        cout << cipher[i];
                        break;
                    } else
                        continue;


                }
            }
            cout << "\n";
        } else if (div == '2') {

            string a = "ABCDEFGHIJKLM";
            string b = "NOPQRSTUVWXYZ";
            for (int j = 0; j < txt.size(); j++) {
                for (int i = 0; i < a.size(); i++) {

                    if (txt[j] == b[i]) {
                        cout << b[(a.size() - 1) - i];
                        break;
                    }
                    if (txt[j] == a[i]) {
                        cout << a[(a.size() - 1) - i];
                        break;
                    } else
                        continue;

                }
            }
            cout << "\n";

        } else {
            cout << "invalid input" << "\n";
            continue;
        }

        break;
    }
}

#include <iostream>
#include<vector>
#include<limits>
#include<cstdlib>
using namespace std;
void test(int a, int b, int x,int e, int temp,const vector<char>& characters)//this function to compute equation that convert letter
{
  string cipher;
  e=((a*x)+b);
    if (e>25)
    {
      temp=e%26;
      cipher=cipher+characters.at(temp); 
               
    }else{
      temp=e;
      cipher=cipher+characters.at(temp);//to collect all letters in one string
    } 
  cout<<cipher;
}
void cipher0 ( int a, int b, string word)
{
  cout<<"welcome to our programm"<<endl;//print welcome message
  int e,x,temp;
  string cipher;
  vector<char> characters={'A','B','C','D' ,'E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};// all letters to define his index
  cout<<"please enter the key a, b :";// enter factors of equation
  bool validinput=false;
  while (!validinput)
  {
    try
    {
      cin>>a;
      if (cin.fail() || a<=0)
      {
        throw invalid_argument("invalid input:please enter a valid number that is positive integer");
      }
      cin>>b;
      if (cin.fail() || b<=0)
      {
        throw invalid_argument("invalid input:please enter a valid number that is positive integer");
      }
      validinput=true;
    }
    catch(const invalid_argument& e)
    {
      std::cerr << e.what() << '\n';
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
  }validinput=false;
  cin.ignore();
  cout<<"enter your word:";
  bool found;
  getline(cin,word);
  for (int i = 0; i < word.length(); i++)
  {
    if (isalpha(word[i])||isspace(word[i]))
    {
      found=false;
    }else{
      found=true;
      cout<<"word should be contain only alphabetic characters";
      break;
    }
  }
  while (found)
  {
    cout<<"please enter anther word";
    getline(cin,word);
    for (int i = 0; i < word.length(); i++)
    {
      if (isalpha(word[i])||isspace(word[i]))
      {
        found=false;
      }else{
        found=true;
        cout<<"word should be contain only alphabetic characters";
        break;
      }
    }
  } 
  for (int i= 0; i <word.length(); i++)// to make all letter capital when user enter small letters
  {
    word[i]=toupper(word[i]);
  }
  for(char i:word)// make loop on each character to convert it
  { 
    if(i=='A'){
      x=0;
      test(a, b, x, e ,temp, characters);   
    } 
    else if (i=='B')
    {
        x=1;
        test(a, b, x, e,temp,characters);
    }else if (i=='C')
    {
        x=2;
        test(a, b, x, e,temp,characters);
    }else if (i=='D')
    {
        x=3;
        test(a, b, x, e,temp, characters);

    }else if (i=='E')
    {
        x=4;
        test(a, b, x, e,temp,characters);
    }else if (i=='F')
    {
        x=5;
        test(a, b, x, e, temp,characters);
    }else if (i=='G')
    {
        x=6;
        test(a, b, x, e,temp ,characters);
    }else if (i=='H')
    {
        x=7;
        test(a, b, x, e, temp,characters);
    }else if (i=='I')
    {
        x=8;
        test(a, b, x,e,temp, characters);
    }else if (i=='J')
    {
        x=9;
        test(a, b, x, e, temp,characters);
    }else if (i=='K')
    {
        x=10;
        test(a, b, x, e, temp,characters);
    }else if (i=='L')
    {
        x=11;
        test(a, b, x, e,temp,characters);
    }else if (i=='M')
    {
        x=12;
        test(a, b, x, e, temp,characters);
    }else if (i=='N')
    {
        x=13;
        test(a, b, x, e,temp, characters);
    }else if (i=='O')
    {
        x=14;
        test(a, b, x, e,temp ,characters);
    }else if (i=='P')
    {
        x=15;
        test(a, b, x,e,temp, characters);
    }else if (i=='Q')
    {
        x=16;
        test(a, b, x, e, temp ,characters);
    }else if (i=='R')
    {
        x=17;
        test(a, b, x, e, temp, characters);
    }else if (i=='S')
    {
        x=18;
        test(a, b, x, e,temp,characters);
    }else if (i=='T')
    {
        x=19;
        test(a, b, x, e, temp, characters);
    }else if (i=='U')
    {
        x=20;
        test(a, b, x, e,temp ,characters);
    }else if (i=='V')
    {
        x=21;
        test(a, b, x, e,temp, characters);
    }else if (i=='W')
    {
        x=22;
        test(a, b, x, e,temp, characters);
    }else if (i=='X')
    {
        x=23;
        test(a, b, x,e ,temp, characters);
    }else if (i=='Y')
    {
        x=24;
        test(a, b, x, e,temp, characters);
    }else if (i=='Z')
    {
        x=25;
        test(a, b, x, e,temp,characters);
    }   
}
cout<<cipher;
}
void EQUATION(int c, int b, int y,int d, int temp ,const vector<char>& characters)// to compute equation of decipher 
{
  string plain;
  d=c*(y-b);
  if(d<0){
    temp=(d%26)+26;
  }
  else if (d>=0)
  {
    temp=d%26;
  }
  plain=plain+characters.at(temp); 
  cout<<plain;
} 
void decipher(int c,int b ,string word){
  int y,temp,d;
  cout<<"enter your key c and b";
  string plain;
  vector<char> characters={'A','B','C','D' ,'E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  bool validinput=false;
  while (!validinput)
  {
    try
    {
      cin>>c;
      if (cin.fail() || c<=0)
      {
        throw invalid_argument("invalid input:please enter a valid number that is positive integer");
      }
      cin>>b;
      if (cin.fail() || b<=0)
      {
        throw invalid_argument("invalid input:please enter a valid number that is positive integer");
      }
      validinput=true;
    }
    catch(const invalid_argument& e)
    {
      std::cerr << e.what() << '\n';
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
  }validinput=false;
  cin.ignore();
  cout<<"enter your word:";
  bool found;
  getline(cin,word);
  for (int i = 0; i < word.length(); i++)
  {
    if (isalpha(word[i])||isspace(word[i]))
    {
      found=false;
    }else{
      found=true;
      cout<<"word should be contain only alphabetic characters";
      break;
    }
  }
  while (found)
  {
    cout<<"please enter anther word";
    getline(cin,word);
    for (int i = 0; i < word.length(); i++)
    {
      if (isalpha(word[i])||isspace(word[i]))
      {
        found=false;
      }else{
        found=true;
        cout<<"word should be contain only alphabetic characters";
        break;
      }
    }
  } 
  for (int i= 0; i <word.length(); i++)
  {
    word[i]=toupper(word[i]);
  }
  for(char i:word)
  { 
    if(i=='A'){
      y=0;
      EQUATION(c,b,y,d,temp,characters);  
    } 
    else if (i=='B')
    { 
      y=1;
            
    }else if (i=='C')
    {
      y=2;
      EQUATION(c,b,y,d,temp,characters);
            
    }else if (i=='D')
    {
      y=3;
      EQUATION(c,b,y,d,temp,characters);
            

    }else if (i=='E')
    {
      y=4;

      EQUATION(c,b,y,d,temp,characters);    
    }else if (i=='F')
    {
      y=5;
      EQUATION(c,b,y,d,temp,characters);
            
    }else if (i=='G')
    {
      y=6;
      EQUATION(c,b,y,d,temp,characters);
            
    }else if (i=='H')
    {
      y=7;
      EQUATION(c,b,y,d,temp,characters);
           
    }else if (i=='I')
    {
      y=8;
      EQUATION(c,b,y,d,temp,characters); 
           
    }else if (i=='J')
    {
      y=9;
      EQUATION(c,b,y,d,temp,characters);
            
    }else if (i=='K')
    {
      y=10;
      EQUATION(c,b,y,d,temp,characters);
              
    }else if (i=='L')
    {
      y=11;
      EQUATION(c,b,y,d,temp,characters);
            
    }else if (i=='M')
    {
      y=12;
      EQUATION(c,b,y,d,temp,characters);
        
    }else if (i=='N')
    {
      y=13;
      EQUATION(c,b,y,d,temp,characters);
            
    }else if (i=='O')
    {
      y=14;
      EQUATION(c,b,y,d,temp,characters);
           
    }else if (i=='P')
    {
      y=15;
      EQUATION(c,b,y,d,temp,characters);
           
    }else if (i=='Q')
    {
      y=16;
      EQUATION(c,b,y,d,temp,characters);
            
    }else if (i=='R')
    {
      y=17;
      EQUATION(c,b,y,d,temp,characters);
           
    }else if (i=='S')
    {
     y=18;
     EQUATION(c,b,y,d,temp,characters);
            
    }else if (i=='T')
    {
      y=19;
      EQUATION(c,b,y,d,temp,characters);
            
    }else if (i=='U')
    {
      y=20;
      EQUATION(c,b,y,d,temp,characters);
            
    }else if (i=='V')
    {
      y=21;
      EQUATION(c,b,y,d,temp,characters);
            
    }else if (i=='W')
    {
      y=22;
      EQUATION(c,b,y,d,temp,characters);      
    }else if (i=='X')
    {
      y=23;
      EQUATION(c,b,y,d,temp,characters);      
    }else if (i=='Y')
    {
      y=24;
      EQUATION(c,b,y,d,temp,characters);      
    }else if (i=='Z')
    {
      y=25;
      EQUATION(c,b,y,d,temp,characters);
            
    }   
   }
   cout<<plain<<endl;
}

void main0()
{
  int a,b;
  int c;
  string word;
  string option;
  while (true)
    {
        cout<<"Ahlan ya user ya habibi."<<endl<<"What do you like to do today?"<<endl<<"1- Cipher a message"<<endl<<"2- Decipher a message"<<endl<<"3- End"<<endl;
        cout<<"plaese enter your option";
        string option;
        cin>>option;
        cin.ignore();
        if (option=="1")// if user want to encryption
        {
          cipher0 (a,b,word);
            
          break;
        }else if (option=="2")
        {
          decipher( c, b , word);
          break;
        }else if (option=="3")
        {
          cout<<"your programm finished";
          break;
        }
        else
        {
          cout<<"plese enter a valid value that is 1 or 2 or 3";
        }
    }

}
