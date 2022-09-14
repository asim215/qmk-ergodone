# ErgoDone Configuration

- Configure keys in qmk configurator.
- Export to .json
- Update qmk. Put file in qmk_framework dir. Convert it to C file.
```
git pull
qmk setup
qmk json2c -o  my_keymap_j2c.c ./ktec_ergodone_layout_ergodox_pretty_80_mine_qwerty.json
```
- Cut and paste new keys from `my_keymap_j2c.c` to ./keyboards/ktec/ergodone/keymaps/my_keymap/keymap.c
- Compile it
```
qmk compile -kb ktec/ergodone -km my_keymap
```
- Get tkg-toolkit. Go to tkg-toolkit/linux
- Press 2 keys on left part of keyboard (in upper row two on far right) with at the same time connect cable to make keyboard ready to update firmware. 
- Update firmware with
```
sudo ./bin/hid_bootloader_cli -mmcu=atmega32u4 ~/qmk_firmware/ktec_ergodone_my_keymap.hex
```