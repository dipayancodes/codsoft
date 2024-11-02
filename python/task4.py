import random

def play_round():
    choices = ["rock", "paper", "scissors"]
    user_choice = input("Choose rock, paper, or scissors: ").lower()
    if user_choice not in choices:
        print("Invalid choice. Please try again.")
        return None, None

    computer_choice = random.choice(choices)
    print(f"You chose {user_choice}, Computer chose {computer_choice}")

    if user_choice == computer_choice:
        return "tie", computer_choice
    elif (user_choice == "rock" and computer_choice == "scissors") or \
         (user_choice == "scissors" and computer_choice == "paper") or \
         (user_choice == "paper" and computer_choice == "rock"):
        return "win", computer_choice
    else:
        return "lose", computer_choice

def game():
    user_score = 0
    computer_score = 0

    while True:
        result, computer_choice = play_round()
        
        if result == "win":
            user_score += 1
            print("You win this round!")
        elif result == "lose":
            computer_score += 1
            print("Computer wins this round!")
        elif result == "tie":
            print("It's a tie!")
        else:
            continue

        print(f"Score - You: {user_score}, Computer: {computer_score}")
        
        play_again = input("Do you want to play another round? (y/n): ").lower()
        if play_again != 'y':
            print("Thanks for playing!")
            break

game()

