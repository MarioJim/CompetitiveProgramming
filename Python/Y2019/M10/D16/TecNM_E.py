numDecl = input()
numAssign = input()

identifiers = []
stillUsing = []

for i in range(numDecl):
    identifiers.append(raw_input().split(' ')[1])
    stillUsing.append(i)

for i in range(numAssign):
    inputStr = raw_input().split(' ')
    fromAssign = identifiers.index(inputStr[0])
    toAssign = identifiers.index(inputStr[2][:-1])
    stillUsing[fromAssign] = toAssign

print(len(set(stillUsing)))
