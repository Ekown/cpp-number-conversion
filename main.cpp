#include<iostream>
#include<string>
#include <stdio.h>

using namespace std;

void clearScreen();

string dec2bin(string decimalInputVal);
string dec2oct(string decimalInputVal);
string dec2hex(string decimalInputVal);
int bin2dec();
int oct2dec();
int hex2dec();

string capitalizeFirstLetter(string wordString);
bool validateInput(string inputVal, string choiceVal);

string backInfo = "(Press [X] to go to the previous menu)";

int main() {
    string choiceVal;
    string operationVal[2];
    bool bInvalidOption;

    bInvalidOption = false;

    do {
        clearScreen();  

        cout << "Welcome to the Number Conversion program";
        cout << "\n";
        cout << "\n[1] Decimal to Binary";
        cout << "\n[2] Decimal to Octal";
        cout << "\n[3] Decimal to Hexadecimal";
        cout << "\n[4] Binary to Decimal";
        cout << "\n[5] Octal to Decimal";
        cout << "\n[6] Hexadecimal to Decimal";
        cout << "\n[7] Exit";

        // Decimal input limit 0 -> 9999
        // Binary input limit 10011100001111
        // Octal input limit 0 -> 23417
        // Hexa input limit 0 -> 270F

        cout << "\n\nPlease choose an operation above (1-6): ";
        getline(cin, choiceVal);

        if (choiceVal == "1") {
            operationVal[0] = "decimal";
            operationVal[1] = "binary";
        } else if (choiceVal == "2") {
            operationVal[0] = "decimal";
            operationVal[1] = "octal";
        } else if (choiceVal == "3") {
            operationVal[0] = "decimal";
            operationVal[1] = "hexadecimal";
        } else if (choiceVal == "4") {
            operationVal[0] = "binary";
            operationVal[1] = "decimal";
        } else if (choiceVal == "5") {
            operationVal[0] = "octal";
            operationVal[1] = "decimal";
        } else if (choiceVal == "6") {
            operationVal[0] = "hexadecimal";
            operationVal[1] = "decimal";
        } else if (choiceVal == "7") {
            break;
        } else {
            bInvalidOption = true;
            continue;
        }

        bool bCorrectInput = true;
        string inputVal;

        do {
            clearScreen();

            cout << "\n" << capitalizeFirstLetter(operationVal[0]) << " to " << capitalizeFirstLetter(operationVal[1]) << " conversion...";
            
            cout << "\n\nPlease enter the " << operationVal[0] << " value " << backInfo << ": ";
            getline(cin, inputVal);

            if (inputVal == "X" || inputVal == "x") {
                bInvalidOption = true;
                break;
            }

            if (validateInput(inputVal, choiceVal)) {
                string tryAgainVal;

                if (choiceVal == "1") {
                    cout << "\nThe " << operationVal[1] << " value of " << inputVal << " is " << dec2bin(inputVal);
                } else if (choiceVal == "2") {
                    cout << "\nThe " << operationVal[1] << " value of " << inputVal << " is " << dec2oct(inputVal);
                } else if (choiceVal == "3") {
                    cout << "\nThe " << operationVal[1] << " value of " << inputVal << " is " << dec2hex(inputVal);
                }

                do {
                    cout << "\n\nDo you want to enter again (Y/N)? ";
                    getline(cin, tryAgainVal);

                    if (tryAgainVal == "Y" || tryAgainVal == "y") {
                        bCorrectInput = false;
                        break;
                    }

                    if (tryAgainVal == "N" || tryAgainVal == "n") {
                        bCorrectInput = true;
                        bInvalidOption = true;
                    }

                    clearScreen();
                } while (tryAgainVal != "N" && tryAgainVal != "n");
            } else {
                bCorrectInput = false;
            }

        } while(!bCorrectInput);
    } while(bInvalidOption);

    cout << "\nThank you for using the Number Conversion program. Goodbye!";

    cout << "\n";

    return 0;
}

void clearScreen() {
    system("clear");
}

string capitalizeFirstLetter(string wordString) {
    wordString[0] = toupper(wordString[0]);

    return wordString;
}

bool validateInput(string inputVal, string choiceVal) {
    int numericalVal;
    bool bIsNumericVal = true;

    try {
        numericalVal = stoi(inputVal);
    } catch(exception &err) {
        bIsNumericVal = false;
    }
    
    if ((choiceVal == "1" || choiceVal == "2" || choiceVal == "3") && bIsNumericVal) {
        return numericalVal >= 0 && numericalVal <= 9999;
    }
}

string dec2bin(string decimalInputVal) {
    string binaryOutput;
    int remainder;
    int decimalInputConvertVal;
    
    binaryOutput = "";
    decimalInputConvertVal = stoi(decimalInputVal);

    do {
        remainder = decimalInputConvertVal % 2;

        binaryOutput = to_string(remainder) + binaryOutput;

        decimalInputConvertVal /= 2;
    } while(decimalInputConvertVal != 0);
    
    return binaryOutput;
}

string dec2oct(string decimalInputVal) {
    string octalOutput;
    int remainder;
    int decimalInputConvertVal;
    
    octalOutput = "";
    decimalInputConvertVal = stoi(decimalInputVal);

    do {
        if (decimalInputConvertVal >= 8) {
            remainder = decimalInputConvertVal % 8;
            octalOutput = to_string(remainder) + octalOutput;
        } else {
            octalOutput = to_string(decimalInputConvertVal) + octalOutput;
        }        

        decimalInputConvertVal /= 8;
    } while(decimalInputConvertVal != 0);
    
    return octalOutput;
}

string dec2hex(string decimalInputVal) {
    string hexOutput;
    int remainder;
    int decimalInputConvertVal;
    
    hexOutput = "";
    decimalInputConvertVal = stoi(decimalInputVal);

    do {
        remainder = decimalInputConvertVal % 16;

        switch(remainder) {
            case 10: 
                hexOutput = "A" + hexOutput;
                break;
            case 11: 
                hexOutput = "B" + hexOutput;
                break;
            case 12: 
                hexOutput = "C" + hexOutput;
                break;
            case 13: 
                hexOutput = "D" + hexOutput;
                break;
            case 14: 
                hexOutput = "E" + hexOutput;
                break;
            case 15: 
                hexOutput = "F" + hexOutput;
                break;
            default:
                hexOutput = to_string(remainder) + hexOutput;
        }              

        decimalInputConvertVal /= 16;
    } while(decimalInputConvertVal != 0);
    
    return hexOutput;
}

int bin2dec() {

}

int oct2dec() {

}

int hex2dec() {

}
