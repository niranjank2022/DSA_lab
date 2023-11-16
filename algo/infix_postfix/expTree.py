class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def inorder(node):
    if node:
        inorder(node.left)
        print(node.val, end=" ")
        inorder(node.right)


def preorder(node):
    if node:
        print(node.val, end=" ")
        preorder(node.left)
        preorder(node.right)


def postorder(node):
    if node:
        postorder(node.left)
        postorder(node.right)
        print(node.val, end=" ")


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

    return prefix[::-1]


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


def constructTree(infix: str):
    infix = "".join(infix.split())
    prefix = convertToPrefix(infix)
    postfix = convertToPostfix(infix)
    stack = []
    for ch in postfix:
        if ch.isdigit():
            stack.append(TreeNode(int(ch)))
        else:
            n1 = stack.pop()
            n2 = stack.pop()
            op = TreeNode(ch)
            op.left = n1
            op.right = n2
            stack.append(op)
    root = stack[0]
    inorder(root)
    print()
    preorder(root)
    print()
    postorder(root)
    print()

    stack = []
    for ch in prefix[::-1]:
        if ch.isdigit():
            stack.append(TreeNode(int(ch)))
        else:
            n1 = stack.pop()
            n2 = stack.pop()
            op = TreeNode(ch)
            op.left = n1
            op.right = n2
            stack.append(op)

    root = stack[0]
    inorder(root)
    print()
    preorder(root)
    print()
    postorder(root)
    print()
    return root


if __name__ == '__main__':
    root = constructTree("(1+(4+5+2)-3)+(6+8)")

    root = constructTree(" 3-1 + 2 ")
