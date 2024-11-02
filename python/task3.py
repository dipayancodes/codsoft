import random
import string

def generate_password():
    length = int(input("Enter desired password length: "))
    complexity = input("Include uppercase, lowercase, digits, and symbols? (y/n): ").lower()

    characters = string.ascii_lowercase + string.digits
    if complexity == 'y':
        characters += string.ascii_uppercase + string.punctuation

    password = ''.join(random.choice(characters) for _ in range(length))
    print("Generated Password:", password)

generate_password()

