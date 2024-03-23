// File:  CS112_A2_T2_S25&S26
// purpose : Fraction calculator
//Name 1: Abdelrahman mohamed gabr  ID:20231098    email:gabrabdo908@gmail.com

/* Algorithm
 1.print welcome message and input message
2.check if the input is valid or not
3.take str1 and divide it to nominator and denominator if exist and do this to str2 also
4. do all operations and convert to integer  to make it suitable to calculate
5.do the arithmetic operation based on the input
6.print the result
7. exit input
 */


#include <iostream>
#include <regex>
#include <cctype>
#include <string>
using namespace std;
int main ()
{
    cout<<"welcome to fraction calculator " << endl;
//    Big loop to calculator
    while (true){
        cout << "\nplease choose  1-continue  2-Exit \n";
        char answ;
        cin >> answ;
        cin.ignore();
        if (answ == '1'){
        cout << "\n";
        cout << "Please enter equation you want to calc \n";
    string str1;
    getline(cin, str1);

    char   opperation;
    string numenatir1;
    string demonator1 ;
    string numenatir2;
    string demontor2 ;

    bool con = true;

    // Iterate through the string to show if have any chars or in valid chars
    for (int i = str1.length() - 1; i >= 0; i--) {
        if ((str1[i] >= '0' && str1[i] <= '9') || isspace(str1[i]) || str1[i] == '/' || str1[i] == '*' || str1[i] == '-' || str1[i] == '+')
        {
            if (str1[i] == ' ')
            {
                str1.erase(i, 1); // Erase the space character
            }
        }
        else {
            con = false;
        }
    }
    if (con == false)
    {
        cout << "Invalid input please put a number"<<endl;
        continue;
    }
string temp = str1;

    if (str1[0] == '+' || str1[0] == '-')
       {
           numenatir1.push_back( str1[0]); // Insert the character into numenatir1
           str1.erase(0,1);
       }
// calc numerator1
for (int q=0; q<str1.length(); q++)
 {
if (str1[q] == '+' || str1[q] == '-' || str1[q] == '/' ||str1[q] == '*')
    break;
else
{
    numenatir1.push_back( str1[q]); // Insert the character into numenatir1
    str1.erase(q,1);
    q--;
}

}

// Avilable patterns
    regex pttrn1 (R"((\+?-?\d+)/(\d+)[-\/\*\+](\+?-?\d+)/(\+?-?\d+))");     // Example 1/2 + 3/4
    regex pttrn2("^([-+]?(\\d+))([\\+\\-\\*\\/])(\\d+)/((\\d+))$");         // Example 31 * 1/4
    regex pttrn3("^([\\+\\-]?\\d+)[\\+\\-\\*\\/]([\\+\\-]?\\d+)[\\+\\-\\*]([\\+\\-]?\\d+)$"); // Example  1/2 +3
    regex pttrn4 (R"((\+?-?\d+)\s*[\+\/\*\-]\s*(\+?-?\d+))");   // Example 1 + 2

    smatch matches; // for regex
//    patt
    if (regex_match(temp,pttrn1))
    {
        str1.erase(0,1);
//        calc dem1
        for (int z=0; str1.length()>z;z++)
        {
            if (str1[z] == '+' || str1[z] == '-' || str1[z] == '/' ||str1[z] == '*')
                break;
            else
            {
                demonator1.push_back( str1[z]); // Insert the character into demonator1
                str1.erase(z,1);
                z--;
            }
        }

        opperation = str1[0];
        str1.erase(0,1);
//        calc num2
    for (int z=0; z<str1.length(); z++){
        if (str1[z] == '/')
            break;
        else{
            numenatir2.push_back( str1[z]); // Insert the character into num2
            str1.erase(z,1);
            z--;
        }
    }
    str1.erase(0,1);
//    calc dem2
 for (int z=0; z<str1.length();z++){
     demontor2.push_back( str1[z]); // Insert the character into num2
     str1.erase(z,1);
     z--;
 }

    }

    else if (regex_match(temp,pttrn2))
    {
        demonator1 = "1";
        opperation = str1[0];
        str1.erase(0,1);

        for (int v=0; str1.length()>v; v++)
        {
            if (str1[v] == '/' )
                break;
            else
            {
                numenatir2.push_back( str1[v]); // Insert the character into demonator1
                str1.erase(v,1);
                v--;
            }
        }
        str1.erase(0,1);
        for (int v=0; v<str1.length(); v++){
            demontor2.push_back( str1[v]); // Insert the character into demonator1
            str1.erase(v,1);
            v--;
        }
    }

    else if (regex_match(temp,pttrn3))
    {
        demontor2 = "1";
        str1.erase(0,1);
        for (int n=0; n<str1.length(); n++){
            if (str1[n] == '+' || str1[n] == '-' || str1[n] == '*')
                break;
            else
            {
                demonator1.push_back( str1[n]); // Insert the character into demonator1
                str1.erase(n,1);
                n--;
            }
        }
        opperation = str1[0];
        str1.erase(0,1);
        for (int n=0 ; n<str1.length(); n++){
            numenatir2.push_back( str1[n]); // Insert the character into demonator1
            str1.erase(n,1);
            n--;
        }


    }


    else if (regex_match(temp, matches, pttrn4)) {
        string numerator1 = matches[1]; // First number
        string numerator2 = matches[2]; // Second number
        string operation = temp.substr(numerator1.length(), 1); // Operator

        numenatir1 =  numerator1;
        numenatir2 = numerator2 ;
        demonator1 = demontor2 = "1";
        opperation =  operation[0] ;


    }

    else {
        cout << "Invalid pattern please try again";
        continue;
    }

//    change strings values to equivalent int values
int numerator_1 = stoi(numenatir1);
int Denominator_1 = stoi(demonator1);
int numerator_2 = stoi(numenatir2);
int Denominator_2 = stoi(demontor2);

// if Denominator == 0 return error
if (Denominator_1 == 0 ||Denominator_2 ==0){
    cout << "Invalid number in Denominator!!";
    continue;
}
// operations for +,-,/,*
    if (opperation== '+')
    {
        if (Denominator_1 == Denominator_2){
            if ((numerator_1+numerator_2 == Denominator_1))
                cout << 1;
            else
                cout<< (numerator_1 + numerator_2) << '/' <<  Denominator_1;

        }
        else
            cout<< ((numerator_1*Denominator_2) + (Denominator_1*numerator_2)) << '/' <<  Denominator_1*Denominator_2 ;
    }

    else if(opperation== '-')
    {
        if (Denominator_1 == Denominator_2)
        {
            if (numerator_1 - numerator_2 == 0)
                cout << 0;
            else
                cout << (numerator_1 - numerator_2) << "/" << Denominator_1;
        }
        else
            cout<< ((numerator_1*Denominator_2) - (Denominator_1*numerator_2)) << '/' <<  Denominator_1*Denominator_2 ;
    }

    else if(opperation== '*'){
        cout<< (numerator_1*numerator_2)<<'/'<<(Denominator_1*Denominator_2) ;
    }
    else if(opperation== '/'){
        cout<< (numerator_1*Denominator_2)<<'/'<<(Denominator_1*numerator_2) ;
    }
        }
        else if (answ == '2'){
            cout << "Thanks for your try \n";
            break;
        }
        else
            cout << " Invalid choice please take valid choice\n";
        continue;
    }
    return 0 ;
}
