# Laser Raven

*A 32+6 trackpoint columnar unibody split designed with nordic languages in mind.*

* Keyboard Maintainer: [@humanplayer2](https://github.com/humanplayer2)
* Hardware Supported: [laserraven](https://github.com/humanplayer2/mkmods/tree/main/homemade/LaserRaven)

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb humanplayer2/laserraven -km default

Flashing example for this keyboard:

    qmk flash -kb humanplayer2/laserraven -km default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## External Features
- [Custom Shift Keys by Pascal Getreuer](https://getreuer.info/posts/keyboards/custom-shift-keys/index.html).

## Bootloader

Enter the bootloader in 3 ways:

* **Keycode in layout**: Press the key mapped to `QK_BOOT`: top row, highest key on either side, plus very rigth-most key.
* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (the left outer-ring key) and plug in the keyboard.
* **Physical reset button**: Briefly press the button on the front of the PCB, if available. Double tap for Pro Micro, 1 second press for Sea Picro / RP2040s.
