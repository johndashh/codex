# Simple calculator

def add(a, b):
    return a + b


def subtract(a, b):
    return a - b


def multiply(a, b):
    return a * b


def divide(a, b):
    if b == 0:
        raise ValueError("Cannot divide by zero")
    return a / b


def main():
    print("Simple Calculator")
    print("Select operation:")
    print("1. Add")
    print("2. Subtract")
    print("3. Multiply")
    print("4. Divide")

    choice = input("Enter choice (1/2/3/4): ")

    if choice not in {'1', '2', '3', '4'}:
        print("Invalid choice")
        return

    try:
        num1 = float(input("Enter first number: "))
        num2 = float(input("Enter second number: "))
    except ValueError:
        print("Please enter valid numbers")
        return

    if choice == '1':
        result = add(num1, num2)
        op = '+'
    elif choice == '2':
        result = subtract(num1, num2)
        op = '-'
    elif choice == '3':
        result = multiply(num1, num2)
        op = '*'
    else:
        try:
            result = divide(num1, num2)
        except ValueError as e:
            print(e)
            return
        op = '/'

    print(f"{num1} {op} {num2} = {result}")


if __name__ == "__main__":
    main()
