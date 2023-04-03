class testClass:

	def __init__(self):
		self.var1 = 5
		self.var2 = "test class"

	def testFunction(self, addN):
		self.var1 += addN

	def printState(self):
		print("var1 is ", self.var1)
		print("var2 is ", self.var2)
