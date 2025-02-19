# LaserProsthetic

*A 47+6 trackpoint columnar unibody split designed with splayed pinky clusters.*

* Keyboard Maintainer: [@humanplayer2](https://github.com/humanplayer2)
* Hardware Supported: [laserprosthetic](https://github.com/humanplayer2/mkmods/tree/main/homemade/LaserProsthetic)

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb humanplayer2/laserprosthetic -km default

Flashing example for this keyboard:

    qmk flash -kb humanplayer2/laserprosthetic -km default
    
See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## External Features
- Linux Trackpoint middle-mouse scrolling: Enabled by the keyboard name end in `Trackpoint`.
- [Custom Shift Keys by Pascal Getreuer](https://getreuer.info/posts/keyboards/custom-shift-keys/index.html).

## Bootloader

Enter the bootloader in one of three ways:
* **Keycode in layout**: Press the key mapped to `QK_BOOT`: rigth-most right thumb key plus top left key.
* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (top left key) and plug in the keyboard.
* **Physical reset button**: Twice short `RST` and `GND` on the ProMicro.

## Flashing Permissions on Fedora
When flashing, if `Waiting for /dev/ttyACM0 to become writable...` keeps ticking, either
- open another terminal and run `sudo chmod o+rw /dev/ttyACM0`, or, 
- for a long term solution, find the owning group by 
    - `ll /dev/ttyACM0` (it's `dialout` for me), and 
    - add your user to the group: `sudo usermod -aG dialout youruser`,
    - log out and in, confirm membership by `sudo cat /etc/gshadow | grep dialout`.