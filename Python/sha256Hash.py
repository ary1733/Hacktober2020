from hashlib import sha256
data = input('Enter plaintext data: ')
output = sha256(data.encode('utf-8'))
print(output)
