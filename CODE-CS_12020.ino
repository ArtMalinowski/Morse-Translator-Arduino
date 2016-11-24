// Mace Code for CS12020
// I created a constant String to collect all valus wich will be used in transleate to MACE code
const String mace_a = "=";
const String mace_b = "^^=";
const String mace_c = "^=$";
const String mace_d = "=^";
const String mace_e = "^";
const String mace_f = "^=^";
const String mace_g = "==";
const String mace_h = "^==";
const String mace_i = "^^";
const String mace_j = "=^^";
const String mace_k = "^$";
const String mace_l = "^^$";
const String mace_m = "^=";
const String mace_n = "=$";
const String mace_o = "$=";
const String mace_p = "$^";
const String mace_q = "=^$";
const String mace_r = "^$=";
const String mace_s = "^$^";
const String mace_t = "$";
const String mace_u = "$$";
const String mace_v = "==^";
const String mace_w = "==$";
const String mace_x = "=$^";
const String mace_y = "^$$";
const String mace_z = "===";
const String mace_1 = "$^^=";
const String mace_2 = "$^^$";
const String mace_3 = "$^=^";
const String mace_4 = "$^==";
const String mace_5 = "$^=$";
const String mace_6 = "$^$^";
const String mace_7 = "$^$=";
const String mace_8 = "$^$$";
const String mace_9 = "$=^^";
const String mace_0 = "$^^^";
const String mace_stop = "$^^";
const String mace_comma = "$^=";
const String mace_apostrophe = "$=^";
const String mace_question = "$==";
const String mace_exclamation = "$=$";
const String mace_plus = "$$^";
const String mace_minus = "$$=";
const String mace_multiply = "$$$";
const String mace_divide = "$^$";
const String mace_equals = "$===$";
// I've define names for all leds,poteintiometr and IR tansmiter and reciver which I will used in my code
// to create my code more readable
#define blueLed 11
#define redLed 5
#define poteintiometr A0
#define amberLed 6
#define yellowLed 9
#define greenLed 10
#define ir_transmiter A1
#define ir_reciver 2
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // I created pinModes for all leds wich I will used
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(amberLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(poteintiometr, INPUT);
  pinMode(ir_reciver, INPUT);
  pinMode(ir_transmiter, OUTPUT);
}
// get_input function wihich will read an integer from the serial port
String get_input() {
  while (!Serial.available()) {
    //wait for a the user to enter a value
    ;
  }
  return Serial.readString();
}
// function which translate string to mace code
String string2mace(String message) {
  // string which will be return at the end of function
  String result;
  // the loop which will end at end of message lenghth
  for (int i = 0; i < message.length(); i++) {
    // function check if the next letter and the prestent letter is backspace and the 'i' cannot be the penulitmate letter
    if (message[i + 1] != ' ' && message[i] != ' ' && i != message.length() - 1) {
      // if the fucntion "if" come true print translated char to mace and backslash
      result += char2mace(message[i]);
      result += '/';
    }
    else
      // else print only translated char to mace
      result += char2mace(message[i]);
  }
  // return previous string withe the result of the code
  return result;
}
// function which translate code Mace to string
String mace2string(String m) {
  // string temp will collect data wich will then tanslate to ascii
  String temp;
  // string mace_ascii will collect tranlated characters from temp
  String mace_ascii;
  // if the pneulimate will not be backslash I need add back slash
  if (m.length() - 1 != '/')
    m += '/';
  for (int i = 0; i <= m.length(); i++) {
    if (m[i] != '/' && m[i] != ' ' )
    {
      // adding signals forming the same letter
      temp += m[i];
    }
    else {
      //addign translated signals to mace_ascii
      mace_ascii += (mace2char(temp));
      // make temp empty
      temp = "";
    }
    // if backspace add backspace to mace_ascii
    if (m[i] == ' ')
      mace_ascii += " ";
  }
  return mace_ascii;
}
// sendDigitalMace is used to send control leds
void sendDigitalMace(int pin, String message ) {
  // I ve made simply calculation to create poteintiometr form 20-500
  float x = (float)480 / (float)1023;
  float  time_unit = (analogRead(poteintiometr) * x) + 20;
  for (int i = 0 ; i < message.length(); i++) {
    // function if- control led and how long they should work
    if (message[i] == '^') {
      digitalWrite(pin, HIGH);
      delay(time_unit);
      digitalWrite(pin, LOW);
      delay(time_unit);
    } else if (message[i] == '=') {
      digitalWrite(pin, HIGH);
      delay(3 * time_unit);
      digitalWrite(pin, LOW);
      delay(time_unit);
    } else if (message[i] == '$') {
      digitalWrite(pin, HIGH);
      delay(4 * time_unit);
      digitalWrite(pin, LOW);
      delay(time_unit);
    } else if (message[i] == '/') {
      delay(3 * time_unit);
    } else if (message[i] == ' ') {
      delay(5 * time_unit);
    }
  }
}
// String char2mace translate characters to mace code one by one.It work on swtich function
String char2mace(char x) {
  switch (x) {
    case 'A':
      return mace_a;
      break;
    case 'B':
      return mace_b;
      break;
    case 'C':
      return mace_c;
      break;
    case 'D':
      return mace_d;
      break;
    case 'E':
      return mace_e;
      break;
    case 'F':
      return mace_f;
      break;
    case'G':
      return mace_g;
      break;
    case'H':
      return mace_h;
      break;
    case'I':
      return mace_i;
      break;
    case'J':
      return mace_j;
      break;
    case'K':
      return mace_k;
      break;
    case'L':
      return mace_l;
      break;
    case'M':
      return mace_m;
      break;
    case'N':
      return mace_n;
      break;
    case'O':
      return mace_o;
      break;
    case'P':
      return mace_p;
      break;
    case'Q':
      return mace_q;
      break;
    case'R':
      return mace_r;
      break;
    case'S':
      return mace_s;
      break;
    case'T':
      return mace_t;
      break;
    case'U':
      return mace_u;
      break;
    case'V':
      return mace_v;
      break;
    case'W':
      return mace_w;
      break;
    case'X':
      return mace_x;
      break;
    case'Y':
      return mace_y;
      break;
    case'Z':
      return mace_z;
      break;
    case'1':
      return mace_1;
      break;
    case'2':
      return mace_2;
    case'3':
      return mace_3;
      break;
    case'4':
      return mace_4;
      break;
    case'5':
      return mace_5;
      break;
    case'6':
      return mace_6;
      break;
    case'7':
      return mace_7;
      break;
    case'8':
      return mace_8;
      break;
    case'9':
      return mace_9;
      break;
    case'0':
      return mace_0;
      break;
    case'.':
      return mace_stop;
      break;
    case',':
      return mace_comma;
      break;
    case'?':
      return mace_question;
      break;
    case'\'':
      return mace_apostrophe;
      break;
    case'!':
      return mace_exclamation;
      break;
    case'+':
      return mace_plus;
      break;
    case'-':
      return mace_minus;
      break;
    case'*':
      return mace_multiply;
      break;
    case'/':
      return mace_divide;
      break;
    case'=':
      return mace_equals;
      break;
    default:
      return " ";
  }
}
// function tranlsate mace to char. the functione base on if
char mace2char(String m) {
  if (m.equals(mace_a)) {
    return'A';
  } else if (m.equals(mace_b)) {
    return'B';
  } else if (m.equals(mace_c)) {
    return'C';
  } else if (m.equals(mace_d)) {
    return'D';
  } else if (m.equals(mace_e)) {
    return'E';
  } else if (m.equals(mace_f)) {
    return'F';
  } else if (m.equals(mace_g)) {
    return'G';
  } else if (m.equals(mace_h)) {
    return'H';
  } else if (m.equals(mace_i)) {
    return'I';
  } else if (m.equals(mace_j)) {
    return'J';
  } else if (m.equals(mace_k)) {
    return'K';
  } else if (m.equals(mace_l)) {
    return'L';
  } else if (m.equals(mace_m)) {
    return'M';
  } else if (m.equals(mace_n)) {
    return'N';
  } else if (m.equals(mace_o)) {
    return'O';
  } else if (m.equals(mace_p)) {
    return'P';
  } else if (m.equals(mace_q)) {
    return'Q';
  } else if (m.equals(mace_r)) {
    return'R';
  } else if (m.equals(mace_s)) {
    return'S';
  } else if (m.equals(mace_t)) {
    return'T';
  } else if (m.equals(mace_u)) {
    return'U';
  } else if (m.equals(mace_w)) {
    return'W';
  } else if (m.equals(mace_x)) {
    return'X';
  }else if (m.equals(mace_v)) {
    return'V';
  } else if (m.equals(mace_y)) {
    return'Y';
  } else if (m.equals(mace_z)) {
    return'Z';
  }   else if (m.equals(mace_1)) {
    return'1';
  } else if (m.equals(mace_2)) {
    return'2';
  } else if (m.equals(mace_3)) {
    return'3';
  } else if (m.equals(mace_4)) {
    return'4';
  } else if (m.equals(mace_5)) {
    return'5';
  } else if (m.equals(mace_6)) {
    return'6';
  } else if (m.equals(mace_7)) {
    return'7';
  } else if (m.equals(mace_8)) {
    return'8';
  } else if (m.equals(mace_9)) {
    return'9';
  } else if (m.equals(mace_0)) {
    return'0';
  } else if (m.equals(mace_stop)) {
    return'.';
  } else if (m.equals(mace_comma)) {
    return',';
  } else if (m.equals(mace_question)) {
    return'?';
  } else if (m.equals(mace_apostrophe)) {
    '\'';
  } else if (m.equals(mace_exclamation)) {
    return'!';
  } else if (m.equals(mace_plus)) {
    return'+';
  } else if (m.equals(mace_minus)) {
    return'-';
  } else if (m.equals(mace_multiply)) {
    return'*';
  } else if (m.equals(mace_divide)) {
    return'/';
  } else if (m.equals(mace_divide)) {
    return'=';
  }
}
// function check_IRled- Turn on the IR LED for 1000ms and then turn it off
void check_IRled(String message) {
  // integer time_turn_on=How long should be on
  int time_turn_on = 1000;
  //chech if the first 4 character after translated from mace code are compatible with this from task
  if (message[0] == '+' && message[1] == '-' && message[2] == 'I' && message[3] == 'R' ) {
    //turning on IR transimter with maximum requency
    analogWrite(ir_transmiter, 38000);
    //delay after the ir_trasmiter will be turn on
    delay(time_turn_on);
    digitalWrite(ir_transmiter, LOW);
    //turn on blue led
    sendDigitalMace(blueLed, string2mace(message));
  }
}
// function check_rxir -Read the value from the IR receiver and transmit it on the Serial Port as “HIGH” or “LOW”
void check_rxir(String message) {
  // chech if the first 4 character after translated from mace code are compatible with this from task
  if (message[0] == 'R' && message[1] == 'X' && message[2] == 'I' && message[3] == 'R' ) {
    // check if IR reciver is low, if yes, print Low
    if (digitalRead(ir_reciver) == LOW)
      Serial.println("Low");
    else
      // if not low print High
      Serial.println("High");
    //turn on blue led
    sendDigitalMace(blueLed, string2mace(message));
  }
}
// function check_vrv which check what is the value of poteintiomtr and print in MACE code this value
void check_vrv(String message) {
  // array which will store data of each number of poteintiometr
  int tab[4];
  // string which will store all the numbers
  String mace_code;
  // chech if the first 3 character after translated from mace code are compatible with this from task
  if (message[0] == 'V' && message[1] == 'R' && message[2] == 'V') {
    // iteger which will sotre the value of poteintiomer
    int x = analogRead(poteintiometr);
    // loop which will add number from the last to first
    for ( int i = 4 ; i > 0; i--) {
      // adding the remainder from dividing poteintiometr value
      tab[i] = x % 10;
      // divide the value of poteintiometr for 10 after adding the remainder
      x = x / 10;
    }
    // loop which will add the number of poteintiometr to mace_code string
    for (int i = 0; i < 5 ; i++) {
      if (tab[i] == 1)
        mace_code += 1;
      if (tab[i] == 2)
        mace_code += 2;
      if (tab[i] == 3)
        mace_code += 3;
      if (tab[i] == 4)
        mace_code += 4;
      if (tab[i] == 5)
        mace_code += 5;
      if (tab[i] == 6)
        mace_code += 7;
      if (tab[i] == 8)
        mace_code += 8;
      if (tab[i] == 9)
        mace_code += 9;
      if (tab[i] == 0)
        mace_code += 0;
    }
    // Print translated number to mace code
    Serial.print(string2mace(mace_code));
    // turn on blueLed
    sendDigitalMace(blueLed, string2mace(message));
  }
}
// function check_vrv Sets the brightness of the LEDs.  Each block of 3 digits if the PWM intensity for the LED, in the order red, amber ,yellow, green.
void check_LP12digitals(String message) {
  // integer A which will store date how many time add a corectly number
  int a = 0;
  // check if the first two translated are A and P
  if (message[0] == 'L' && message[1] == 'P' ) {
    // loop from 2 to 13 beacause we already check the 0 and 1 character
    for (int i = 2; i < 14; i++) {
      //check 12 characters , whether they are numbers
      if (message[i] == '0' || message[i] == '1' || message[i] == '2' || message[i] == '3' || message[i] == '4' || message[i] == '5' || message[i] == '6' || message[i] == '7' || message[i] == '8' || message[i] == '9')
        //adding always 1 when we find number
        a++;
    }
  }
  // if a is equal to 12 we can start do next part 
  if (a == 12) {
    int x;
    // loop will set the brightness of the Leds
    for (int i = 0; i < 4; i++) {
      // inteager y which will store the number which will set the brigntess of the Leds
      int y;
      // loop wich will add individual numbers to integer y
      for (int j = 0; j < 3; j++) {
        // loop in wich function switch which check what number need to be add to integer 
        //y which is used Horner method.
                switch (message[i * 3 + j + 2]) {
          case '1': {
              x = 1;
              break;
            }
          case '2': {
              x = 2;
              break;
            }
          case '3': {
              x = 3;
              break;
            }
          case '4': {
              x = 4;
              break;
            }
          case '5': {
              x = 5;
              break;
            }
          case '6': {
              x = 6;
              break;
            }
          case '7': {
              x = 7;
              break;
            }
          case '8': {
              x = 8;
              break;
            }
          case '9': {
              x = 9;
              break;
            }
          case '0': {
              x = 0;
              break;
            }
          default : x = 0;
        }
        // I used Horner methods which recommend one of my friend to count variable written as string of 3 chars

        y = y * 10 + x;
      }
      // if y is bigger then 255, y will change fo 255
      if (y > 255) y = 255;
      // switch enters data to each led and turn on them 
      switch (i) {
        case 0: {
            analogWrite(redLed, y);
            break;

          }
        case 1: {
            analogWrite(amberLed, y);
            break;
          }
        case 2: {
            analogWrite(yellowLed, y);
            break;
          }
        case 3: {
            analogWrite(greenLed, y);
            break;
          }
      }
      // y need to be change for 0 to used horner method egain
      y = 0;
    }
  }
  // we turn on blueLed and when the blueLed stop work other led also stop work
  sendDigitalMace(blueLed, string2mace(message));
  if (digitalRead(redLed) == HIGH)
    digitalWrite(redLed, LOW);
  if (digitalRead(amberLed) == HIGH)
    digitalWrite(amberLed, LOW);
  if (digitalRead(yellowLed) == HIGH)
    digitalWrite(yellowLed, LOW);
  if (digitalRead(greenLed) == HIGH)
    digitalWrite(greenLed, LOW);
}

void loop() {
  // string message will be equal to our function get_input
  String message = get_input();
  // integer X will be used to determine whether it is the ASCII code or MACE
  int x = 0;
  // loop which will repeat as many times as the word has letters
  for (int i = 0; i < message.length(); i++) {
    // chech if it is the some signals from MACE code
    // I want check only first 4 characters but my friend persuaded me that this is more validate method 
    // beacasue it check whole code not only firsy characters
    if ((message[i] == '^') || (message[i] == '$') || (message[i] == '='))
    // if yes add x++
      x++;
  }
  // if there is less than half of characters from MACE code
  // print string2mace(message)
  if (x < message.length() / 2) {
    Serial.println(string2mace(message));
    sendDigitalMace(redLed, string2mace(message));


  }
  else {
    // if there is more than half of characters from MACE code
    // print mace2string(message) 
    Serial.println(mace2string(message));
    //induce previously created functions
    check_vrv(mace2string(message));
    check_IRled(mace2string(message));
    check_rxir(mace2string(message));
    check_LP12digitals(mace2string(message));
  }
}
