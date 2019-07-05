import os

env = Environment() # Initialize the environment
if os.name == 'nt':
	print("Windows")
	env.Append(CPPDEFINES=['WINDOWS'])
else:
	print("Linux??")
env.Program(target = 'tutorial', source = ["tutorial.cpp"])
