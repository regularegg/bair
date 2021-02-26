# bair

@Team Gabe/BAIR

## So you want to run BAIR at home

First, it's totally ok if you don't have your neopixel strip yet. You can still download the Bair sketch (that's what arduino files are called) and get it on your CPX. I will show you how you can check to see if the code is running successfully using the serial monitor.

## Requirements

1x CPX

1x Cable

**Arduino 1.8.13** installed

**Arduino CPX Board** installed (Tools> Board > AVR Boards > Arduino Circuit Playground Express)

**Arduino Libraries:** Adafruit Circuit Playground, Adafruit NeoPixel, Adafruit NeoMatrix (not in use yet)



## How to run BAIR on your CPX

After you make sure you have the latest Arduino IDE (the app), the CPX board installed, and the libraries installed, you can download the the .ino file in this repo. You don't need to download anything else as of right now. 

Then, simply open it in Arduino. **Do your final check as stated below:**

**BOARD**: On a Mac (sorry windows friends idk how y'all do it), go to the Tools menu on the menu bar and go to Board. Make sure you have "Adafruit Circuit Playground Express" selected. If you can't find it, it's under the AVR boards submenu. If you still can't find it, go to Board Manager and search "AVR Board". Then install the latest version.
![alt text](https://github.com/regularegg/bair/blob/main/README%20illustrations/dependency.png)

**PORT**: Open the sub menu and select the option that has the words "Adafruit Circuit Playground" in it. If you can't find that port, try unplugging your board and plugging it back in or using a different USB port.
![alt text](https://github.com/regularegg/bair/blob/main/README%20illustrations/finalcheck.png)

Then press the little -> right arrow button on the top to send it to your CPX. After it's done uploading, your CPX should be dark except for the little green light in the bottom.

## How to see it work without LEDS

For now, you can use the serial monitor to see the sound data it is collecting. To open that menu, go to Tools > Serial Monitor (or use the following Mac command: SHIFT + COMMAND + M). 

Then you should be able to see a series of numbers (usually around 50) that rises when you make sounds. If you don't, pls contact me bc it works for me.



## Troubleshooting

If it doesn't work, check to see if you have all the libraries I've listed. Otherwise, HMU.

Worst case, you can go to Library > Arduino15 and delete the whole Arduino15 folder. Then restart Arduino and it should generate a fresh one. Now you can reinstall all those fun libraries!
