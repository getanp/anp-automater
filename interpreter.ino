#include <Keyboard.h>

//
// ------------- SIMPLE SCRIPT INTERPRETER -------------
// Supported commands:
//
// wait <seconds>
// press <key> <count>
// type <string>
//
// Keys: return, tab, down, up, left, right
//
// Script will later be downloaded via SPI —
// but this interpreter will not need to change.
//

// Example script (later load via SPI)
const char *script =
  "wait 14\n"
  "press return 1\n"
  "wait 10\n"
  "press tab 1\n"
  "press down 20\n"
  "press return 1\n"
  "wait 2\n"
  "type ssid\n"
  "press tab 1\n"
  "press down 2\n"
  "press tab 1\n"
  "type password\n"
  "press tab 3\n"
  "press return 1\n"
  "wait 10\n"
  "press tab 1\n"
  "press return 1\n"
  "wait 15\n"
  "press tab 2\n"
  "press return 1\n"
  "wait 10\n"
  "press tab 7\n"
  "type enrollment@place.com\n"
  "press return 1\n"
  "wait 5\n"
  "type password\n"
  "wait 10\n"
  "press return 1\n"
  "press tab 3\n"
  "press return 1\n"
  "wait 2\n"
  "press tab 2\n"
  "press return 1\n";


// Map command string → keycode
uint8_t resolveKey(const String &k) {
  if (k == "return") return KEY_RETURN;
  if (k == "tab")    return KEY_TAB;
  if (k == "down")   return KEY_DOWN_ARROW;
  if (k == "up")     return KEY_UP_ARROW;
  if (k == "left")   return KEY_LEFT_ARROW;
  if (k == "right")  return KEY_RIGHT_ARROW;
  return 0;
}


void runLine(String line) {
  line.trim();
  if (line.length() == 0) return;

  // ---- WAIT ----
  if (line.startsWith("wait ")) {
    int secs = line.substring(5).toInt();
    delay(secs * 1000);
    return;
  }

  // ---- PRESS ----
  if (line.startsWith("press ")) {
    int space1 = line.indexOf(' ', 6);
    String key = line.substring(6, space1);
    int count = line.substring(space1 + 1).toInt();

    uint8_t k = resolveKey(key);
    for (int i = 0; i < count; i++) {
      Keyboard.press(k);
      delay(100);
      Keyboard.releaseAll();
      delay(100);
    }
    return;
  }

  // ---- TYPE ----
  if (line.startsWith("type ")) {
    String msg = line.substring(5);
    Keyboard.print(msg);
    delay(200);
    return;
  }
}


void runScript(const char *s) {
  String line = "";
  while (*s) {
    if (*s == '\n') {
      runLine(line);
      line = "";
    } else {
      line += *s;
    }
    s++;
  }
  if (line.length()) runLine(line);
}


void setup() {
  Keyboard.begin();
  delay(2000);

  runScript(script);

  Keyboard.end();
}

void loop() {
}
