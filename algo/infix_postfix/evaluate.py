def evaluatePostfix(infix: str):
    infix = "".join(infix.split())  # Remove the whitespace between
    postfix = convertToPostfix(infix)
    print(postfix)
    digit = []
    for ch in postfix:
        if ch.isdigit():
            digit.append(int(ch))
        else:
            n2 = digit.pop()
            n1 = digit.pop()
            if ch == '+':
                digit.append(n1 + n2)
            elif ch == '-':
                digit.append(n1 - n2)
            elif ch == '*':
                digit.append(n1 * n2)
            elif ch == '/':
                digit.append(n1 // n2)

    print(digit)
    return digit[0]


def convertToPrefix(infix: str):
    infix = infix[::-1]
    op = []
    prefix = []
    rank = {'+': 1, '-': 1, '*': 2, '/': 2, ')': 0}
    for ch in infix:
        if ch.isdigit():
            prefix.append(ch)
        elif ch == ')':
            op.append(ch)
        elif ch == '(':
            while op and op[-1] != ')':
                prefix.append(op.pop())
            op.pop()
        else:
            while op and rank[op[-1]] > rank[ch]:
                prefix.append(op.pop())
            op.append(ch)

    while op:
        prefix.append(op.pop())

    print(prefix[::-1])
    return prefix[::-1]


def evaluatePrefix(infix):
    infix = "".join(infix.split())
    prefix = convertToPrefix(infix)
    stack = []
    for ch in prefix[::-1]:
        if ch.isdigit():
            stack.append(int(ch))
        else:
            n1 = stack.pop()
            n2 = stack.pop()
            if ch == '+':
                stack.append(n1 + n2)
            elif ch == '-':
                stack.append(n1 - n2)
            elif ch == '*':
                stack.append(n1 * n2)
            elif ch == '/':
                stack.append(n1 // n2)

    print(stack)
    return stack[0]


def convertToPostfix(infix: str):
    op = []
    postfix = []
    rank = {'+': 1, '-': 1, '/': 2, '*': 2, '(': 0}
    for ch in infix:
        if ch.isdigit():  # Push if it digit
            postfix.append(ch)
        elif ch == '(':  # Push if it is left parenthesis
            op.append(ch)
        elif ch == ')':  # Pop all the operators in op stack until '(' is found. Finally pop that also
            while op and op[-1] != '(':
                postfix.append(op.pop())
            op.pop()
        else:
            # Pop and push the operators if their precedence is higher than the curr operator.
            # Push the curr operator into the op stack
            while op and rank[op[-1]] >= rank[ch]:
                postfix.append(op.pop())
            op.append(ch)

    # Pop and push the operators
    while op:
        postfix.append(op.pop())

    return postfix


evaluatePrefix("(1+(4+5+2)-3)+(6+8)")
evaluatePostfix("(1+(4+5+2)-3)+(6+8)")
evaluatePrefix(" 3-1 + 2 ")
evaluatePostfix(" 3-1 + 2 ")
