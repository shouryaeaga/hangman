def contains_accent(accent_line):
    # Check each character's Unicode code point
    for char in accent_line:
        if ord(char) > 127:  # ASCII range ends at 127
            return True
    return False

words = open("words", "r")
myDict = []
for line in words:
    if len(line) < 5:
        continue
    if "'" in line:
        continue
    if len(line) > 14:
        continue
    if line.strip()[-1] == 's':
        continue
    if line.isupper():
        continue
    if line[0].isupper():
        continue
    if contains_accent(line):
        continue

    myDict.append(line)

words.close()

newWords = open("dictionary.txt", "w")

for x in myDict:
    newWords.write(x)

newWords.close()