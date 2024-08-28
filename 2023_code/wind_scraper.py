""" A script to find local windspeed from a website """

import urllib.request
import re

url = "https://meteotrend.com/forecast/us/new-york/"

# Define custom headers
headers = {
    'User-Agent': 'Microsoft Edge', 
    'Accept-Language': 'en-US,en;q=0.5',
}

# Create a custom request with headers
request = urllib.request.Request(url, headers=headers)

try:
    # Send an HTTP GET request to the website using urllib
    with urllib.request.urlopen(request) as response:
        html = response.read().decode('utf-8')

    l = int(len(html) / 2)

    #print(html[l:])
    text=html
    # Use regex to find the wind speed and gusts patterns
    wind_speed_pattern = r'speed\s+<b>(\d+-\d+)\s+<i title="kilometers per hour">'
    gust_speed_pattern = r'Wind gusts:\s+<b>(\d+)\s+<i title="kilometers per hour">km/h</i></b>'

    # Search for the wind speed pattern in the text
    wind_speed_match = re.search(wind_speed_pattern, text)

    if wind_speed_match:
        wind_speed = wind_speed_match.group(1)
        print(f"Wind Speed: {wind_speed} km/h")
    else:
        print("Wind Speed not found in the text.")

    # Search for the gust speed pattern in the text
    gust_speed_match = re.search(gust_speed_pattern, text)

    if gust_speed_match:
        gust_speed = gust_speed_match.group(1)
        print(f"Gust Speed: {gust_speed} km/h")
    else:
        print("Gust Speed not found in the text.")

except urllib.error.URLError as e:
    print("Failed to retrieve the web page:", e)
