# Stupid Simple Alert Watch

this is the code that goes along with my Stupid Simple Alert Watch project on Hackaday.io

I've included the ti ez430 Chronos code, as well as the python code that's running on a raspberry pi with attached cc1101 dongle

## ti Chronos
The chronos code strips down the UI on the watch to the barest essentials - showing the time and allowing to select and send an alert. 

## Raspberry Pi
The raspberry pi is responsible for sending email notification(s) when an alert event is received from the watch, and the code for it lives in /home/alerter.

There's an "alerter.py" script that runs at startup to listen for chronos events, and it is based on the following code:
https://web.archive.org/web/20130222052925/http://chemicaloliver.net/programming/receiving-ti-ez430-chronos-button-presses-in-processing-and-python/

When an "S1" button press is received, alerter executes "sendalert.py" which calls a function in "email_handler.py" to actually send the email.  The recipients are hard-coded in sendalert.py.  Email_handler.py uses the smtplib, MIMEMultipart and MIMEText libs to handle sending - more info and instructions can be found here:
https://iotbytes.wordpress.com/programmatically-send-e-mail-from-raspberry-pi-using-python-and-gmail/

I set up a special gmail account for sending the alert emails and the information for that account is stored in a "settings.ini" file.  The destination addresses can be any valid email address... I'm using a destination address from my mobile phone provider that converts the email to sms, so I get a text message when there's an alert.

To run the alerter.py script at startup, I modified the /etc/rc.local file with the following line:
python /home/myrpi/alerter/alerter.py

That's pretty much it... this project was thrown together pretty quickly but I hope you find something useful!
