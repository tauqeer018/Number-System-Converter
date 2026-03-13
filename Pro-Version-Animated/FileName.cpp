#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <thread>    
#include <chrono> 
#include<sstream>

using namespace std;

void clearScreen() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void printHeader(const string& title) {
    cout << "\n**********************************************\n";
    cout << "* " << setw(42) << left << title << " *\n";
    cout << "**********************************************\n";
}

void printResult(const string& from, const string& to, const string& value) {
    cout << "\n----------------------------------------------\n";
    cout << "| Conversion Result:\n";
    cout << "| From:   " << setw(35) << left << from << " |\n";
    cout << "| To:     " << setw(35) << left << to << " |\n";
    cout << "| Result: " << setw(35) << left << value << " |\n";
    cout << "----------------------------------------------\n";
}

void showProgress() {
	cout << "Converting ";
	for (int i = 0; i < 3; i++) {
		cout << ".";
		cout.flush();
		this_thread ::sleep_for(chrono::milliseconds(300));
	}
	cout << endl;
}

string toLower(string str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}
bool isValidOctalForConversion(string num) {
	int dotCount = 0;
	for (char c : num) {
		if (c == '.') {
			dotCount++;
			if (dotCount > 1) {
				return false;
			}
		}
		else if (c < '0' || c > '7') {
			return false;
		}
	}
	return true;
}

bool isInteger(string n) {
	for (char d : n) {
		if (!isdigit(d)) {
			return false;
		}
	}
	return true;
}

bool isFloat(string num) {
	int dotcount = 0;
	for (char c : num) {
		if (c == '.') {
			dotcount++;
		}
		else if (!isdigit(c)) {
			return false;
		}
	}
	return dotcount == 1;
}

bool isValidHex(const string& s) {
	if (s.empty()) return false;
	int dotCount = 0;
	for (char c : s) {
		char ch = toupper(c);
		if (ch == '.') {
			dotCount++;
			if (dotCount > 1) return false;
		}
		else if (!((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F'))) {
			return false;
		}
	}
	return true;
}

bool isvalidBinary(string n) {
	for (char c : n) {
		if (c != '0' && c != '1' && c != '.') {
			return false;
		}
	}
	return true;
}

void decimalToBinaryConversion() {
    clearScreen();
    printHeader("DECIMAL TO BINARY CONVERSION");

    cout << "Enter decimal number (e.g., 123 or 123.456): ";
    string input;
    getline(cin, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    try {
        if (input.find('.') != string::npos) {
            float num = stof(input);
            showProgress();

            int integerPart = num;
            float fractionalPart = num - integerPart;
            string binary;

            if (integerPart == 0) {
                binary = "0";
            }
            else {
                while (integerPart > 0) {
                    binary = to_string(integerPart % 2) + binary;
                    integerPart /= 2;
                }
            }

            if (fractionalPart > 0) {
                binary += ".";
                int precision = 10;
                while (precision-- && fractionalPart > 0) {
                    fractionalPart *= 2;
                    int bit = fractionalPart;
                    binary += to_string(bit);
                    fractionalPart -= bit;
                }
            }

            printResult("Decimal: " + input, "Binary", binary);
        }
        else {
            int num = stoi(input);
            showProgress();

            string binary;
            if (num == 0) {
                binary = "0";
            }
            else {
                while (num > 0) {
                    binary = to_string(num % 2) + binary;
                    num /= 2;
                }
            }

            printResult("Decimal: " + input, "Binary", binary);
        }
    }
    catch (...) {
        cout << "\nInvalid input! Please enter a valid decimal number.\n";
    }
}

void decimalToOctalConversion() {
    clearScreen();
    printHeader("DECIMAL TO OCTAL CONVERSION");

    cout << "Enter decimal number (e.g., 123 or 123.456): ";
    string input;
    getline(cin, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    try {
        if (input.find('.') != string::npos) {
            float num = stof(input);
            showProgress();

            int integerPart = num;
            float fractionalPart = num - integerPart;
            string octal;

            if (integerPart == 0) {
                octal = "0";
            }
            else {
                while (integerPart > 0) {
                    octal = to_string(integerPart % 8) + octal;
                    integerPart /= 8;
                }
            }

            if (fractionalPart > 0) {
                octal += ".";
                int precision = 10;
                while (precision-- && fractionalPart > 0) {
                    fractionalPart *= 8;
                    int bit = fractionalPart;
                    octal += to_string(bit);
                    fractionalPart -= bit;
                }
            }

            printResult("Decimal: " + input, "Octal", octal);
        }
        else {
            int num = stoi(input);
            showProgress();

            string octal;
            if (num == 0) {
                octal = "0";
            }
            else {
                while (num > 0) {
                    octal = to_string(num % 8) + octal;
                    num /= 8;
                }
            }

            printResult("Decimal: " + input, "Octal", octal);
        }
    }
    catch (...) {
        cout << "\nInvalid input! Please enter a valid decimal number.\n";
    }
}

void decimalToHexConversion() {
    clearScreen();
    printHeader("DECIMAL TO HEXADECIMAL CONVERSION");

    cout << "Enter decimal number (e.g., 123 or 123.456): ";
    string input;
    getline(cin, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    try {
        const string hexDigits = "0123456789ABCDEF";

        if (input.find('.') != string::npos) {
            float num = stof(input);
            showProgress();

            int integerPart = num;
            float fractionalPart = num - integerPart;
            string hex;

            if (integerPart == 0) {
                hex = "0";
            }
            else {
                while (integerPart > 0) {
                    hex = hexDigits[integerPart % 16] + hex;
                    integerPart /= 16;
                }
            }

            if (fractionalPart > 0) {
                hex += ".";
                int precision = 10;
                while (precision-- && fractionalPart > 0) {
                    fractionalPart *= 16;
                    int bit = fractionalPart;
                    hex += hexDigits[bit];
                    fractionalPart -= bit;
                }
            }

            printResult("Decimal: " + input, "Hexadecimal", hex);
        }
        else {
            int num = stoi(input);
            showProgress();

            string hex;
            if (num == 0) {
                hex = "0";
            }
            else {
                while (num > 0) {
                    hex = hexDigits[num % 16] + hex;
                    num /= 16;
                }
            }

            printResult("Decimal: " + input, "Hexadecimal", hex);
        }
    }
    catch (...) {
        cout << "\nInvalid input! Please enter a valid decimal number.\n";
    }
}

void binaryToDecimalConversion() {
    clearScreen();
    printHeader("BINARY TO DECIMAL CONVERSION");

    cout << "Enter binary number (e.g., 1010 or 1010.101): ";
    string input;
    getline(cin, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    bool isValid = true;
    int dotCount = 0;
    for (char c : input) {
        if (c == '.') {
            dotCount++;
            if (dotCount > 1) {
                isValid = false;
                break;
            }
        }
        else if (c != '0' && c != '1') {
            isValid = false;
            break;
        }
    }

    if (!isValid) {
        cout << "\nInvalid binary number! Only 0, 1 and . are allowed.\n";
        return;
    }

    showProgress();

    size_t dotPos = input.find('.');
    string intPart = (dotPos == string::npos) ? input : input.substr(0, dotPos);
    string fracPart = (dotPos == string::npos) ? "" : input.substr(dotPos + 1);

    int decimal = 0;
    for (int i = 0; i < intPart.size(); i++) {
        if (intPart[i] == '1') {
            decimal += pow(2, intPart.size() - 1 - i);
        }
    }

    double fraction = 0.0;
    for (int i = 0; i < fracPart.size(); i++) {
        if (fracPart[i] == '1') {
            fraction += 1.0 / pow(2, i + 1);
        }
    }

    double result = decimal + fraction;
    ostringstream oss;
    oss << fixed << setprecision(6) << result;
    printResult("Binary: " + input, "Decimal", oss.str());

}

void octalToDecimalConversion() {
    clearScreen();
    printHeader("OCTAL TO DECIMAL CONVERSION");

    cout << "Enter octal number (e.g., 123 or 123.456): ";
    string input;
    getline(cin, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    bool isValid = true;
    int dotCount = 0;
    for (char c : input) {
        if (c == '.') {
            dotCount++;
            if (dotCount > 1) {
                isValid = false;
                break;
            }
        }
        else if (c < '0' || c > '7') {
            isValid = false;
            break;
        }
    }

    if (!isValid) {
        cout << "\nInvalid octal number! Only digits 0-7 and . are allowed.\n";
        return;
    }

    showProgress();

    size_t dotPos = input.find('.');
    string intPart = (dotPos == string::npos) ? input : input.substr(0, dotPos);
    string fracPart = (dotPos == string::npos) ? "" : input.substr(dotPos + 1);

    int decimal = 0;
    for (int i = 0; i < intPart.size(); i++) {
        decimal += (intPart[i] - '0') * pow(8, intPart.size() - 1 - i);
    }

    double fraction = 0.0;
    for (int i = 0; i < fracPart.size(); i++) {
        fraction += (fracPart[i] - '0') * (1.0 / pow(8, i + 1));
    }

    double result = decimal + fraction;
    ostringstream oss;
    oss << fixed << setprecision(6) << result;
    printResult("Binary: " + input, "Decimal", oss.str());

}

void hexToDecimalConversion() {
    clearScreen();
    printHeader("HEXADECIMAL TO DECIMAL CONVERSION");

    cout << "Enter hexadecimal number (e.g., 1A3 or 1A3.B4): ";
    string input;
    getline(cin, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    bool isValid = true;
    int dotCount = 0;
    for (char c : input) {
        if (c == '.') {
            dotCount++;
            if (dotCount > 1) {
                isValid = false;
                break;
            }
        }
        else if (!((c >= '0' && c <= '9') ||
            (toupper(c) >= 'A' && toupper(c) <= 'F'))) {
            isValid = false;
            break;
        }
    }

    if (!isValid) {
        cout << "\nInvalid hexadecimal number! Only digits 0-9, A-F and . are allowed.\n";
        return;
    }

    showProgress();

    size_t dotPos = input.find('.');
    string intPart = (dotPos == string::npos) ? input : input.substr(0, dotPos);
    string fracPart = (dotPos == string::npos) ? "" : input.substr(dotPos + 1);

    int decimal = 0;
    for (int i = 0; i < intPart.size(); i++) {
        char c = toupper(intPart[i]);
        int value = (c >= 'A') ? (c - 'A' + 10) : (c - '0');
        decimal += value * pow(16, intPart.size() - 1 - i);
    }

    double fraction = 0.0;
    for (int i = 0; i < fracPart.size(); i++) {
        char c = toupper(fracPart[i]);
        int value = (c >= 'A') ? (c - 'A' + 10) : (c - '0');
        fraction += value * (1.0 / pow(16, i + 1));
    }

    double result = decimal + fraction;
    ostringstream oss;
    oss << fixed << setprecision(6) << result;
    printResult("Binary: " + input, "Decimal", oss.str());

}

void binaryToOctalConversion() {
    clearScreen();
    printHeader("BINARY TO OCTAL CONVERSION");

    cout << "Enter binary number (e.g., 1010 or 1010.101): ";
    string input;
    getline(cin, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    bool isValid = true;
    int dotCount = 0;
    for (char c : input) {
        if (c == '.') {
            dotCount++;
            if (dotCount > 1) {
                isValid = false;
                break;
            }
        }
        else if (c != '0' && c != '1') {
            isValid = false;
            break;
        }
    }

    if (!isValid) {
        cout << "\nInvalid binary number! Only 0, 1 and . are allowed.\n";
        return;
    }

    showProgress();

    size_t dotPos = input.find('.');
    string intPart = (dotPos == string::npos) ? input : input.substr(0, dotPos);
    string fracPart = (dotPos == string::npos) ? "" : input.substr(dotPos + 1);

   
    while (intPart.size() % 3 != 0) {
        intPart = "0" + intPart;
    }

    string octal;
    for (size_t i = 0; i < intPart.size(); i += 3) {
        string group = intPart.substr(i, 3);
        int value = (group[0] - '0') * 4 + (group[1] - '0') * 2 + (group[2] - '0');
        octal += to_string(value);
    }

    if (!fracPart.empty()) {
        octal += ".";
        while (fracPart.size() % 3 != 0) {
            fracPart += "0";
        }

        for (size_t i = 0; i < fracPart.size(); i += 3) {
            string group = fracPart.substr(i, 3);
            int value = (group[0] - '0') * 4 + (group[1] - '0') * 2 + (group[2] - '0');
            octal += to_string(value);
        }
    }

    printResult("Binary: " + input, "Octal", octal);
}

void binaryToHexConversion() {
    clearScreen();
    printHeader("BINARY TO HEXADECIMAL CONVERSION");

    cout << "Enter binary number (e.g., 1010 or 1010.101): ";
    string input;
    getline(cin, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    bool isValid = true;
    int dotCount = 0;
    for (char c : input) {
        if (c == '.') {
            dotCount++;
            if (dotCount > 1) {
                isValid = false;
                break;
            }
        }
        else if (c != '0' && c != '1') {
            isValid = false;
            break;
        }
    }

    if (!isValid) {
        cout << "\nInvalid binary number! Only 0, 1 and . are allowed.\n";
        return;
    }

    showProgress();

    const string hexDigits = "0123456789ABCDEF";
    size_t dotPos = input.find('.');
    string intPart = (dotPos == string::npos) ? input : input.substr(0, dotPos);
    string fracPart = (dotPos == string::npos) ? "" : input.substr(dotPos + 1);

    while (intPart.size() % 4 != 0) {
        intPart = "0" + intPart;
    }

    string hex;
    for (size_t i = 0; i < intPart.size(); i += 4) {
        string group = intPart.substr(i, 4);
        int value = (group[0] - '0') * 8 + (group[1] - '0') * 4 +
            (group[2] - '0') * 2 + (group[3] - '0');
        hex += hexDigits[value];
    }

    if (!fracPart.empty()) {
        hex += ".";
        
        while (fracPart.size() % 4 != 0) {
            fracPart += "0";
        }

        for (size_t i = 0; i < fracPart.size(); i += 4) {
            string group = fracPart.substr(i, 4);
            int value = (group[0] - '0') * 8 + (group[1] - '0') * 4 +
                (group[2] - '0') * 2 + (group[3] - '0');
            hex += hexDigits[value];
        }
    }

    printResult("Binary: " + input, "Hexadecimal", hex);
}

void hexToBinaryConversion() {
    clearScreen();
    printHeader("HEXADECIMAL TO BINARY CONVERSION");

    cout << "Enter hexadecimal number (e.g., 1A3 or 1A3.B4): ";
    string input;
    getline(cin, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    bool isValid = true;
    int dotCount = 0;
    for (char c : input) {
        if (c == '.') {
            dotCount++;
            if (dotCount > 1) {
                isValid = false;
                break;
            }
        }
        else if (!((c >= '0' && c <= '9') ||
            (toupper(c) >= 'A' && toupper(c) <= 'F'))) {
            isValid = false;
            break;
        }
    }

    if (!isValid) {
        cout << "\nInvalid hexadecimal number! Only digits 0-9, A-F and . are allowed.\n";
        return;
    }

    showProgress();

    const string binaryDigits[] = {
        "0000", "0001", "0010", "0011",
        "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011",
        "1100", "1101", "1110", "1111"
    };

    size_t dotPos = input.find('.');
    string intPart = (dotPos == string::npos) ? input : input.substr(0, dotPos);
    string fracPart = (dotPos == string::npos) ? "" : input.substr(dotPos + 1);

    string binary;
    for (char c : intPart) {
        c = toupper(c);
        int value = (c >= 'A') ? (c - 'A' + 10) : (c - '0');
        binary += binaryDigits[value];
    }

    size_t firstOne = binary.find('1');
    if (firstOne != string::npos) {
        binary = binary.substr(firstOne);
    }
    else {
        binary = "0";
    }

    if (!fracPart.empty()) {
        binary += ".";
        for (char c : fracPart) {
            c = toupper(c);
            int value = (c >= 'A') ? (c - 'A' + 10) : (c - '0');
            binary += binaryDigits[value];
        }
    }

    printResult("Hexadecimal: " + input, "Binary", binary);
}

void hexToOctalConversion() {
    clearScreen();
    printHeader("HEXADECIMAL TO OCTAL CONVERSION");

    cout << "Enter hexadecimal number (e.g., 1A3 or 1A3.B4): ";
    string input;
    getline(cin, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    bool isValid = true;
    int dotCount = 0;
    for (char c : input) {
        if (c == '.') {
            dotCount++;
            if (dotCount > 1) {
                isValid = false;
                break;
            }
        }
        else if (!((c >= '0' && c <= '9') ||
            (toupper(c) >= 'A' && toupper(c) <= 'F'))) {
            isValid = false;
            break;
        }
    }

    if (!isValid) {
        cout << "\nInvalid hexadecimal number! Only digits 0-9, A-F and . are allowed.\n";
        return;
    }

    showProgress();

    size_t dotPos = input.find('.');
    string intPart = (dotPos == string::npos) ? input : input.substr(0, dotPos);
    string fracPart = (dotPos == string::npos) ? "" : input.substr(dotPos + 1);

    string binary;
    const string binaryDigits[] = {
        "0000", "0001", "0010", "0011",
        "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011",
        "1100", "1101", "1110", "1111"
    };

    for (char c : intPart) {
        c = toupper(c);
        int value = (c >= 'A') ? (c - 'A' + 10) : (c - '0');
        binary += binaryDigits[value];
    }

    size_t firstOne = binary.find('1');
    if (firstOne != string::npos) {
        binary = binary.substr(firstOne);
    }
    else {
        binary = "0";
    }

    if (!fracPart.empty()) {
        binary += ".";
        for (char c : fracPart) {
            c = toupper(c);
            int value = (c >= 'A') ? (c - 'A' + 10) : (c - '0');
            binary += binaryDigits[value];
        }
    }

    size_t binaryDotPos = binary.find('.');
    string binaryIntPart = (binaryDotPos == string::npos) ? binary : binary.substr(0, binaryDotPos);
    string binaryFracPart = (binaryDotPos == string::npos) ? "" : binary.substr(binaryDotPos + 1);

    while (binaryIntPart.size() % 3 != 0) {
        binaryIntPart = "0" + binaryIntPart;
    }

    string octal;
    for (size_t i = 0; i < binaryIntPart.size(); i += 3) {
        string group = binaryIntPart.substr(i, 3);
        int value = (group[0] - '0') * 4 + (group[1] - '0') * 2 + (group[2] - '0');
        octal += to_string(value);
    }

    if (!binaryFracPart.empty()) {
        octal += ".";
       
        while (binaryFracPart.size() % 3 != 0) {
            binaryFracPart += "0";
        }

        for (size_t i = 0; i < binaryFracPart.size(); i += 3) {
            string group = binaryFracPart.substr(i, 3);
            int value = (group[0] - '0') * 4 + (group[1] - '0') * 2 + (group[2] - '0');
            octal += to_string(value);
        }
    }

    printResult("Hexadecimal: " + input, "Octal", octal);
}

void octalToBinaryConversion() {
    clearScreen();
    printHeader("OCTAL TO BINARY CONVERSION");

    cout << "Enter octal number (e.g., 123 or 123.456): ";
    string input;
    getline(cin, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
    
    bool isValid = true;
    int dotCount = 0;
    for (char c : input) {
        if (c == '.') {
            dotCount++;
            if (dotCount > 1) {
                isValid = false;
                break;
            }
        }
        else if (c < '0' || c > '7') {
            isValid = false;
            break;
        }
    }

    if (!isValid) {
        cout << "\nInvalid octal number! Only digits 0-7 and . are allowed.\n";
        return;
    }

    showProgress();

    const string binaryDigits[] = {
        "000", "001", "010", "011",
        "100", "101", "110", "111"
    };

    size_t dotPos = input.find('.');
    string intPart = (dotPos == string::npos) ? input : input.substr(0, dotPos);
    string fracPart = (dotPos == string::npos) ? "" : input.substr(dotPos + 1);

    string binary;
    for (char c : intPart) {
        int value = c - '0';
        binary += binaryDigits[value];
    }

    size_t firstOne = binary.find('1');
    if (firstOne != string::npos) {
        binary = binary.substr(firstOne);
    }
    else {
        binary = "0";
    }

    if (!fracPart.empty()) {
        binary += ".";
        for (char c : fracPart) {
            int value = c - '0';
            binary += binaryDigits[value];
        }
    }

    printResult("Octal: " + input, "Binary", binary);
}

void octalToHexConversion() {
    clearScreen();
    printHeader("OCTAL TO HEXADECIMAL CONVERSION");

    cout << "Enter octal number (e.g., 123 or 123.456): ";
    string input;
    getline(cin, input);
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    bool isValid = true;
    int dotCount = 0;
    for (char c : input) {
        if (c == '.') {
            dotCount++;
            if (dotCount > 1) {
                isValid = false;
                break;
            }
        }
        else if (c < '0' || c > '7') {
            isValid = false;
            break;
        }
    }

    if (!isValid) {
        cout << "\nInvalid octal number! Only digits 0-7 and . are allowed.\n";
        return;
    }

    showProgress();

    size_t dotPos = input.find('.');
    string intPart = (dotPos == string::npos) ? input : input.substr(0, dotPos);
    string fracPart = (dotPos == string::npos) ? "" : input.substr(dotPos + 1);

    string binary;
    const string binaryDigits[] = {
        "000", "001", "010", "011",
        "100", "101", "110", "111"
    };

    for (char c : intPart) {
        int value = c - '0';
        binary += binaryDigits[value];
    }

    size_t firstOne = binary.find('1');
    if (firstOne != string::npos) {
        binary = binary.substr(firstOne);
    }
    else {
        binary = "0";
    }

    if (!fracPart.empty()) {
        binary += ".";
        for (char c : fracPart) {
            int value = c - '0';
            binary += binaryDigits[value];
        }
    }

    const string hexDigits = "0123456789ABCDEF";
    size_t binaryDotPos = binary.find('.');
    string binaryIntPart = (binaryDotPos == string::npos) ? binary : binary.substr(0, binaryDotPos);
    string binaryFracPart = (binaryDotPos == string::npos) ? "" : binary.substr(binaryDotPos + 1);

    while (binaryIntPart.size() % 4 != 0) {
        binaryIntPart = "0" + binaryIntPart;
    }

    string hex;
    for (size_t i = 0; i < binaryIntPart.size(); i += 4) {
        string group = binaryIntPart.substr(i, 4);
        int value = (group[0] - '0') * 8 + (group[1] - '0') * 4 +
            (group[2] - '0') * 2 + (group[3] - '0');
        hex += hexDigits[value];
    }

    if (!binaryFracPart.empty()) {
        hex += ".";
        while (binaryFracPart.size() % 4 != 0) {
            binaryFracPart += "0";
        }

        for (size_t i = 0; i < binaryFracPart.size(); i += 4) {
            string group = binaryFracPart.substr(i, 4);
            int value = (group[0] - '0') * 8 + (group[1] - '0') * 4 +
                (group[2] - '0') * 2 + (group[3] - '0');
            hex += hexDigits[value];
        }
    }

    printResult("Octal: " + input, "Hexadecimal", hex);
}

void displayMainMenu() {
    clearScreen();
    printHeader("NUMBER CONVERSION TOOL");
    cout << "1. Decimal to Non-Decimal Conversions\n";
    cout << "2. Non-Decimal to Decimal Conversions\n";
    cout << "3. Non-Decimal to Non-Decimal Conversions\n";
    cout << "4. Exit\n";
    cout << "Select an option (1-4): ";
}

void displayDecimalToNonDecimalMenu() {
    clearScreen();
    printHeader("DECIMAL TO NON-DECIMAL CONVERSIONS");
    cout << "1. Decimal to Binary\n";
    cout << "2. Decimal to Octal\n";
    cout << "3. Decimal to Hexadecimal\n";
    cout << "4. Return to Main Menu\n";
    cout << "Select an option (1-4): ";
}

void displayNonDecimalToDecimalMenu() {
    clearScreen();
    printHeader("NON-DECIMAL TO DECIMAL CONVERSIONS");
    cout << "1. Binary to Decimal\n";
    cout << "2. Octal to Decimal\n";
    cout << "3. Hexadecimal to Decimal\n";
    cout << "4. Return to Main Menu\n";
    cout << "Select an option (1-4): ";
}

void displayNonDecimalToNonDecimalMenu() {
    clearScreen();
    printHeader("NON-DECIMAL TO NON-DECIMAL CONVERSIONS");
    cout << "1. Binary to Octal\n";
    cout << "2. Binary to Hexadecimal\n";
    cout << "3. Hexadecimal to Binary\n";
    cout << "4. Hexadecimal to Octal\n";
    cout << "5. Octal to Binary\n";
    cout << "6. Octal to Hexadecimal\n";
    cout << "7. Return to Main Menu\n";
    cout << "Select an option (1-7): ";
}

int main() {
	int choice;

	do {
		displayMainMenu();
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1: {
			int subChoice;
			do {
				displayDecimalToNonDecimalMenu();
				cin >> subChoice;
				cin.ignore();

				switch (subChoice) {
				case 1: decimalToBinaryConversion(); break;
				case 2: decimalToOctalConversion(); break;
				case 3: decimalToHexConversion(); break;
				case 4: break;
				default: cout << "Invalid choice. Please try again.\n";
				}
				if (subChoice != 4) {
					cout << "\nPress Enter to continue...";
					cin.ignore();
				}
			} while (subChoice != 4);
			break;
		}
		case 2: {
			int subChoice;
			do {
				displayNonDecimalToDecimalMenu();
				cin >> subChoice;
				cin.ignore();

				switch (subChoice) {
				case 1: binaryToDecimalConversion(); break;
				case 2: octalToDecimalConversion(); break;
				case 3: hexToDecimalConversion(); break;
				case 4: break;
				default: cout << "Invalid choice. Please try again.\n";
				}
				if (subChoice != 4) {
					cout << "\nPress Enter to continue...";
					cin.ignore();
				}
			} while (subChoice != 4);
			break;
		}
		case 3: {
			int subChoice;
			do {
				displayNonDecimalToNonDecimalMenu();
				cin >> subChoice;
				cin.ignore();

				switch (subChoice) {
				case 1: binaryToOctalConversion(); break;
				case 2: binaryToHexConversion(); break;
				case 3: hexToBinaryConversion(); break;
				case 4: hexToOctalConversion(); break;
				case 5: octalToBinaryConversion(); break;
				case 6: octalToHexConversion(); break;
				case 7: break;
				default: cout << "Invalid choice. Please try again.\n";
				}
				if (subChoice != 7) {
					cout << "\nPress Enter to continue...";
					cin.ignore();
				}
			} while (subChoice != 7);
			break;
		}
		case 4:
			cout << "Exiting program. Goodbye!\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
			cout << "\nPress Enter to continue...";
			cin.ignore();
		}
	} while (choice != 4);

	return 0;
}