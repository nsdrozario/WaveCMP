# WaveCMP 
WaveCMP is a small program that is designed to find how long a sine wave is above or below a certain threshold.

*Disclaimer: the results from this program are not intended to be 100% accurate. Do not use this program for any applications where extreme precision and accuracy is necessary.*

## Binaries

Binaries for Windows (64 bit) are available in the [releases category](https://github.com/nsdrozario/WaveCMP/releases/) of this repository. 

## Usage

WaveCMP uses a GUI for input. The input fields specify parameters for solving the length of the sum of intervals the wave breaks the specified threshhold.

### Wave function parameters

These parameters construct `f(x)`, which is a sine wave. This is the function WaveCMP will compare against the given threshold. 

- **Amplitude**: the amplitude of the wave, defined as the distance from the crest (maximum point) and the mean (constant value the wave oscillates around) of the wave
- **Period**: the length of the interval that is repeated periodically throughout the wave (the wave starts at the same position for this number of units)
- **Phase**: the horizontal shift of the wave.
- **Mean**: the constant value that the wave oscillates around (for example, the mean of `sin(x)` is `0`.)

### WaveCMP-specific parameters

These parameters define how WaveCMP will calculate the answer.

  -**Resolution**: how many data points to use per unit when calculating the definite integral of `max(f(x), mean)`, where `f(x)` is constructed by the parameters listed above, and `mean` is the mean value supplied. Inversely proportional to Δx.
  -**Interval start**: The inclusive lower bound of the interval the program will analyze.
  -**Interval end**:  The inclusive upper bound of the interval the program will analyze.
  -**Comparator**: Whether to compare when wave is below/above threshold; currently this function is not implemented and the program will only output when the wave is above the threshold even when otherwise selected (this will be fixed on a later update).
  -**Comparison value**: The constant for comparing the wave function's value against (called the threshold by the above descriptions of this program's parameters).

## Building

Simply run `compile_project.sh`. Requires `gtkmm-3.0`, `pkg-config` and `g++` to be installed.

## How does it work?

First, the parameters for the function `A*sin(((2*pi)/B) * (x-C)) + D` are plugged in, and then that function is compared with the comparison value supplied by the user to find the maximum value. If graphed, this would look like a function that is flattened except when the wave goes above the specified threshold. Then, it uses the trapezoidal rule to find the definite integral for the resulting function. This is divided by the integral of the same function over half a period, accounting for one cycle of a wave. This ratio is how many half-periods the sine wave is above the threshold. Then, that value is multiplied by the actual half-period, and is outputted by the program.
