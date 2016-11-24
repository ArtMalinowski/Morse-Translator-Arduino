# Morse-Translator-Arduino
Code which translat words into morse code 

Morse Translator Arduin 

In the beginning I defined constant string to collect all values, which will be used for translations into MACE code. Then I opened serial port, set data rate to 9600 bps. After that I started to do the first part of the assignment. I wrote string “char2mace”, in which I used switch function to change ASCII to MACE code. In this part I also wrote string “get_input” which will be used to enter MACE  and  ASCII.

I created a string string2mace. In this function firstly I created a string result will be return at the end of function. After that check if the next letter and the present letter is backspace and the 'I' cannot be the penultimate letter. If the function "if" come true print translated char to mace and backslash else print only  translated char to mace.

Then I needed to write char “mace2char”, in which I used if function to change MACE code. Then I started to write a string mace2string, which will translate and combine signals. So I needed to create two strings: one(temp) which hold signals latter translated to characters, and second(mace_ascii) which collects characters, which will later create words. I also needed to create a few conditions, like if there is no backslash at the end of message length I need to add backslash, because without this backslash the last character cannot be translated.

I start with defining all pin which I needed to use and also I defined (potentiometer) . I’ve also created pinMode to each of them. In the beginning I wanted to create a function, which would check only first four characters to see if is it MACE or ASCII but then I talked to my friend and he persuaded me that it is better to check, if half of characters is ASCII or MACE, because to check the whole code is a more reasonable method. Then I created a function sendDigitalMace. I needed to control transmission speed by the potentiometer, so I created 'X', in which I counted value for 480. Then I created time_unit, in which I multiplied potentiometer, and added 20 (as minimal value of potentiometer). After that I’ve created a loop, which is repeated as many times as message length. With function IF I controlled, how long blueLed or redLed should shine, depending on the value of potentiometer and timing of transmission.


In part 3 after all void function we need to turn on the blue LED at the end of void expect void check_LP.  The beginning of void check_LP was not so hard, because I wanted to use very similar method to check the first four characters in part 2. Firstly, I needed to check if the translated characters are L or P. I used a simple function IF. Then I needed to create a loop, which would repeat itself twelve times and check if it is a number. If a character is a number I need to add 1 to previously created integer 'A' and if A is equal to 12, I could start the next part. While working on the next part I used Horner Method. I needed to create the first loop , which would set the brightness of LEDs. In this loop I needed to create integer Y, which would store the number  meant to set the brightness of LEDs, and another loop, in which function switch, which checks what number needs to be added to  'Y' used in Horner Method.  If Y is over than 255 the value must be returned as 255. The value Y should be added and turn on LEDs by switch function.After that we turn on blueLed and when this led stop work we turn of all other leds.  At the end 'Y' must be changed into 0 to be used in Horner Method again.  

I started the void check_VRV with checking translated characters. Then I created integer 'X', which stores the value of potentiometer and I created a loop, which adds a number to array 'TAB'. I added the remainder from dividing potentiometer value and after that I divided this number by 10. Then I created a loop, in which I checked IF tab[i] is one of the numbers I added to previously created string mace_code and then I translated to MACE and printed it in serial port.  

After this two data messages I created two others. First one – void_IRLED.   After checking translated characters  I created integer time_turn_on  to set how long should it be on. We need to turn on IR transmitter with maximum frequency after delay (time_turn_on). Ir_trasmiter will be turned off. 

Second one - Function check_rxir -  After checking translated characters read the value from the IR receiver and transmit it on the Serial Port as “HIGH” or “LOW”.  After checking we can check if IR receiver is low. If yes, print Low. If not low, print High.  



