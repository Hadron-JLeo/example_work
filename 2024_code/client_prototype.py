import requests

port = '21444'
ip = '13.43.145.149'
url = f'http://{ip}:{port}/endpoint'
#url2 = "http://172.31.3.78:214"

server_cmd = input('Enter Command: ')
data = {'key': server_cmd}
response = requests.post(url, json=data)

print(response.text)
