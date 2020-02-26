# Stupid Simple Alert Watch

this is the code that goes along with my Stupid Simple Alert Watch project on Hackaday.io

I've included the ti ez430 Chronos code, as well as the python code that's running on a raspberry pi with attached cc1101 dongle

## ti Chronos
The chronos code strips down the UI on the watch to the barest essentials - showing the time and allowing to select and send an alert. 

## Raspberry Pi
The raspberry pi code is responsible for receiving alerts and in turn sending any email notification(s).  I've set up a free gmail account to send the alerts.  The destination addresses for the alerts can be any valid email address... I'm using an address from my mobile phone provider that converts the email to sms, so I end up receiving a text message when there's an alert.

It is based on this code that receives the alerts:
https://web.archive.org/web/20130222052925/http://chemicaloliver.net/programming/receiving-ti-ez430-chronos-button-presses-in-processing-and-python/

...and calls a python script based on this code to send the email:
https://iotbytes.wordpress.com/programmatically-send-e-mail-from-raspberry-pi-using-python-and-gmail/

I hope you find something useful!
