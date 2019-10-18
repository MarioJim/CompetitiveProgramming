numLines = input()
completeMessage = ""
for i in range(numLines):
    completeMessage += raw_input()

message = ""
for i in range(15, len(completeMessage), 16):
    if (not (completeMessage[i] == 'X' and (completeMessage[i-1] == 'I' or completeMessage[i-1] == 'O'))):
        message += completeMessage[i]

if message.startswith("TRIANGULO") and len(message) == 10:
    size = ord(message[9]) - ord('A') + 1
    for i in range(size):
        print('*' * (i + 1))
    exit()

if message.startswith("CUADRADO") and len(message) == 9:
    size = ord(message[8]) - ord('A') + 1
    for i in range(size):
        print('*' * size)
    exit()

if message.startswith("PIRAMIDE") and len(message) == 9:
    size = ord(message[8]) - ord('A') + 1
    for i in range(size):
        print(' ' * (size - i - 1) + '*' * (2 * i + 1))
    exit()

print message
