# Waterbear

Keyboard maintainer: [humanplayer2](github.com/humanplayer2)

## For first test build: I think I have a dead GP9 on right, so I bridged to GP10; Firmware reflects this, currently.

## Compile and flash.

Waterbear uses EE_HANDS to set sides. So once, we need to write side to the EEPROM chip. On both left and rigth side, flash the default firmware:

`qmk flash -kb humanplayer2/waterbear -km default -bl uf2-split-<left/right>`

Henceforth, we can now flash default firmware to each side using

`qmk flash -kb humanplayer2/waterbear -km default`