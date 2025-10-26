#include <Keyboard.h>

void setup() {
  Keyboard.begin();
  delay(2000);

  // Step 1: Press Enter
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();

  // Step 2: Wait 2 seconds
  delay(10000);

  // Step 3: Press Tab
  Keyboard.press(KEY_TAB);
  delay(100);
  Keyboard.releaseAll();

  // Step 4: Press Down Arrow 20 times
  for (int i = 0; i < 20; i++) {
    Keyboard.press(KEY_DOWN_ARROW);
    delay(50);
    Keyboard.releaseAll();
    delay(50);
  }

  // Step 5: Press Enter
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();

  // Step 6: Wait 2 seconds
  delay(2000);


  Keyboard.print("Your SSID");
  delay(300);

  // Step 8: Tab
  Keyboard.press(KEY_TAB);
  delay(100);
  Keyboard.releaseAll();
  delay(200);

  // Step 9: Down Arrow, Down Arrow
  for (int i = 0; i < 2; i++) {
    Keyboard.press(KEY_DOWN_ARROW);
    delay(100);
    Keyboard.releaseAll();
    delay(100);
  }

  // Step 10: Tab
  Keyboard.press(KEY_TAB);
  delay(100);
  Keyboard.releaseAll();
  delay(200);

  Keyboard.print("Wifi Password");
  delay(300);

  // Step 12: Tab ×3
  for (int i = 0; i < 3; i++) {
    Keyboard.press(KEY_TAB);
    delay(100);
    Keyboard.releaseAll();
    delay(200);
  }

  // Step 13: Enter
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(200);

  // Step 14: Wait 10 seconds
  delay(10000);

  // Step 15: Tab once
  Keyboard.press(KEY_TAB);
  delay(100);
  Keyboard.releaseAll();
  delay(200);

  // Step 16: Press Enter
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  
  delay(15000);
  // Step 17: Tab ×2 (new)
  for (int i = 0; i < 2; i++) {
    Keyboard.press(KEY_TAB);
    delay(100);
    Keyboard.releaseAll();
    delay(200);
  }
  
  // Step 18: Press Enter
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  delay(10000);
  for (int i = 0; i < 8; i++) {
    Keyboard.press(KEY_TAB);
    delay(100);
    Keyboard.releaseAll();
    delay(200);
  }
  // Step 19: Type email
  Keyboard.print("<your-enrollment-service@place.org>");
  delay(500);

  // Step 20: Press Enter
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
    // Step 21: Wait 2 seconds
  delay(5000);

  // Step 22: Type password
  Keyboard.print("<your password to enroll>");
  delay(500);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(10000);
  //License Accept.
  //Keyboard.press(KEY_TAB);
  //delay(100);
  //Keyboard.releaseAll();
  //delay(200);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(10000);
  for (int i = 0; i < 3; i++) {
    Keyboard.press(KEY_TAB);
    delay(100);
    Keyboard.releaseAll();
    delay(200);
  }
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();

  delay(2000);
  for (int i = 0; i < 2; i++) {
    Keyboard.press(KEY_TAB);
    delay(100);
    Keyboard.releaseAll();
    delay(200);
  }

  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();

  // Step 21: Stop
  Keyboard.end();
}

void loop() {
  // do nothing
}
