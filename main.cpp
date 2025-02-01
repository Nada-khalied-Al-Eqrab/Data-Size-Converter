#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Function to convert data size from one unit to another
double convertDataSize(double value, const string &fromUnit, const string &toUnit) {
    const double bitToByte = 1.0 / 8;
    const double byteToKilobyte = 1.0 / 1024;
    const double kilobyteToMegabyte = 1.0 / 1024;
    const double megabyteToGigabyte = 1.0 / 1024;
    const double gigabyteToTerabyte = 1.0 / 1024;

    // Conversion factors
    double inBytes;

    // Convert from the input unit to bytes
    if (fromUnit == "bit") {
        inBytes = value * bitToByte;
    } else if (fromUnit == "byte") {
        inBytes = value;
    } else if (fromUnit == "kilobyte") {
        inBytes = value / byteToKilobyte;
    } else if (fromUnit == "megabyte") {
        inBytes = value / (byteToKilobyte * kilobyteToMegabyte);
    } else if (fromUnit == "gigabyte") {
        inBytes = value / (byteToKilobyte * kilobyteToMegabyte * megabyteToGigabyte);
    } else if (fromUnit == "terabyte") {
        inBytes = value / (byteToKilobyte * kilobyteToMegabyte * megabyteToGigabyte * gigabyteToTerabyte);
    } else {
        throw invalid_argument("Invalid input unit.");
    }

    // Convert from bytes to the target unit
    if (toUnit == "bit") {
        return inBytes / bitToByte;
    } else if (toUnit == "byte") {
        return inBytes;
    } else if (toUnit == "kilobyte") {
        return inBytes * byteToKilobyte;
    } else if (toUnit == "megabyte") {
        return inBytes * (byteToKilobyte * kilobyteToMegabyte);
    } else if (toUnit == "gigabyte") {
        return inBytes * (byteToKilobyte * kilobyteToMegabyte * megabyteToGigabyte);
    } else if (toUnit == "terabyte") {
        return inBytes * (byteToKilobyte * kilobyteToMegabyte * megabyteToGigabyte * gigabyteToTerabyte);
    } else {
        throw invalid_argument("Invalid output unit.");
    }
}

int main() {
    double value;
    string fromUnit, toUnit;

    cout << "Welcome to the Data Size Converter!\n";
    cout << "Supported units: bit, byte, kilobyte, megabyte, gigabyte, terabyte\n";

    // Input: Value and units
    cout << "Enter the value to convert: ";
    cin >> value;
    cout << "Enter the unit of the value (bit, byte, kilobyte, megabyte, gigabyte, terabyte): ";
    cin >> fromUnit;
    cout << "Enter the unit to convert to (bit, byte, kilobyte, megabyte, gigabyte, terabyte): ";
    cin >> toUnit;

    try {
        // Perform conversion
        double result = convertDataSize(value, fromUnit, toUnit);
        cout << "The converted value is: " << result << " " << toUnit << endl;
    } catch (const invalid_argument &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
