# this program is used to download website content
import httplib

conn = httplib.HTTPSConnection("www.baidu.com")
conn.request("GET", "/")
r1 = conn.getresponse()

print r1.status, r1.reason

data = r1.read()
print data
