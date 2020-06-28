# WaveCMP 
WaveCMP is a small program that is designed to find how long a sine wave is above or below a certain threshold.

*Disclaimer: the results from this program are not intended to be 100% accurate. Do not use this program for any applications where extreme precision and accuracy is necessary.*

## Usage

WaveCMP accepts input in form of a file. This file can be supplied as a single command line argument to the path of the file, or it can be inputted as a string of text after starting the program.

## Building

You can run the file `build.sh` builds this project. The commands it runs are:

```
g++ src/wavecmp.cpp -c -o wavecmp.o -Iinclude/
g++ src/func.cpp -c -o func.o -Iinclude/
g++ wavecmp.o func.o -o wavecmp
```

## How does it work?

First, the parameters for the function `A*sin(((2*pi)/B) * (x-C)) + D` are plugged in, and then that function is compared with the comparison value supplied by the user to find the maximum value. If graphed, this would look like a function that is flattened except when the wave goes above the specified threshold. Then, it uses the trapezoidal rule to find the definite integral for the resulting function. This is divided by the integral of the same function over half a period, accounting for one cycle of a wave. This ratio is how many half-periods the sine wave is above the threshold. Then, that value is multiplied by the actual half-period, and is outputted by the program.