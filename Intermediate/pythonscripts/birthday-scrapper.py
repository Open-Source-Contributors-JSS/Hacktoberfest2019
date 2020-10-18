import requests
import sys
from datetime import datetime
from bs4 import BeautifulSoup
try:
    now = datetime.now()
    FirstName = sys.argv[1].capitalize()
    LastName = sys.argv[2].capitalize()
    FullName = FirstName + "_" + LastName

    try:
        result = requests.get("https://en.wikipedia.org/wiki/" + FullName)
        src = result.content
        soup = BeautifulSoup(src, 'lxml')
        bday = soup.find("span", {"class": "bday"})
        bday = (str(bday)[19:29])
        bbyear = int((str(bday)[0:4]))
        age = int(now.year) - bbyear
        bmonth = int((str(bday)[5:7]))
        bdday = int((str(bday)[8:10]))
        monthtemp = int(now.month) - bmonth
        daytemp = int(now.day) - bdday

        if daytemp == 0 and monthtemp == 0:
            age = age
        elif daytemp < 1 and monthtemp < 1:
            age = age - 1

        print(LastName + " was born on " + str(bdday) + "/" + str(bmonth) + "/" + str(bbyear))
        print(FirstName + " is " + str(age) + " years old")

    except:
        print("Check if the name is spelled correctly or try a different person")
except:
    print("Enter the first name and last name of person as arguments")
