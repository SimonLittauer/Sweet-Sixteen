/*
 * 16n Faderbank Firmware Configuration
 * (c) 2017,2018,2020 by Brian Crabtree, Sean Hellfritsch, Tom Armitage, and Brendon Cassidy
 * MIT License
 */


/*
 * firmware metadata
 */

int MAJOR_VERSION = 0x02;
int MINOR_VERSION = 0x00;
int POINT_VERSION = 0x01;

/*
 * device metadata
 */

#if defined(__MKL26Z64__) || defined(__MK20DX128__) || defined(_LC_DEBUG)
const int DEVICE_ID = 0x03; // 16nLC, do not change, needed by editor
#else
const int DEVICE_ID = 0x02; // 16n, do not change, needed by editor
#endif

// restricts output to only channel 1 for development purposes
// #define DEV 1

// activates printing of debug messages
// #define DEBUG 1

// enables legacy compatibility with non-multiplexer boards
// #define V125

// define startup delay in milliseconds
// largely only needed for "Sweet-Sixteen" type devices
#define BOOTDELAY 10000

// allow the Tsesseract Modular GESS & midi note implementation:
#define GESS 1

// set to 0 to disable MIDI output from faders (CC/PB).
// GESS gate notes are not affected by this.
#define FADER_MIDI_OUTPUT 0

#ifdef GESS
// default GESS settings (midi note, velocity and channel):
byte _nNote[8] = { 30, 40, 50, 60, 70, 80, 90, 100 };
byte _nVelocity[8] = { 120, 120, 120, 120, 120, 120, 120, 120 };
byte _nChannel[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
#endif

// uncomment this to allow PITCHBEND for controller 127
// #define PITCHBEND 1

// I2C Address for Faderbank. 0x34 unless you ABSOLUTELY know what you are doing.
#define I2C_ADDRESS 0x34

// Optional "resolution mod" for I2C master mode (1-14).
// Uncomment to quantize fader updates to fixed steps.
// Output value is still scaled to full 14-bit range (0..16383).
// #define I2C_FADER_RESOLUTION_BITS 8

#ifdef DEV

const int channelCount = 1;
const int ports[] = {A0};

#else

const int channelCount = 16;

#endif
