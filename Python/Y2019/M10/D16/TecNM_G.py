import string

text = raw_input()
text = text.upper()
toEncode = text[0] == 'E'
text = list(text[1:])
textLength = len(text)
secondLine = raw_input().split(' ')
groupLength = int(secondLine[0][1:])
offset = int(secondLine[1][1:])
if (not toEncode):
    offset = -offset
result = ""

for i in range(1 + (textLength // groupLength)):
    for char in text[i * groupLength:(i+1) * groupLength][::-1]:
        result += chr(ord(char) + offset)

print result
