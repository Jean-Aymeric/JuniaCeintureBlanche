#include <stdio.h>

#define conversionFrancsToEuros 0.15244902
#define conversionEurosToFrancs 6.55957
#define startPriceInFrancs 0.57
#define endPriceInEuros 0.90
#define startYear 1970
#define endYear 2020

float convertEurosToFrancs(float priceToConvert) {
    return priceToConvert * conversionEurosToFrancs;
}

float convertFrancsToEuros(float priceToConvert) {
    return priceToConvert * conversionFrancsToEuros;
}

float getConversionFactor() {
    return (endPriceInEuros - convertFrancsToEuros(startPriceInFrancs)) / (endYear - startYear);
}

float getPriceInEuroByYear(int year) {
    return ((year - startYear) * getConversionFactor()) + (startPriceInFrancs * conversionFrancsToEuros);
}

int main() {
    for (int i = 0; i < 100; i++) {
        printf("%d\t%f € \t%f f\n",
               startYear+i,
               getPriceInEuroByYear(startYear+i),
               convertEurosToFrancs(getPriceInEuroByYear(startYear+i)));
    }
    return 0;
}
