import exampleClass

# For loops
start = 1
end = 11
# Loop goes from [start, end) 
for i in range(start, end):
    print(i)

stepSize = 2    
for j in range(start, end, stepSize):
    print(j)

# While loops
while(end > 0):
    print(end)
    end -= 1
    
# if else
isTrue = False
if (isTrue == True):
    #Does this if statement in paranthesis is True
    stepSize = 2
else:
    # Does this if statement in paranthesis is False
    stepSize = 1

# if elif else
if (stepSize == 2):
    stepSize = 12
elif (stepSize == 1):
    stepSize = 13
else:
    stepSize = 14

print(stepSize)
# switch

TC = exampleClass.testClass()
TC.printState()
TC.testFunction(5)
TC.printState()
