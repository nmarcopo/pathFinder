#!/usr/bin/env python3
# sshin1 nmarcopo
import sys
import random

size = int(sys.argv[1])
letters = ['f', 'g', 'G', 'h', 'm', 'r']


print(6)
print('''f 3
g 1
G 2
h 4
r 5
m 7
''',end='')
print('{n1} {n2}'.format(n1=size, n2 = size))
for x in range(0, size):
    for y in range(0, size):
        print(random.choice(letters),end='')
    print()
print('''0 0
{n1} {n2}'''.format(n1=size-1, n2=size-1)) # size-1 because index starts at 0
