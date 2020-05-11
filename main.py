def solution(inputString):
    stack = []
    count = 0
    for item in inputString:
        if item == "(" or "[" or "<" or "{":
            stack.append(item)
        elif item == ")" or "]" or ">" or "}":
            try:
                stack.pop()
                count = count + 1
            except IndexError:
                return -1

    if len(stack) == 0:
        return count