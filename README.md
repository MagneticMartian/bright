# bright
I did not like the way that xrandr causes my screen to flicker when I decrease the brightness. So, I created bright which edits the backlight system file "brightness" to change the brightness. NO MORE FLICKER!!!!1!11!!!
## Privilege level
Due to, the software editing a system file, bright must be ran with elevated privileges.
## Compiling
```
gcc -o bright bright.c
sudo ln -s /path/to/bright /usr/bin/
```
## Examples
### increase brightness by 5%
```
sudo bright --increment
-or-
sudo bright -i
```

### decrease brightness by 5%
```
sudo bright --decrement
-or-
sudo bright -d
```
### change brightness by specific amount
```
sudo bright --set <desired_percentage>
```
## TODO
1) write the help statement
2) create a makefile
