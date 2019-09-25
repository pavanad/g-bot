# G-Bot v2

G-Bot is a simple robot based on the PIC16F877A microcontroller

## How to control

Use any APP for bluetooth control and configure the protocol below.

Pyserial example

```bash
pip install pyserial
chmod +x /dev/tty.HC-06-SPPDev
````

```python
import serial
gbot = serial.Serial('/dev/tty.HC-06-SPPDev', baudrate=9600)
gbot.write(b'&$LIGF ')
gbot.close()
```

*Default password HC-06: 1234*

## Protocol

**Mode options**

```
&$MODM  |  manual mode
&$MODA  |  automatic mode
```

**Engine controls**

```
&$DIRF  |  front
&$DIRFS |  front with 250ms and stop
&$DIRB  |  back
&$DIRS  |  stop
&$DIRL  |  left
&$DIRR  |  right
```

**Actions and other commands**

```
&$ACTD  |  denial
&$ACTH  |  happiness
&$ACTLL |  look left
&$ACTLR |  look right
```

**Control Light**

```
&$LIGL  |  light left
&$LIGR  |  light right
&$LIGF  |  light front
```
