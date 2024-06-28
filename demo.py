import time
import pyautogui

# Function to simulate typing character by character
def type_like_human(text, typing_speed=0.1):
    for char in text:
        if char != '\n':  # Skip newlines for more natural typing
            pyautogui.typewrite(char, interval=typing_speed)
        else:
            pyautogui.press('enter')
            time.sleep(2)  # Pause a bit longer for newlines

# Function to erase a portion of text and rewrite it
def erase_and_rewrite(text_to_erase, text_to_rewrite, typing_speed=0.1):
    # Select and delete the text to erase
    pyautogui.hotkey('ctrl', 'a')  # Select all text
    pyautogui.press('backspace')  # Delete selected text

    # Type the new text in its place
    type_like_human(text_to_rewrite, typing_speed)

# Input and output file paths
source_file_path = "test_.cpp"
destination_file_path = "solve.cpp"

# Open the source file for reading
with open(source_file_path, "r") as source_file:
    # Read the content character by character
    content = source_file.read()

# Focus on the destination application (e.g., a text editor)
# You might need to adjust the coordinates or method based on your operating system and setup
# Uncomment the following lines and provide appropriate coordinates if necessary.
# pyautogui.click(x=your_x_coordinate, y=your_y_coordinate)

# Continuously erase and rewrite the code until manually stopped
while True:
    erase_and_rewrite(content, content, typing_speed=0.05)

    # You can add a way to manually stop the loop, for example, by checking for a key press
    # or using an external event. Here, we wait for the user to press Enter to stop the loop.
    stop_input = input("Press Enter to stop erasing and rewriting...")
    if stop_input == "":
        break

print("Erase and rewrite loop stopped.")
