##------------------------------------------
##--- based on demo.py by Pradeep Singh, found at:
##--- https://iotbytes.wordpress.com/programmatically-send-e-mail-from-raspberry-pi-using-python-and-gmail/
##------------------------------------------

#import the class definition from "email_handler.py" file
from email_handler import Class_eMail

# set the email ID where you want to send the test email
# this should really be in an array or read from a config file
To_Email_ID1 = "{some address}"
To_Email_ID2 = "{some other address"

Subject = "Watch Alert";
Message = "Watch Alert: HELP pressed.";

# Send Plain Text Email(s)
# this should really be in a loop
email = Class_eMail()
email.send_Text_Mail(To_Email_ID1, Subject, Message)
del email

email = Class_eMail()
email.send_Text_Mail(To_Email_ID2, Subject, Message)
del email
