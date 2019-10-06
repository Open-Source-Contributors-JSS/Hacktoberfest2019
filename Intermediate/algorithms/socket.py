# Enter http://en.wikipedia.org/wiki/Web_scraping
from urllib import *
from bs4 import BeautifulSoup

url = input('Enter - ')

html = request.urlopen(url).read()
soup = BeautifulSoup(html)

# # Retrieve a list of the anchor tags
# # Each tag is like a dictionary of HTML attributes

# tags = soup('a')

# for tag in tags:
#    print(tag.get('href', None))
tags = soup('a')

for tag in tags:
   print(tag.get('href', None))