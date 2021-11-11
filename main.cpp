#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void clearScreen();
string capitalizeFirstLetter(string wordString);

string dec2bin(string decimalInputVal);
string dec2oct(string decimalInputVal);
string dec2hex(string decimalInputVal);

int bin2dec(string binaryInputVal);
int oct2dec(string octalInputVal);
int hex2dec(string hexadecimalInputVal);

bool validateInput(string inputVal, string choiceVal);
int raiseToPowerOf(int base, int exponent);
string trimZeros(string binaryInputVal);

int checkIfDecimal(string decimalInputVal);
int checkIfBinary(string binaryInputVal);
int checkIfOctal(string octalInputVal);

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

            if (validateInput(inputVal, operationVal[0])) {
                string tryAgainVal;

                cout << "\nThe " << operationVal[1] << " value of " << inputVal << " is ";

                if (choiceVal == "1") {
                    cout << dec2bin(inputVal);
                } else if (choiceVal == "2") {
                    cout << dec2oct(inputVal);
                } else if (choiceVal == "3") {
                    cout << dec2hex(inputVal);
                } else if (choiceVal == "4") {
                    cout << bin2dec(inputVal);
                } else if (choiceVal == "5") {
                    cout << oct2dec(inputVal);
                } else if (choiceVal == "6") {
                    cout << hex2dec(inputVal);
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

bool validateInput(string inputVal, string operationVal) {
    int numericalVal;
    bool bIsNumericVal = true;

    try {
        numericalVal = stoi(inputVal);
    } catch(exception &err) {
        bIsNumericVal = false;
    }
    
    if ((operationVal == "decimal") && bIsNumericVal) {
        return (numericalVal >= 0 && numericalVal <= 9999) && checkIfDecimal(inputVal);
    } else if (operationVal == "binary") {
        int bIsBinary = checkIfBinary(inputVal);
        long long int binaryVal = stoll(inputVal);

        if (bIsBinary == 0) {
            return false;
        }

        inputVal = trimZeros(inputVal);

        return (inputVal.size() > 0 && inputVal.size() <= 14) && (binaryVal >= 0 && binaryVal <= 10011100001111);
    } else if (operationVal == "octal" && bIsNumericVal) {
        return (numericalVal >= 0 && numericalVal <= 23417) && checkIfOctal(inputVal);
    } else {
        return false;
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

int bin2dec(string binaryInputVal) {
    int decimalOutput = 0;
    string currentBinaryDigit;

    for(int i = 0; i < binaryInputVal.size(); i++) {        
        currentBinaryDigit = binaryInputVal[binaryInputVal.size() - (i + 1)];

        // we could just use pow() here, but i'm a masochist so...
        if (currentBinaryDigit == "1") {
            decimalOutput += (stoi(currentBinaryDigit) * raiseToPowerOf(2, i));
        }
    }

    return decimalOutput;
}

int oct2dec(string octalInputVal) {
    int octalOutput = 0;
    string currentOctalDigit;

    for(int i = 0; i < octalInputVal.size(); i++) {
        currentOctalDigit = octalInputVal[octalInputVal.size() - (i + 1)];
        octalOutput += (stoi(currentOctalDigit) * raiseToPowerOf(8, i));
    }

    return octalOutput;
}

int hex2dec(string decimalInputVal) {

}

string trimZeros(string binaryInputVal) {
    string trimmedInput = "";
    int bFirstNonZero = 0;
    
    if (binaryInputVal.size() == 1) {
        trimmedInput = "0";
    }

    for (int i = 0; i < binaryInputVal.size(); i++) {
        if (bFirstNonZero == 0) {
            bFirstNonZero = binaryInputVal[i] == '1';
        }

        if (bFirstNonZero == 1) {
            trimmedInput += binaryInputVal[i];
        }
    }

    return trimmedInput;
}

int checkIfDecimal(string decimalInputVal) {
    int bIsDecimal = 1;
    string currentDecimalDigit;

    try {
        for(int i = 0; i < decimalInputVal.size(); i++) {
            currentDecimalDigit = decimalInputVal[i];
            stoi(currentDecimalDigit);
        }
    } catch (exception &err) {
        bIsDecimal = 0;
    }
    
    return bIsDecimal;
}

int checkIfBinary(string binaryInputVal) {
    int bIsBinary = 1;

    for(int i = 0; i < binaryInputVal.size(); i++) {
        if (binaryInputVal[i] != '0' && binaryInputVal[i] != '1') {
            bIsBinary = 0;
            break;
        }
    }
    
    return bIsBinary;
}

int checkIfOctal(string octalInputVal) {
    int bIsOctal = 1;

    for(int i = 0; i < octalInputVal.size(); i++) {
        if (octalInputVal[i] == '8' || octalInputVal[i] == '9') {
            bIsOctal = 0;
            break;
        }
    }
    
    return bIsOctal;
}

int raiseToPowerOf(int base, int exponent) {
    int poweredUpVal = 1;

    if (exponent == 0) {
        return poweredUpVal;
    }

    for (int i = 1; i <= exponent; i++) {
        poweredUpVal *= base;
    }

    return poweredUpVal;
}
