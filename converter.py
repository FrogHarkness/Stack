import os
import binascii
from datetime import datetime

def get_file_header(path):
    """
    Retrieve the first two hexadecimal numbers of a file
    """
    data = open(path, 'rb')
    hex_str = binascii.b2a_hex(data.read(2))
    return str(hex_str[:2], 'utf8'), str(hex_str[2:4], 'utf8')

"""
JPEG file header hexadecimal is 0xFFD8FF
PNG file header hexadecimal is 0x89504E
GIF file header hexadecimal is 0x474946
"""
def identify_file_type(directory):
    first_value, second_value = get_file_header(directory)
    first_value = int(first_value, 16)
    second_value = int(second_value, 16)
    code_key = first_value ^ 0xFF
    file_type = 'jpg'

    if first_value ^ 0xFF == second_value ^ 0xD8:
        code_key = first_value ^ 0xFF
        file_type = 'jpg'
    elif first_value ^ 0x89 == second_value ^ 0x50:
        code_key = first_value ^ 0x89
        file_type = 'png'
    elif first_value ^ 0x47 == second_value ^ 0x49:
        code_key = first_value ^ 0x47
        file_type = 'gif'
    
    return code_key, file_type

def process_file(path, filename):
    file_path = os.path.join(path, filename)
    modification_time = datetime.fromtimestamp(os.path.getmtime(file_path)).strftime('%Y-%m-%d %H.%M.%S')
    code_key, file_type = identify_file_type(file_path)

    directory_name = path.split('\\')[-1]
    if not os.path.exists(directory_name):
        os.mkdir(directory_name)
    
    source_file = open(file_path, "rb")
    destination_file = open(directory_name + '\\' + modification_time + '-' + filename[:10] + '.' + file_type, "wb")

    for current_byte in source_file:
        for byte in current_byte:
            destination_file.write(bytes([byte ^ code_key]))

    source_file.close()
    destination_file.close()

def process_directory(path):
    files = os.listdir(path)
    print('Total files:{}'.format(len(files)))
    i = 0
    for filename in files:
        try:
            print('{} ... {}'.format(i, filename))
            process_file(path, filename)
            i += 1
        except:
            pass

if __name__=="__main__":
    process_directory(r"C:\Users\FrogHarkness\Documents\WeChat Files\wxid_5d6v5u1a026912\FileStorage\Image\2021-11")
