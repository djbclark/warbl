//Chart for determining the numbers of steps down from the current note to the next lower note on the scale, for sliding
const PROGMEM byte steps[] = {

  1, //B 59
  1, //C 60
  2, //C# 61
  1, //D 62//Ionian starts here
  1, //D# 63
  2, //E 64
  1, //F 65
  2, //F# 66
  1, //G 67
  1, //G# 68
  2, //A 69//Mixolydian starts here
  1, //Bb 70//natural minor starts here
  2, //B 71
  1, //C 72
  2, //C# 73
  1, //D 74
  2, //D# 75
  2, //E 76
  1, //F 77
  2, //F# 78
  1, //G 79
  1, //G# 80
  2, //A 81
  1, //Bb 82
  2, //B 83
  1, //C 84
 };



//Fingering Charts
//these are stored in PROGMEM to save SRAM space.
//The fingering charts can be either explicit, meaning an exact pattern is required to return a note, or general, where the highest uncovered hole is used to determine the note. This allows use to ignore all the holes below that, so we catch various open fingering patterns without having to list all of them.
//we check the explicit patterns first, and if there's not a match we check the general patterns (if desired).


// MAE FOOFOO 17 Nov 2018 - Added full key map and vibrato flags
//Tin whistle/Irish flute
struct tinwhistle_explicit_entry {
  uint8_t midi_note;
  uint8_t vibrato; //send pitch bend down
};

const struct tinwhistle_explicit_entry tinwhistle_explicit[64] PROGMEM = {  //explicit fingering patterns that aren't covered by the general patterns below. Sensor numbers from left to right are L1,L2,L3,R1,R2,R3,R4. The Lthumb, R4 (pinky) and bell sensors are ignored for now.
{73, 0}, //0000000 C#
{73, 0}, //0000001 C#
{73, 0}, //0000010 C#
{73, 0}, //0000011 C#
{73, 0}, //0000100 C#
{73, 0}, //0000101 C#
{73, 0}, //0000110 C#
{73, 0}, //0000111 C#
{73, 0}, //0001000 C#
{73, 0}, //0001001 C#
{73, 0}, //0001010 C#
{73, 0}, //0001011 C#
{73, 0}, //0001100 C#
{73, 0}, //0001101 C#
{73, 0}, //0001110 C#
{73, 0}, //0001111 C#
{73, 0}, //0010000 C#
{73, 0}, //0010001 C#
{73, 0}, //0010010 C#
{73, 0}, //0010011 C#
{73, 0}, //0010100 C#
{73, 0}, //0010101 C#
{73, 0}, //0010110 C#
{73, 0}, //0010111 C#
{72, 0b000010}, //0011000 C#
{72, 1}, //0011001 C | kVibratoMask;
{72, 1}, //0011010 C| kVibratoMask; 
{72, 1}, //0011011 C| kVibratoMask; 
{72, 0}, //0011100 C
{72, 0}, //0011101 C
{72, 0}, //0011110 C
{74, 0}, //0011111 D
{71, 0b000010}, //0100000 B
{71, 1}, //0100001 B | kVibratoMask;
{71, 1}, //0100010 B | kVibratoMask;
{71, 1}, //0100011 B | kVibratoMask;
{71, 0}, //0100100 B
{71, 0}, //0100101 B
{71, 0}, //0100110 B
{71, 0}, //0100111 B
{71, 0}, //0101000 B
{71, 0}, //0101001 B
{71, 0}, //0101010 B
{71, 0}, //0101011 B
{71, 0}, //0101100 B
{71, 0}, //0101101 B
{71, 0}, //0101110 B
{71, 0}, //0101111 B
{69, 0b000010}, //0110000 A
{69, 1}, //0110001 A | kVibratoMask;
{69, 1}, //0110010 A | kVibratoMask;
{69, 1}, //0110011 A | kVibratoMask;
{69, 0}, //0110100 A
{69, 0}, //0110101 A
{69, 0}, //0110110 A
{68, 0}, //0110111 G#
{67, 0b000010}, //0111000 G#
{67, 1}, //0111001 G | kVibratoMask;
{67, 1}, //0111010 G | kVibratoMask;
{67, 1}, //0111011 G | kVibratoMask;
{66, 0}, //0111100 F#
{65, 0}, //0111101 F#
{64, 0}, //0111110 E
{62, 0}, //0111111 D


 };


// MAE FOOFOO 17 Nov 2018 - Added full key map and vibrato flags
//Uilleann
struct uilleann_explicit_entry {
  uint8_t midi_note;
  uint8_t vibrato; //send pitch bend down
};

const struct uilleann_explicit_entry uilleann_explicit[128] PROGMEM = {  //explicit fingering patterns that aren't covered by the general patterns below. Sensor numbers from left to right are L1,L2,L3,R1,R2,R3,R4. The bell sensor is ignored for now.
{73, 0}, //0000000 C#
{73, 0b000010}, //0000001 C#
{73, 0}, //0000010 C#
{73, 0}, //0000011 C#
{73, 0}, //0000100 C#
{73, 1}, //0000101 C#
{73, 0}, //0000110 C#
{73, 0}, //0000111 C#
{73, 0}, //0001000 C#
{73, 0}, //0001001 C#
{73, 0}, //0001010 C#
{73, 0}, //0001011 C#
{73, 0}, //0001100 C#
{73, 0}, //0001101 C#
{73, 0}, //0001110 C#
{73, 0}, //0001111 C#
{73, 0}, //0010000 C#
{73, 0}, //0010001 C#
{73, 0}, //0010010 C#
{73, 0}, //0010011 C#
{73, 0}, //0010100 C#
{73, 0}, //0010101 C#
{73, 0}, //0010110 C#
{73, 0}, //0010111 C#
{73, 0}, //0011000 C#
{73, 0}, //0011001 C#
{73, 0}, //0011010 C#
{73, 0}, //0011011 C#
{73, 0}, //0011100 C#
{73, 0}, //0011101 C#
{73, 0}, //0011110 C#
{73, 0}, //0011111 C#
{73, 0}, //0100000 C#
{73, 0}, //0100001 C#
{73, 0}, //0100010 C#
{73, 0}, //0100011 C#
{73, 0}, //0100100 C#
{73, 0}, //0100101 C#
{73, 0}, //0100110 C#
{73, 0}, //0100111 C#
{73, 0}, //0101000 C#
{73, 0}, //0101001 C#
{73, 0}, //0101010 C#
{73, 0}, //0101011 C#
{73, 0}, //0101100 C#
{73, 0}, //0101101 C#
{73, 0}, //0101110 C#
{73, 0}, //0101111 C#
{72, 0b000010}, //0110000 C
{72, 0b000010}, //0110001 C
{72, 0}, //0110010 C
{72, 0b000010}, //0110011 C
{72, 1}, //0110100 C | kVibratoMask;
{72, 1}, //0110101 C | kVibratoMask;
{72, 0}, //0110110 C | kVibratoMask;
{72, 1}, //0110111 C | kVibratoMask;
{72, 0}, //0111000 C
{72, 0b000010}, //0111001 C
{72, 0}, //0111010 C
{72, 0}, //0111011 C
{72, 0}, //0111100 C
{72, 1}, //0111101 C | kVibratoMask;
{72, 0}, //0111110 C
{73, 0}, //0111111 C#
{71, 0}, //1000000 B
{71, 0b000010}, //1000001 B
{71, 0}, //1000010 B
{71, 0b000010}, //1000011 B
{71, 0}, //1000100 B
{71, 1}, //1000101 B | kVibratoMask;
{71, 0}, //1000110 B
{71, 1}, //1000111 B | kVibratoMask;
{70, 0}, //1001000 Bb
{71, 0}, //1001001 B
{70, 0}, //1001010 Bb
{71, 0}, //1001011 B
{71, 0}, //1001100 B
{71, 0}, //1001101 B
{71, 0}, //1001110 B
{71, 0}, //1001111 B
{71, 0}, //1010000 B
{71, 0}, //1010001 B
{71, 0}, //1010010 B
{71, 0}, //1010011 B
{71, 0}, //1010100 B
{71, 0}, //1010101 B
{71, 0}, //1010110 B
{71, 0}, //1010111 B
{71, 0}, //1011000 B
{71, 0}, //1011001 B
{71, 0}, //1011010 B
{71, 0}, //1011011 B
{71, 0}, //1011100 B
{71, 0}, //1011101 B
{71, 0}, //1011110 B
{71, 0}, //1011111 B
{69, 0}, //1100000 A
{69, 0b000010}, //1100001 A
{69, 0}, //1100010 A
{69, 0b000010}, //1100011 A
{69, 0}, //1100100 A
{69, 1}, //1100101 A | kVibratoMask;
{69, 0}, //1100110 A
{69, 1}, //1100111 A | kVibratoMask;
{68, 0}, //1101000 G#
{69, 0}, //1101001 A
{68, 0}, //1101010 G#
{69, 0}, //1101011 A
{69, 0}, //1101100 A
{69, 0}, //1101101 A
{69, 0}, //1101110 A
{69, 0}, //1101111 A
{67, 0}, //1110000 G
{67, 0b000010}, //1110001 G
{67, 0}, //1110010 G
{67, 0b000010}, //1110011 G
{67, 0}, //1110100 G
{67, 1}, //1110101 G | kVibratoMask
{67, 0}, //1110110 G
{67, 1}, //1110111 G | kVibratoMask
{66, 0}, //1111000 F#
{66, 0}, //1111001 F#
{65, 0}, //1111010 F#
{66, 0}, //1111011 F#
{64, 0}, //1111100 E
{64, 0}, //1111101 E
{63, 0}, //1111110 Eb
{62, 0} //1111111 D

};


//GHB/Scottish smallpipes
struct GHB_explicit_entry {
  uint8_t midi_note;
};


const struct GHB_explicit_entry GHB_explicit[128] PROGMEM = {  //explicit fingering patterns. Sensor numbers from left to right are L1,L2,L3,R1,R2,R3,R4. The bell sensor is ignored.

{72}, //0000000 G (as written, actual note sounded is Bb, like on real GHB) Noteshift variable is used to transpose from key of D (all fingerings are based on D) to Bb. Uses equal temperament, but temperament can be set in app (e.g. Universal Piper).
{72}, //0000001 G
{72}, //0000010 G
{72}, //0000011 G
{72}, //0000100 G
{72}, //0000101 G
{72}, //0000110 G
{72}, //0000111 G
{72}, //0001000 G
{72}, //0001001 G
{72}, //0001010 G
{72}, //0001011 G
{72}, //0001100 G
{72}, //0001101 G
{72}, //0001110 G
{72}, //0001111 G
{72}, //0010000 G
{72}, //0010001 G
{72}, //0010010 G
{72}, //0010011 G
{72}, //0010100 G
{72}, //0010101 G
{72}, //0010110 G
{72}, //0010111 G
{72}, //0011000 G
{72}, //0011001 G
{72}, //0011010 G
{72}, //0011011 G
{72}, //0011100 G
{72}, //0011101 G
{72}, //0011110 G
{72}, //0011111 G
{72}, //0100000 G
{72}, //0100001 G
{72}, //0100010 G
{72}, //0100011 G
{72}, //0100100 G
{72}, //0100101 G
{72}, //0100110 G
{72}, //0100111 G
{72}, //0101000 G
{72}, //0101001 G
{72}, //0101010 G
{72}, //0101011 G
{72}, //0101100 G
{72}, //0101101 G
{72}, //0101110 G
{72}, //0101111 G
{72}, //0110000 G
{72}, //0110001 G
{72}, //0110010 G
{72}, //0110011 G
{72}, //0110100 G
{72}, //0110101 G
{72}, //0110110 G
{72}, //0110111 G
{72}, //0111000 G
{72}, //0111001 G
{72}, //0111010 G
{72}, //0111011 G
{72}, //0111100 G
{72}, //0111101 G
{72}, //0111110 G
{73}, //0111111 G#
{71}, //1000000 F#
{71}, //1000001 F#
{71}, //1000010 F#
{71}, //1000011 F#
{71}, //1000100 F#
{71}, //1000101 F#
{71}, //1000110 F#
{71}, //1000111 F#
{71}, //1001000 F#
{71}, //1001001 F#
{71}, //1001010 F#
{71}, //1001011 F#
{71}, //1001100 F#
{71}, //1001101 F#
{71}, //1001110 F#
{71}, //1001111 F#
{71}, //1010000 F#
{71}, //1010001 F#
{71}, //1010010 F#
{71}, //1010011 F#
{71}, //1010100 F#
{71}, //1010101 F#
{71}, //1010110 F#
{71}, //1010111 F#
{71}, //1011000 F#
{71}, //1011001 F#
{70}, //1011010 F
{70}, //1011011 F#
{71}, //1011100 F#
{71}, //1011101 F#
{71}, //1011110 F#
{71}, //1011111 F#
{69}, //1100000 E
{69}, //1100001 E
{69}, //1100010 E
{69}, //1100011 E
{69}, //1100100 E
{69}, //1100101 E
{69}, //1100110 E
{69}, //1100111 E
{69}, //1101000 E
{69}, //1101001 E
{69}, //1101010 E
{69}, //1101011 E
{69}, //1101100 E
{69}, //1101101 E
{69}, //1101110 E
{69}, //1101111 E
{67}, //1110000 D
{67}, //1110001 D
{67}, //1110010 D
{67}, //1110011 D
{67}, //1110100 D
{67}, //1110101 D
{67}, //1110110 D
{67}, //1110111 D
{66}, //1111000 C#
{66}, //1111001 C#
{65}, //1111010 C
{65}, //1111011 C
{64}, //1111100 B
{63}, //1111101 A#
{62}, //1111110 A
{60}, //1111111 G

};



//Northumbrian
struct northumbrian_explicit_entry {
  uint8_t keys;
  uint8_t midi_note;
  uint8_t expressive_hole; //this is the hole that can be partially covered to bend the given note down to the next lowest note on the scale.
  uint8_t distance; //the number of half steps (semitones) down to the next lowest note on the scale, so we know how far down to bend the current note to reach it.
};

const struct northumbrian_explicit_entry northumbrian_explicit[0] PROGMEM = {  //explicit fingering patterns. Sensor numbers from left to right are L1,L2,L3,R1,R2,R3,R4. The bell sensor is ignored.

  //{0b01111111, 74, 9, 2} // high G

};

struct northumbrian_general_entry {
  uint8_t keys;
  uint8_t midi_note;
};

const struct northumbrian_general_entry northumbrian_general[9]PROGMEM  = {  //general fingering pattern for each MIDI note. In this case, the index (position from right) of the leftmost uncovered hole is used to determine the MIDI note. This way all other holes below that one are ignored.
  {127, 60},//This will be interpreted as slient (closed pipe). The findleftmostunsetbit function returns 127 if all holes are covered.
  {0, 62},//G --- noteshift variable is set by default to lower the key to F, which is most common for Northumbrian.
  {1, 64},//A
  {2, 66},//B
  {3, 67},//C
  {4, 69},//D
  {5, 71},//E
  {6, 73},//F#
  {7, 74},//high G

};



//Gaita
struct gaita_explicit_entry {
  uint8_t midi_note;
};


const struct gaita_explicit_entry gaita_explicit[256]PROGMEM  = {  //general fingering pattern for each MIDI note. In this case, the index (position from right) of the leftmost uncovered hole is used to determine the MIDI note. This way all other holes below that one are ignored.
{75}, //00000000 C  MIDI notes in the GAITA chart are shifted 1 note upward to bring the base note to a similar range as other instruments, because this base note is used in octave-shifting calculations. The notes are shifted back down again later to bring them in tune.
{75}, //00000001 
{75}, //00000010 C
{75}, //00000011 
{75}, //00000100 
{75}, //00000101 
{75}, //00000110 
{75}, //00000111 
{75}, //00001000 
{75}, //00001001 C
{75}, //00001010 
{75}, //00001011 
{75}, //00001100 
{75}, //00001101 
{75}, //00001110 
{74}, //00001111 B
{75}, //00010000 
{75}, //00010001 
{75}, //00010010 
{75}, //00010011 
{75}, //00010100 
{75}, //00010101 
{75}, //00010110 
{75}, //00010111 
{75}, //00011000 
{75}, //00011001 
{75}, //00011010 
{75}, //00011011 
{75}, //00011100 
{75}, //00011101 
{75}, //00011110 
{75}, //00011111 
{75}, //00100000 
{75}, //00100001 
{75}, //00100010 
{75}, //00100011 
{75}, //00100100 
{75}, //00100101 
{75}, //00100110 
{75}, //00100111 
{75}, //00101000 
{75}, //00101001 
{75}, //00101010 
{73}, //00101011 A#
{73}, //00101100 
{73}, //00101101 
{73}, //00101110 
{73}, //00101111 
{80}, //00110000 F
{74}, //00110001 B
{74}, //00110010 
{74}, //00110011 
{74}, //00110100 
{74}, //00110101 
{74}, //00110110 
{74}, //00110111 
{79}, //00111000 E
{74}, //00111001 
{78}, //00111010 D#
{74}, //00111011 
{77}, //00111100 D
{74}, //00111101 
{75}, //00111110 
{74}, //00111111 B
{84}, //01000000 A
{84}, //01000001 A
{84}, //01000010 A
{73}, //01000011 A#
{73}, //01000100 
{73}, //01000101 
{84}, //01000110 A
{84}, //01000111 
{84}, //01001000 
{73}, //01001001 A#
{73}, //01001010 
{73}, //01001011 
{73}, //01001100 
{73}, //01001101 
{73}, //01001110 
{73}, //01001111 
{83}, //01010000 G#
{83}, //01010001 
{83}, //01010010 
{83}, //01010011 
{83}, //01010100 G#
{83}, //01010101 
{83}, //01010110 
{75}, //01010111 C
{75}, //01011000 
{75}, //01011001 
{75}, //01011010 
{75}, //01011011 
{75}, //01011100 
{75}, //01011101 
{83}, //01011110 G#
{75}, //01011111 
{82}, //01100000 G
{82}, //01100001 G
{82}, //01100010 G
{82}, //01100011 G
{82}, //01100100 
{82}, //01100101 
{82}, //01100110 
{82}, //01100111 
{82}, //01101000 
{82}, //01101001 G
{82}, //01101010 
{82}, //01101011 
{81}, //01101100 F#
{81}, //01101101 
{81}, //01101110 
{82}, //01101111 G
{80}, //01110000 F
{80}, //01110001 F
{80}, //01110010 F
{80}, //01110011 
{80}, //01110100 
{80}, //01110101 
{80}, //01110110 F
{80}, //01110111 F
{79}, //01111000 E
{79}, //01111001 E
{78}, //01111010 D#
{78}, //01111011 D#
{77}, //01111100 D
{76}, //01111101 C#
{75}, //01111110 C
{74}, //01111111 B
{74}, //10000000 B
{74}, //10000001 
{74}, //10000010 
{74}, //10000011 B
{74}, //10000100 
{74}, //10000101 
{74}, //10000110 B
{74}, //10000111 
{74}, //10001000 
{74}, //10001001 B
{74}, //10001010 B
{74}, //10001011 
{74}, //10001100 
{74}, //10001101 
{74}, //10001110 B
{74}, //10001111 B
{74}, //10010000 
{74}, //10010001 
{74}, //10010010 
{74}, //10010011 
{74}, //10010100 
{74}, //10010101 
{74}, //10010110 
{74}, //10010111 
{74}, //10011000 
{74}, //10011001 
{74}, //10011010 
{74}, //10011011 
{74}, //10011100 
{74}, //10011101 
{74}, //10011110 
{74}, //10011111 
{73}, //10100000 A#
{73}, //10100001 A#
{73}, //10100010 A#
{73}, //10100011 A#
{73}, //10100100 A#
{73}, //10100101 A#
{73}, //10100110 A#
{73}, //10100111 A#
{73}, //10101000 A#
{73}, //10101001 A#
{73}, //10101010 A#
{73}, //10101011 
{73}, //10101100 A#
{73}, //10101101 A#
{73}, //10101110 A#
{73}, //10101111 A#
{75}, //10110000 C
{75}, //10110001 C
{75}, //10110010 C
{75}, //10110011 C
{75}, //10110100 
{75}, //10110101 C
{75}, //10110110 C
{73}, //10110111 A#
{75}, //10111000 
{75}, //10111001 C
{75}, //10111010 C
{75}, //10111011 C
{75}, //10111100 C
{75}, //10111101 
{75}, //10111110 C
{75}, //10111111 C
{72}, //11000000 A
{72}, //11000001 A
{72}, //11000010 A
{72}, //11000011 A
{72}, //11000100 
{72}, //11000101 
{72}, //11000110 A
{72}, //11000111 
{72}, //11001000 
{72}, //11001001 A
{72}, //11001010 A
{72}, //11001011 
{72}, //11001100 
{72}, //11001101 
{72}, //11001110 A
{72}, //11001111 A
{71}, //11010000 G#
{74}, //11010001 B
{71}, //11010010 G#
{71}, //11010011 G#
{71}, //11010100 
{71}, //11010101 
{71}, //11010110 G#
{71}, //11010111 
{71}, //11011000 
{71}, //11011001 G#
{71}, //11011010 G#
{71}, //11011011 
{71}, //11011100 
{71}, //11011101 
{71}, //11011110 G#
{71}, //11011111 G#
{70}, //11100000 G
{70}, //11100001 G
{70}, //11100010 G
{70}, //11100011 
{70}, //11100100 
{70}, //11100101 G
{70}, //11100110 G
{70}, //11100111 G
{69}, //11101000 F#
{70}, //11101001 G
{70}, //11101010 G
{70}, //11101011 
{69}, //11101100 F#
{69}, //11101101 
{70}, //11101110 G
{70}, //11101111 
{68}, //11110000 F
{68}, //11110001 F
{68}, //11110010 F
{68}, //11110011 F
{68}, //11110100 
{68}, //11110101 F
{68}, //11110110 F
{68}, //11110111 F
{67}, //11111000 E
{67}, //11111001 E
{66}, //11111010 D#
{66}, //11111011 D#
{65}, //11111100 D
{64}, //11111101 C#
{63}, //11111110 C
{62}, //11111111 B

};



//North American Flute
struct naf_explicit_entry {
  uint8_t midi_note;
};

const struct naf_explicit_entry naf_explicit[128]PROGMEM  = {  //general fingering pattern for each MIDI note. In this case, the index (position from right) of the leftmost uncovered hole is used to determine the MIDI note. This way all other holes below that one are ignored.
{75}, //0000000 D#5
{74}, //0000001 D5
{74}, //0000010 D5
{73}, //0000011 C#5
{74}, //0000100 D5
{73}, //0000101 C#5
{73}, //0000110 C#5
{72}, //0000111 C5
{74}, //0001000 D5
{73}, //0001001 C#5
{73}, //0001010 C#5
{72}, //0001011 C5
{73}, //0001100 C#5
{72}, //0001101 C5
{72}, //0001110 C5
{71}, //0001111 B4
{74}, //0010000 D5
{73}, //0010001 C#5
{73}, //0010010 C#5
{72}, //0010011 C5
{73}, //0010100 C#5
{72}, //0010101 C5
{72}, //0010110 C5
{71}, //0010111 B4
{73}, //0011000 C#5
{72}, //0011001 C5
{72}, //0011010 C5
{71}, //0011011 B4
{77}, //0011100 F5
{76}, //0011101 E5
{76}, //0011110 E5
{75}, //0011111 D#5
{74}, //0100000 D5
{73}, //0100001 C#5
{73}, //0100010 C#5
{72}, //0100011 C5
{73}, //0100100 C#5
{72}, //0100101 C5
{71}, //0100110 B4
{70}, //0100111 A#4
{78}, //0101000 F#5
{77}, //0101001 F5
{77}, //0101010 F5
{76}, //0101011 E5
{77}, //0101100 F5
{76}, //0101101 E5
{76}, //0101110 E5
{75}, //0101111 D#5
{72}, //0110000 C5
{71}, //0110001 B4
{71}, //0110010 B4
{70}, //0110011 A#4
{71}, //0110100 B4
{70}, //0110101 A#4
{70}, //0110110 A#4
{69}, //0110111 A4
{77}, //0111000 F5
{76}, //0111001 E5
{76}, //0111010 E5
{75}, //0111011 D#5
{76}, //0111100 E5
{75}, //0111101 D#5
{75}, //0111110 D#5
{74}, //0111111 D5
{73}, //1000000 C#5
{72}, //1000001 C5
{72}, //1000010 C5
{71}, //1000011 B4
{72}, //1000100 C5
{71}, //1000101 B4
{70}, //1000110 A#4
{69}, //1000111 A4
{72}, //1001000 C5
{71}, //1001001 B4
{70}, //1001010 A#4
{69}, //1001011 A4
{71}, //1001100 B4
{70}, //1001101 A#4
{70}, //1001110 A#4
{69}, //1001111 A4
{72}, //1010000 C5
{71}, //1010001 B4
{71}, //1010010 B4
{70}, //1010011 A#4
{71}, //1010100 B4
{70}, //1010101 A#4
{70}, //1010110 A#4
{69}, //1010111 A4
{71}, //1011000 B4
{70}, //1011001 A#4
{70}, //1011010 A#4
{69}, //1011011 A4
{70}, //1011100 A#4
{69}, //1011101 A4
{69}, //1011110 A4
{68}, //1011111 G#4
{71}, //1100000 B4
{70}, //1100001 A#4
{70}, //1100010 A#4
{69}, //1100011 A4
{70}, //1100100 A#4
{69}, //1100101 A4
{69}, //1100110 A4
{68}, //1100111 G#4
{70}, //1101000 A#4
{69}, //1101001 A4
{69}, //1101010 A4
{68}, //1101011 G#4
{69}, //1101100 A4
{68}, //1101101 G#4
{68}, //1101110 G#4
{67}, //1101111 G4
{69}, //1110000 A4
{68}, //1110001 G#4
{68}, //1110010 G#4
{67}, //1110011 G4
{68}, //1110100 G#4
{67}, //1110101 G4
{67}, //1110110 G4
{66}, //1110111 F#4
{67}, //1111000 G4
{66}, //1111001 F#4
{66}, //1111010 F#4
{65}, //1111011 F4
{65}, //1111100 F4
{64}, //1111101 E4
{62}, //1111110 D4
{63} //1111111 D#4

};



//Kaval
struct kaval_explicit_entry {
  uint8_t midi_note;
};

const struct kaval_explicit_entry kaval_explicit[128]PROGMEM  = {  //general fingering pattern for each MIDI note. In this case, the index (position from right) of the leftmost uncovered hole is used to determine the MIDI note. This way all other holes below that one are ignored.

{70}, //0000000 Bb
{70}, //0000001 
{70}, //0000010 
{70}, //0000011 
{70}, //0000100 
{70}, //0000101 
{70}, //0000110 
{70}, //0000111 
{70}, //0001000 
{70}, //0001001 
{70}, //0001010 
{70}, //0001011 
{70}, //0001100 
{70}, //0001101 
{70}, //0001110 
{70}, //0001111 
{70}, //0010000 
{70}, //0010001 
{70}, //0010010 
{70}, //0010011 
{70}, //0010100 
{70}, //0010101 
{70}, //0010110 
{70}, //0010111 
{70}, //0011000 
{70}, //0011001 
{70}, //0011010 
{70}, //0011011 
{70}, //0011100 
{70}, //0011101 
{70}, //0011110 
{70}, //0011111 
{70}, //0100000 
{70}, //0100001 
{70}, //0100010 
{70}, //0100011 
{70}, //0100100 
{70}, //0100101 
{70}, //0100110 
{70}, //0100111 
{70}, //0101000 
{70}, //0101001 
{70}, //0101010 
{70}, //0101011 
{70}, //0101100 
{70}, //0101101 
{70}, //0101110 
{70}, //0101111 
{70}, //0110000 
{70}, //0110001 
{70}, //0110010 
{70}, //0110011 
{70}, //0110100 
{70}, //0110101 
{70}, //0110110 
{70}, //0110111 
{70}, //0111000 
{70}, //0111001 
{70}, //0111010 
{70}, //0111011 
{70}, //0111100 
{70}, //0111101 
{70}, //0111110 
{70}, //0111111 
{69}, //1000000 A
{69}, //1000001 
{69}, //1000010 
{69}, //1000011 
{69}, //1000100 
{69}, //1000101 
{69}, //1000110 
{69}, //1000111 
{69}, //1001000 
{69}, //1001001 
{69}, //1001010 
{69}, //1001011 
{69}, //1001100 
{69}, //1001101 
{69}, //1001110 
{69}, //1001111 
{69}, //1010000 
{69}, //1010001 
{69}, //1010010 
{69}, //1010011 
{69}, //1010100 
{69}, //1010101 
{69}, //1010110 
{69}, //1010111 
{69}, //1011000 
{69}, //1011001 
{69}, //1011010 
{69}, //1011011 
{69}, //1011100 
{69}, //1011101 
{69}, //1011110 
{69}, //1011111 
{68}, //1100000 G#
{68}, //1100001 
{68}, //1100010 
{68}, //1100011 
{68}, //1100100 
{68}, //1100101 
{68}, //1100110 
{68}, //1100111 
{68}, //1101000 
{68}, //1101001 
{68}, //1101010 
{68}, //1101011 
{68}, //1101100 
{68}, //1101101 
{68}, //1101110 
{68}, //1101111 
{67}, //1110000 G
{67}, //1110001 
{67}, //1110010 
{67}, //1110011 
{67}, //1110100 
{67}, //1110101 
{67}, //1110110 
{67}, //1110111 
{66}, //1111000 F#
{66}, //1111001 
{66}, //1111010 
{66}, //1111011 
{65}, //1111100 F
{65}, //1111101 
{64}, //1111110 E
{62} //1111111 D

};





//Recorder
struct recorder_explicit_entry {
  uint8_t midi_note;
};

const struct recorder_explicit_entry recorder_explicit[128]PROGMEM  = {  //general fingering pattern for each MIDI note. In this case, the index (position from right) of the leftmost uncovered hole is used to determine the MIDI note. This way all other holes below that one are ignored.

{74}, //0000000 C
{74}, //0000001 C
{74}, //0000010 C
{74}, //0000011 C
{74}, //0000100 C
{74}, //0000101 C
{74}, //0000110 C
{74}, //0000111 C
{74}, //0001000 C
{74}, //0001001 C
{74}, //0001010 C
{74}, //0001011 C
{74}, //0001100 C
{74}, //0001101 C
{74}, //0001110 C
{74}, //0001111 C
{74}, //0010000 C
{74}, //0010001 C
{74}, //0010010 C
{74}, //0010011 C
{74}, //0010100 C
{74}, //0010101 C
{74}, //0010110 C
{74}, //0010111 C
{74}, //0011000 C
{74}, //0011001 C
{74}, //0011010 C
{74}, //0011011 C
{74}, //0011100 C
{74}, //0011101 C
{74}, //0011110 C
{74}, //0011111 C
{74}, //0100000 C
{74}, //0100001 C
{74}, //0100010 C
{74}, //0100011 C
{74}, //0100100 C
{74}, //0100101 C
{74}, //0100110 C
{74}, //0100111 C
{74}, //0101000 C
{74}, //0101001 C
{74}, //0101010 C
{74}, //0101011 C
{74}, //0101100 C
{74}, //0101101 C
{74}, //0101110 C
{74}, //0101111 C
{74}, //0110000 C
{74}, //0110001 C
{74}, //0110010 C
{74}, //0110011 C
{74}, //0110100 C
{74}, //0110101 C
{74}, //0110110 C
{74}, //0110111 C
{74}, //0111000 C
{74}, //0111001 C
{74}, //0111010 C
{74}, //0111011 C
{74}, //0111100 C
{74}, //0111101 C
{74}, //0111110 C
{74}, //0111111 C
{73}, //1000000 B
{73}, //1000001 B
{73}, //1000010 B
{73}, //1000011 B
{73}, //1000100 B
{73}, //1000101 B
{73}, //1000110 B
{73}, //1000111 B
{73}, //1001000 B
{73}, //1001001 B
{73}, //1001010 B
{73}, //1001011 B
{73}, //1001100 B
{73}, //1001101 B
{73}, //1001110 B
{73}, //1001111 B
{73}, //1010000 B
{73}, //1010001 B
{73}, //1010010 B
{73}, //1010011 B
{73}, //1010100 B
{73}, //1010101 B
{73}, //1010110 B
{73}, //1010111 B
{72}, //1011000 Bb
{72}, //1011001 Bb
{72}, //1011010 Bb
{72}, //1011011 Bb
{72}, //1011100 Bb
{72}, //1011101 Bb
{72}, //1011110 Bb
{72}, //1011111 Bb
{71}, //1100000 A
{71}, //1100001 A
{71}, //1100010 A
{71}, //1100011 A
{71}, //1100100 A
{71}, //1100101 A
{71}, //1100110 A
{71}, //1100111 A
{71}, //1101000 A
{71}, //1101001 A
{71}, //1101010 A
{71}, //1101011 A
{71}, //1101100 A
{71}, //1101101 A
{71}, //1101110 A
{71}, //1101111 A
{69}, //1110000 G
{69}, //1110001 G
{69}, //1110010 G
{69}, //1110011 G
{69}, //1110100 G
{69}, //1110101 G
{68}, //1110110 F#
{68}, //1110111 F#
{67}, //1111000 F
{68}, //1111001 F
{69}, //1111010 F
{67}, //1111011 F
{66}, //1111100 E
{65}, //1111101 D#
{64}, //1111110 D
{62} //1111111 C


};
