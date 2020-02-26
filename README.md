# Stupid Simple Alert Watch

this is the code that goes along with my Stupid Simple Alert Watch project on Hackaday.io

I've included the ti ez430 Chronos code, as well as the python code that's running on a raspberry pi with attached cc1101 dongle

## ti Chronos Code
My chronos code strips down the UI on the watch to the barest essentials - showing the time and allowing the user to select and send an alert.

The watch runs on a modified version of the ez430_Chronos software that comes on the device (Software Projects\Chronos Watch\CCS\Sports Watch) and thankfully, their code is pretty easy to follow.

Here's a comment from their code that illustrates what shows on the display as you scroll through functions by pressing the * (top left) and # (bottom left) buttons:

LINE1: [Time] -> Alarm -> Temperature -> Altitude -> Heart rate -> Speed -> Acceleration
LINE2: [Date] -> Stopwatch -> Battery  -> ACC -> PPT -> SYNC -> Calories/Distance --> RFBSL

I didn't need any of that stuff, so I changed the function pointers in the menu options to skip over anything I didn't want when you pressed the * or # button.  

My new help function was added in a new set of help.c/.h files, and I inserted that function into the linked list of menu options mentioned above.  The help function uses the same SimpliciTI code that was used to send the power point commands.

I also disabled bluerobin and changed the processRequests function in the main.c file, to skip the temperature, pressure and altitude measurements, since I didn't care about that either.

For confirmation that the Help alert is being sent, the watch flashes while it transmits and beeps five times upon completion of the transmission.  There is no acknowledgement from the pi that an alert was received - might be something for later, but it hasn't been necessary so far.

## Raspberry Pi Code
The raspberry pi is responsible for sending email notification(s) when an alert event is received from the watch.  I booted up a fresh install of Raspbian and created an ~/alerter folder to house my code.

Inside the ~/alerter folder is an "alerter.py" script that runs at startup to listen for chronos events, and it is based on the following code:
https://web.archive.org/web/20130222052925/http://chemicaloliver.net/programming/receiving-ti-ez430-chronos-button-presses-in-processing-and-python/

When an "S1" button press is received, alerter executes "sendalert.py" which calls a function in "email_handler.py" to actually send the email.  The recipients are hard-coded in sendalert.py.  Email_handler.py uses the smtplib, MIMEMultipart and MIMEText libs to handle sending - more info and instructions can be found here:
https://iotbytes.wordpress.com/programmatically-send-e-mail-from-raspberry-pi-using-python-and-gmail/

I set up a special gmail account for sending the alert emails and the information for that account is stored in a "settings.ini" file.  The destination addresses can be any valid email address... I'm using a destination address from my mobile phone provider that converts the email to sms, so I get a text message when there's an alert.

To run the alerter.py script at startup, I modified the /etc/rc.local file with the following line:
python /home/myrpi/alerter/alerter.py

That's pretty much it... this project was thrown together pretty quickly but I hope you find something useful!
