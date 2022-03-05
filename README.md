# bright
I did not like the way that xrandr causes my screen to flicker when I decrease the brightness. So, I created bright which edits the backlight system file "brightness" to change the brightness. NO MORE FLICKER!!!!1!11!!! 

This currently only works for intel cpu's.
## Privilege level
Due to, the software editing a system file, bright must be ran with elevated privileges.
## Compiling
```
gcc -o bright bright.c
sudo ln -s /path/to/bright /usr/bin/
```
## Examples
### increase brightness by 10%
```
sudo bright --increment
-or-
sudo bright -i
```

### decrease brightness by 10%
```
sudo bright --decrement
-or-
sudo bright -d
```
### change brightness by specific amount
```
sudo bright --set <desired_percentage>
-or-
sudo bright -s <desired_percentage>
```
## TODO
1) create a makefile
2) Add support for other cpu's and gpu's 
