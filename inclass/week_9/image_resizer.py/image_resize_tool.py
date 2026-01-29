from PIL import Image
import os

def resize_image(input_path, output_path, size):
    try:
        if not os.path.exists(input_path):
            print(f"Error: Could not find {input_path}")
            return

        with Image.open(input_path) as img:
            # Resize using LANCZOS filter for high quality
            img_resized = img.resize(size, Image.Resampling.LANCZOS)
            img_resized.save(output_path)
            print(f"Success! Saved resized image to: {output_path}")
            print(f"New Size: {size}")

    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    # --- Configuration ---
    # We resize to 240x240 which is a standard ST7789 display size for Pico
    # Change to (128, 128) if you are using a smaller OLED
    TARGET_SIZE = (500, 500) 
    
    INPUT_FILE = "/home/abdullah-naci-bodur/Desktop/ME489/inclass/week_9/image_resizer.py/little_daisies.png"
    OUTPUT_FILE = "/home/abdullah-naci-bodur/Desktop/ME489/inclass/week_9/image_resizer.py/little_daisies_middle.png"
    
    # Run the resize
    resize_image(INPUT_FILE, OUTPUT_FILE, TARGET_SIZE)